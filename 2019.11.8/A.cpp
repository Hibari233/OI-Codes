#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=45;
int num[MAXN][MAXN];
int main(){
    int n;
    scanf("%d",&n);
    num[1][n/2+1]=1;
    int last_x=1,last_y=n/2+1;
    for(int i=2;i<=n*n;i++){
        if(last_x==1&&last_y!=n){num[n][last_y+1]=i;last_x=n,last_y=last_y+1;}
        else if(last_y==n&&last_x!=1){num[last_x-1][1]=i;last_x=last_x-1,last_y=1;}
        else if(last_x==1&&last_y==n){num[last_x+1][last_y]=i;last_x=last_x+1,last_y=last_y;}
        else if(last_x!=1&&last_y!=n){
            if(num[last_x-1][last_y+1]==0){num[last_x-1][last_y+1]=i;last_x=last_x-1,last_y=last_y+1;}
            else{num[last_x+1][last_y]=i;last_x=last_x+1,last_y=last_y;}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j!=n)
                printf("%d ",num[i][j]);
            else printf("%d",num[i][j]);
        }
            
        printf("\n");
    }
    return 0;
}