#include "sorting.h"
#include "utils.h"

int main()
{
    // Initialize random number generator
    srand(time(0));

    int arrSize = 1000, nbIt, it;
    int *arr1, *arr2, *arr3, *arr4, *arr5;

    int caseType;
    do
    {
        printf("Entrez le type de cas (1 pour le meilleur cas, 2 pour le cas moyen, 3 pour le pire cas) : ");
        scanf("%d", &caseType);
    } while (caseType < 1 || caseType > 3);

    printf("Entrez le nombre d'itérations : ");
    scanf("%d", &nbIt);

    double mat[nbIt][6];

    for (it = 0; it < nbIt; it++)
    {
        arr1 = generateRandomArray(arrSize, caseType);
        arr2 = copyArray(arr1, 0, arrSize - 1);
        arr3 = copyArray(arr1, 0, arrSize - 1);
        arr4 = copyArray(arr1, 0, arrSize - 1);
        arr5 = copyArray(arr1, 0, arrSize - 1);
        mat[it][0] = arrSize;
        mat[it][1] = timeTaken(arr1, arrSize, selectionSort);
        mat[it][2] = timeTaken(arr2, arrSize, insertionSort);
        mat[it][3] = timeTaken(arr3, arrSize, bubbleSort);
        mat[it][4] = timeTaken(arr4, arrSize, shellSort);
        mat[it][5] = timeTaken(arr4, arrSize, mergeSort);
        arrSize += 1000;
    }

    saveDataToFile(mat, nbIt);
    executeGnuplot();

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    return 0;
}