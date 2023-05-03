#include <stdio.h>
#include <stdlib.h>
#define INF 10000
#define MAX 20
int Bellman_Ford(int G[MAX][MAX], int V, int E, int edge[MAX][2]) {
int i, u, v, k, distance[MAX], parent[MAX], S, flag = 1;
printf("Enter source: ");
scanf("%d", &S); //출발지
// distance initializing. All nodes set value to inf except start node.
// Parent arrays are also needed to be initialized with negative values such as -1
// Main algorithm of Bellman ford. To find the nodes u and v, we can use the edge
// array. It contains edge information from source nodes to destination nodes.
// For example, edge[0][0] means a start point, edge[0][1] indicates the end point.

//각 정점 INF로 초기화
for (i =0; i<V; i++){
	distance[i] = INF; //정점까지의 거리
	parent[i] = -1; //이전노드가 누구?
}
distance[S-1] = 0;

//최소거리로 초기ㅣ화
for(i=0; i<V; i++){
	for(k=0; k<E; k++){
		u = edge[k][0];
		v = edge[k][1];
		if(distance[u] + G[u][v] < distance[v]){
			distance[v] = distance[u] + G[u][v];
			parent[v]=u;
		}
	}
}







//edge 갱신 음의 사이클이 있는지?
for (k = 0; k<E; k++) { u = edge[k][0], v = edge[k][1];
if (distance[u] + G[u][v] < distance[v])
flag = 0;
}
if (flag)
for (i = 0; i<V; i++)
printf("Vertex %d -> cost = %d parent = %d\n", i + 1, distance[i], parent[i] + 
1);
return flag;
}


int main(void) {
int V, edge[MAX][2], G[MAX][MAX], i, j, k = 0;
printf("BELLMAN FORD\n");
printf("Enter no. of vertices: ");
scanf("%d", &V);
printf("Enter graph in matrix form:\n");
for (i = 0; i<V; i++)
for (j = 0; j<V; j++) {
scanf("%d", &G[i][j]);
if (G[i][j] != 0)
edge[k][0] = i, edge[k++][1] = j;
}
if (Bellman_Ford(G, V, k, edge))
printf("\nNo negative weight cycle\n");
else printf("\nNegative weight cycle exists\n");
return 0;
}
