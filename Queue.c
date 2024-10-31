#include<stdio.h>
#include<stdlib.h>
#define max_size 1000
struct Queue{
    int front;
    int rear;
    int arr[max_size];
};

struct Queue* create(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=0;
    return q;
}
int isFull(struct Queue* q){
    if(q->rear==max_size){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue* q){
    if(q->front==q->rear-1){
        return 1;
    }
    return 0;
}
void push(struct Queue* q,int val){
    if(isFull(q)){
        printf("Queue size limit exceeded\n");
        return;
    }
    q->arr[q->rear]=val;
    q->rear++;
}
void pop(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue size limit exceeded\n");
        return;
    }
    q->front++;
}
void peek(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n",q->arr[q->front+1]);
    return;
}
void printQueue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    for(int i=q->front+1;i<q->rear;i++){
        printf("%d\t",q->arr[i]);
    }
    printf("\n");
}
int main(){
    printf("Your Options\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. Stack elements\n");
    printf("other than this: Exit\n");
    struct Queue* q=create();
    while(1){
        int n,flag=0,val;
        printf("Select you option: \n");
        scanf("%d",&n);
        switch(n){
            case 1:printf("Enter element to push : ");
                   scanf("%d",&val);
                   push(q,val);
                   break;
            case 2:pop(q);
                   break;
            case 3:peek(q);
                   break;
            case 4:printQueue(q);
                   break;
            default:flag=1;
                    break;
        }
        if(flag==1){
            break;
        }
    }
}