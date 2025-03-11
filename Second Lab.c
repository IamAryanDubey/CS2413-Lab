/*Question 1 - Implementing queue using stacks.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;
    int size;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->size = 100;
    queue->stack1 = (int*)malloc(queue->size * sizeof(int));
    queue->stack2 = (int*)malloc(queue->size * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}


/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/













/*Question 2 - */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *queue1;
    int *queue2;
    int front1, rear1;
    int front2, rear2;
    int size;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->size = 100;
    stack->queue1 = (int*)malloc(stack->size * sizeof(int));
    stack->queue2 = (int*)malloc(stack->size * sizeof(int));
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->rear2 + 1 >= obj->size) return;
    obj->queue2[++(obj->rear2)] = x;
    if (obj->front2 == -1) obj->front2 = 0;
    while (obj->front1 != -1 && obj->front1 <= obj->rear1) {
        obj->queue2[++(obj->rear2)] = obj->queue1[obj->front1++];
    }
    int *tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    obj->front1 = 0;
    obj->rear1 = obj->rear2;
    obj->front2 = obj->rear2 = -1;
}

int myStackPop(MyStack* obj) {
    if (obj->front1 == -1 || obj->front1 > obj->rear1) return -1;
    int x = obj->queue1[obj->front1++];
    if (obj->front1 > obj->rear1) {
        obj->front1 = obj->rear1 = -1;
    }
    return x;
}

int myStackTop(MyStack* obj) {
    if (obj->front1 == -1 || obj->front1 > obj->rear1) return -1;
    return obj->queue1[obj->front1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->front1 == -1 || obj->front1 > obj->rear1;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/