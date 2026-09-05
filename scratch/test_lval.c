
extern int arr[];
void foo(int offset) {
    (*(int*)((char*)arr + offset)) -= 1;
    ((int*)((char*)arr + offset))[0]--;
}
