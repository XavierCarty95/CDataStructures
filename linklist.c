#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct {
  struct Node *head;
  struct Node *tail;
  int nodeCount;
}LinkedList;

// function prototypes
void initList(LinkedList *);
int loadFromFile(LinkedList *, char *);
void createListFromRandomNumbers(LinkedList *, int);
void insertAtHead(LinkedList *, int);
void insertAtTail(LinkedList *, int);
void printListDetail(LinkedList *);
void printList(LinkedList *);
Node * find(LinkedList *, int, Node **);
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);
void reverse(LinkedList *);






// to initialize the linkedlist object
// Input parameter: listp is the pointer to linkedlist object
// Precondition: LinkedList object pointed by listptr must be existing.
// Return Value: Nothing
void initList(LinkedList *lstPtr){
  lstPtr->head = NULL;
  lstPtr->tail = NULL;
  lstPtr->nodeCount = 0;
}



// To add a new node at the end of the LinkedList
// Input parameters: pointer to struct LinkedList, an integer data that will
//                   be the content  of the new node.
// Precondition: The linkedList object must be existing.
// Return Value: Nothing
void insertAtTail(LinkedList *listPtr, int data){
  Node *newNodePtr = (Node*)malloc(sizeof(Node));
  if (newNodePtr == NULL){
    printf("Unable to allocate new node\n");
    return;
  }
  newNodePtr->data = data;
  newNodePtr->next = NULL;


  if (listPtr->nodeCount == 0){
    // this is the case when the list is empty
    listPtr->head = newNodePtr;
    listPtr->tail = newNodePtr;
  }
  else{
    // this is the case when the list is not empty
    listPtr->tail->next = newNodePtr;
    listPtr->tail = newNodePtr;
  }
  listPtr->nodeCount++;
}


// To add a new node at the begining of the LinkedList
// Input parameters: pointer to struct LinkedList, an integer data that will
//                   be the content  of the new node.
// Precondition: The linkedList object must be existing.
// Return Value: Nothing

void insertAtHead(LinkedList *listPtr, int data){
  Node *newNodePtr = (Node*)malloc(sizeof(Node));
  if (newNodePtr == NULL){
    printf("Unable to allocate new node\n");
    return;
  }
  newNodePtr->data = data;
  newNodePtr->next = NULL;


  if (listPtr->nodeCount == 0){
    // this is the case when the list is empty
    listPtr->head = newNodePtr;
    listPtr->tail = newNodePtr;
  }
  else{
    // this is the case when the list is not empty
    newNodePtr->next = listPtr->head;
    listPtr->head = newNodePtr;
  }
  listPtr->nodeCount++;
}

void printListDetail(LinkedList *lstPtr){
  if (lstPtr->nodeCount == 0){
    printf("Linked list is empty\n");
    return;
  }
  printf("Printing linked list in details\n");
  printf("HEAD: %p\n", lstPtr->head);
  Node *current = lstPtr->head;
  int counter = 1;
  while(current != NULL){
    printf("%d. (%p)[%d|%p]\n", counter, current, current->data, current->next);
    current = current->next;
    counter++;
  }
  printf("TAIL: %p\n", lstPtr->tail);

}

void printList(LinkedList *lstPtr){
  if (lstPtr->nodeCount == 0){
    printf("Linked list is empty\n");
    return;
  }
  Node *current = lstPtr->head;
  while(current != NULL){
    printf("%d\n", current->data);
    current = current->next;
  }

}

void menu(){
  printf("    Singly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("1. Load from file\n");          // load integer data from file and will create the list
                                          // by using insert_at_tail operation (menu option 3)  
  printf("2. Insert at head\n");          // inserting a new node as the first node
  printf("3. Insert at tail\n");          // inserting a new node as the last node
  printf("4. Print List (detail)\n");     // printing the linked list in details,
                                          // including the data and pointer in each node
  printf("5. Print List (data only)\n");  // prints the integer data in each node
  printf("6. Find\n");                    // finds if an integer exisits in a node from
                                          // the start in the list
  printf("7. Delete first\n");            // deletes the first node
  printf("8. Delete last\n");             // deletes the last node
  printf("9. Delete a target node\n");    // deletes a particular node, if that exists
  printf("10.Reverse\n");                 // will physically reverse the list
  printf("11. Quit\n");                   // to terminate each node
}

int main(){
  LinkedList list;
  initList(&list);
  int choice;
  menu();
  int quit = 0;
  int data, n, target;
  int success;
  Node *current = NULL, *prev = NULL;
  while(!quit){
    printf("Please input your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1: printf("Will be implemented in next lectures of the section 7.\n"); 
            break;
      
      case 2:
            // ask to input
            printf("Input data to insert at head (as first node): ");
            scanf("%d", &data);
            insertAtHead(&list, data);

            break;
      case 3:
            printf("Input data to insert at tail (as last node): ");
            scanf("%d", &data);
            insertAtTail(&list, data);
            break;
      case 4:printListDetail(&list);
            break;
      case 5:
            printList(&list);
            break;
      case 6:
            printf("Will be implemented in next lectures of the section 7.\n");
            break;
      case 7:
            printf("Will be implemented in next lectures of the section 7.\n");
            break;
      case 8:printf("Will be implemented in next lectures of the section 7.\n");
            break;
      case 9:
            printf("Will be implemented in next lectures of the section 7.\n");
            break;
      case 10:
            printf("Will be implemented in next lectures of the section 7.\n");
            break;
      case 11:
            quit = 1;
            break;
      default:
            printf("Invalid option chosen, valid option is from 1 - 11\n");
    }
  }

  return 0;
}
