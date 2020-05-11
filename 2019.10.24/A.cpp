#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
const int MAXN=205;
int n,na,nb,a,b,score_a=0,score_b=0;
int rules[20][20];
queue<int> order_a;
queue<int> order_b;
void init(){
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++)
            rules[i][j]=-1;
    }
    rules[0][0]=rules[1][1]=rules[2][2]=rules[3][3]=rules[4][4]=0;
    rules[1][0]=rules[2][1]=rules[3][2]=rules[4][0]=rules[4][1]=rules[0][2]=rules[0][3]=rules[1][3]=rules[2][4]=rules[3][4]=1;
    rules[2][0]=rules[3][0]=rules[3][1]=rules[4][2]=rules[4][3]=rules[0][1]=rules[0][4]=rules[1][2]=rules[1][4]=rules[2][3]=2;
	//from a to b //rules[a][b]
	//rules=0 round draw
	//rules=1 round win
	//rules=2 round lose
}
int main(){
	init();
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=1;i<=na;i++) {scanf("%d",&a),order_a.push(a);}
	for(int i=1;i<=nb;i++) {scanf("%d",&b),order_b.push(b);}
	for(int i=1;i<=n;i++){
		int cur_a=order_a.front(),cur_b=order_b.front();
		order_a.pop();order_b.pop();
		order_a.push(cur_a),order_b.push(cur_b);
		if(rules[cur_a][cur_b]==1){
			score_a++;
		}
		if(rules[cur_a][cur_b]==2){
			score_b++;
		}
	}
	printf("%d %d\n",score_a,score_b);
	return 0;
}