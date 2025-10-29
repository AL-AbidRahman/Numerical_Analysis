#include <bits/stdc++.h>
using namespace std;

double fn(double x){

return (1.0/(1.0+x*x));

}

int main(){

double lower_limit = 0.0;
double upper_limit = 1.0;

double step = (1.0)/(6.0);

int n = (upper_limit-lower_limit)/step;

double area = fn(lower_limit) + fn(upper_limit);

double odd = 0.0;
double even = 0.0;

for(int i=1; i<n; i++){

double x = lower_limit + i*step;

if(i%2==1) odd += fn(x);
else even += fn(x);

}

area = (step/3.0)*(area + 4*odd + 2*even);

printf("approximated area is : %.6f\n", area);

  return 0;
}