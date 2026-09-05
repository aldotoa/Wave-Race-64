void dummy(int*);
void test(int a) {
    int v0, v1, v2;
    dummy(&v0);
    dummy(&v1);
    dummy(&v2);
    if (a) {
        int inner;
        dummy(&inner);
    }
}
