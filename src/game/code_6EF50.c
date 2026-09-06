#include "common.h"

extern int D_801D7DB0;
extern struct Vec3f D_800E6DD0[4];
extern s32 D_800E6E30[];
extern SprayParticle D_801D7B70[16];
extern s32 D_801D7DB0;
extern s32 D_801AE950;

void Math_FloatRand(f32, f32);
s32 Math_Rand(int);

/* Spray pool limits (same values as the original literals). */
#define SPRAY_POOL_SIZE 16
#define SPRAY_BURST_SOURCES 8

/* Frees the whole spray pool and rewinds the round-robin cursor. */
void Spray_Reset(void) {
    int i;

    D_801D7DB0 = 0;

    for (i = 0; i < ARRAY_COUNT(D_801D7B70); i++) {
        D_801D7B70[i].active = 0;
    }
}

/* Spawns one spray particle at the next round-robin pool slot.
 * The spawn position is offset by the source's base direction, the
 * horizontal velocity is normalized to a fixed speed, and the Y velocity
 * gets a random upward lift. (Math_FloatRand's return value is discarded
 * by the original code; the call is kept for byte-match.) */
void Spray_Spawn(s32 source_id, f32 x_position, f32 y_position, f32 z_position, f32 x_velocity, f32 y_velocity,
                 f32 z_velocity) {
    struct SprayParticle* particle;
    struct Vec3f* srcPos;
    f32 randLift;
    f32 horizScale;
    f32 dirX;
    f32 dirY;
    f32 dirZ;

    particle = &D_801D7B70[D_801D7DB0];
    particle->active = 1;
    particle->age = 0;

    srcPos = &D_800E6DD0[source_id];
    particle->dlist = D_800E6E30[source_id];

    dirX = srcPos->x;
    dirY = srcPos->y;
    dirZ = srcPos->z;

    particle->posX = x_position + dirX;
    particle->posY = y_position + dirY;
    particle->posZ = z_position + dirZ;

    Math_FloatRand(8.0f, x_position);

    horizScale = sqrtf(SQ(dirX) + SQ(dirZ));
    if (horizScale > 0.0f) {
        horizScale = 12.0f / horizScale;
    }

    dirX *= horizScale;
    dirZ *= horizScale;
    randLift = Math_Rand(0xC) + 8.0f;
    particle->velX = dirX + x_velocity;
    particle->velY = randLift + y_velocity;
    particle->velZ = dirZ + z_velocity;

    D_801D7DB0++;
    D_801D7DB0 = D_801D7DB0 % SPRAY_POOL_SIZE;
}

/* Spawns a full 8-source spray burst at one spot, plus a ring effect
 * 24 units above the burst origin. */
void Spray_SpawnBurst(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 i;

    for (i = 0; i < SPRAY_BURST_SOURCES; i++) {
        Spray_Spawn(i, arg0, arg1, arg2, arg3, arg4, arg5);
    }
    func_800AF43C(arg0, arg1 + 24.0f, arg2);
}

/* Advances all live spray particles one frame: integrates velocity,
 * applies gravity, and frees particles that fall below y = -128. */
void Spray_Update(void) {
    int i;

    for (i = 0; i < SPRAY_POOL_SIZE; i++) {
        struct SprayParticle* particle = &D_801D7B70[i];

        if (particle->active != 0) {
            particle->age++;
            particle->posX += particle->velX;
            particle->posY += particle->velY;
            particle->posZ += particle->velZ;
            particle->velY -= 6.0f;

            if (particle->posY < -128.0f) {
                particle->active = 0;
            }
        }
    }
}

/* Appends display lists for all live spray particles and returns the
 * advanced display list pointer. */
void Spray_Draw(Gfx** gdl) {
    Gfx* gdlh;
    s32 i;

    gdlh = *gdl;
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                     G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_2CYCLE);
    gDPSetTexturePersp(gdlh++, G_TP_PERSP);
    gDPSetTextureFilter(gdlh++, G_TF_BILERP);
    gDPSetCombineMode(gdlh++, G_CC_MODULATEIA, G_CC_MODULATEIA2);
    gDPSetRenderMode(gdlh++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
    gDPSetAlphaCompare(gdlh++, G_AC_NONE);

    for (i = 0; i < ARRAY_COUNT(D_801D7B70); i++) {
        struct SprayParticle* particle = &D_801D7B70[i];

        if (particle->active != 0) {
            func_801EE46C(&D_801AE948->unk4140[D_801AE950], (-particle->age) * 8, -particle->velZ, 0, particle->velX,
                          particle->posX, particle->posY, particle->posZ);

            gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(gdlh++, particle->dlist);
        }
    }

    *gdl = gdlh;
}
