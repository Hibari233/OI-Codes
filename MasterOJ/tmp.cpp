#include<bits/stdc++.h>
using namespace std;
int main()
{
	deque<int>q;
	string s;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='0')
		{
			q.clear();
		}
		else if(s[i]=='1')
		{
			q.push_front(1);
		}
		else if(s[i]=='2')
		{
			q.push_back(2);
		}
		else if(s[i]=='3')
		{
			if(q.empty()) cout<<-1<<endl;
			else cout<<q.front()<<endl;
			q.push_back(3);
		}
		else if(s[i]=='4')
		{
			if(q.empty()) cout<<0<<endl;
			else cout<<q.back()<<endl;
			q.push_front(4);
		}
		else if(s[i]=='5')
		{
			if(q.empty()) cout<<"anyh"<<endl;
			else if(q.size()==1) cout<<"aaa"<<endl;
			else cout<<q.back()+q.front()<<endl;
			q.push_back(5);
		}
		else if(s[i]=='6')
		{
			if(q.empty()) cout<<"acyk"<<endl;
			else if(q.size()==1) cout<<"aaa"<<endl;
			else cout<<max(q.back()+q.front(),-(q.back()+q.front()))<<endl;
			q.push_front(6);
		}
		else if(s[i]=='7')
		{
			int total=1;
			for(auto it=q.begin();it!=q.end();it++,total++)
			{
				if(*it==7){
					cout<<total<<endl;
					break;
				}
			}
			q.push_front(7);
		}
		else if(s[i]=='8')
		{
			q.push_front(8);
			q.push_back(8);
		}
		else if(s[i]=='9')
		{
			reverse(q.begin(),q.end());
		}
	}
	if(q.size()==0) cout << "empty" << endl;
	else cout << q.size() << endl;
	return 0;
}