extern int D_arr1[], D_arr2[], D_arr3[], D_arr4[], D_arr5[], D_arr6[];
extern short count;
void bar(int);

void test(int cond) {
    int i;
    for (i = 0; i < count; i++) {
        if (cond == 0) {
            bar(D_arr1[i]);
            bar(D_arr2[i]);
        } else if (cond == 1) {
            bar(D_arr3[i]);
            bar(D_arr4[i]);
        } else {
            bar(D_arr5[i]);
            bar(D_arr6[i]);
        }
    }
}
