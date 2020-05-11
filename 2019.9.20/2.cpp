#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1005;
int n,m,ans=0;
int main(){
    scanf("%d%d",&n,&m);
    if(n==2) 
    n++,m++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int a=1;a<=n;a++){
                for(int b=1;b<=m;b++){
                    for(int o=1;o<=n;o++){
                        for(int p=1;p<=m;p++){
                            if(i==a&&i==b) continue;
                            if(i==o&&i==p) continue;
                            if(a==o&&b==p) continue;
                            if(i==a&&a==o) continue;
                            if(j==b&&b==p) continue;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}