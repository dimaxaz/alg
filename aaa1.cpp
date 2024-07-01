#include <stdio.h>
#include <stdlib.h>

// Функция для обмена значений двух переменных
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Функция для сортировки массива выбором
void selectionSort(int arr[], int n) {
    int i, j, minIdx;

    // Один за другим перемещаем границу неотсортированной части массива
    for (i = 0; i < n - 1; i++) {
        // Находим минимальный элемент в неотсортированной части массива
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;

        // Обмениваем найденный минимальный элемент с первым элементом
        swap(&arr[minIdx], &arr[i]);
    }
}

// Функция для печати массива
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    system("chcp 1251>null");
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Отсортированный массив: \n");
    printArray(arr, n);

    return 0;
}
