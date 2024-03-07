#include<stdio.h>

int map[11][11];
int main()
{
int n, m, a, b, i, j;
    
scanf("%d %d",&n, &m);
for(i=1; i<=m; i++)
{
    scanf("%d %d", &a, &b);
    map[a][b]= 1;
    map[b][a]= 1;
    }
    
for(i=1; i<=n; i++)
{
for(j=1; j<=n; j++)
    {
    printf("%d ", map[i][j]);
    }
    printf("\n");
}
     return 0;
}
