#include<iostream>
#include<string>
using namespace std;
string a;
int count=0;
int main(){
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]=='(') count++;
        if(a[i]==')') count--;
        if(count<0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(count!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(count==0){
        cout<<"YES"<<endl;
        return 0;
    }
}