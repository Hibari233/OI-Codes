#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans=0;
int num[10005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(num[j]<num[i]){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}