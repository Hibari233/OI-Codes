#include<iostream>
using namespace std;
int a,b,ans=0; 
bool run(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        int year=i/10000;
        int month=(i/100)-(i/10000)*100;
        int day=i-(i/100)*100;
        bool judge=run(year);
        if(day<1) continue;
        if(month<1||month>12) continue;
        if(month==1)
            if(day>31) continue;
        if(month==2)
            if(judge==true)
                if(day>29) continue;
        if(month==2)
            if(judge==false)
                if(day>28) continue;
        if(month==3)
            if(day>31) continue;
        if(month==4)
            if(day>30) continue;
        if(month==5)
            if(day>31) continue;
        if(month==6)
            if(day>30) continue;
        if(month==7)
            if(day>31) continue;
        if(month==8)
            if(day>31) continue;
        if(month==9)
            if(day>30) continue;
        if(month==10)
            if(day>31) continue;
        if(month==11)
            if(day>30) continue;
        if(month==12)
            if(day>31) continue;
        
        int a[10]={0};
        int n=i;
        int pos=1;
        while(n){
            a[pos++]=n%10;
            n/=10;
        }
        if(a[1]==a[8]&&a[2]==a[7]&&a[3]==a[6]&&a[4]==a[5]){
            ans++;
        }
    }
    cout<<ans<<endl;
}