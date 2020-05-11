#include<iostream>
using namespace std;
const int MAXN=1000;
int s[MAXN];
int num[MAXN]={0};
inline void init(int n){
    for(int i=1;i<=n;i++)
        s[i]=i;
}
inline int find(int p){
    return s[p]=p==s[p]?p:find(s[p]);
}
inline void uni(int p,int q){
    int fp=find(p),fq=find(q);
    s[fp]=s[fq];
    }
int main(){
	int n,m;
	while(cin>>n){
		if(n==0) break;
		cin>>m;
		init(n);
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			uni(x,y);
			num[x]++;
			num[y]++;
		}
		int fa=find(1);
		bool judge=false;
		for(int i=2;i<=n;i++){
			if(fa!=find(i)){
				cout<<0<<endl;
				judge=true;
				break;
			}
		}
		if(judge==true) continue;
		for(int i=1;i<=n;i++){
			if(num[i]%2!=0){
				cout<<0<<endl;
				judge=true;
				break;
			}
		}
		if(judge==true) continue;
		cout<<1<<endl;
	}
}