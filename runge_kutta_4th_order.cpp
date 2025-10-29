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

int size = (1.0-0.0)/(0.25);

double arr[size+1];

for(int i=1; i<=size; i++){

double k1 = slope(x0,y0);

double k2 = slope( x0+(step/2.0), y0 + k1*(step/2.0) );

double k3 = slope( x0+(step/2.0), y0 + k2*(step/2.0) );

double k4 = slope( x0+step, y0 + k3*step );

arr[i] = y0 + step*((k1 +2*k2 + 2*k3 + k4)/6.0);

x0 = x0 + step; y0 = arr[i];

}

for(int i=1; i<size+1; i++) printf("iteration %d : %.6f\n", i,arr[i]);


  return 0;
}