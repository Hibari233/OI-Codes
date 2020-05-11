#include<iostream>
using namespace std;
int n,m,squ=0,rec=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=i;x<=n;x++){
                for(int y=j;y<=m;y++){
                    if(i==x&&j==y) continue;
                    int l=y-j;
                    int w=x-i;
                    if(l==w) squ++;
                    else rec++;
                }
            }
        }
    }
    squ+=n*m;
    printf("%d %d\n",squ,rec);
    return 0;
}