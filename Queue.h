#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int n;
    struct Queue* link;
}Queue;


Queue* createNodeQueue(){
    Queue* n = (Queue*)malloc(sizeof(Queue));
    if(n==NULL){
        return NULL;
    }else{
        return n;
    }
}

int addInQueue(Queue** head,int n){
    Queue* temp=*head;
    Queue* newNode = createNodeQueue();
    newNode->n = n;
    newNode->link = NULL;
    if((*head)==NULL){
        (*head) = newNode; 
    }
    else if((*head)->link==NULL){
        (*head)->link = newNode;
    }
    else{
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = newNode;
        
    }
}

void display(Queue** head){
    Queue* temp = *head;
    printf("\nHII\n");
    printf("\n");
    while(temp!=NULL){
        printf("%d\t",temp->n);
        temp = temp->link;
    }
    // printf("%d\t",temp->n);
    printf("\n");


}
