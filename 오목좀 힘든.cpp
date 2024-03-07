#include<stdio.h> //표준입출력 헤더파일 선언
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include <cmath>
#include <random> // C++11
#include <vector>

using namespace std;

int arr[19][19] = {0,};
//가로, 세로, 대각선 아래, 대각선 위순
int dy[4] = {0, 1, 1, -1};
int dx[4] = {1, 0, 1, 1};
bool flag = false;	//승부가 났는지 판별 
int win, frow, fcol;	//이긴돌, 가로줄, 세로줄

//가로, 세로, 연속갯수, 무슨색돌인지, 어느방향인지
void dfs(int row, int col, int cnt, int who, int d){
	//범위밖이면 리턴 
	if(row==-1||col==-1||row==19||col==19) return;
	
	//5카운트에 다음방향값이 다른색이고, 반대방향도 다른색이면 5목, 승부남
	if((cnt==5)&&(arr[row+dy[d]][col+dx[d]]!=who)&&(arr[row-dy[d]*5][col-dx[d]*5]!=who)){
		flag = true;
		win = who;
		frow = row - dy[d]*4 + 1;	//시작점은 4방향전값 + 0부터시작했으므로 1더해줌
		fcol = col - dx[d]*4 + 1;	//시작점은 4방향전값 + 0부터시작했으므로 1더해줌
		return;
	}
	
	//다음방향도 이어진다면 호출
	if(cnt>=2&&arr[row+dy[d]][col+dx[d]]==who) dfs(row+dy[d], col+dx[d], cnt+1, who, d);
	
	//처음이라면 4방향 탐색
	if(cnt==1){
		for(int i=0;i<4;i++){
			if(arr[row+dy[i]][col+dx[i]]==who) dfs(row+dy[i], col+dx[i], cnt+1, who, i);
		}
	}
	
	return;
}


int main(){
	
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	
	for(int i=0;i<19;i++){
		if(flag) break;
		for(int j=0;j<19;j++){
			if(arr[i][j]!=0) dfs(i, j, 1, arr[i][j], 0);
		}
	}
	
	if(flag) printf("%d\n%d %d", win, frow, fcol);
	else printf("0");
	
	return 0;
}
