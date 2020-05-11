#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100050;
int n,k,ans=0;
int s[MAXN];
priority_queue<int> q;
queue<int> qq;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]),q.push(s[i]);
	while(1){
		for(int i=1;i<=k;i++){
			int temp=q.top();
			temp--;
			q.pop();
			if(temp==0) continue;
			qq.push(temp);
		}
		while(qq.size()){
			q.push(qq.front());
			qq.pop();
		}
		ans++;
		if(q.size()<k) break;
	}
	printf("%d\n",ans);
	return 0;
}
/*
两种情况
当最小堆数量大于k堆时：
那么每次选择时都会选到一个最小堆，使其变为一个更小堆
我们可以选择剩下的k堆
5 3
1 2 3 4 9
1 2 2 3 8
1 2 1 2 7
1 1 1 1 6
1 1 0 0 5
0 0 0 0 4
5 3
2 2 2 5 5 
2 2 1 4 4
2 1 1 3 4
1 1 1 2 3
1 1 0 1 2
1 0 0 0 1
*/