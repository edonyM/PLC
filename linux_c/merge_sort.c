#include <stdio.h>
#include <stdlib.h>

int a[10] = {10, 2, 3, 5, 8, 9, 7, 32, 8, 11};
//int a[2] = {10, 2};
void merge(int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;
    /*int merge_group1[len1] = {0};
    int merge_group2[len2] = {0};*/
    int *merge_group1 = (int*)malloc(len1);
    int *merge_group2 = (int*)malloc(len2);
    for (int i = 0; i < (mid - start + 1); ++i) merge_group1[i] = a[start + i];
    for (int i = 0; i < (end - mid); ++i) merge_group2[i] = a[mid + 1 + i];

    int c_grp1 = 0;
    int c_grp2 = 0;
    int c_a = start;
    while (c_grp1 < len1 && c_grp2 < len2) {
        if (merge_group1[c_grp1] < merge_group2[c_grp2]) {
            a[c_a++] = merge_group1[c_grp1++];
        } else {
            a[c_a++] = merge_group2[c_grp2++];
        }
    }
    while (c_grp1 < len1) {
        a[c_a++] = merge_group1[c_grp1++];
    }
    while (c_grp2 < len2) {
        a[c_a++] = merge_group2[c_grp2++];
    }

    free(merge_group1);
    free(merge_group2);
}


void sort(int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        sort(start, mid);
        sort(mid + 1, end);
        merge(start, mid, end);
    }

}
int main() {
    sort(0, 9);
    for (int i=0; i < 10; ++i) printf("%d ", a[i]);
    /*printf("\n%d %d %d %d %d %d %d %d %d %d\n",
           a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);*/
}
