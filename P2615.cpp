#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=45;
int num[MAXN][MAXN];
int main(){
    int n;
    cin>>n;
    num[1][n/2+1]=1;
    int last_i=1,last_j=n/2+1;
    int mark=0;
    for(int i=2;i<=n*n;i++){
        if(last_i==1&&last_j!=n){
            num[n][last_j+1]=i;
            last_i=n,last_j=last_j+1;
        }
        else if(last_j==n&&last_i!=1){
            num[last_i-1][1]=i;
            last_i=last_i-1,last_j=1;
        }
        else if(last_i==1&&last_j==n){
            num[last_i+1][last_j]=i;
            last_i=last_i+1,last_j=last_j;
        }
        else if(last_i!=1&&last_j!=n){
            if(num[last_i-1][last_j+1]==0){
                num[last_i-1][last_j+1]=i;
                last_i=last_i-1,last_j=last_j+1;
            }
            else{
                num[last_i+1][last_j]=i;
                last_i=last_i+1,last_j=last_j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}