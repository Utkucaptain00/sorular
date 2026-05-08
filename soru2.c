#include <stdio.h>

void customSort(int a[], int n) {
    int temp;

    // Önce küçükten büyüğe sırala (basit bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int sonuc[n];
    int left = 0, right = n - 1;
    int k = 0;

    while (left <= right) {
        sonuc[k++] = a[right--]; // en büyük
        if (left <= right)
            sonuc[k++] = a[left++]; // en küçük
    }

    for (int i = 0; i < n; i++)
        printf("%d ", sonuc[i]);
}

int main() {
    int dizi[] = {60, 80, 3, 9, 57, 11};
    int n = 6;

    customSort(dizi, n);
    return 0;
}
