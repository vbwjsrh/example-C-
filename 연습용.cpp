#include <stdio.h> //hello world ��� ���ڰ� �ϳ��� ������ hello world�� ����ϴ� �ڵ�
main(){
  unsigned a[3] ={560229490,1867980911,1819043144};
    int i = a[1]^1867980909;
    do{
      do{
        putchar(a[i] & 255);
      } while (a[i] >>= 8);
    }while(i--);
}