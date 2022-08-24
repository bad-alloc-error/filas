#ifndef __FILA_ESTATICA_H__
#define __FILA_ESTATICA_H__

#include<stdbool.h>
#include<stdint.h>

typedef struct queue_t queue_t;

queue_t* create(int capacity);
void enqueue(queue_t* queue, int value);
void dequeue(queue_t* queue);
bool is_empty(const queue_t* queue);
bool is_full(const queue_t* queue);
uint64_t size(const queue_t* queue);
void print_queue(const queue_t* queue);
int peek(const queue_t* queue);
void free_queue(queue_t** queue);
#endif