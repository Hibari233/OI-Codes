#include<iostream>
#include<string>
using namespace std;
const int MAXN=100005;
int num_A[MAXN],num_B[MAXN];
string ans_l;
int main(){
    //freopen("deviation.in","r",stdin);
    //freopen("deviation.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int p=1;p<=T;p++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>num_A[i];
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>num_B[i];
        int value;
        bool judge=true;
        bool first=false;
        int ans_l;
        int ans_k=0;
        int min_k=0x3f3f3f3f;
        int ans_r=0;
        for(int a=1;a<=n-m;a++){
            judge=true;
            value=num_B[1]-num_A[a];
            for(int i=2;i<=m;i++){
                if(num_B[i]!=num_A[i+a-1]){
                    judge=false;
                    break;
                }
            }
            if(judge==true){
                if(value<=min_k){
                    min_k=value;
                }
                ans_k++;
                if(first==false){
                    ans_l=num_B[a];
                }
                ans_r=num_B[a];
                first=true;
            }
        }
        cout<<ans_k<<" "<<min_k<<" "<<ans_k<<" "<<ans_l<<" "<<ans_r<<endl;
    }
}
/*
    5
    2 3 3 3 3
    2
    6 7

 */