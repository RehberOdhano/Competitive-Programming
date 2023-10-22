#include<bits/stdc++.h>
using namespace std;

void sortByPairty(vector<int>&arr, int n) {
	int left = 0, right = (n - 1);
	while(left < right) {
		// if the values both at left and right indices are
		// odd then move the right pointer to the left
		if((arr[left] & 1) && (arr[right] & 1)) {
			right--;
		}

		// if the values both at left and right indices are
		// even the move the left pointer to the right
		if(!(arr[left] & 1) && !(arr[right] & 1)) {
			left++;
		}

		// if the value at left is odd and the value at right
		// is even then swap the values
		if((arr[left] & 1) && !(arr[right] & 1)) {
			swap(arr[left], arr[right]);
			left++, right--;
		}

		// if the value at left is even and the value at right
		// is odd then just move the left pointer to the right
		// and the right pointer to the left
		if(!(arr[left] & 1) && (arr[right] & 1)) {
			left++, right--;
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
		vector<int>arr(n);
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		sortByPairty(arr, n);
		for(int element : arr) {
			cout<<element<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}