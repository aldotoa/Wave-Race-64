extern int D_arr1[];
extern int D_arr2[];
extern short count;
void bar(int);

void test(void) {
    int i;
    for (i = 0; i < count; i++) {
        int off = i * 4;
        bar(*(int*)((char*)D_arr1 + off));
        bar(*(int*)((char*)D_arr2 + off));
    }
}
