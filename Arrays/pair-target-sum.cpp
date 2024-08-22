#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define pf push_front
#define ll long long int
#define ull unsigned long long 
#define MOD 1000000007
#define mod 998244353

vector<int> solve(vector<int>nums, int n, int target) {
	int a = 0, b = 0;
	unordered_set<int>numbers;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		b = nums[i];
		a = target - b;
		vector<int>::iterator it = find(nums.begin(), nums.end(), a);
		if(numbers.find(a) != numbers.end()) {
			ans.insert(ans.end(), {it - nums.begin(), i});
			return ans;
		}

		numbers.insert(b);
	}

	// returning an empty vector
	return {};
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, test = 1, n = 0, target = 0;
	cin>>t;
	while(t--) {
		cin>>n>>target;
		vector<int>nums(n);
		for(int i = 0; i < n; i++) {
			cin>>nums[i];
		}

		vector<int> pair = solve(nums, n, target);
		
		if(pair.size() == 0) {
			cout<<"Case #"<<test<<": No such pair exists!"<<endl;
		} else {
			cout<<"Case #"<<test<<": "<<pair[0]<<","<<pair[1]<<endl;
		}
		test++;
	} 

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}