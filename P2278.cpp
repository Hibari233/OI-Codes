#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=30000;
struct st{
	int id,st,t,h;
}task;
long long time_total;
bool operator < (const st &x,const st &y){
	if(x.h==y.h) return x.st>y.st;
	else return x.h<y.h;
}
priority_queue<st> q;
int main(){
	while(scanf("%d%d%d%d",&task.id,&task.st,&task.t,&task.h)!=EOF){
		while(!q.empty()&&time_total+q.top().t<=task.st){
			st cur=q.top();
			q.pop();
			printf("%d %lld\n",cur.id,time_total+cur.t);
			time_total+=cur.t;
		}
		if(!q.empty()){
			st cur=q.top();
			q.pop();
			cur.t=cur.t-task.st+time_total;
			q.push(cur);
		}
		q.push(task);
		time_total=task.st;
	}
	while(!q.empty()){
		st ans=q.top();
		q.pop();
		time_total+=ans.t;
		printf("%d %lld\n",ans.id,time_total);
	}
	return 0;
}