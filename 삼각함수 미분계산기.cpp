#include <stdio.h>
#include <math.h>

int main() 
{
   double h=1, v1, v2, x, y, dv, index=1;

    
    printf("cos x의 미분계수 x값을 입력하세요");
    scanf("%lf", &x);
    
    y=cos(x);
    v1=(cos(x+10)-y)/10;
    v2=v1;
    printf("cos x = %.2lf (반올림)\n", y);
    
    while(index>0.01)
    {
        v1=v2;
        v2=(cos(x+h)-y)/h;
        h/=10;
        index=fabs(v1-v2);
    }
    printf("평균 변화율: %lf\n",index);
    printf("미분계수: %lf",v2);
    return 0;
}