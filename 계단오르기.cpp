#include <stdio.h>

long long int dp[10000001];

	int f(int n)
{ 
  if(n==1) return 1;
  if(n==2) return 2;
  if(n==3) return 4;
  if(n==4) return 7;
  if(n==5) return 13;
	
  if(dp[n]!=0) return dp[n]; //�޸�� ���� �̹� ����Ǿ��ִ�? -> �Լ� ȣ������ ���� �ٷ� ����
    
	else return dp[n] = (f(n-1) + f(n-2) + f(n-3))%1000;
}

int main()
{
	
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	
	return 0;
}