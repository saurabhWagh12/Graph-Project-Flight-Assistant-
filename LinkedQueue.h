#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include "LL.h"
struct queue{
    struct node *que;
    int size;
    int count;
    struct node *front;
    struct node *rear;
};
void init(struct queue *queue,int size){
    queue->que = NULL;
    queue->size = size;
    queue->count = 0;
    queue->front = queue->rear = NULL;
}
bool isEmpty(struct queue queue){
    if(queue.rear == NULL){
        return true;
    }else{
        return false;
    }
}
bool isFull(struct queue queue){
    if(queue.size == queue.count){
        return true;
    }
    else{
        return false;
    }
}
// void insertFromFront(struct Dqueue *queue,int val){
//     if(!isFull(*queue)){
//         if(isEmpty(*queue)){
//             queue->front = queue->rear = 0;
//             queue->que[queue->front] = val;
//         }
//         else{
//             queue->front = (queue->size + queue->front - 1) % queue->size;
//             queue->que[queue->front] = val;
//         }
//     }
// }
void enque(struct queue *queue,int val){
    if(!isFull(*queue)){
        if(isEmpty(*queue)){
            queue->rear = insertAtEnd(&(queue->que),val);
            queue->count = queue->count + 1;
            queue->front = queue->rear;
        }else{
            queue->rear = insertAtEnd(&(queue->que),val);
            queue->count = queue->count + 1;
        }
            
        
    }
}
int deque(struct queue *queue){
    if(!isEmpty(*queue)){
        if(queue->rear == queue->front){
            int data = (queue->front)->data;
            queue->front = NULL;
            queue->rear = NULL;
            queue->count = queue->count - 1;
        
            return data;
        }
        else{
            int data = (queue->front)->data;
            queue->front = (queue->front)->next;
            queue->count = queue->count - 1;
            return data;
        }
    }
}
// int deleteFromRear(struct Dqueue *queue){
//     if(!isEmpty(*queue)){
//         if(queue->rear == queue->front){
//             int data = queue->que[queue->front];
//             queue->front = queue->rear = -1;
//             return data;
//         }
//         else{
//             int data = queue->que[queue->rear];
//             queue->rear = (queue->size + queue->rear - 1)%queue->size;
//             return data;
//         }
//     }
// }
int peekRear(struct queue queue){
    return (queue.rear)->data;
}
int peekFront(struct queue queue){
    return (queue.front)->data;
}
void displayAll(struct queue queue){
    display(queue.front);
}

