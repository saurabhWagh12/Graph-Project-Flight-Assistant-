#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int src;
    int dest;
    int wt;
    int time;
    struct Node* link;
}Node;

Node* createNode(){
    Node* n = (Node*)malloc(sizeof(Node));
    if(n==NULL){
        return NULL;
    }else{
        return n;
    }
}

int add(Node** head,int src,int dest,int wt,int time){
    Node* temp=*head;
    Node* newNode = createNode();
    newNode->src = src;
    newNode->dest = dest;
    newNode->wt = wt;
    newNode->time = time;
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

Node* get(Node** head,int i){
    Node* temp= *head;
    int pos=0;
    while(pos!=i){
        temp = temp->link;
        pos++;
    }
    return temp->link;
}


int size(Node* head){
    Node* temp =head;
    int i=0;
    while(temp->link!=NULL){
        temp=temp->link;
        i++;
    }
    return i;
}
