#include<iostream>
using namespace std;
const int MAXN=100000;
int missile[MAXN];
int f1[MAXN],f2[MAXN];
int max1=-1,max2=-1;
int main(){
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int p=1;
    while(cin>>missile[p]){
        p++;
    }
    p--;
    for(int i=1;i<=p;i++){
        f1[i]=1;f2[i]=1;
    }
    for(int i=2;i<=p;i++){
        for(int j=1;j<i;j++){
            if(missile[j]<missile[i]){
                f1[i]=max(f1[i],f1[j]+1);
            }
            if(missile[j]>=missile[i]){
                f2[i]=max(f2[i],f2[j]+1);
            }
        }
        max1=max(max1,f1[i]);
        max2=max(max2,f2[i]);
    }
    cout<<max2<<endl;
    cout<<max1<<endl;
    return 0;
}