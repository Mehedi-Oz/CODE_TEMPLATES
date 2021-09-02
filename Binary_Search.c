#include <stdio.h>

int Binary_Search(int array[], int start_index, int end_index, int search) {
    while (start_index <= end_index) {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == search)
            return middle;
        if (array[middle] < search)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}

int main( ) {
    int search, i, n;
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter a number to search\n");
    scanf("%d", &search);

    int found_index = Binary_Search(array, 0, n - 1, search);

    if (found_index == -1) {
        printf("Element not found in the array ");
    } else {
        printf("Element found at index : %d", found_index);
    }
    return 0;
}