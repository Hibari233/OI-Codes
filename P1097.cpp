#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int num[200050];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++){
		//printf("%d\n",i);
		int count=1;
		for(int j=i+1;j<=n+2;j++){
			if(num[i]==num[j]){
				count++;
			}
			else{
				cout<<num[i]<<" "<<count<<endl;
				i=i+count-1;
				break;
			}
		}
	}
	return 0;
}
// 2 2 2 4 4 5 100 100