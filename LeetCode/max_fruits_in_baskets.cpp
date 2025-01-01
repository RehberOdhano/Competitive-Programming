// Leetcode Problem: 904. Fruit into baskets

// 5
// 4
// 0 0 1 1
// 3
// 1 2 1
// 4
// 0 1 2 2
// 5
// 1 2 3 2 2
// 11
// 3 3 3 1 2 1 1 2 3 3 4

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int totalFruits(vector<int>& fruits) {
	int maxNumberOfFruits = INT_MIN;
	int numberOfFruits = fruits.size();

	return maxNumberOfFruits;
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
		vector<int>fruits(n);
		for(int i = 0; i < n; i++) {
			cin>>fruits[i];
		}
		cout<<totalFruits(fruits)<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}