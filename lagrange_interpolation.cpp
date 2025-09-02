#include <bits/stdc++.h>
using namespace std;

int n; 
double arrX[100], arrY[100];

double f(int indx, double value){

double numerator=1, denominator=1;

for(int j=0; j<n; j++){

if(j!=indx){ 
  numerator   *= value - arrX[j]; 
  denominator *= arrX[indx] - arrX[j];
}

}

return arrY[indx]*(numerator/denominator);

}

int main(){

cin >> n;
double value; cin >> value;

for(int i=0; i<n; i++) cin >> arrX[i];

for(int i=0; i<n; i++) cin >> arrY[i];

double ans = 0;

for(int i=0; i<n; i++) 
    ans += f(i, value);

cout<<ans<<endl;


  return 0;
}