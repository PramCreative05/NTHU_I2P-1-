#include <stdio.h>
#include <string.h>

int graph[100][100];
int visited[100];
int N, K; //N=total nodes; K=Available Relationship

/* First Step: Populate the graph for DFS */
void addEgde(int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}

/* Second Step: DFS for skipping the nodes */
void DFS(int v){
    visited[v] = 1; //Activating new nodes
    for(int i = 0; i < N; i++){ //Scan adjacent nodes: Col wise
        if(graph[v][i] && !visited[i]) DFS(i); //Inject recursive: discovery
    }
}

/* Third Step: Driver Function count the blocks */

int blocks(){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            DFS(i);
            count++; //After exit from block, add +1
        }
    }
    return count;
}

int main(void){
    scanf("%d %d", &N, &K);

    //Initialized Platform
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    //Parsing available relationship
    for(int i = 0; i < K; i++){
        int a, b;
        scanf(" %d %d", &a, &b);
        addEgde(a, b);
    }

    //Call the driver
    int found = blocks();

    printf("%d\n", found - 1);
    return 0;
}
