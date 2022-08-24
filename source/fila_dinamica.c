#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"../include/fila_dinamica.h"
#include"../include/linked.h"

struct queue_t{
    linked_list_t* value;
    int size;
};

queue_t* create_queue(void){
    
    queue_t* queue = (queue_t *)calloc(1, sizeof(queue_t));
    queue->value = init(); /*linked.h*/
    queue->size = 0;
    return queue;
}

void enqueue(queue_t* queue, int value){
    insert(queue->value, value); /*linked.h*/
    queue->size++;
}

void dequeue(queue_t* queue){
    remove_last(queue->value);
    queue->size--;
}

bool is_empty_queue(queue_t* queue){
    return is_empty(queue->value); /*linked.h*/
}

void destroy(queue_t** queue){
    queue_t* q = *queue;

    destroy_list(&q->value); /*linked.h*/
    free(q);
    *queue = NULL;
}




