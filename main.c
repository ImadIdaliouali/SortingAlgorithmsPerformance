#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listgenerator.h"
#include "sortingalgorithms.h"
#include <omp.h>


int main() {
    int sizes[] = {10, 100, 500, 1000, 10000};
    int numLists = sizeof(sizes) / sizeof(sizes[0]);

    // Create a 2D array to store execution times for each algorithm
    double executionTimes[numLists][5];

    // Set the number of threads for OpenMP (adjust as needed)
    omp_set_num_threads(4);

    executeParallelSortingTests(sizes, numLists, executionTimes);

    // Print the results in a table-like format
//    printf("%-15s%-20s%-20s%-20s%-20s%-20s\n", "List Size", "Insertion Sort", "Selection Sort", "Bubble Sort", "Merge Sort", "Quick Sort");
//    for (int i = 0; i < numLists; i++) {
//        printf("%-15d%-20lf%-20lf%-20lf%-20lf%-20lf\n", sizes[i], executionTimes[i][0], executionTimes[i][1], executionTimes[i][2], executionTimes[i][3], executionTimes[i][4]);
//    }


    // Open a file for writing
    FILE* dataFile = fopen("execution_times.csv", "w");

    // Print header row
    fprintf(dataFile, "List Size,Insertion Sort,Selection Sort,Bubble Sort,Merge Sort,Quick Sort\n");

    // Loop through the results and write them to the file
    for (int i = 0; i < numLists; i++) {
        fprintf(dataFile, "%d,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n", sizes[i], executionTimes[i][0], executionTimes[i][1], executionTimes[i][2], executionTimes[i][3], executionTimes[i][4]);
    }

    // Close the file
    fclose(dataFile);


    int result = system("gnuplot plot_script.gp");

    // Check the result of the system call
    if (result == 0) {
        printf("Gnuplot script executed successfully.\n");
    } else {
        printf("Error executing Gnuplot script.\n");
    }

    return 0;
}

