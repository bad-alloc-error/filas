#include<stdio.h>
#include<stdlib.h>
#include"../include/fila_estatica.h"


struct queue_t{
    int* value;
    int capacity;
    uint64_t size;
    int begin;
    int end;
};

queue_t* create(int capacity){

    queue_t* queue = (queue_t *)calloc(1, sizeof(queue_t));
    queue->capacity = capacity;
    queue->begin = 0;
    queue->end = queue->begin;
    queue->value = (int *)calloc(capacity, sizeof(int));
    queue->size = 0;
    return queue;

}

int peek(const queue_t* queue){

    /*evita que retorne lixo da memória*/
    if(is_empty(queue)){
        fprintf(stderr, "Fila vazia!\n");
        exit(-1);
    }

    return queue->value[queue->begin];
}

void enqueue(queue_t* queue, int value){

    if(!is_full(queue)){
        queue->value[queue->end] = value;
        queue->end = (queue->end + 1) % queue->capacity;
        queue->size++;
        return;
    };

    fprintf(stderr, "Fila cheia! Valor não inserido: [%d]\n",value);
    exit(-1);
}

void dequeue(queue_t* queue){
    
    if(is_empty(queue)){
        fprintf(stderr, "Fila vazia!\n");
        exit(-1);
    }
    
    printf("Valor removido: [%d]\n", queue->value[queue->begin]);
    queue->begin = (queue->begin + 1) % queue->capacity;
    queue->size--;
}

bool is_empty(const queue_t* queue){

    if(queue->size > 0) return false;

    return true;

}

bool is_full(const queue_t* queue){

    if(queue->size == queue->capacity) return true;

}
uint64_t size(const queue_t* queue){
    return queue->size;
}

void print_queue(const queue_t* queue){

    printf("Capacidade: [%d]\n", queue->capacity);
    printf("Tamanho: [%zu]\n", queue->size);

    int i;
    for(uint64_t s = 0, i = queue->begin; s < queue->size; s++, i = (i + 1) % queue->capacity){
        printf("Dado enfileirado: [%d]\n", queue->value[i]);
    }

}

void free_queue(queue_t** queue){

    queue_t* q = *queue;

    free(q->value);
    free(q);

    *queue = NULL;
}

