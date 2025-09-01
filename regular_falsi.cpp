#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (log(3*x)-3) ;
}

int main() {
   
double lower, upper;
int minInterval = INT_MAX;

for(int i=1; i<=19; i++){

  for(int j=i+1; j<=20; j++){

    if(f(i)*f(j)<0) {
      if((j-i)<=minInterval) { lower = i; upper = j; minInterval = j-i; }
      break;
    }
  }
}

cout<<"Lower Bound : "<<lower<<endl<<"Upper Bound : "<<upper<<endl;
double tolerance = 1e-8;
double c = (upper*f(lower)-lower*f(upper))/(f(lower)-f(upper));
double root = c;
int iterationCount = 0;

while(fabs(f(c))>tolerance && fabs(upper-lower)>tolerance){

c = (upper*f(lower)-lower*f(upper))/(f(lower)-f(upper));
root = c;
if(f(c)*f(lower)<0) upper = c;
else lower = c;
iterationCount++;
}

printf("Root is : ");
printf("%.5f\n", root);
cout<<iterationCount<<endl;

return 0; }