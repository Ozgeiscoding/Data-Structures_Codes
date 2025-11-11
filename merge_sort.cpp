#include <stdio.h>

const int MAX_SIZE = 100; // maximum-number-of-items-in-array

void merge(int D[], int left, int k, int right) {
    int i, j, l = 0;
    int M[MAX_SIZE]; // temporary array

    for (i = left, j = k + 1; (i <= k) && (j <= right); ) {
        if (D[i] < D[j]) {
            M[l] = D[i];
            i++;
            l++;
        }
        else {
            M[l] = D[j];
            j++;
            l++;
        }
    }

    // copy the remaining elements to M
    while (i <= k) {
        M[l] = D[i];
        i++;
        l++;
    }
    while (j <= right) {
        M[l] = D[j];
        j++;
        l++;
    }

    // copy M to D
    for (i = left, l = 0; i <= right; i++, l++)
        D[i] = M[l];
}

void mergeSort(int D[], int left, int right) {
    if (left < right) {
        int k = (left + right) / 2;
        mergeSort(D, left, k);
        mergeSort(D, k + 1, right);
        merge(D, left, k, right);
    }
}

int main() {
    int D[] = { 4, 10, 3, 5, 1 };
    int n = sizeof(D) / sizeof(D[0]);
    int i;

    printf("Orijinal dizi: ");
    for (i = 0; i < n; i++)
        printf("%d ", D[i]);
    printf("\n");

    mergeSort(D, 0, n - 1);

    printf("Siralanmis dizi: ");
    for (i = 0; i < n; i++)
        printf("%d ", D[i]);
    printf("\n");

    return 0;
}
