#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100;
int num;
int cnt=0;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        cnt=0;
        scanf("%d",&n);
	    for(int i=1;i<=n;i++) {scanf("%d",&num);if(num==1) cnt++;}
        if(cnt%2==1) printf("rabbit\n");
        else printf("hamster\n");
    }
    return 0;
}