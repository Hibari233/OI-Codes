#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN=100;
map<string,string> mp; 
char now[MAXN];
char x[MAXN],y[MAXN];
string a;
int main(){
    while(gets(now)){
        if(now[0]=='\n') break;
        memcpy(now,x,strlen(now));
        scanf("%s",&y);
        mp[y]=x;
    }
    while(cin>>a){
        if(mp[a].size()!=0)
            cout<<mp[a]<<endl;
        else
            cout<<"eh"<<endl;
    }
    return 0;
}