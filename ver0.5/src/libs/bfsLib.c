#include "../include/inc.h"
#include <stdbool.h>

#define MAX 1000

typedef struct node{
    int x,y;
    bool visited;
}node;



/** Inizio Implementazione CODA **/

int inizioCoda = 0;
int fineCoda = -1;
int contatoreItem = 0;

bool enqueue(node* queue, int x, int y);
bool dequeue();
int peek(node* queue, int x, int y);
bool isfull();
bool isempty();

bool isfull(){
    return contatoreItem == MAX;
}

bool isempty(){
    return contatoreItem == 0;
}

bool enqueue(node* queue, int x, int y){
    if(!isfull()){
        if(fineCoda == MAX-1)
            fineCoda = -1;
        queue[++fineCoda] -> x = x;
        queue[++fineCoda] -> y = y;
        queue[++fineCoda] -> visited = 0;
        contatoreItem++;
    }
}

node dequeue(node* queue){
    node removed;
    removed.x = queue[inizioCoda++] -> x;
    removed.y = queue[inizioCoda++] -> y;
    removed.visited = queue[inizioCoda++] -> visited;
    if(inizioCoda == MAX)
        inizioCoda = 0;
    contatoreItem--;
    return removed;
}

node peek(node* queue){
    node peeked;
    peeked.x = queue[inizioCoda] -> x;
    peeked.y = queue[inizioCoda] -> y;
    peeked.visited = queue[inizioCoda] -> visited;
    return peeked;
}

int size(){
    return contatoreItem;
}

/** Fine Implementazione CODA **/

void bfs(int startx, int starty, int endx, int endy){

    int i;
    int rr;
    int cc;
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    for(i = 0; i < 4; i++){

        rr = startx + dr[i];
        cc = starty + dc[i];

        if(rr < 0 || cc < 0)
            continue;
        if(rr >= H || cc >= W)
            continue;

    }


}
