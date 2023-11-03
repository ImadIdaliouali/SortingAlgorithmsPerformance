#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
}

double timeTaken(int *arr, int n, void fun(int *, int))
{
    time_t start, end;
    double execTime;
    start = clock();
    fun(arr, n);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void printMatrix(double mat[][5], int n)
{
    int i;
    printf("Size, Selection Sort, Insertion Sort, Bubble Sort, Shell Sort\n");
    for (i = 0; i < n; i++)
        printf("%.0f, %f, %f, %f, %f\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
}

int *copyArray(int *arr, int n)
{
    int *cArr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        cArr[i] = arr[i];
    return cArr;
}