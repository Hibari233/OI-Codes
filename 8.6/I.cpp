#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=160000;
int s[MAXN];//1~n==A;n+1~2n+1==B;2n+1~3n+1==C; A eat B ; B eat C; C eat A;
int fake=0;
void init(int n){
    for(int i=1;i<=3*n;i++)
        s[i]=i;
}
int find(int p){
    if(p==s[p]) return p;
    return s[p]=find(s[p]);
}
void uni(int p,int q){
    int fp=find(p),fq=find(q);
    s[fp]=fq;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    init(n);
    for(int i=1;i<=k;i++){
        int d,x,y;
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n){
            fake++;
            continue;
        }
        if(d==1){
            if(find(x+n)==find(y)||find(y)==find(x+2*n)){
                fake++;
            }
            else{
                uni(x,y);
                uni(x+n,y+n);
                uni(x+2*n,y+2*n);
            }
        }
        else{
            if(x==y||find(x)==find(y)||find(x+2*n)==find(y)){
                fake++;
            }
            else{
                uni(x,y+2*n);
                uni(x+n,y);
                uni(x+2*n,y+n);
            }
        }
    }
    cout<<fake<<endl;
    return 0;
}