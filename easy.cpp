#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const double eps=0.000005;
const int MAXN=100020;
long long num[MAXN];
bool pow_(long long w){
    for(int i=2;i*i<w;i++){
        double ck=log(w)/log(i);
        //cout<<ck<<" "<<ceil(ck)<<endl;
        if(ceil(ck)>ck-eps&&ceil(ck)<ck+eps){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    long long N,ans=0;
    cin>>N;
    for(long long i=1;i<=N;i++){
        cin>>num[i];
    }
    for(long long i=1;i<=N;i++){
        if(pow_(num[i])==true)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}