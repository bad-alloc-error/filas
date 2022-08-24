#ifndef __FILA_DINAMICA_H__
#define __FILA_DINAMICA_H__
#include<stdbool.h>

typedef struct queue_t queue_t;

queue_t* create_queue(void);
void enqueue(queue_t* queue, int value);
void dequeue(queue_t* queue);
bool is_empty_queue(queue_t* queue);
int size(queue_t* queue);
int peek(queue_t* queue);
void destroy(queue_t** queue);

#endif