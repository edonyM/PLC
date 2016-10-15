#include <stdio.h>

int a[10] = {10, 3, 4, 8, 11, 31, 7, 3, 89, 0};

int partrition(int start, int end) {
    int pivot = a[start];

    while (start < end) {
        while (start < end && a[end] > pivot) end--;
        a[start] = a[end];
        for (int i=0; i < 10; ++i) printf("+%d ", a[i]);printf("\n");
        while (start < end && a[start] <= pivot) start++;
        a[end] = a[start];
        for (int i=0; i < 10; ++i) printf("-%d ", a[i]);printf("\n");
    }


    a[start] = pivot;
    return start;
}

void quick_sort(int start, int end) {
    int mid;
    if (start < end) {
        mid = partrition(start, end);
        quick_sort(start, mid-1);
        quick_sort(mid+1, end);
    }
}

int main() {
    quick_sort(0, 9);
    for (int i=0; i < 10; ++i) printf("%d ", a[i]);
}
