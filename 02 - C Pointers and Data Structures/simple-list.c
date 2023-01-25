#include <stdio.h>
#include <stdlib.h>

struct list {
    int item;
    struct list *next;
};

int main()
{
    struct list head;
    struct list *cur;

    head.item = 0;

    // add items to the list
    cur = malloc(sizeof(struct list));
    cur->item = 1;
    head.next = cur;       // head -> cur 
    
    // add two more items
    cur->next = malloc(sizeof(struct list)); // head -> cur -> new node
    cur = cur->next;
    cur->item = 2;
    cur->next = malloc(sizeof(struct list));
    cur = cur->next;
    cur->item = 3;
    cur->next = 0x00;

    //iterate over the linked list
    for(cur = &head; cur; cur=cur->next) {
        printf("&node: %p\t item: %d\n", cur, cur->item);
    }
}