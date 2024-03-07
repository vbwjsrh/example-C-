#include <stdio.h>
#define INF 100000
 
int a[100][100]; //����� ������ �迭
int visit[100]; 
int dist[100]; 
int start, end;
int N,M;
// input �� sample
// ù��° ���ο��� ������ ����, �����ǰ���
// �ι�° ���κ��ʹ� ������ ������ �Է¹��� ����ġ�� m���� ���´�.
// ����° ���ο��� �������� ������ �־�����..
void input()
{
        int i,j;
        int from,to; //�������� ����
        int w; //����ġ

        for ( i =1;i <=N; i++)    // �� �������� ���� ������ ����ġ�� ���Ѵ�� �ʱ�ȭ.
                for ( j =1; j <=N; j++)
                        if ( i!= j)
                               { a[i][j] = INF;}
       
        scanf("%d %d",&N,&M); //������ ����, ������ ������BB �Է�
        for ( i =1;i <= M; i++) // �������� �������� ���� ������ ����ġ�� �Է�
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
 
        dist[start] = 0;                                        // �������� �Ÿ� 0
 
        for ( i =1;i <=N; i++)
        {
                min = INF;
               
                for ( j =1 ; j <=N; j++)
                {
                        if ( visit[j] == 0 && min > dist[j])    // ���� �ִ� �����߿� ���� ����� ���� ����
                        {
                                min = dist[j];
                                v = j;
                        }
                }
 
                visit[v] = 1;   // ���� ����� �������� �湮, i�������� ���� ����� �ִܰ�� v
       
                for ( j = 1;j <= N; j++)      
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


