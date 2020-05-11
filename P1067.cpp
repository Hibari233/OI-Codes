#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=105;
int n;
int s[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=n;i>=0;i--) scanf("%d",&s[i]);
    for(int i=n;i>=0;i--){
        if(s[i]==0) continue;
        if(s[i]<0) putchar('-');
        if(i!=n&&s[i]>0) putchar('+');
        if(i==0){
            printf("%d\n",abs(s[i]));
            break;
        }
        if(abs(s[i])!=1) printf("%d",abs(s[i]));
        putchar('x');
        if(i!=1){
            putchar('^');
            printf("%d",i);
        }
    }
    return 0;
}