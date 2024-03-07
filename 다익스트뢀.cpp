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
        // �� �������� ���� ������ ����ġ�� ���Ѵ�� �ʱ�ȭ�Ѵ�.(�ּҰ��� ���ϱ�����)
        for ( i =1;i <=n; i++)
                for ( j =1; j <=n; j++)
                        if ( i!= j)
                                a[i][j] = INF;
       
        for ( i =1; i <= m; i++) // �������� �������� ���� ������ ����ġ�� �Է�
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
 
        dist[start] = 0;        // �������� �Ÿ� 0
 
        for ( i =1;i <=n; i++)
        {
                min = INF;
               
                for ( j =1 ; j <=n; j++)
                {
                        if ( visit[j] == 0 && min > dist[j])    // ���� �ִ� �����߿� ���� ����� ���� ����
                        {
                                min = dist[j];
                                v = j;
                        }
                }
 
                visit[v] = 1;   // ���� ����� �������� �湮, i�������� ���� ����� �ִܰ�� v
       
                for ( j = 1;j <= n; j++)      
                {
                        if ( dist[j] > dist[v] + a[v][j])       // �湮�� ������ ���� �ٸ� ���������� �Ÿ��� ª�������� ����Ͽ� �����Ȱ� ����
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
