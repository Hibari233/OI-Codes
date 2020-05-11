#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> num;
const int MAXN=1005;
int T,ans;
int main(){
    cin>>T;
    for(int p=1;p<=T;p++){
        ans=0;
        num.clear();
        int n;
        cin>>n;
        int total=n;
        for(int i=1;i<=n;i++){
            int tmp;
            cin>>tmp;
            num.push_back(tmp);
        }
        while(total!=0){
            if(total==3){
                int a,b,c;
                a=num.front();
                num.pop_front();
                b=num.front();
                num.pop_front();
                c=num.front();
                num.pop_front();
                ans+=(b+c+a);
                total-=3;
            }
            else if(total==2){
                int a,b;
                a=num.front();
                num.pop_front();
                b=num.front();
                num.pop_front();
                ans+=b;
                total-=2;
            }
            else if(total==1){
                int a;
                a=num.front();
                num.pop_front();
                ans+=a;
                total--;
                break;
            }
            else{
                int a,b,c,d,ass[3];
                a=num.front();
                num.pop_front();
                b=num.front();
                num.push_front(a);
                d=num.back();
                num.pop_back();
                c=num.back();
                num.pop_back();
                ass[1]=c+d+2*a;
                ass[2]=2*b+d+a;
                ans+=min(ass[1],ass[2]);
                total-=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}