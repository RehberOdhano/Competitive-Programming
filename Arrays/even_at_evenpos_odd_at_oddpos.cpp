#include<bits/stdc++.h>
using namespace std;

// will place the even numbers at even indices and odd
// numbers at odd indices - solved using two-pointers
// approach
void evenOdd(vector<int>&numbers, int n) {
	int left = 0, right = 1;
	// we'll iterate over the array until the left or the
	// right pointer does not reach the end of the array
	while(left < n && right < n) {
		// if value at left(even) index is odd and the value
		// at right(odd) index is even then we'll swap the
		// values and move both the pointers to their next
		// even and odd positions respectively
		if((numbers[left] & 1) && !(numbers[right] & 1)) {
			swap(numbers[left], numbers[right]);
			left += 2, right += 2;
		} else {
			// if the value at left(even) index is even then
			// move the left pointer to the next even index
			if(!(numbers[left] & 1)) left += 2;

			// if the value at right(odd) index is odd then
			// move the right pointer to the next odd index 
			if((numbers[right] & 1)) right += 2;
		}
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
		evenOdd(numbers, n);
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