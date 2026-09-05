
union Foo {
    struct {
        int a;
        int b;
    };
    int arr[2];
};
extern union Foo foo;
int bar(int i) {
    return foo.a + foo.arr[i];
}
