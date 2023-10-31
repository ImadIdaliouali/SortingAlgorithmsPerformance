#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listgenerator.h"
#include "linkedlist.h"

int generateRandomNumber(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

struct LinkedList* generateRandomLinkedList(int size) {
    struct LinkedList* list = createLinkedList();
    for (int i = 0; i < size; i++) {
        int data = generateRandomNumber(0, 100);
        append(list, data);
    }
    return list;
}

struct LinkedList** generateRandomLinkedLists(int* sizes, int numLists) {
    struct LinkedList** listArray = (struct LinkedList**)malloc(numLists * sizeof(struct LinkedList*));
    if (listArray == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numLists; i++) {
        listArray[i] = generateRandomLinkedList(sizes[i]);
    }

    return listArray;
}
