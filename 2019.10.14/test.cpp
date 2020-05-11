#include<iostream>
#include<queue>
using namespace std;
priority_queue<node> q;
struct node{
	int x;
}a[10000];
bool operator < (const node &x,const node &y){
	return x.x>y.x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		node tmp;
		cin>>tmp.x;
		q.push(tmp);
	}
	for(int i=1;i<=n;i++){
		node tmp;
		tmp=q.top();
		cout<<tmp.x<<endl;
		q.pop();
	}
	return 0;
}