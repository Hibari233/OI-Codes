#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
string a;
deque<int> q;
int main(){
    cin >> a;
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]=='0') q.clear();
        else if(a[i]=='1') q.push_front(1);
        else if(a[i]=='2') q.push_back(2);
        else if(a[i]=='3'){
            if(q.size()==0) printf("-1\n");
            else cout << q.front() << endl;
            q.push_back(3);
        }
        else if(a[i]=='4'){
            if(q.size()==0) printf("0\n");
            else cout << q.back() << endl;
            q.push_front(4);
        }
        else if(a[i]=='5'){
            if(q.size()==0) printf("anyh\n");
            else if(q.size()==1) printf("aaa\n");
            else cout << q.front() + q.back() << endl;
            q.push_back(5);
        }
        else if(a[i]=='6'){
            if(q.size()==0) printf("acyk\n");
            else if(q.size()==1) printf("aaa\n");
            else cout << abs(q.front() - q.back()) << endl;
            q.push_front(6);
        }
        else if(a[i]=='7'){
            bool mark=false;
            int cnt=1;
            deque<int>::iterator it;
            for(it=q.begin();it<q.end();it++,cnt++) if(*it==7) {printf("%d\n",cnt);mark=true;break;}
            if(mark==false) printf("No\n");
            q.push_front(7);
        }
        else if(a[i]=='8'){q.push_front(8);q.push_back(8);}
        else if(a[i]=='9') reverse(q.begin(),q.end());
    }
    if(q.size()) cout << q.size() << endl;
    else cout << "empty" << endl;
    return 0;
}