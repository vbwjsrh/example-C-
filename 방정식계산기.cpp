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
int n, l; //n�� ����, l�� ���� ����
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

 printf("������ �Է��ϼ��� : "); // �������� ���� �Է� 
  scanf("%d", &n);

 printf("\n");

 for(int i = n; i >= 0; i--)
 {
  printf("%d������ ����� �Է��ϼ��� : ", i); // �������� ��� �Է�, 9������ ��� ����
  scanf("%lf", &a[i]);
 }

 printf("\n");

 for(int k = 100; k >= -100; k--) // x0�� -100���� 100���� ���� 
{
 x = k;

 for(int j = 1; j <= 10000; j++) // ������ ���ϰ� x������ ���ϴ� ������ 10000�� �ݺ� 
 {
  if(x == 0)
   x -= 0.000001; // x�� 0�̸� ������ �߻��ϱ� ������ �ſ� ���� ������ ���� 
  
  for(int i = n; i >= 0; i--)
   slope += a[i]*i*pow(x, i-1); // �̺а��(������ ����)��� 

  for(int i = n; i >= 0; i--)
   y += a[i]*pow(x, i); // y��ǥ ��� 
  
  x = (x*slope-y)/slope; // x���� ��� 

  if(slope == 0)
   x = 0;

  slope = 0;
  y = 0;
 }

 x += 0.0000005;
 x = floor(x*pow(10, 6))/pow(10, 6); // �Ҽ� 6��°�ڸ����� �ݿø�

 for(int i = 1; i <= 10; i++) // ���� ���� �ߺ��Ͽ� ��µ��� �ʰ� �ϱ� ���� ��ġ 
 {
 if(x == d[i]) // ���� �ᱣ���� ���� ��� ������� ����
  goto skip;
 }
 l++;
 d[l] = x;

 skip:
 continue;
}
 if(l > 10) //���� �������� ���� ��� ����(���� ���� ��� ���Ѵ�� ��µ�)
 {
  printf("���� �������� �ʽ��ϴ�.");
 }

else
 { 
  printf("�������� �ش� ");
  for(int i = 1; i <= l; i++)
  {
   if(d[i] < 9999) // ���� ����
    printf("%lf, ", d[i]);
  }
  printf("\b\b �Դϴ�.");
  }

}