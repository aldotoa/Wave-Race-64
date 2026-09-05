
    extern int arr1[], arr2[];
    void bar(int);
    void foo(int n) {
    
    int offset = 0;
    int i = 0;
    if (n > 0) {
        do {
            bar(*(int*)((unsigned char*)arr1 + offset));
            bar(*(int*)((unsigned char*)arr2 + offset));
            i++;
            offset += 4;
        } while (i < n);
    }
    
    }
    