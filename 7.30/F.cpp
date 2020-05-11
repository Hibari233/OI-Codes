#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000;
string num;
int sorted_num[MAXN];
int times=1;
int cnt=0;
int main(){
    while(cin>>num){
        num[num.length()]='5';
        cnt=0;
        memset(sorted_num,0,sizeof(sorted_num));
        for(int i=0;i<=num.length();i++){
            if(num[i]=='5'){
                times=1;
                for(int j=i-1;j>=0&&num[j]!='5';j--){
                    sorted_num[cnt]+=(num[j]-'0')*times;
                    times*=10;
                }
                if(num[i]=='5'&&num[i-1]=='5')
                    cnt--;
                if(num[i]=='5'&&i==1)
                    cnt--;
                cnt++;
            }
        }
        sort(sorted_num,sorted_num+cnt);
        for(int i=0;i<cnt;i++){
            cout<<sorted_num[i];
            if(i<cnt-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}