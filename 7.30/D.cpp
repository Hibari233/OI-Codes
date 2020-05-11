#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
const int MAXN=100000;
int num_train;
string order_in,order_out;
int cur_in[MAXN];
int cur_out=0;
int ans[MAXN];
int ans_cur=0;
int stack_top=0;
int main(){
    while(cin>>num_train>>order_in>>order_out){
        cur_out=0;
        ans_cur=0;
        memset(ans,0,sizeof(ans));
        memset(cur_in,0,sizeof(cur_in));
        for(int i=0;i<num_train;i++){
            cur_in[stack_top]=(order_in[i]-'0');
            stack_top++;
            ans[ans_cur]=1;
            ans_cur++;
            //cout<<cur_in[stack_top-1]<<endl;
            for(int j=0;j<num_train;j++){
                if(cur_in[stack_top-1]==(order_out[cur_out]-'0')){
                    ans[ans_cur]=2;
                    ans_cur++;
                    stack_top--;
                    cur_out++;
                }
            }
        }
        /*
        for(int i=0;i<num_train*2;i++)
            cout<<ans[i]<<" ";
        */
        //cout<<cur_out<<endl;
        if(cur_out==num_train){
            cout<<"Yes."<<endl;
            for(int i=0;i<num_train*2;i++){
                if(ans[i]==1)
                    cout<<"in"<<endl;
                if(ans[i]==2)
                    cout<<"out"<<endl;
            }
            cout<<"FINISH"<<endl;
        }
        if(cur_out!=num_train){
            cout<<"No."<<endl;
            cout<<"FINISH"<<endl;
        }
    }
    return 0;
}
//15432 12345