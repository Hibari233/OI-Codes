#include<iostream>
using namespace std;
const int MAXN=510;
int F,n,m,w;
int graph[MAXN][MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=0x3f3f3f3f;
        }
    }
}
int main(){
    cin>>F;
    for(int p=1;p<=F;p++){
        cin>>n>>m>>w;
        init(n);
        for(int i=1;i<=m;i++){
            int s,e,t;
            cin>>s>>e>>t;
            if(t<graph[s][e]){
                graph[s][e]=t;
                graph[e][s]=t;
            }
        }
        for(int i=1;i<=w;i++){
            int s,e,t;
            cin>>s>>e>>t;
            graph[s][e]=-t;
        }
        bool judge=false;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(graph[i][k]+graph[k][j]<graph[i][j])
                        graph[i][j]=graph[i][k]+graph[k][j];
                }
                if(graph[i][i]<0){
                    if(judge!=true)
                        cout<<"YES"<<endl;
                    judge=true;
                    break;
                }
            }
            if(judge==true) break;
        }
        if(judge==false){
            cout<<"NO"<<endl;
        }
    }
}