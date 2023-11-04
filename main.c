#include "sorting.h"
#include "utils.h"

int main()
{
    srand(time(0));

    int arrSize = 1000, nbIt = 20, it;
    int *arr1, *arr2, *arr3, *arr4;
    double mat[nbIt][5];

    int caseType;
    do
    {
        printf("Entrez le type de cas (1 pour le meilleur cas, 2 pour le cas moyen, 3 pour le pire cas) : ");
        scanf("%d", &caseType);
    } while (caseType < 1 || caseType > 3);

    for (it = 0; it < nbIt; it++)
    {
        arr1 = generateRandomArray(arrSize, caseType);
        arr2 = copyArray(arr1, arrSize);
        arr3 = copyArray(arr1, arrSize);
        arr4 = copyArray(arr1, arrSize);
        mat[it][0] = arrSize;
        mat[it][1] = timeTaken(arr1, arrSize, selectionSort);
        mat[it][2] = timeTaken(arr2, arrSize, insertionSort);
        mat[it][3] = timeTaken(arr3, arrSize, bubbleSort);
        mat[it][4] = timeTaken(arr4, arrSize, shellSort);
        arrSize += 1000;
    }

    saveDataToFile(mat, nbIt);
    executeGnuplot();

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    return 0;
}