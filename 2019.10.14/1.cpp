#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200050;
int n,m;
struct st{
	int num,front,back,price;
}clo[MAXN];
int like[MAXN],ans[MAXN]={0};
bool mark[MAXN];
priority_queue<st> color1;
priority_queue<st> color2;
priority_queue<st> color3;
bool operator < (const st &x,const st &y){
	return x.price>y.price;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) clo[i].num=i;
	for(int i=1;i<=n;i++) scanf("%d",&clo[i].price);
	for(int i=1;i<=n;i++) scanf("%d",&clo[i].front);
	for(int i=1;i<=n;i++) scanf("%d",&clo[i].back);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&like[i]);
	for(int i=1;i<=n;i++){
		if(clo[i].front==1) color1.push(clo[i]);
		if(clo[i].front==2) color2.push(clo[i]);
		if(clo[i].front==3) color3.push(clo[i]);
		if(clo[i].back==1) color1.push(clo[i]);
		if(clo[i].back==2) color2.push(clo[i]);
		if(clo[i].back==3) color3.push(clo[i]);
	}
	for(int i=1;i<=m;i++){
		if(like[i]==1){
			int size=color1.size();
			if(size<=0) {ans[i]=-1;continue;}
			st tmp=color1.top();
			while(mark[tmp.num]==true){
				color1.pop();
				size=color1.size();
				if(size<=0) break;
				tmp=color1.top();
			}
			if(size<=0) {ans[i]=-1;continue;}
			ans[i]=tmp.price;
			mark[tmp.num]=true;
			color1.pop();
		}
		if(like[i]==2){
			int size=color2.size();
			if(size<=0) {ans[i]=-1;continue;}
			st tmp=color2.top();
			while(mark[tmp.num]==true){
				color2.pop();
				size=color2.size();
				if(size<=0) break;
				tmp=color2.top();
			}
			if(size<=0) {ans[i]=-1;continue;}
			ans[i]=tmp.price;
			mark[tmp.num]=true;
			color2.pop();
		}
		if(like[i]==3){
			int size=color3.size();
			if(size<=0) {ans[i]=-1;continue;}
			st tmp=color3.top();
			while(mark[tmp.num]==true){
				color3.pop();
				size=color3.size();
				if(size<=0) break;
				tmp=color3.top();
			}
			if(size<=0) {ans[i]=-1;continue;}
			ans[i]=tmp.price;
			mark[tmp.num]=true;
			color3.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
		if(i!=m) printf(" ");
		else printf("\n");
	}
	return 0;
}