#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=105;
int n,maxx=-1,total=0,mark=0;
struct st{
	string name;
	int avg,cla,num;
	char lv,west;
	int total;
}stu[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>stu[i].name;
		scanf("%d%d",&stu[i].avg,&stu[i].cla);
		cin>>stu[i].lv>>stu[i].west;
		scanf("%d",&stu[i].num);
	}
	for(int i=1;i<=n;i++){
		if(stu[i].avg>80&&stu[i].num>=1) stu[i].total+=8000;
		if(stu[i].avg>85&&stu[i].cla>80) stu[i].total+=4000;
		if(stu[i].avg>90) stu[i].total+=2000;
		if(stu[i].avg>85&&stu[i].west=='Y') stu[i].total+=1000;
		if(stu[i].cla>80&&stu[i].lv=='Y') stu[i].total+=850;
	}
	for(int i=1;i<=n;i++){
		total+=stu[i].total;
		if(stu[i].total>maxx) maxx=stu[i].total,mark=i;
	}
	cout<<stu[mark].name<<endl;
	printf("%d\n%d\n",stu[mark].total,total);
	return 0;
}