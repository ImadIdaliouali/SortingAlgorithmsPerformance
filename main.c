#include "sorting.h"
#include "utils.h"

int main()
{
    srand(time(0));

    int arrSize = 1000, nbIt = 20, it;
    int *arr1, *arr2;
    double mat[nbIt][3];
    for (it = 0; it < nbIt; it++)
    {
        arr1 = generateRandomArray(arrSize);
        arr2 = copyArray(arr1, arrSize);
        mat[it][0] = arrSize;
        mat[it][1] = timeTaken(arr1, arrSize, selectionSort);
        mat[it][2] = timeTaken(arr2, arrSize, insertionSort);
        arrSize += 1000;
    }
    printMatrix(mat, nbIt);
    return 0;
}