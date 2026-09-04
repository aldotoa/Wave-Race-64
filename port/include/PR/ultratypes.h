#ifndef _ULTRA64_TYPES_H_
#define _ULTRA64_TYPES_H_

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

typedef signed char            s8;
typedef unsigned char          u8;
typedef signed short int       s16;
typedef unsigned short int     u16;
typedef signed int             s32;
typedef unsigned int           u32;
typedef signed long long int   s64;
typedef unsigned long long int u64;

typedef volatile u8   vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8   vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float  f32;
typedef double f64;

#if defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__)
typedef unsigned long size_t;
typedef long ssize_t;
typedef unsigned long uintptr_t;
typedef long intptr_t;
typedef long ptrdiff_t;
#else
typedef u32 size_t;
typedef s32 ssize_t;
typedef u32 uintptr_t;
typedef s32 intptr_t;
typedef s32 ptrdiff_t;
#endif

#endif /* _ULTRA64_TYPES_H_ */
