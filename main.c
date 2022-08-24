#include<stdio.h>
#include"include/fila_estatica.h"

int main(){

    queue_t* q = create(10);
    queue(q, 855);
    queue(q, 565);
    queue(q, 346);
    queue(q, 764);
    queue(q, 254);
    queue(q, 222);
    queue(q, 111);
    queue(q, 986);
    queue(q, 458);
    queue(q, 936);
    int p = peek(q);

    print_queue(q);

    printf("%d\n", p);
    dequeue(q);
    print_queue(q);

    return 0;
}