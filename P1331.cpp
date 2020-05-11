#include<iostream>
using namespace std;
const int MAXN=1005;
int r,c,ans=0;
char graph[MAXN][MAXN];
int xx[10]={0,-1,1,0};
int yy[10]={-1,0,0,1};
void dfs(int x,int y){
	graph[x][y]='.';
	for(int i=0;i<=3;i++){
		if(x+xx[i]<1||x+xx[i]>r||y+yy[i]<1||y+yy[i]>c) continue;
		if(graph[x+xx[i]][y+yy[i]]=='.') continue;
		dfs(x+xx[i],y+yy[i]);
	}
}
bool judge(int x,int y){
	int count=0;
    if(graph[x][y]=='#') count++;
    if(graph[x+1][y]=='#') count++;
    if(graph[x][y+1]=='#') count++;
    if(graph[x+1][y+1]=='#') count++;
    if(count==3) return false;
    return true;
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=r-1;i++){
		for(int j=1;j<=c-1;j++){
			if(judge(i,j)==false){
				printf("Bad placement.\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(graph[i][j]=='#'){
				dfs(i,j),ans++;
			}
		}
	}
	printf("There are %d ships.",ans);
	return 0;
}