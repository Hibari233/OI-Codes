#include<iostream>
using namespace std;
const int MAXN=10005;
const int MAXMEM=100000000;
long long n,s;
long long c[MAXN],y[MAXN];
long long nc[MAXN];
long long ans=0;
long long now[MAXMEM];
long long memorize(long long i,long long j){
    if(now[i*17+j*13]!=0) return now[i*17+j*13];
    else return c[j]+(i-j)*s;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        long long bef=0x3f3f3f3f;
        for(int j=1;j<=i;j++){
            now[i*17+j*13]=memorize(i,j);
            bef=min(now[i*17+j*13],bef);
        }
        nc[i]=min(bef,c[i]);
    }
    for(int i=1;i<=n;i++){
        ans+=(y[i]*nc[i]);
    }
    cout<<ans<<endl;
    return 0;
}
