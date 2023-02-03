#include <stdio.h>
#include <stdlib.h>

// Simple singly linked list structure
struct list {
    struct list* next;
};

// inherited list of integers
struct list_int {
    struct list* next;
    int item;
};


int main()
{
    struct list* list;
    struct list* cur;
    int i;

    // create the first node in the list
    list = malloc(sizeof(struct list_int));
    list->next = NULL;
    ((struct list_int*) list)->item = 0;

    //populate the list
    cur = list;
    for(i=1; i<=10; i++) {
        cur->next = malloc(sizeof(struct list_int));
        cur->next->next = NULL;
        ((struct list_int*) (cur->next))->item = i;

        cur = cur->next;
    }

    //print out the list
    for(cur=list; cur; cur=cur->next) {
        printf("%d\n", ((struct list_int*) cur)->item);
    }

    //destroy the list
    cur = list;
    while(cur) {
        list=cur;
        cur=cur->next;
        free(list);
    }
}
