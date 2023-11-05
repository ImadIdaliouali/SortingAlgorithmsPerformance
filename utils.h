#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int n, int caseType)
{
    int *arr = (int *)malloc(n * sizeof(int));
    int i;

    switch (caseType)
    {
    //? Best Case
    case 1:
        for (i = 0; i < n; i++)
            arr[i] = i;
        break;

    //? Average Case
    case 2:
        for (i = 0; i < n; i++)
            arr[i] = rand();
        break;

    //? Worst Case
    case 3:
        for (i = 0; i < n; i++)
            arr[i] = n - i - 1;
        break;
    }

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

int *copyArray(int *arr, int start, int end)
{
    int length = end - start + 1;
    int *cArr = (int *)malloc(length * sizeof(int));
    int i;
    for (i = 0; i < length; i++)
        cArr[i] = arr[start + i];
    return cArr;
}

void saveDataToFile(double mat[][6], int n)
{
    FILE *fptr = fopen("data.txt", "w");
    int i;
    fprintf(fptr, "Size, Selection Sort, Insertion Sort, Bubble Sort, Shell Sort, Merge Sort\n");
    for (i = 0; i < n; i++)
        fprintf(fptr, "%.0f, %f, %f, %f, %f, %f\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], mat[i][5]);
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