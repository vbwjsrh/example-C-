#include <stdio.h>
long long int a[80001], n, i, j, c;
int main (void)
{
    scanf ("%d", &n); // 소들의 개수 입력
    for (i=0; i<n; i++)
    {
        scanf ("%d", &a[i]); // 키 입력
    }
    
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (a[i] > a[j])
            { // 만약 키가 더 작다면?
                c++; // 개수 증가
            }
            else 
            {
                break; // 만약 크거나 같은 키를 가지고 있으면 break
            }
        }
    }
    printf ("%d", c); // c출력
}
