#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=105;
int T,n;
stack<int> cir;
struct st{
    char val;
    int from,to;
    bool can;
}dat[MAXN];
string source[MAXN],time1;
void read(){
    scanf("%d ",&n);
    getline(cin,source[0]);
    for(int i=1;i<=n;i++) getline(cin,source[i]);
}
void get1(){
    int pos=0;
    for(int i=0;i<source[0].size();i++){
        if(source[0][i]=='('){
            for(int j=i+1;j<source[0].size();j++){
                if(source[0][j]==')') break;
                swap(time1[++pos],source[0][j]);
            }
        }
        break;
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        read();
        cout<<source[0][2]<<endl;
        cout<<time1<<endl;
    }
}
/*
1
2 O(1)
F i 1 1
E
*/