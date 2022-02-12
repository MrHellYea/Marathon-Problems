#include <iostream>
#include <vector>
	
using namespace std;
	
	
int main() {
	int T, k, i;
	vector<string> X = {"-1", "-1", "-1", "1210 2020", "21200", "-1", "3211000", "42101000", "521001000", "6210001000"};
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> k;
		cout << X[k - 1] << endl;
	}
	
	return 0;
}