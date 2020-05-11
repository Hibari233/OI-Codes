#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const long long MAXN=100050;
long long base[MAXN];
long long n;
long long m,p1,s1,s2;
long long pl=0,pr=0;
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>base[i];
    }
    cin>>m>>p1>>s1>>s2;
    base[p1]+=s1;
    for(long long i=1;i<=m-1;i++){
        pl+=base[i]*(m-i); 
    }
    for(long long i=m+1;i<=n;i++){
        pr+=base[i]*(i-m);
    }
    if(pl>pr){
        long long val=pl-pr;
        long long ans=0;
        for(long long i=m+1;i<=n;i++){
            long long cur_ans=0;
            cur_ans=pr+s2*(i-m);
            if(abs(pl-cur_ans)<val){
                val=abs(pl-cur_ans);
                ans=i;
            }
        }
        if(ans==0){
            cout<<m<<endl;
            return 0;
        }
        cout<<ans<<endl;
        return 0;
    }
    else if(pl<pr){
        long long val=pr-pl;
        long long ans=0;
        for(long long i=1;i<=m-1;i++){
            long long cur_ans=0;
            cur_ans=pl+s2*(m-i);
            if(abs(cur_ans-pr)<val){
                val=abs(pr-cur_ans);
                ans=i;
            }
        }
        if(ans==0){
            cout<<m<<endl;
            return 0;
        }
        cout<<ans<<endl;
        return 0;
    }
    else{
        cout<<m<<endl;
        return 0;
    }
}