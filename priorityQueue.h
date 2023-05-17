#include<stdio.h>
#include<stdlib.h>

typedef struct Pair{
    int n;
    int path;
    struct Pair* link;
}Pair;

typedef struct NodePQ{
    Pair p;
    struct NodePQ* link;
}NodePQ;

NodePQ* createNodePQPQ(){
    NodePQ* newNodePQ = (NodePQ*)malloc(sizeof(NodePQ));
    return newNodePQ;
}

void insertInPQ(NodePQ** head,Pair pair){
    NodePQ* newNodePQ = createNodePQPQ();
    newNodePQ->link = NULL;
    (newNodePQ->p).n = pair.n;
    (newNodePQ->p).path = pair.path;
    if(*head == NULL){
        *head = newNodePQ;
    }else if((*head)->link==NULL){
        if((*head)->p.path > (newNodePQ->p).path){
            NodePQ* temp = *head;
            *head = newNodePQ;
            newNodePQ->link = temp;
        }else if((*head)->p.path < (newNodePQ->p).path){
            (*head)->link = newNodePQ;
        }
    }else{
        NodePQ* temp = *head;
        while(temp->link!=NULL){
            if(temp->p.path<newNodePQ->p.path && temp->link->p.path>newNodePQ->p.path){
                NodePQ* temp2 = temp->link;
                newNodePQ->link = temp2;
                temp->link = newNodePQ;
                break;
            }else if(temp->p.path==newNodePQ->p.path || temp->link->p.path==newNodePQ->p.path){
                NodePQ* temp2 = temp->link;
                newNodePQ->link = temp2;
                temp->link = newNodePQ;
            }
            temp = temp->link;
        }
        if(temp->p.path < newNodePQ->p.path){
            temp->link = newNodePQ;
        }  
    }
}

int isEmptyPQ(NodePQ** head){
    if(*head==NULL){
        return 1;
    }
    return 0;
}

Pair removePQ(NodePQ** head){
    Pair t = (*head)->p;
    NodePQ* temp = *head;
    *head = temp->link;
    free(temp);
    return t;
}