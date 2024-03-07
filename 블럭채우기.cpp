#include<iostream>
#include<stdio.h>
#define tt 100007
#define lli long long int 
using namespace std;

long long int dp[10000001];

int f(int n)
{ 
  if(n==2) return 7;
  if(n==3) return 22;
  if(n==4) return 71;
  if(n==5) return 228;
  if(n==6) return 733;

if(dp[n]!= 0)
    return dp[n];
else
{
    dp[n]= (3*f(n-1)%tt+f(n-2)%tt-f(n-3)%tt)%tt;
    if(dp[n]<0)
    return dp[n]+tt;
    else
    return dp[n];
}

}

int main()
{
	int N;
    scanf("%d",&N);
    if(N<2) printf("0");
    else printf("%d",f(N));
	return 0;
}
