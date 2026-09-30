#include <stdio.h>

int sequentialSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int a[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    int n = 10, key;

    printf("Enter roll number: ");
    scanf("%d", &key);

    int s = sequentialSearch(a, n, key);
    int b = binarySearch(a, n, key);

    if (s != -1)
        printf("Sequential Search: Found at position %d\n", s + 1);
    else
        printf("Sequential Search: Not Found\n");

    if (b != -1)
        printf("Binary Search: Found at position %d\n", b + 1);
    else
        printf("Binary Search: Not Found\n");

    return 0;
}
