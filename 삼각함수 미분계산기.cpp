#include <stdio.h>
#include <math.h>

int main() 
{
   double h=1, v1, v2, x, y, dv, index=1;

    
    printf("cos x�� �̺а�� x���� �Է��ϼ���");
    scanf("%lf", &x);
    
    y=cos(x);
    v1=(cos(x+10)-y)/10;
    v2=v1;
    printf("cos x = %.2lf (�ݿø�)\n", y);
    
    while(index>0.01)
    {
        v1=v2;
        v2=(cos(x+h)-y)/h;
        h/=10;
        index=fabs(v1-v2);
    }
    printf("��� ��ȭ��: %lf\n",index);
    printf("�̺а��: %lf",v2);
    return 0;
}