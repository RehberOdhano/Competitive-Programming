// https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// finding the minimum value in the given range using two-pointer approach
// but this solution will throw TLE
ll findMinInRange(vector<ll>&nums, ll left, ll right) {
	ll ans = nums[0];
	while(left <= right) {
		if(nums[left] <= nums[right]) {
			if(nums[left] < ans) {
				ans = nums[left];
			}
			left++;
		} else {
			if(nums[right] < ans) {
				ans = nums[right];
			}
			right--;
		}
	}
	return ans;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll n, q, l, r;
	cin>>n>>q;
	vector<ll>nums(n+1, 0);
	nums[0] = LONG_MAX;
	for(int i = 1; i <= n; i++) cin>>nums[i];

	while(q--) {
		cin>>l>>r;
		cout<<findMinInRange(nums, l, r)<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}