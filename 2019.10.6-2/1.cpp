#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n;
int r,c;
int pos[50];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		char j1,j2;
		cin>>j1;
		if(j1=='R') scanf("%d",&r);
		else scanf("%d",&c);
		cin>>j2;
		if(j2=='R') scanf("%d",&r);
		else scanf("%d",&c);
		if(c<1||c>m||r<1||r>m){
			printf("-1\n");
			continue;
		}
		int cc=c,p=1,mod=26;
		printf("%d ",r);
		int num=0;
		while(cc!=0){
			int a=cc%mod;
			cc=cc/26;
			pos[p]=a;
			p++;
			num++;
		}
		for(int j=1;j<=num;j++){
			if(pos[j]==0) putchar('Z');
			else printf("%c",(char)(pos[j]-1+'A'));
		}
		printf("\n");
	}
	return 0;
}