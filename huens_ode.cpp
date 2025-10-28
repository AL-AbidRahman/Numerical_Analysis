#include <bits/stdc++.h>
using namespace std;

double slope(double x, double y){

double numerator = x*x + y*y;
double denominator = x + y;

return (numerator/denominator);

}

int main(){

double y0 = 1; double x0 = 0;

double step = 0.25;

int size = (1.0-0.0)/step;

double arr[size+1];

for(int i=1; i<=size; i++){

arr[i] = y0 + (( slope(x0,y0) + slope(x0+step, y0 + slope(x0,y0)*step) )/2.0)*step;

x0 += step; y0 = arr[i];

}


for(int i=1; i<=size; i++) printf("iteration %d : %0.6f\n", i,arr[i]);

  return 0;
}