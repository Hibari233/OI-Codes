#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=400050;
long long n,m,q;
long long a[MAXN];
long long sum,ans;
bool cmp(int x,int y){
	return x>y;
}
priority_queue<long long> qq;
queue<long long> res;
int main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	if(m==1){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		ans=sum/m;
		if(ans*m==sum) printf("%lld\n",ans);
		else printf("%lld\n",ans+1);
		for(int i=1;i<=q;i++){
			int p,c;
			scanf("%d%d",&p,&c);
			int cur=c-a[p];
			a[p]=c;
			sum+=cur;
			ans=sum/m;
			if(ans*m==sum) printf("%lld\n",ans);
			else printf("%lld\n",ans+1);
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) if(a[i]!=0) qq.push(a[i]);
		while(qq.size()){
			for(int i=1;i<=m;i++){
				long long val=qq.top();
				res.push(val);
				qq.pop();
				if(qq.size()==0&&res.size()!=0) break;
			}
			while(res.size()){
				long long val=res.front();
				val--;
				if(val>0) {qq.push(val);res.pop();}
				else res.pop();
			}
			ans++;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=q;i++){
			long long p,c;
			ans=0;
			scanf("%lld%lld",&p,&c);
			a[p]=c;
			for(int i=1;i<=n;i++) if(a[i]!=0) qq.push(a[i]);
				while(qq.size()){
				for(int i=1;i<=m;i++){
					long long val=qq.top();
					res.push(val);
					qq.pop();
					if(qq.size()==0&&res.size()!=0) break;
				}
				while(res.size()){
					long long val=res.front();
					val--;
					if(val>0) {qq.push(val);res.pop();}
					else res.pop();
				}
				ans++;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}