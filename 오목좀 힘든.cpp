#include<stdio.h> //ǥ������� ������� ����
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include <cmath>
#include <random> // C++11
#include <vector>

using namespace std;

int arr[19][19] = {0,};
//����, ����, �밢�� �Ʒ�, �밢�� ����
int dy[4] = {0, 1, 1, -1};
int dx[4] = {1, 0, 1, 1};
bool flag = false;	//�ºΰ� ������ �Ǻ� 
int win, frow, fcol;	//�̱䵹, ������, ������

//����, ����, ���Ӱ���, ������������, �����������
void dfs(int row, int col, int cnt, int who, int d){
	//�������̸� ���� 
	if(row==-1||col==-1||row==19||col==19) return;
	
	//5ī��Ʈ�� �������Ⱚ�� �ٸ����̰�, �ݴ���⵵ �ٸ����̸� 5��, �ºγ�
	if((cnt==5)&&(arr[row+dy[d]][col+dx[d]]!=who)&&(arr[row-dy[d]*5][col-dx[d]*5]!=who)){
		flag = true;
		win = who;
		frow = row - dy[d]*4 + 1;	//�������� 4�������� + 0���ͽ��������Ƿ� 1������
		fcol = col - dx[d]*4 + 1;	//�������� 4�������� + 0���ͽ��������Ƿ� 1������
		return;
	}
	
	//�������⵵ �̾����ٸ� ȣ��
	if(cnt>=2&&arr[row+dy[d]][col+dx[d]]==who) dfs(row+dy[d], col+dx[d], cnt+1, who, d);
	
	//ó���̶�� 4���� Ž��
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
