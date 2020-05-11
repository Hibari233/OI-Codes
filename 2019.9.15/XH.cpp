#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int num(int x){
    int count=0;
    while(x!=0){
        x=x/10;
        count++;
    }
    return count;
}
bool judge(int n){
    int ll=num(n);
    if(ll==2){
        int first=n/10;
        int second=n%10;
        if(abs(second-first)==7) return true;
        else return false;
    }
    if(ll=3){
        int first=n/100;
        int second=n/10-first*10;
        int third=n%10;
        int ff=abs(first-second);
        int ss=abs(second-third);
        int ans=abs(ff-ss);
        if(ans==7) return true;
        else return false;
    }
    if(ll==4){
        int first=n/1000;
        int second=n/100-first*100;
        int third=n/10-second*10;
        int Zhengfourth=n%10;
        int ff,ss,tt;
        ff=abs(first-second);
        ss=abs(second-third);
        tt=abs(third-Zhengfourth);
        int fff,sss;
        fff=abs(ss-ff);
        sss=abs(tt-ss);
        int ans;
        ans=abs(fff-sss);
        if(ans==7) return true;
        else{
            return false;
        }
    }
    if(ll==5){
        int first=n/10000;
        int second=n/1000-first*1000;
        int third=n/100-second*100;
        int Zhengfourth=n/10-third*10;
        int fif=n%10;
        int ff,ss,tt,ZZ;
        ff=abs(second-first);
        ss=abs(third-second);
        tt=abs(Zhengfourth-third);
        ZZ=abs(fif-Zhengfourth);
        int fff,sss,ttt;
        fff=abs(ss-ff);
        sss=abs(tt-ss);
        ttt=abs(ZZ-tt);
        int ffff,ssss;
        ffff=abs(fff-sss);
        ssss=abs(ttt-sss);
        int ans;
        ans=abs(ffff-ssss);
        if(ans==7) return true;
        else return false;
    }
}
int main(){
    int l,r,res=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(judge(i)==true) res++;
    }
    cout<<res<<endl;
    return 0;
}