#include <stdio.h>
#include <assert.h>

int cmpInt(void* a, void* b) {
	return *((int*)a) > *((int*)b);
}

void qs(void* arr, int num, size_t size, int (*cmp)(void *a, void *b)) {
    int i = 0;
    int j = num - 1;
    char* ptr = (char*)arr;
    char* mid = ptr + (num / 2) * size;
    char* tmp = (char*)malloc(size);

    do {
        while (cmp(mid, ptr + i * size)) {
            i++;
        }
        while (cmp(ptr + j * size, mid)) {
            j--;
        }
        if (i <= j) {
            memcpy(tmp, ptr + i * size, size);
            memcpy(ptr + i * size, ptr + j * size, size);
            memcpy(ptr + j * size, tmp, size);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qs(ptr, j + 1, size, cmp);
    }
    if (i < num) {
        qs(ptr + i * size, num - i, size, cmp);
    }
}

int main() {
    int a[] = { 2, 1, 5, 4, 3 };
    int b[] = { 1, 2, 3, 4, 5 };
    qs(a, 5, sizeof(int), cmpInt);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
        assert(a[i] == b[i]);
    }
}