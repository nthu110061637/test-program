#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MIN_VALUE 1
#define MAX_VALUE 100

// 生成指定範圍內的隨機數
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// 修改自Mibench的qsort範例，從程式碼中直接讀取輸入數據
void qsort_modified(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left;
        int j = right;
        int temp;

        do {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;

            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);

        qsort_modified(arr, left, j);
        qsort_modified(arr, i, right);
    }
}

int main() {
    int arr[SIZE];

    // 設置隨機種子
    srand(time(NULL));

    // 在這裡填入您想要的輸入數據
    // 例如，可以使用generateRandomNumber函数生成一個指定範圍內的隨機數組合
    for (int i = 0; i < SIZE; i++) {
        arr[i] = generateRandomNumber(MIN_VALUE, MAX_VALUE);
    }

    // 輸出未排序的隨機數陣列
    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 使用修改後的qsort_modified函式進行排序
    qsort_modified(arr, 0, SIZE - 1);

    // 輸出排序後的結果
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
