#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct list{
    node* head;
}List;

void addToHead(List* list, int data){
    struct node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void traverse(List* list){
    node* current = list->head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node* merge(List* l1, List* l2){
    node* head1 = l1-> head;
    node* head2 = l2-> head;

    node* dummy = (node*)malloc(sizeof(node));
    dummy -> data = -1;
    dummy -> next = NULL;

    node* temp = dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            head1= head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if(head1 != NULL){
        temp->next = head1;
    }else{
        temp->next = head2;
    }

    node* mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

int main(){
    List* l1 = (List*)malloc(sizeof(List));
    l1->head = NULL;

    List* l2 = (List*)malloc(sizeof(List));
    l2->head = NULL;
    
    addToHead(l1, 1);
    addToHead(l1, 2);
    addToHead(l1, 4);
    traverse(l1);

    addToHead(l2, 1);
    addToHead(l2, 3);
    addToHead(l2, 4);
    traverse(l2);


    node* mergedhead = merge(l1, l2);
    printf("merged list:\n");
    while(mergedhead != NULL){
        printf("%d->", mergedhead->data);
        mergedhead = mergedhead->next;
    }
    printf("NULL\n");

    return 0;
}