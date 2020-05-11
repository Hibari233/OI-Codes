#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300000;
int num[MAXN];
int chafen[MAXN];
int main(){
	ios::sync_with_stdio(false);
    int n,k;
	cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i],chafen[i]=num[i]-num[i-1];
    sort(chafen+2,chafen+n+1);
	int sum=0;
	for(int i=2;i<=n-k+1;i++){
		sum+=chafen[i];
	}
	cout<<sum<<endl;
	return 0;
}