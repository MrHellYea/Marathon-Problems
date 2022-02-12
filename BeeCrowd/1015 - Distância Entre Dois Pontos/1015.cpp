#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double dist(double, double, double, double);


int main () {
  double x1, y1, x2, y2;
  
  cin >> x1 >> y1 >> x2 >> y2; 
  cout << fixed;
  cout << setprecision(4);
  cout << dist(x1, y1, x2, y2) << endl;
  
  return 0;
}


double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
