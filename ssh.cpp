#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> q;
int main(){
	int n,a[100];
	scanf("%d",&n);
	for(auto i=1;i<=n;i++) scanf("%d",&a[i]);
	for(auto i=1;i<=n;i++) q.push(a[i]);
	while(q.size()){
		scanf("%d",&n);
		if(n==1) q.pop();
		printf("%d",q.size());
	}
	return 0;
}