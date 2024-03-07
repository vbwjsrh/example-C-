#include <stdio.h> //hello world 라는 글자가 하나도 없지만 hello world를 출력하는 코드
main(){
  unsigned a[3] ={560229490,1867980911,1819043144};
    int i = a[1]^1867980909;
    do{
      do{
        putchar(a[i] & 255);
      } while (a[i] >>= 8);
    }while(i--);
}