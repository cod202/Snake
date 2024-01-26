#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "snake.h"

void initialize_queue(queue *q) {
    q->first = NULL;
    q->last = NULL;
}


void enqueue(int x, int y,  queue *q) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->items.x = x;
    newNode->items.y = y;
    newNode->next = NULL;
    if (q->first == NULL) {
        newNode->direction = UP;
        q->first = newNode;
        q->last = newNode;
        
    }
    else{
        newNode->direction = q->last->direction;
        q->last->next = newNode;
        q->last = newNode;
    }
}


int is_empty(queue *q) {
    if (q->first == NULL){
        return 1;
    };
    return 0;
}

void dequeue(queue *q) {
    if (!is_empty(q)) {
        if (q->first == q->last){
            q->first = NULL;
            q->last = NULL;
        }
        else{
            node* aux;
            aux = q->first;
            q->first = q->first->next;
            free(aux);
        }
    }
}
