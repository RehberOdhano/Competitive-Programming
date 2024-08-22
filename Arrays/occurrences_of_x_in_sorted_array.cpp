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

int solveUsingArrays(int arr[], int n, int x) {
	// returns an iterator pointing to the first element in the
	// range [arr, arr + n) which has a value greater than or 
	// equal to the given value (in this case x), if the given
	// value is present otherwise it returns an iterator pointing
	// after the last element of the array which has a value zero
	int *firstOccurrence = lower_bound(arr, arr + n, x);

	cout<<firstOccurrence<<" "<<*firstOccurrence<<endl;
	if(firstOccurrence == (arr + n) || *firstOccurrence != x) {
		return -1;
	}

	// returns an iterator pointing to the first element in the
	// range [arr, arr + n) which has a value greater than the 
	// given value (in this case x), if the given value is present
	// otherwise it returns an iterator pointing after the last 
	// element of the array which has a value zero

	// we're only looking in the sub-array after the first occurrence
	int *lastOccurrence = upper_bound(firstOccurrence, arr + n, x);
	cout<<lastOccurrence<<" "<<*lastOccurrence<<endl;
	return lastOccurrence - firstOccurrence;
}

int anotherSolution(vector<int>&numbers, int n, int x) {
	vector<int>::iterator lowerBound = lower_bound(numbers.begin(), numbers.end(), x);
	int occurrences = 1;

	// checking the first occurrence of x
	if(lowerBound == numbers.end()) {
		return -1;
	}

	// checking the last occurrence of x
	vector<int>::iterator upperBound = upper_bound(numbers.begin(), numbers.end(), x);
	if(upperBound == numbers.end()) {
		return occurrences;
	}

	// calculating the number of occurrences of x by subtracting the
	// position of last and first occurrence of x respectively
	occurrences = (upperBound - numbers.begin()) - (lowerBound - numbers.begin());
	return occurrences;	
}

int solve(vector<int>&numbers, int n, int x) {
	int left = 0, right = n - 1, mid = 0;

	while(left <= right) {
		mid = left + (right - left)/2;
		if(numbers[mid] == x) {
			return mid;
		}

		if(x > numbers[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, x = 0;
	// int test = 1;
	cin>>t;
	while(t--) {
		cin>>n>>x;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}

		int *arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = numbers[i];
		}

		cout<<solveUsingArrays(arr, n, x);
		delete[] arr;

		// int indexOfFirstOccurrence = solve(numbers, n, x);
		// int indexOfFirstOccurrence = anotherSolution(numbers, n, x);
		// if(indexOfFirstOccurrence == -1) {
		// 	cout<<"Case #"<<test<<": "<<indexOfFirstOccurrence<<endl;
		// } else {
		// 	// int occurrences = 1;
		// 	// for(int i = 0; i < indexOfFirstOccurrence; i++) {
		// 	// 	if(numbers[i] == x) {
		// 	// 		occurrences++;
		// 	// 	}
		// 	// }

		// 	// for(int i = indexOfFirstOccurrence+1; i < n; i++) {
		// 	// 	if(numbers[i] == x) {
		// 	// 		occurrences++;
		// 	// 	}
		// 	// }
		// 	cout<<"Case #"<<test<<": "<<indexOfFirstOccurrence<<endl;
		// }
		// test++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}