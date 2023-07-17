
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];


bool visited[MAX];



void bfs(int adj[MAX][MAX],int start,int v) {
    int queue[MAX];
    int front = 0, rear = 0;
    
    visited[start] = true;
    queue[rear++] = start;
    
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        for (int i = 0; i < v; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}
int main() {
    int v =7;          //0,1,2,3,4,5,6
    int adj[MAX][MAX] ={{0,1,1,0,0,0,0},//0  // v*v
                        {1,0,0,1,0,0,0},//1
                        {1,0,0,0,1,0,0},//2
                        {0,1,0,0,1,1,0},//3
                        {0,0,1,1,0,1,0},//4
                        {0,0,0,1,1,0,1},//5
                        {0,0,0,0,0,1,0}};//6
    
    
    
    bfs(adj,0,v);

    
    return 0;
}
