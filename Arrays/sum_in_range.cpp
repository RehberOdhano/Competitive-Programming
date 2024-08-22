// https://cses.fi/problemset/task/1646

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> prefixSum(vector<ll>nums, int n) {
	vector<ll>prefixSumArr(n+1, 0);
	for(int i = 1; i <= n; i++) {
		prefixSumArr[i] = prefixSumArr[i-1] + nums[i-1];
	}
	return prefixSumArr;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, q, l, r;
	cin>>n>>q;
	vector<ll>nums(n);
	for(int i = 0; i < n; i++) cin>>nums[i];
	vector<ll>prefixSums = prefixSum(nums, n);

	while(q--) {
		cin>>l>>r;
		cout<<prefixSums[r] - prefixSums[l-1]<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}