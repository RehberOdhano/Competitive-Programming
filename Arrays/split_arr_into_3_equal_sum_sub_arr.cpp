#include<bits/stdc++.h>
using namespace std;

bool splitArrIntoThreeEqualSumSubArr(vector<int>&numbers, int n) {
	int arrSum = 0;
	for(int number : numbers) arrSum += number;
	
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, testCase = 1;
	bool canSplitArr;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		canSplitArr = splitArrIntoThreeEqualSumSubArr(numbers, n);
		if(canSplitArr) cout<<"Case #"<<testCase<<": POSSIBLE"<<endl;
		else cout<<"Case #"<<testCase<<": IMPOSSIBLE"<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}