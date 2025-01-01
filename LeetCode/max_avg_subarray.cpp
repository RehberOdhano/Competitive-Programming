// Leetcode Problem: 643. Maximum Average Subarray I

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

double solve(vector<int>nums, int n, int windowSize) {
	double maxAvgSubArray = INT_MIN;
	int sum = 0;

	for(int i = 0; i < windowSize; i++) sum += nums[i];
	double avgSubArray = sum/(double)windowSize;
	maxAvgSubArray = max(maxAvgSubArray, avgSubArray);

	for(int i = 1, j = windowSize; j < n; i++, j++) {
		sum = sum - nums[i-1] + nums[j];
		avgSubArray = sum/(double)windowSize;
		maxAvgSubArray = max(maxAvgSubArray, avgSubArray);
	}

	return maxAvgSubArray;
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
		cout<<solve(nums, n, k)<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}