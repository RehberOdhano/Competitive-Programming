#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
const unsigned int M = 1000000007;
using namespace std;

ll solve(vector<vector<ll>>v, int p, int n) {
	ll ans = 0, pressure = 0;
	
	for(int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end());

		if(pressure > v[i][0] && pressure < v[i][(n-1)]) {
			if(pressure - v[i][0] <= v[i][(n-1)] - pressure) {
				ans += (pressure - v[i][0]) + (v[i][(n-1)] - v[i][0]) % M;
				pressure = v[i][(n-1)];
			} else {
				ans += (v[i][(n-1)] - pressure) + (v[i][(n-1)] - v[i][0]) % M;
				pressure = v[i][0];
			}
		} else {
			if(pressure < v[i][(n-1)]) {
				ans += (v[i][(n-1)] - pressure)  % M;
				pressure = v[i][(n-1)];
			} else {
				ans += (pressure - v[i][0]) % M;
				pressure = v[i][0];
			}
		}
	}

	return ans;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		int N, P;
		cin>>N>>P;
		vector<vector<ll>>X(N);
		for(int i = 0; i < N; i++) {
			X[i] = vector<ll>(P);
			for(int j = 0; j < P; j++) {
				cin>>X[i][j];
			}
		}
		// cout<<"X"<<endl;
		// for(int i = 0; i < N; i++) {
		// 	for(int x : X[i]) cout<<x<<" ";
		// 	cout<<endl;
		// }
		cout<<"Case #"<<test<<": "<<solve(X, P, N)<<endl;
		test++;
	}
	return 0;
}