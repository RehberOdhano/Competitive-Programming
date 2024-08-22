// Leetcode Problem 560: Subarray Sum Equals K

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

vector<int> composePrefixSumArr(int n, vector<int>nums) {
	vector<int> prefixSumArr({nums[0]});
	for(int i = 1; i < n; i++) {
		prefixSumArr.push_back(nums[i] + prefixSumArr[i-1]);
	}
	return prefixSumArr;
}

int solve(int n, vector<int>prefixSumArr, int k) {
	int countOfSubArrSumEqualToK = 0;

	int initialVal = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(prefixSumArr[j] - initialVal == k) countOfSubArrSumEqualToK++;
		}
		initialVal = prefixSumArr[i];
	}

	return countOfSubArrSumEqualToK;
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
		int n, k;
		cin>>n>>k;
		
		vector<int>nums(n);
		for(int i = 0; i < n; i++) {
			cin>>nums[i];
		}

		vector<int>prefixSumArr = composePrefixSumArr(n, nums);
		cout<<solve(n, prefixSumArr, k)<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}