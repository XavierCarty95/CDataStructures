#include <stdio.h>
#include <stdlib.h>


typedef struct NODE {
    int data;
    struct NODE *next;

}NODE;

typedef struct {
    struct NODE *head;
    struct NODE *tail;
    int nodeCount;
}LinkedList;


void initList(LinkedList *);
void createList(LinkedList *);
void insertAtHead(LinkedList *, int);

void insertAtTail(LinkedList *,int);
void printListDetail(LinkedList *);
NODE * find(LinkedList * , int);
void deleteFirst(LinkedList * );
void deleteLast(LinkedList *);
void deleteTarget(LinkedList *, int);
void reverse(LinkedList *);




void initList(LinkedList *lstptr){
    lstptr->head = NULL;
    lstptr->tail = NULL;
    lstptr->nodeCount = 0;
}
void insertAtTail(LinkedList *lstptr, int data){
    NODE *newNodePtr = (NODE*)malloc(sizeof(NODE));
    if(newNodePtr == NULL){
        printf("Unable to allocate new node");
        return;
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;
    //this is the case when the list is empty
    if(lstptr->nodeCount == 0){
        lstptr->head = newNodePtr;
        lstptr->tail = newNodePtr;
    }
    // if it is not empty
    else{
        lstptr->tail->next = newNodePtr;
        lstptr->tail = newNodePtr;
    }

    lstptr->nodeCount++;
}
void insertAtHead(LinkedList *lstptr, int data){
    NODE  *newNodePtr = (NODE*)malloc(sizeof(NODE));
    if (newNodePtr == NULL){
        printf("Memory could not be allocated ");
        return;
    }


        newNodePtr->data = data;
        newNodePtr->next = NULL;


    if(lstptr->nodeCount == 0){
        lstptr->head = newNodePtr;
        lstptr->tail = newNodePtr;
    }

     else{
       newNodePtr->next = lstptr->head;
        lstptr->head = newNodePtr;
         }

    lstptr->nodeCount++;

}
void printListDetail(LinkedList *lstptr){
    if(lstptr->nodeCount == 0){
        printf("Link list is empty");
        return;
    }
    printf("printing linked list in details\n");
    printf("head %p\n", lstptr->head);
    NODE *current = lstptr->head;
    int counter = 1;
    while(current != '\0'){
        printf("%d. (%p)[%d|%p]\n",counter, current,current->data,current->next);
        current = current->next;
        counter++;
    }
    printf("TAIL: %p\n",lstptr->tail);

}

void printList(LinkedList *lstptr){
    if(lstptr->nodeCount == 0){
        printf("Link list is empty");
        return;
    }
    NODE *current = lstptr->head;
    while(current != '\0'){
        printf("%d\n",current->data);
        current = current->next;
    }
}

NODE *find(LinkedList *lstptr, int target){
    NODE* current = lstptr->head;
    while(current != NULL){
        if(current->data == target){
            break;
        }
        current = current->next;
    }
    return current;
}
void menu(){
    printf(" Singly Linked List Operations\n");
    printf("----------------------------------\n");
    printf(" 1. Load from file\n");

    printf(" 2. Insert at head\n");
    printf(" 3. Insert at tail");
     printf(" 4. Print List (detail)\n");
    printf(" 5. Print list (data only)\n");
    printf(" 6. Find\n");
    printf(" 7. Delete First\n");
    printf(" 8. Delete last");
    printf(" 9. Delete a target node");
    printf("10. Reverse\n");
    printf("11. Quit\n");
}



int main(){
    LinkedList list;
    initList(&list);
    menu();
    int quit = 0;
    int choice;
    int data;
    while(!quit){
        printf("Please input your choice");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Input data to insert at head: ");
                scanf("%d",&data);
                insertAtHead(&list, data);
                break;
            case 2:
                printf("Input data to insert at Tail: ");
                scanf("%d",&data);
                insertAtTail(&list, data);
            break;
            case 3:
                printf("Input data to insert at tail (as last node");
            case 4:
                printListDetail(&list);
            case 6:
                printf("Search for a node");
                scanf("%d",&data);
                find(&list, data);

        }

    }

    return 0;
}
