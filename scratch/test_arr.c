extern int D_arr1[];
extern int D_arr2[];
void bar(int);

void test1(int n) {
    int i = 0;
    int off = 0;
    if (n > 0) {
        do {
            bar(*(int*)((char*)D_arr1 + off));
            bar(*(int*)((char*)D_arr2 + off));
            i++;
            off += 4;
        } while (i < n);
    }
}
