#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[110],b[1010];
bool caps=false;
int main(){
    cin>>a;
    cin>>b;
    int pos=0;
    for(int i=0;i<strlen(b);i++){
        char cur_key=a[pos];
        char cur_pass=b[i];
        pos++;
        if(pos>=strlen(a)) pos=0;
        if(cur_pass-'a'>=0) caps=false;
        else caps=true;
        int cur_passn,cur_keyn;
        if(caps==true) cur_passn=cur_pass-'A';
        else cur_passn=cur_pass-'a';
        if(cur_key>='a') cur_keyn=cur_key-'a';
        else cur_keyn=cur_key-'A';
        if(cur_passn>=cur_keyn){
            char ans=cur_passn-cur_keyn;
            if(caps==true) printf("%c",ans+'A');
            else printf("%c",ans+'a');
        }
        else{
            char ans=(26-cur_keyn)+cur_passn;
            if(caps==true) printf("%c",ans+'A');
            else printf("%c",ans+'a');
        }
    }
    printf("\n");
    return 0;
}