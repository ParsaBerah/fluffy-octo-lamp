#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n, int (*compare)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// توابع مقایسه
int ascending(int a, int b) { return a > b; }
int descending(int a, int b) { return a < b; }

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n, ascending);
    printf("Sorted ascending: ");
    printArray(arr, n);

    bubbleSort(arr, n, descending);
    printf("Sorted descending: ");
    printArray(arr, n);

    return 0;
}