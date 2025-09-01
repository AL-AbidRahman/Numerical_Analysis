#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (4*x*x +3*x -3) ;
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
cout<<"Lower Bound : "<<lower1<<endl<<"Upper Bound : "<<upper1<<endl;

double mid, rootBisection;
int iterationCount = 10;

while(iterationCount--){

mid = (upper1+lower1)/2;
rootBisection = mid;
if(f(mid)*f(lower1)<0) upper1 = mid;
else lower1 = mid;

}

printf("rootBisection is : ");
printf("%.15f\n", rootBisection);


double c, rootFalsi;
iterationCount = 10;

while(iterationCount--){

c = (upper2*f(lower2)-lower2*f(upper2))/(f(lower2)-f(upper2));
rootFalsi = c;
if(f(c)*f(lower2)<0) upper2 = c;
else lower2 = c;

}

printf("rootFalsi is : ");
printf("%.15f\n", rootFalsi);

return 0;

}


// exact root between [0, 1] is x≈0.568729304408844 (wolframAlpha)
//             rootBisection is : 0.569335937500000  true error < 10^-2
//                 rootFalsi is : 0.568729264079016  true error < 10^-6

// so for a fixed number of iterations, 
// false position method(also known as regular falsi) performs much 
// better as compared to bisection method, this is because regular falsi
// method converges towards the root much faster than bisection method.