#include <iostream>
#include <iomanip>
using namespace std;

void linear_regression(float x[], float y[],int precision) {
 float moy_xy=0,cov=0,var=0,sum_xy=0,square_x=0,moy_square_x=0,sum_x=0,sum_y=0,moy_x=0,moy_y=0;
 string op="";
 int n=sizeof(x)/sizeof(x[0]);
 for (int i=0;i<n;i++) {
  sum_xy+=x[i]*y[i];
  sum_x+=x[i];
  sum_y+=y[i];
  square_x+=x[i]*x[i];

 }
 moy_x=sum_x/n;
 moy_y=sum_y/n;
 moy_xy=sum_xy/n;
 cov=moy_xy-moy_x*moy_y;
 moy_square_x=square_x/n;
 var=moy_square_x-moy_x*moy_x;

 float a=cov/var;
 float b=moy_y-a*moy_x;
 if (b<0) {
  op='_';
 }
 else if (b>0) {
  op='+';
 }

 cout<< fixed<<setprecision(precision);
 cout<<"a="<<a<<endl;
 cout<<"b="<<b<<endl;
 if (b!=0) {
  cout<<"y="<<a<<"x"<<op<<b<<endl;

 }else {
  cout<<"y="<<a<<"x"<<endl;
 }

}

int main() {
 float x[] = {1, 2, 3, 4, 5};
 float y[] = {2, 4, 6, 8, 8};
 linear_regression(x, y,2);
 return 0;
}
