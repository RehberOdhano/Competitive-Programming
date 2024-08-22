// Given an array of size n. For every i = 0 to n-1, output max(a[0],a[1]...,a[i])
// for example: arr = [1 0 5 4 6 8] -> output: 1 1 5 5 6 8

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

vector<int> solve(vector<int>nums, int n) {
	vector<int> prefixMaxArr{nums[0]};
	for(int i = 1; i < n; i++) {
		prefixMaxArr.push_back(max(prefixMaxArr[i-1], nums[i]));
	}
	return prefixMaxArr;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		vector<int> prefixMax = solve(nums, n);
		for(int max : prefixMax) {
			cout<<max<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}