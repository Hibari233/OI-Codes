#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int T,k;
int cnt[30];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s;
		scanf("%d",&k);
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<s.length();i++){
			cnt[s[i]-'a']++;
		}
		sort(cnt,cnt+26,cmp);
		int ct=0;
		for(int i=0;i<26;i++){
			if(cnt[i]>1) ct+=cnt[i];
		}
		if(ct>k) puts("Uncertain");
		else puts("Certain");
	}
	return 0;
}
/*
aaabbbccc
4


*/