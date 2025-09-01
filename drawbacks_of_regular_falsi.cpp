#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (x*x*x*x*x*x*x*x*x*x -1);

}

int main() {
   
double lower1, upper1, lower2, upper2;
int minInterval = INT_MAX;

for(int i=-10; i<=9; i++){

  for(int j=i+1; j<=10; j++){

    if(f(i)*f(j)<0) {
      if((j-i)<=minInterval) { 
        lower1 = i; upper1 = j; 
        lower2 = i; upper2 = j;
        minInterval = j-i; }
        break;
    }
  }
}
cout<<"Lower Bound : "<<lower1<<endl<<"Upper Bound : "<<upper1<<endl<<endl;

double mid, rootBisection;
int iterationCountBisection =0;
double tolerance = 1e-10;
lower1 = 0.1;
while(fabs(f(mid))>tolerance && fabs(upper1-lower1)>tolerance){

mid = (upper1+lower1)/2;
rootBisection = mid;
if(f(mid)*f(lower1)<0) upper1 = mid;
else lower1 = mid;
iterationCountBisection++;

}

printf("rootBisection is : ");
printf("%.15f\n", rootBisection);
cout<<"bisection method iteration count : "<<iterationCountBisection<<endl<<endl;

double c, rootFalsi;
int iterationCountFalsi = 0;

while(fabs(f(c))>tolerance && fabs(upper2-lower2)>tolerance){

c = (upper2*f(lower2)-lower2*f(upper2))/(f(lower2)-f(upper2));
rootFalsi = c;
if(f(c)*f(lower2)<0) upper2 = c;
else lower2 = c;
iterationCountFalsi++;

}

printf("rootFalsi is : ");
printf("%.15f\n", rootFalsi);
cout<<"false position iteration count : "<<iterationCountFalsi<<endl;

return 0;

}

// for the initial interval [a, b], if one of the extreme's 
// functional value is significantly greater than other's (f(a)>>f(b) or f(b)>>f(a)),
// the root estimate c keeps getting pulled toward one side.
// This can cause one endpoint to remain fixed for many iterations which leads to 
// extremely slow progress. So convergence becomes much slower than bisection.

// Let's take a look at the output of this programm 

// Lower Bound : 0
// Upper Bound : 2

// rootBisection is : 1.000000000014552
// bisection method iteration count : 35

// rootFalsi is : 0.999999999990073
// false position iteration count : 3026

// f(2) >> f(0); 
// False position stagnates → takes many more iterations for the same accuracy. 