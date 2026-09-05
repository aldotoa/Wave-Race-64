void bar(int);
void foo(int n) {
    int a;
    register int b;
    a = 0;
    b = 0;
    while (a < n) {
        bar(a);
        bar(b);
        a++;
        b++;
    }
}
