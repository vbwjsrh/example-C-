#include <stdio.h>
#define INF 100000
 
int a[100][100]; //비용이 저장할 배열
int visit[100]; 
int dist[100]; 
int start, end;
int N,M;
// input 값 sample
// 첫번째 라인에는 정점의 개수, 간선의개수
// 두번째 라인부터는 정점별 간선의 입력받을 가중치가 m번이 들어온다.
// 세번째 라인에는 시작점과 끝점이 주어진다..
void input()
{
        int i,j;
        int from,to; //정점에서 정점
        int w; //가중치

        for ( i =1;i <=N; i++)    // 각 정점으로 가는 간선의 가중치를 무한대로 초기화.
                for ( j =1; j <=N; j++)
                        if ( i!= j)
                               { a[i][j] = INF;}
       
        scanf("%d %d",&N,&M); //정점의 개수, 간선의 개수가BB 입력
        for ( i =1;i <= M; i++) // 정점에서 정점으로 가는 간선의 가중치가 입력
        {
                scanf("%d %d %d",&from,&to,&w);
                a[from][to] =w;
        }

        scanf("%d %d" ,&start,&end);

        for ( i =1;i <=N; i++) 
        {dist[i] = INF;}
}
 
void dijkstra()
{
        int i,j;
        int min;
        int v;
 
        dist[start] = 0;                                        // 시작점의 거리 0
 
        for ( i =1;i <=N; i++)
        {
                min = INF;
               
                for ( j =1 ; j <=N; j++)
                {
                        if ( visit[j] == 0 && min > dist[j])    // 갈수 있는 정점중에 가장 가까운 정점 선택
                        {
                                min = dist[j];
                                v = j;
                        }
                }
 
                visit[v] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
       
                for ( j = 1;j <= N; j++)      
                {
                        if ( dist[j] > dist[v] + a[v][j])       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
                                dist[j] = dist[v] + a[v][j];
                }
        }
}
 
 
int main(void)
{
        input();
        dijkstra();
        printf("%d \n",dist[end]);
        return 0;
}


