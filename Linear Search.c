#include <stdio.h>

int Linear_Search(int array[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (key == array[i])
            return i;
    }
    return -1;
}

int main() {
    int search, i, n;
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Enter a number to search\n");
    scanf("%d", &search);

    int result = Linear_Search(array, n, search);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}
