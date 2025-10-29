#include <bits/stdc++.h>
using namespace std;

double fn(double x){

return cos(x);

}

int main(){

double x0 = 0;

int interval = 3;

double step = ((M_PI/2.0)-0.0)/interval;

double area = 0.0;

for(int i=1; i<=interval; i++){

double lower_limit = x0;
double upper_limit = x0 + step;

double partialArea = (0.5)*(fn(lower_limit)+fn(upper_limit))*step;

area += partialArea;

x0 += step;

}

printf("approximated area is : %.6f\n", area);

  return 0;
}