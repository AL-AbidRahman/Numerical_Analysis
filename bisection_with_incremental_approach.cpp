#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (x*x*x - 4*x -9) ;
}

int main() {
   
double lower, upper;
int minInterval = INT_MAX;

for(int i=-10; i<=9; i++){

  for(int j=i+1; j<=10; j++){

    if(f(i)*f(j)<0) {
      if((j-i)<=minInterval) { lower = i; upper = j; minInterval = j-i; }
      break;
    }
  }
}
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

return 0; }