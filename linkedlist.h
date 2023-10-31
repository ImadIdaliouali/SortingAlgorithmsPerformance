#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct LinkedList* createLinkedList();
void append(struct LinkedList* list, int data);
void freeLinkedList(struct LinkedList* list);
void printLinkedList(struct LinkedList* list);

#endif

