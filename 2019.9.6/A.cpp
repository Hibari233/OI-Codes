#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a;
int count[30];
int main(){
    int res=-1;
    int n;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        memset(count,0,sizeof(count));
        for(int j=i+1;j<n;j++){
            int maxx=-1,minn=0x3f3f3f3f;
            count[a[j]-'a']++;
            for(int p=0;p<26;p++){
                if(count[p]==0) continue;
                maxx=max(maxx,count[p]);
                minn=min(minn,count[p]);
            }
            int ans=maxx-minn;
            if(ans>res) res=ans;
        }
    }
    cout<<res<<endl;
    return 0;
}