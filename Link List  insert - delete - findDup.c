#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;

    Node* next;
};

typedef struct{
    Node* head;
    Node* tail;
} List;

void init(List* list)
{
    list -> head = NULL;
    list -> tail = NULL;
}

void insert(List* list, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Failed to allocate memory.\n");
        return;
    }

    newNode -> data = val;
    newNode -> next = NULL;

    if(list -> head == NULL)
    {
        list -> head = newNode;
        list -> tail = newNode;
    }
    else{
        list -> tail -> next = newNode;
        list -> tail = newNode; // Update tail pointer
    }
}

void delNode(List* list, int val)
{
    if(list -> head == NULL) return; // List is empty

    Node* curr = list -> head;
    Node* prev = NULL;

    while(curr != NULL && curr -> data == val)
    {
        // Remove from the beginning of the list
        Node* temp = curr;
        
        curr = curr -> next; // NO need to update prev pointer!

        free(temp);
        list -> head = curr;
    }

    if(curr == NULL) // If the list become empty after removing
    {
        list -> tail = NULL;
        return;
    }

    // Now curr points to the first node that doesn't have the target value
    while(curr != NULL)
    {
        if(curr -> data == val)
        {
            Node* temp = curr;
            prev -> next = curr -> next;
            curr = curr -> next;

            free(temp);

            if(curr == NULL) // If we delete the last node
            {
                list -> tail = prev; // Update the tail pointer
            }
        }

        else
        {
            prev = curr;
            curr = curr -> next;
        }
    }
}

void printList(List* list)
{
    if(list -> head == NULL) return;
    Node* curr = list -> head;

    while(curr != NULL)
    {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}   

void freeList(List* list)
{
    if(list -> head == NULL) return;
    Node* curr = list -> head;

    while(curr!= NULL)
    {
        Node* temp = curr -> next;

        free(curr);

        curr = temp;
    }
}

void findDup(List* list) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* curr = list -> head;

    while (curr != NULL) {

        Node* checker = curr -> next;
        int isDuplicate = 0;

        while (checker != NULL) 
        {
            if (curr->data == checker->data) {
                isDuplicate = 1;
                break;
            }
            checker = checker->next;
        }

        if (isDuplicate) 
        {
            // Check if this duplicate was already printed
            int alreadyPrinted = 0;
            Node* checkerForPrinted = list -> head;

            while (checkerForPrinted != curr) 
            {
                if (checkerForPrinted -> data == curr -> data) {
                    alreadyPrinted = 1;
                    break;
                }
                
                checkerForPrinted = checkerForPrinted -> next;
            }

            if (!alreadyPrinted) 
            {
                printf("Duplicate found: %d\n", curr->data);
            }
        }

        curr = curr->next;
    }
}


int main()
{
    List mylist;
    init(&mylist);

    int N, num, d;
    scanf("%d %d",&d ,&N);

    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &num);
        insert(&mylist, num);
    }

    printList(&mylist);
    findDup(&mylist);

    delNode(&mylist, d);

    printf("\nAfter deletion: \n");
    printList(&mylist);
    freeList(&mylist);

    return 0;
}