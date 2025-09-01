#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (x*x*x - 4*x -9) ;
}

int main() {
   
double lower=0, upper=10;

cout<<"Lower Bound : "<<lower<<endl<<"Upper Bound : "<<upper<<endl;
double tolerance = 1e-10;
double mid = (upper+lower)/2;
double root = mid;
int iterationCount = 0;
while(fabs(f(mid))>tolerance && fabs(upper-lower)>tolerance){

mid = (upper+lower)/2;
root = mid;
if(f(mid)*f(lower)<0) upper = mid;
else lower = mid;
iterationCount++;
}

printf("Root is : ");
printf("%.15f\n", root);
cout<<iterationCount<<endl;

return 0;}