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

// rotating the given array by k-steps using two-pointers
// O(n)
void rotateArrayByKStepsUsingTwoPointers(vector<int>&numbers, int n, int k) {
	if(n == 1 || k == 0 || k == n) return;
	
	int numberOfRightTurns = 0;
	int left = 0, mid = 0, right = 0;
	int temp1 = 0, temp2 = 0;

	if(k > n) {
		if(k % n == 0) return;
		else {
			// calculating the actual number of turns to rotate 
			// the array to the right
			numberOfRightTurns = (k % n);
			if(n == 2) {
				while(numberOfRightTurns--) {
					swap(numbers[0], numbers[1]);
				}
				return;
			}
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

	int t, n = 0, k = 0;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		rotateArrayByKStepsUsingTwoPointers(numbers, n, k);
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