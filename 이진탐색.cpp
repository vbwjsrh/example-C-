#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[5000001];
int n, left, right, center, num; //n은 원소의 개수, left는 처음값, right는 나중값, num은 찾으려는 수
int main()
{ 
scanf("%d %d", &n, &num);             //원소의 개수와 찾을려는 원소
center =n/2;                          //중간순서
for(int i=0; i<n; i++) cin >> arr[i]; // 배열에 원소들을 저장
return 0;
}

long long int f(int left, int right, int n)
{
    if(center==(left+right))
}



}