#include<iostream>
using namespace std;
int num;
bool is_prime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int l,r;
int main(){
    while(cin>>num){
        l=num/2;
        r=num/2;
        for(int i=1;i<=num/2;i++){
            //cout<<l<<" "<<r<<endl;
            if(is_prime(l)==true&&is_prime(r)==true){
                cout<<l<<" "<<r<<endl;
                break;
            }
            else{
                l--;
                r++;
            }
        }
    }
}