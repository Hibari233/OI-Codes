#include<iostream>
#include<string>
using namespace std;
string box;
int main(){
    while(cin>>box){
        int right=0,left=0;
        for(int i=0;i<box.length();i++){
            if(box[i]=='(') right++;
            if(box[i]==')') left++;
            if(box[i]=='B'){
               int ans;
               ans=right-left;
               cout<<ans<<endl;
               break;
            }
        }
    }
}