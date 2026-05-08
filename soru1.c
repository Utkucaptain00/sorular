#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

void insertionSort(int dizi[]) {
    int i, key, j;
    for (i = 1; i < N; i++) {
        key = dizi[i];
        j = i - 1;
        while (j >= 0 && dizi[j] > key) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = key;
    }
}

void selectionSort(int dizi[]) {
    int i, j, min, temp;
    for (i = 0; i < N - 1; i++) {
        min = i;
        for (j = i + 1; j < N; j++) {
            if (dizi[j] < dizi[min])
                min = j;
        }
        temp = dizi[i];
        dizi[i] = dizi[min];
        dizi[min] = temp;
    }
}

int main() {
    int X[N], Y[N];
    clock_t start, end;
    double sure;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        X[i] = rand() % 1001;
        Y[i] = X[i];
    }

    start = clock();
    insertionSort(X);
    end = clock();
    sure = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort Süresi: %f saniye\n", sure);

    start = clock();
    selectionSort(Y);
    end = clock();
    sure = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort Süresi: %f saniye\n", sure);

    return 0;
}
