#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5000;
int graph[MAXN][MAXN];
bool book[MAXN];
int n,k,t,ans=0;
struct node{
    int total;
    int num;
}edge[MAXN];
inline int minn(int x,int y){
    return x<y?x:y;
}
bool operator < (const node &x,const node &y){
    return x.total>y.total;
}
void floyd(){
for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(graph[i][j]==0&&graph[i][l]!=0&&graph[l][j]!=0&&i!=j)
					graph[i][j]=graph[i][l]+graph[l][j];
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)			
				if(graph[i][l]!=0&&graph[l][j]!=0)
					if(graph[i][l]+graph[l][j]<graph[i][j])
						graph[i][j]=graph[i][l]+graph[l][j];
}
int main(){
    cin>>n>>k>>t;
    for(int i=1;i<=n-1;i++){
        int u,v;
        if(k==0){
            cin>>u>>v;
        }
        else{
            cin>>u>>v;
            graph[u][v]=1;
            graph[v][u]=1;
            edge[u].total++;
            edge[v].total++;
            edge[u].num=u;
            edge[v].num=v;
        }
    }
    if(k==0){
        cout<<n<<endl;
        return 0;
    }
    sort(edge+1,edge+n+1);
    int pos=1;
    while(1){
        if(k==1){
            if(edge[pos].total==1){
                break;
            }
            if(book[edge[pos].num]==false){
                book[edge[pos].num]=true;
                ans++;
                for(int i=1;i<=n;i++){
                    if(graph[edge[pos].num][i]!=0){
                        book[i]=true;
                    }
                }
            }
            pos++;
        }
    }
    floyd();
    for(int i=pos;i<=n;i++){
        bool mark=false;
        if(book[edge[i].num]==false){
            for(int j=pos+1;j<=n;j++){
                if(book[edge[j].num]==false){
                    if(graph[edge[i].num][edge[j].num]==2){
                        if(mark==false){
                            ans++;
                            cout<<ans<<endl;
                        }
                        mark=true;
                        book[edge[j].num]=true;
                    }
                }
            }
            book[edge[i].num]=true;
        }
    }
    for(int i=pos;i<=n;i++){
        if(book[edge[i].num]==false){
            ans++;
            book[edge[i].num]=true;
        }
    }
    cout<<ans<<endl;
}