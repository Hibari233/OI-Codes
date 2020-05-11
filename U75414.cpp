#include<iostream>
#include<map>
using namespace std;
map<int,int> num;
int main(){
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a;
        scanf("%d",&a);
        int x,y;
        if(a==1){scanf("%d%d",&x,&y);num[x]=y;}
        else{scanf("%d",&x);printf("%d\n",num[x]);}
    }
    return 0;
}