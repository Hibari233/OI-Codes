#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int ans;
int main(){
    while(cin>>s){
        ans+=s.length();
    }
    cout<<ans<<endl;
    return 0;
}