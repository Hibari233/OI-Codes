#include<iostream>
#include<bits/stdc++.h>
#include<deque>
using namespace std;
const int MAXN=10010;
int n;
unsigned long long a[MAXN];
deque<char> s;
int base=233;
int ans=1;
unsigned long long mod=2123704401301379571;
unsigned long long hashe_normal(deque<char> s){
    
    unsigned long long ans=0;
    for(int i=0;i<6;i++){
        int s_now=s.front();
        s.pop_front();
        ans=(ans*base+(unsigned long long)s_now)%mod;
        //cout<<s_now-'0'<<" ";
    }
    cout<<endl;
    return ans;
}
unsigned long long hashe_reverse(deque<char> s){
    unsigned long long ans=0;
    for(int i=0;i<6;i++){
        int s_now=s.back();
        s.pop_back();
        ans=(ans*base+(unsigned long long)s_now)%mod;
        //cout<<s_now-'0'<<" ";
    }
    cout<<endl;
    return ans;
}
int main(){
    int h=0;
    cin>>n;
    for(int j=0;j<n;j++){
        for(int i=0;i<6;i++){
            char tmp;
            cin>>tmp;
            s.push_back(tmp);
        }
        if(s.front()=='1'&&s.back()=='6'){
            a[h]=hashe_normal(s);
            h++;
        }
        else if(s.front()>s.back()){
            while(s.back()!='6'){
                char back=s.back();
                s.pop_back();
                s.push_front(back);
            }
            a[h]=hashe_normal(s);
            h++;
        }
        else if(s.front()<s.back()){
            while(s.back()!='1'){
                char back=s.back();
                s.pop_back();
                s.push_front(back);
            }
            for(int i=1;i<6;i++){
                char tmp=s.back();
                s.pop_back();
                cout<<tmp<<" ";
            }
            cout<<endl;
            a[h]=hashe_reverse(s);
            h++;
        }
        else if(s.front()==s.back()){
            break;
        }
    }
    
    //cout<<a[0]<<endl;
    //cout<<a[1]<<endl;
    sort(a,a+n);
    for(int i=1;i<n-1;i++){
        if(a[i]==a[i-1]){
            cout<<"Twin snowflakes found."<<endl;
        }
    }
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}