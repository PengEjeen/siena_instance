#include<stdio.h>
#include <limits.h>

// 정점의 수를 지정한다.
#define V 5

// INF를 무한대라고 지정하고, INT_MAX를 이용한다.
#define INF 10000


// 플로이드 워셜의 결과를 출력하는 함수
void printSolution(int dist[][V]) {
printf("Following matrix shows the shortest distances, between every pair of vertices \n\n");
printf("\t   to→ ");
for (int i = 0; i < V; i++)
printf("[%d]    ", i);

printf("\n      ↓from \n");

for (int i = 0; i < V; i++) {
printf("\t[%d]", i);
for (int j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("%7s", "INF");
else
printf("%7d", dist[i][j]);
}
printf("\n");
}
}
// 모든 경로에 대한 최단 거리를 찾아주는 플로이드 워셜 함수
void floydWarshall(int graph[][V]) {
  /* dist[][] 배열에 최단 거리에 대한 정보들이 모두 들어가게 된다. */
   int dist[V][V], i, j, k;
  /*
    dist[][] 배열에 초기값은 그래프에서 주어진 값들이다.
   (즉, 아직 최단 거리를 구하기 전에는 기존의 거리를 최단 거리라 생각한다.)
  */
   for (i = 0; i < V; i++)
   for (j = 0; j < V; j++)
   dist[i][j] = graph[i][j];
   /* 플로이드 워셜 알고리즘의 핵심 */
	for(k=0;k<V;k++){
		for(i=0;i<V;i++){
			if(i==k) continue;
			else{
				for(j=0; j<V; j++){
					if(i==j || j==k) continue;
					else{
						if(dist[i][j]>dist[i][k]+dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
				
	}	
	int is_equal = 0;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if (dist[i][j] != graph[i][j]){
				is_equal++;
			}
		}
	}
	printf("바뀐 개수는: %d\n",is_equal);


//모든 최단거리가 구해지고 난 뒤, 출력
   printSolution(dist);
}

int main(void) {
   int graph[V][V] = {{ 0, 8, 4, 5, 5 },
                              { 7, 0, 6, 2, 2 },
                              { 3, 2, 0, 3, 7 },
                              { 7, 3, 7, 0, 1 },
                              { 3, 7, 4, 2, 0 },
   };

   // 플로이드 워셜 알고리즘으로 진입
   floydWarshall(graph);
   return 0;
}







   
