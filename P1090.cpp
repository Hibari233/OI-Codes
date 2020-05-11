#include<iostream>
#include<functional>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,ans,tmp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&tmp);q.push(tmp);}
	while(q.size()!=1){
		int a=q.top();q.pop();
		int b=q.top();q.pop();
		q.push(a+b);
		ans+=(a+b);
	}
	printf("%d\n",ans);
	return 0;
}