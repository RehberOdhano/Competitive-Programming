#include<bits/stdc++.h>
using namespace std;

void calculatePrefixSum(vector<int>&numbers, int n) {
	int left = 0, right = 1;
	while(right < n) {
		numbers[right] = numbers[left] + numbers[right];
		left++, right++;
	}
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		calculatePrefixSum(numbers, n);
		for(int number : numbers) {
			cout<<number<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}