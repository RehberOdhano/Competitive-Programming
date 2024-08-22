#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

// returns number of triplets whose sum is equal to k
// solved using two-pointer approach
int getPairsUsingTwoPointerApproach(vector<int>&numbers, int n, int k) {
	int count = 0;
	int a = 0, b = 0, c = 0, sum = 0;
	int leftPtr = 0, rightPtr = 0;

	sort(numbers.begin(), numbers.end());

	for(int i = 0; i < n-2; i++) {
		leftPtr = i+1, rightPtr = n-1;
		a = numbers[i];
		while(leftPtr < rightPtr) {
			b = numbers[leftPtr], c = numbers[rightPtr];
			sum = a + b + c;	
			if(sum == k) {
				count++;
				leftPtr++, rightPtr--;
				// displaying the valid triplet
				// cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
			} else if(sum < k) {
				leftPtr++;
			} else {
				rightPtr--;
			}
		}
	}

	return count;	
}

// returns number of triplets whose sum is equal to k
// solved using the binary search

// Note: This solution is working 50/50
int solve(vector<int>&numbers, int n, int k) {
	int count = 0;
	int a = 0, b = 0, c = 0;
	int low = 0, high = 0;
	int mid = 0;
	int left = 0, right = (n - 1);

	// first sort the array/vector in increasing order
	sort(numbers.begin(), numbers.end());

	// after sorting we take two pointers, one will point to the
	// first element and other will point to the last element
	// using their values we'll calculate third value like this:
	// a = k - (b + c)
	// then we'll search whether the value of a exists or not in
	// the range [first+1, last-1] using the binary search
	// we'll move the pointers "left" and "right" based on the value
	// of "a". If the value of is negative then we'll move the 
	// "right" pointer to the right otherwise "left" pointer to
	// the left
	for(int i = 0; i < n; i++) {	
		b = numbers[left]; c = numbers[right];
		a = k - (b + c);
		low = left, high = right;
		while(low <= high) {
			mid = low + (high - low)/2;
			if(numbers[mid] == a && (a != b && b != c)) {
				count++;
				// displaying the valid triplet
				cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
				break;
			}

			if(a > numbers[mid]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		if(a < 0) right--;
		else left++;

	}

	return count;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, testCase = 1, k = 0;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		// cout<<"Case #"<<testCase<<": "<<getPairsUsingTwoPointerApproach(numbers, n, k)<<endl;
		cout<<"Case #"<<testCase<<": "<<solve(numbers, n, k)<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}