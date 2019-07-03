#include <stdio.h> 
#include <stdlib.h>
#include <time.h>



typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
}Node; 

typedef struct { 
    struct Node *head;
    struct Node *tail; 
    int NodeCount; 
    
    
}DBLinkedList;


void initList(DBLinkedList *lstptr);

void addFirst (DBLinkedList* lstptr, int data); 

void addLast(DBLinkedList* lstptr, int data); 

int loadFromFile(DBLinkedList *lstptr, char *fileName);

void createListFromRandomNumbers(DBLinkedList *lstptr, int n);

void printListDetail(DBLinkedList *list);

void printForward(DBLinkedList *lstptr);

void printReverse(DBLinkedList *lstptr);

Node* find(DBLinkedList *lstptr, int target);

int insertAfter(DBLinkedList *lstptr , int target, int data);

int insertBefore(DBLinkedList *lstptr, int target, int data);

int deleteFirst(DBLinkedList* lstptr);

int deleteLast(DBLinkedList* lstptr);

int deleteTarget(DBLinkedList *lstptr, int target);

void menu ();

void initList(DBLinkedList *lstptr) {
    lstptr->head = NULL; 
    lstptr->tail = NULL;
    lstptr->NodeCount = 0; 
   
    
}


void addFirst (DBLinkedList* lstptr, int data){ 
  
  //create new node dynamically using malloc 
  // assign the node content with dat 
  // intitialize the prev and next pointer with NULL 
  // IF THE nodeCount = 0 then 
  // head = tail = assign the address pf the new node 
    // else p>next = heaf 
            //head -> prev = p 
              //head = p 
 
   Node *p = (Node *)malloc(sizeof(Node));
   if(p==NULL){
     printf("Unable to create node for the double linked list");
     return;
   }
   
   p->data = data; 
   p->next = p->prev = NULL;
   
    if(lstptr->NodeCount == 0){
      lstptr->head = lstptr->tail = p;
    }
    
    else { 
      p->next = lstptr->head;
      lstptr->head->prev = p;
    }
    
    lstptr->NodeCount++;
 
  
}

void addLast(DBLinkedList *lstptr, int data){
    Node *p = (Node *)malloc(sizeof(Node));
   if(p == NULL){
     printf("Unable to create node for the double linked list");
     return;
   }
   
   p->data = data; 
   p->next = p->prev = NULL;
   if(lstptr->NodeCount == 0){
      lstptr->head = lstptr->tail = p;
    }
  else{
    lstptr->tail->next = p; 
    p->prev = lstptr->tail; 
    lstptr->tail = p;
  }
  
  lstptr->NodeCount++;
  
}

void printForward(DBLinkedList *lstptr){
  
  Node *p = lstptr->head; 
  if(p == NULL){
    printf("Linked List is empty\n");
    return;
  }
  printf("Content of the double linkedlist: \n");
  while(p!=NULL){
    printf("%4d",p->data);
    p=p->next;
  }
  printf("\n - End -- \n");
  
}

void printReverse(DBLinkedList *lstptr){
  Node *p = lstptr->head; 
  if(p == NULL){
    printf("Linked List is empty\n");
    return;
  }
  printf("Content of the double linkedlist in the reverse order: \n");
  while(p!=NULL){
    printf("%4d",p->data);
    p=p->prev;
  }
  printf("\n - End -- \n");
 
}



int loadFromFile(DBLinkedList *lstptr, char *fileName) {
FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL){
    return 0;
  }
  int data;
  fscanf(inputFile, "%d", &data);
  while(!feof(inputFile)){
   
    fscanf(inputFile, "%d", &data);
  }
  fclose(inputFile);
  return 1;

}
void createListFromRandomNumbers(DBLinkedList *lstptr, int n){
  int i;
  srand(time(NULL));

  for(i = 1; i<=n; ++i){
      int k = rand() % 1000;
      addLast(lstptr, k);
     
  }
}



void menu(){
  printf("    Singly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("1. Load from file\n");          // load integer data from file and will create the list
                                          // by using insert_at_tail operation (menu option 3)
  printf("2. Create list with random numbers\n");
  printf("3. Insert at head\n");          // inserting a new node as the first node
  printf("4. Insert at tail\n");          // inserting a new node as the last node
  printf("5. Print List (detail)\n");     // printing the linked list in details,
                                          // including the data and pointer in each node
  printf("6. Print List (data only)\n");  // prints the integer data in each node
  printf("7. Find\n");                    // finds if an integer exisits in a node from
                                          // the start in the list
  printf("8. Delete first\n");            // deletes the first node
  printf("9. Delete last\n");             // deletes the last node
  printf("10. Delete a target node\n");    // deletes a particular node, if that exists
  printf("11.Reverse\n");                 // will physically reverse the list
  printf("12. Quit\n");                   // to terminate each node
}


int main(){ 
DBLinkedList list;
initList(&list);
int quit = 0;
  int data, n, target;
  int success;
  int choice;
  menu();
  Node *current = NULL, *prev = NULL;
  while(!quit){
    printf("Please input your choice: ");
    scanf("%d", &choice);

switch(choice){
      case 1: success = loadFromFile(&list, "data.txt");
            if (success == 1)
              printf("File has been loaded successfully\n");
            else
              printf("There was some error while loading and creating the list\n");
            break;
      case 2:
            printf("Enter number of integers to be generated and added into the list: ");
            scanf("%d", &n);
            createListFromRandomNumbers(&list, n);
            break;
      case 3:
            // ask to input
            printf("Input data to insert at head (as first node): ");
            scanf("%d", &data);
            addFirst(&list,data);

            break;
      case 4:
            printf("Input data to insert at tail (as last node): ");
            scanf("%d", &data);
            addLast(&list,data);
            break;
      case 5://printListDetail(&list);
            break;
      case 6:
            printForward(&list);
            break;
      case 7: 
            printReverse(&list);
    
      case 12:
            quit = 1;
            break;
      default:
            printf("Invalid option chosen, valid option is from 1 - 11\n");
    }
  }

  return 0;
}
    
