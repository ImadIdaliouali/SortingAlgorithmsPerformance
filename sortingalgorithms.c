#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "sortingalgorithms.h"


struct LinkedList* copyList(struct LinkedList* originalList) {
    struct LinkedList* newList = createLinkedList();
    struct Node* current = originalList->head;
    while (current != NULL) {
        append(newList, current->data);
        current = current->next;
    }
    return newList;
}


void insertion_sort(struct LinkedList* list) {
    struct LinkedList* copy = copyList(list);

    struct Node* sorted = NULL;
    struct Node* current = copy->head;

    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* search = sorted;
            while (search->next != NULL && current->data >= search->next->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }

    list->head = sorted;
    list->size = copy->size;
    free(copy);
}


void selection_sort(struct LinkedList* list) {
    struct LinkedList* copy = copyList(list);
    struct Node* current = copy->head;

    while (current != NULL) {
        struct Node* min = current;
        struct Node* temp = current->next;

        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }

        int tempData = current->data;
        current->data = min->data;
        min->data = tempData;

        current = current->next;
    }

    list->head = copy->head;
    list->size = copy->size;
    free(copy);
}


void bubble_sort(struct LinkedList* list) {
    struct LinkedList* copy = copyList(list);
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = copy->head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    list->head = copy->head;
    list->size = copy->size;
    free(copy);
}


struct Node* merge(struct Node* left, struct Node* right) {
    struct Node* result = NULL;
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}


void split(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* slow;
    struct Node* fast;
    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
    } else {
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}


struct Node* merge_sort_rec(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* front;
    struct Node* back;

    split(head, &front, &back);

    front = merge_sort_rec(front);
    back = merge_sort_rec(back);

    return merge(front, back);
}


void merge_sort(struct LinkedList* list) {
    struct LinkedList* copy = copyList(list);

    copy->head = merge_sort_rec(copy->head);

    list->head = copy->head;
    list->size = copy->size;
    free(copy);
}


struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = end;
    struct Node* prev = NULL;
    struct Node* cur = head;
    struct Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            struct Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == NULL) {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;

    return pivot;
}


struct Node* getTail(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    while (head->next != NULL) {
        head = head->next;
    }

    return head;
}


struct Node* quick_sort_rec(struct Node* head, struct Node* end) {
    if (!head || head == end) {
        return head;
    }

    struct Node* newHead = NULL;
    struct Node* newEnd = NULL;

    struct Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;

        newHead = quick_sort_rec(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quick_sort_rec(pivot->next, newEnd);

    return newHead;
}


void quick_sort(struct LinkedList* list) {
    struct LinkedList* copy = copyList(list);

    struct Node* end = getTail(copy->head);

    copy->head = quick_sort_rec(copy->head, end);

    list->head = copy->head;
    list->size = copy->size;
    free(copy);
}

