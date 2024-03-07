#include<stdlib.h>
#include<iostream>
#include <cmath>
#include <random> // C++11
#include <vector>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include <cmath>
#include <random> // C++11
#include <vector>
int n, l; //n은 차수, l은 근의 개수
double b = 10001;
double a[10], d[11], slope, x, y;
char o[20];

int main(void)
{
 x = 10000;
 slope = 0;
 y = 0;

 for(int i = 1; i <= 10; i++)
  {
      d[i] = 10001;
  }

 printf("차수를 입력하세요 : "); // 방정식의 차수 입력 
  scanf("%d", &n);

 printf("\n");

 for(int i = n; i >= 0; i--)
 {
  printf("%d차항의 계수를 입력하세요 : ", i); // 방정식의 계수 입력, 9차까지 계산 가능
  scanf("%lf", &a[i]);
 }

 printf("\n");

 for(int k = 100; k >= -100; k--) // x0를 -100부터 100까지 설정 
{
 x = k;

 for(int j = 1; j <= 10000; j++) // 접선을 구하고 x절편을 구하는 과정을 10000번 반복 
 {
  if(x == 0)
   x -= 0.000001; // x가 0이면 오류가 발생하기 때문에 매우 작은 값으로 설정 
  
  for(int i = n; i >= 0; i--)
   slope += a[i]*i*pow(x, i-1); // 미분계수(접선의 기울기)계산 

  for(int i = n; i >= 0; i--)
   y += a[i]*pow(x, i); // y좌표 계산 
  
  x = (x*slope-y)/slope; // x절편 계산 

  if(slope == 0)
   x = 0;

  slope = 0;
  y = 0;
 }

 x += 0.0000005;
 x = floor(x*pow(10, 6))/pow(10, 6); // 소수 6번째자리에서 반올림

 for(int i = 1; i <= 10; i++) // 같은 근이 중복하여 출력되지 않게 하기 위한 장치 
 {
 if(x == d[i]) // 같은 결괏값이 나올 경우 출력하지 않음
  goto skip;
 }
 l++;
 d[l] = x;

 skip:
 continue;
}
 if(l > 10) //근이 존재하지 않을 경우 설정(근이 없을 경우 무한대로 출력됨)
 {
  printf("근이 존재하지 않습니다.");
 }

else
 { 
  printf("방정식의 해는 ");
  for(int i = 1; i <= l; i++)
  {
   if(d[i] < 9999) // 오류 방지
    printf("%lf, ", d[i]);
  }
  printf("\b\b 입니다.");
  }

}