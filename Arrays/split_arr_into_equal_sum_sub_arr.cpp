// Question: Check if we can paritition the array into two subarrays with equal sum
// More formally, check that the prefix sum of a part of array is equal to the suffix
// sum of the rest of the array

// sample input -> [6,2,4,3,1]
// output -> true -> prefix sum: [6,2] -> 8 and suffix sum: [4,3,1] -> 8

#include<bits/stdc++.h>
using namespace std;

bool splitArrIntoEqualSumSubArr(vector<int>&numbers, int n) {
	int arrSum = 0;
	for(int number : numbers) arrSum += number;

	int left = 0, right = 1;
	int halfSum = arrSum/2;
	while(right < n) {
		numbers[right] = numbers[left] + numbers[right];
		if(numbers[right] == halfSum) return true;

		left++, right++; 
	}	

	return false;
}

bool splitArrIntoEqualSumSubArrOptimized(vector<int>&numbers, int n) {
	int arrSum = 0;
	for(int number : numbers) arrSum += number;

	int rightSum = 0;
	for(int number : numbers) {
		rightSum += number;
		arrSum -= number;
		if(rightSum == arrSum) {
			return true;
		}
	}

	return false;
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
		canSplitArr = splitArrIntoEqualSumSubArrOptimized(numbers, n);
		if(canSplitArr) cout<<"Case #"<<testCase<<": POSSIBLE"<<endl;
		else cout<<"Case #"<<testCase<<": IMPOSSIBLE"<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}