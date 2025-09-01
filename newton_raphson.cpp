#include <bits/stdc++.h>
using namespace std;

double f(double x){

  return (x*x*x*x*x -3*x +5) ;
}

double derivative(double x){

  return (5*x*x*x*x -3) ;
}


int main() {
   
double lower, upper;
int minInterval = INT_MAX;

for(int i=-20; i<=19; i++){

  for(int j=i+1; j<=20; j++){

    if(f(i)*f(j)<0) {
      if((j-i)<=minInterval) { lower = i; upper = j; minInterval = j-i; }
      break;
    }
  }
}

double initialGuess;
if(derivative(upper)) initialGuess = upper;
else initialGuess = lower;

cout<<"Lower Bound : "<<lower<<endl<<"Upper Bound : "<<upper<<endl;
double tolerance = 1e-8;
double nextGuess = initialGuess - (f(initialGuess)/derivative(initialGuess));
double root = nextGuess;
int iterationCount = 0;

while(fabs(f(nextGuess))>tolerance && fabs(initialGuess-nextGuess)>tolerance){

initialGuess = nextGuess;
nextGuess = initialGuess - (f(initialGuess)/derivative(initialGuess));
root = nextGuess;
iterationCount++;
}

printf("Root is : ");
printf("%.15f\n", root);
cout<<iterationCount<<endl;

return 0; }

//                       exact root is x≈-1.576194959975223022 (wolframAlpha)
// root using Newton-Raphson method is x≈-1.576194959975370  true error < 10^-12
