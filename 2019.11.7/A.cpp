#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=110,M=20;
int n,m,P;
string name[N];
pair<int,string> sentence[N];
string weekday[7]={
	"Today is Monday.",
	"Today is Tuesday.",
	"Today is Wednesday.",
	"Today is Thursday.",
	"Today is Friday.",
	"Today is Saturday.",
	"Today is Sunday."
};
int state[N];
int get_id(string str){
	for(int i=0;i<m;i++)
		if(str==name[i])
			return i;
	return -1;
}
int judge(int day,int badman,int now,string str){
	if(str=="I am guilty.") return badman!=now;
	if(str=="I am not guilty.") return badman==now;
	for(int i=0;i<m;i++)
		if(name[i]+" is guilty."==str)
			return i!=badman;
	for(int i=0;i<m;i++)
		if(name[i]+" is not guilty."==str)
			return i==badman;
	for(int i=0;i<7;i++)
		if(weekday[i]==str)
			return day!=i;
	return -1;
}
bool check(int day,int badman){
	memset(state,-1,sizeof state);
	for(int i=0;i<P;i++){
		pair<int,string> sen=sentence[i];
		int t=judge(day,badman,sen.first,sen.second);
		int p=sen.first;
		if(t==0){
			if(state[p]==-1) state[p]=0;
			else if(state[p]==1) return false;
		}
		else if(t==1){
			if(state[p]==-1) state[p]=1;
			else if(state[p]==0) return false;
		}
	}
	int fake=0,other=0;
	for(int i=0;i<m;i++){
		if(state[i]==1) fake++;
		else if(state[i]==-1) other++;
	}
	return fake<=n&&n<=fake+other;
}
int main(){
	scanf("%d%d%d",&m,&n,&P);
	for(int i=0;i<m;i++) cin>>name[i];
	for(int i=0;i<P;i++){
		string first,second;
		cin>>first;
		first.erase(first.end()-1);
		getline(cin,second);
		second.erase(second.begin());
		sentence[i]=make_pair(get_id(first),second); 
	}
	int cnt,p=-1;
	for(int day=0;day<7;day++){
		cnt=0;
		for(int i=0;i<m;i++){
			if(check(day,i)){
				cnt++;
				p=i;
			}
		}
		if(cnt>1){
			puts("Cannot Determine");
			break;
		}
	}
	if(cnt<=1){
		if(p==-1) puts("Impossible");
		else cout<<name[p]<<endl;
	}
}