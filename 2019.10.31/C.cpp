#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100050;
int n,m,f;
int a[MAXN];
int ans=0;
int main(){
	scanf("%d%d%d",&n,&m,&f);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(f==1){
				if(ans==-1) l^=0,r^=0,x^=0;
				else l^=ans,r^=ans,x^=ans;
			}
			for(int j=l;j<=r;j++) a[j]=x;
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			if(f==1){
				if(ans==-1) x^=0,y^=0;
				else x^=ans,y^=ans;
			}
			int tmp=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(a[j]==x||a[j]==y){
					for(int k=j;k<=n;k++){
						if(a[j]==x&&a[k]==y){
							if(abs(k-j)<tmp) tmp=abs(k-j);
							break;
						}
						if(a[j]==y&&a[k]==x){
							if(abs(k-j)<tmp) tmp=abs(k-j);
							break;
						}
					}
				}
			}
			if(tmp==0x3f3f3f3f) ans=-1;
			else ans=tmp;
			printf("%d\n",ans);
		}
	}
}