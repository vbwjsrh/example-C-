#include <stdio.h>
long long int a[80001], n, i, j, c;
int main (void)
{
    scanf ("%d", &n); // �ҵ��� ���� �Է�
    for (i=0; i<n; i++)
    {
        scanf ("%d", &a[i]); // Ű �Է�
    }
    
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (a[i] > a[j])
            { // ���� Ű�� �� �۴ٸ�?
                c++; // ���� ����
            }
            else 
            {
                break; // ���� ũ�ų� ���� Ű�� ������ ������ break
            }
        }
    }
    printf ("%d", c); // c���
}
