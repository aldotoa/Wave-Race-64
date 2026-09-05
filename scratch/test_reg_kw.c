void bar(int);
void foo(int n) {
    register int a;
    int b;
    a = 0;
    b = 0;
    while (a < n) {
        bar(a);
        bar(b);
        a++;
        b++;
    }
}
