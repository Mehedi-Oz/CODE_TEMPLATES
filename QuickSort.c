#include <stdio.h>

void QS(int Array[], int low, int high);

int partition(int Array[], int low, int high);

void output(int Array[], int size);

int main() {
    int i, size = 0, count_zero = 0;

    int Array[500000];

    for (i = 0;; i++) {
        scanf("%d", &Array[i]);
        size++;
        count_zero++;
        if (Array[i] == 0) {
            count_zero++;
            if (count_zero == 2) {
                break;
            }
        }
    }
    QS(Array, 0, size - 1);
    output(Array, size);

    return 0;
}

void QS(int Array[], int low, int high) {
    if (low < high) {
        int index_pivot = partition(Array, low, high);
        QS(Array, low, index_pivot - 1);
        QS(Array, index_pivot + 1, high);
    }
}

int partition(int Array[], int low, int high) {
    int pivot_value = Array[low];
    int index_pivot = low;

    for (int i = low + 1; i < high; i++) {
        if (Array[i] < pivot_value) {
            Array[index_pivot] = Array[i];
            Array[i] = Array[index_pivot + 1];
            index_pivot++;
        }
    }
    Array[index_pivot] = pivot_value;

    return index_pivot;
}

void output(int Array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", Array[i]);
    }
    printf("\n");
}
