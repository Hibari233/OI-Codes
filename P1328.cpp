#include<iostream>
using namespace std;
const int MAXN=250;
int cycle_A[MAXN],cycle_B[MAXN],score_A,score_B;
int pos_A,pos_B;
int rules[10][10];
void init(){
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++)
            rules[i][j]=-1;
    }
    rules[0][0]=rules[1][1]=rules[2][2]=rules[3][3]=rules[4][4]=0;
    rules[1][0]=rules[2][1]=rules[3][2]=rules[4][0]=rules[4][1]=1;
    rules[2][0]=rules[3][0]=rules[3][1]=rules[4][2]=rules[4][3]=2;
}
int main(){
    init();
    int n,na,nb;
    cin>>n>>na>>nb;
    for(int i=1;i<=na;i++){
        cin>>cycle_A[i];
    }
    for(int j=1;j<=nb;j++){
        cin>>cycle_B[j];
    }
    pos_A=pos_B=1;
    for(int i=1;i<=n;i++){
        int num_A=cycle_A[pos_A];
        int num_B=cycle_B[pos_B];
        bool swaped=false;
        if(rules[num_B][num_A]==-1){
            swap(num_A,num_B);
            swaped=true;
        }
        if(rules[num_B][num_A]==2){
            if(swaped==false)
                score_A++;
            if(swaped==true)
                score_B++;
        }
        if(rules[num_B][num_A]==1){
            if(swaped==false)
                score_B++;
            if(swaped==true)
                score_A++;
        }
        pos_A++;
        pos_B++;
        if(pos_A>na){
            pos_A=1;
        }
        if(pos_B>nb){
            pos_B=1;
        }
    }
    cout<<score_A<<" "<<score_B<<endl;
    return 0;
}