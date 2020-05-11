#include<iostream>
#include<string>
using namespace std;
string ufo;
string team;
int main(){
    long long ufo_num=0,team_num=0;
    cin>>ufo;
    cin>>team;
    ufo_num=ufo[0]-'A'+1;
    team_num=team[0]-'A'+1;
    for(int i=1;i<ufo.length();i++){
        ufo_num*=(ufo[i]-'A'+1);
    }
    for(int i=1;i<team.length();i++){
        team_num*=(team[i]-'A'+1);
    }
    ufo_num=ufo_num%47;
    team_num=team_num%47;
    if(ufo_num==team_num){
        cout<<"GO"<<endl;
    }
    else{
        cout<<"STAY"<<endl;
    }
    return 0;
}