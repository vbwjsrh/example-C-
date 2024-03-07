#include <stdio.h>
#define INF 100000

int a[10001][10001];
int visit[10000001];
int dist[10000001];
int start, end;
int n,m;
 

void input()
{
        int i,j;
        char from,to;
        int w;
        scanf("%d %d",&n,&m);
        // 각 정점으로 가는 간선의 가중치를 무한대로 초기화한다.(최소값을 구하기위해)
        for ( i =1;i <=n; i++)
                for ( j =1; j <=n; j++)
                        if ( i!= j)
                                a[i][j] = INF;
       
        for ( i =1; i <= m; i++) // 정점에서 정점으로 가는 간선의 가중치가 입력
        {
                scanf("%c %c %d",&from,&to,&w);
                /*from=from-64;
                to=to-64;
                a[from][to]=w;*/
        }
 
        for ( i =1; i <=n; i++)
                dist[i] = INF;
        scanf("%d %d" ,&start,&end);
}
 
void dijkstra()
{
        int i,j;
        int min;
        int v;
 
        dist[start] = 0;        // 시작점의 거리 0
 
        for ( i =1;i <=n; i++)
        {
                min = INF;
               
                for ( j =1 ; j <=n; j++)
                {
                        if ( visit[j] == 0 && min > dist[j])    // 갈수 있는 정점중에 가장 가까운 정점 선택
                        {
                                min = dist[j];
                                v = j;
                        }
                }
 
                visit[v] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
       
                for ( j = 1;j <= n; j++)      
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
