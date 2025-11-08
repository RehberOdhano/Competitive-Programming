// Given an array of size n. Output the sum of each sub-array of the given array

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

vector<int> solve(int n, vector<int>prefixSumArr) {
	vector<int> sumOfSubArrays;

	int initialVal = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			sumOfSubArrays.push_back(prefixSumArr[j] - initialVal);
		}
		initialVal = prefixSumArr[i];
	}

	return sumOfSubArrays;
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

		vector<int>prefixSumArr = composePrefixSumArr(n, nums);
		vector<int>sumOfSubArrays = solve(n, prefixSumArr);

		for(int sumOfSubArray : sumOfSubArrays) {
			cout<<sumOfSubArray<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}