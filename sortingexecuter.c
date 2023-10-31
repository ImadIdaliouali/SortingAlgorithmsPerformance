#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listgenerator.h"
#include "sortingalgorithms.h"
#include <omp.h>


// Function to measure the execution time of a sorting algorithm
double measureExecutionTime(struct LinkedList* list, void (*sortFunc)(struct LinkedList*)) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(list);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

// Function to generate random lists, sort them in parallel, and record execution times
void executeParallelSortingTests(int* sizes, int numLists, double executionTimes[][5]) {
    // Generate the random linked lists
    printf("Generating the random lists\n");
    struct LinkedList** generatedLists = generateRandomLinkedLists(sizes, numLists);
    printf("The random lists were generated successfully\n");

    // Perform parallel sorting and measure execution time for each list
    #pragma omp parallel for
    for (int i = 0; i < numLists; i++) {
        struct LinkedList* currentList = generatedLists[i];
        int size = currentList->size;

        // Measure execution time for each sorting algorithm and store it in the 2D array
        executionTimes[i][0] = measureExecutionTime(copyList(currentList), insertion_sort);
        executionTimes[i][1] = measureExecutionTime(copyList(currentList), selection_sort);
        executionTimes[i][2] = measureExecutionTime(copyList(currentList), bubble_sort);
        executionTimes[i][3] = measureExecutionTime(copyList(currentList), merge_sort);
        executionTimes[i][4] = measureExecutionTime(copyList(currentList), quick_sort);

        // Clean up
        freeLinkedList(currentList);
    }

    // Free the array of list heads
    free(generatedLists);
}
