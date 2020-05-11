#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
double a_x,a_y,b_x,b_y,c_x,c_y,d_x,d_y,p,q,r;
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double a_to_b,b_to_c,c_to_d,a_to_c,a_to_d;
double route[10];
int main(){
    cin>>a_x>>a_y>>b_x>>b_y;
    cin>>c_x>>c_y>>d_x>>d_y;
    cin>>p>>q>>r;
    a_to_b=dist(a_x,a_y,b_x,b_y);
    b_to_c=dist(b_x,b_y,c_x,c_y);
    c_to_d=dist(c_x,c_y,d_x,d_y);
    a_to_c=dist(a_x,a_y,c_x,c_y);
    a_to_d=dist(a_x,a_y,d_x,d_y);
    a_to_b/=p;
    c_to_d/=q;
    b_to_c/=r;
    a_to_c/=r;
    a_to_d/=r;
    route[0]=a_to_b+b_to_c+c_to_d;
    route[1]=a_to_c+c_to_d;
    route[2]=a_to_d;
    int min;
    sort(route,route+3);
    cout<<route[0]<<" "<<route[1]<<" "<<route[2]<<" ";
    return 0;
}