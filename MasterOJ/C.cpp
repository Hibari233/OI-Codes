#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
string x;
deque<int> q;
int main(){
	cin >> x;
	for(int i=x.length()-1;i>=0;i--){
		if(x[i]=='0') q.clear();
		else if(x[i]=='1') q.push_front(1);
		else if(x[i]=='2') q.push_back(2);
		else if(x[i]=='3'){
			if(q.size()==0) printf("-1\n");
			else cout << q.front() << endl;
			q.push_back(3);
		}
		else if(x[i]=='4'){
			if(q.size()==0) printf("0\n");
			else cout << q.back() << endl;
			q.push_front(4);
		}
		else if(x[i]=='5'){
			if(q.size()==0) printf("anyh\n");
			else if(q.size()==1) cout<<"aaa"<<endl;
			else cout<< q.front() + q.back() << endl;
			q.push_back(5);
		}
		else if(x[i]=='6'){
			if(q.size()==0) printf("acyk\n");
			else if(q.size()==1) cout<<"aaa"<<endl;
			else cout<< abs(q.front() - q.back()) << endl;
			q.push_front(6);
		}
		else if(x[i]=='7'){
			deque<int>::iterator it;
			int count=1;
			bool mark=false;
			if(mark==false) printf("No\n");
			q.push_front(7);
		}
		else if(x[i]=='8'){
			q.push_front(8);
			q.push_back(8);
		}
		else if(x[i]=='9'){
			reverse(q.begin(),q.end());
		}
	}
	if(q.size()==0) cout << "empty" << endl;
	else cout << q.size() << endl;
	return 0;
}