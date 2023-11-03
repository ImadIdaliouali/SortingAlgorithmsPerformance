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

int *copyArray(int *arr, int n)
{
    int *cArr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        cArr[i] = arr[i];
    return cArr;
}

void saveDataToFile(double mat[][5], int n)
{
    FILE *fptr = fopen("data.txt", "w");
    int i;
    fprintf(fptr, "Size, Selection Sort, Insertion Sort, Bubble Sort, Shell Sort\n");
    for (i = 0; i < n; i++)
        fprintf(fptr, "%.0f, %f, %f, %f, %f\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
    fclose(fptr);
}

void executeGnuplot()
{
    const char *command = "gnuplot plot_script.txt";
    FILE *pipe = popen(command, "r");
    if (pipe == NULL)
        perror("Error!");
    pclose(pipe);
}