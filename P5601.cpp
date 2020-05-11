#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int n,q;
string quest,ans;
map<string,string> mp;
string q_cur,ans_cur[10];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>quest>>ans;
		mp.insert({quest,ans});
	}
	for(int i=1;i<=q;i++){
		cin>>q_cur>>ans_cur[1]>>ans_cur[2]>>ans_cur[3]>>ans_cur[4];
		string tmp=mp.find(q_cur)->second;
		for(int i=1;i<=4;i++){
			if(tmp==ans_cur[i]){
				if(i==1) printf("A\n");
				if(i==2) printf("B\n");
				if(i==3) printf("C\n");
				if(i==4) printf("D\n");
			}
		}
	}
}