#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a;
int main(){
    int n,k;
    while(cin>>n>>k){
        cin>>a;
        int count=0;
        for(int j=0;j<a.length();){
            if(count==k) break;
            if(a[j]=='2'&&a[j+1]=='3'){
                int pos=j+1;
                if(pos%2==1){
                    a[j+1]='2';
                    count++;
                    continue;
                }
                else{
                    a[j]='3';
                    count++;
                    j--;
                    continue;
                }
            }
            j++;
        }
        cout<<a<<endl;
    }
    return 0;
}