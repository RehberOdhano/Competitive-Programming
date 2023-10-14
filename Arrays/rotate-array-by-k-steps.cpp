#include<bits/stdc++.h>
using namespace std;

// rotating the given array by k-steps using nested loops
// O(n^2)
void rotateArrayByKSteps(vector<int>&numbers, int n, int k) {
	int temp1 = 0, temp2 = 0;
	// means array is already rotated
	if(k == 0 || k == n) return;

	// rotating the array to the right by k-steps
	while(k--) {
		temp1 = numbers[0];
		numbers[0] = numbers[n-1];
		for(int i = 1; i < n; i++) {
			temp2 = numbers[i];
			numbers[i] = temp1;
			temp1 = temp2;
		}
	} 
}

// rotating the given array by k-steps using O(n) space
// constraints:
// 1 <= n <= 10^5
// 0 <= k <= 10^5
vector<int> rotateArrayByKStepsUsingAnotherArray(vector<int>numbers, int  n, int k) {
	vector<int>rotatedArray(n);

	int lastIndex = 0;
	for(int i = (n-k), j = 0; i < n; i++, j++) {
		rotatedArray[j] = numbers[i];
		lastIndex = j;
	}

	lastIndex++;
	for(int i = 0; i < (n-k); i++) {
		rotatedArray[lastIndex] = numbers[i];
		lastIndex++;
	}

	return rotatedArray;
}

// rotating the given array by k-steps to the right in O(n) 
// time with constant space O(1) 
// the value of k be greater than, less than or equal to n
void rotateArrayByKStepsUsingReverse(vector<int>&numbers, int n, int k) {
	if(n == 1 || k == 0 || k == n) return;
	k %= n;
	reverse(numbers.begin(), numbers.end());
	reverse(numbers.begin(), numbers.begin() + k);
	reverse(numbers.begin() + k, numbers.end());
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, k = 0;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		rotateArrayByKStepsUsingReverse(numbers, n, k);
		// vector<int>result = rotateArrayByKStepsUsingAnotherArray(numbers, n, k);
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