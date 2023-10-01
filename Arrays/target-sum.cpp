#include<bits/stdc++.h>
using namespace std;

// returns number of all pairs whose sum is equal to k
// solved using hashing
int getPairsUsingHashing(vector<int>&numbers, int n, int k) {
	int a = 0, b = 0;
	
	unordered_map<int, int>mp;

	int count = 0;
	for(int i = 0; i < n; i++) {
		b = numbers[i];
		a = k - b;

		if(mp.find(a) != mp.end()) {
			count += mp[a];
		}

		mp[b]++;
	}

	return count;
}

// returns the number of pairs whose sum is equal to the target
// sum 'k' using lower_bound and upper_bound
int getPairs(vector<int>&numbers, int n, int k) {
	int a = 0, b = 0;
	int firstOccurrence = -1, lastOccurrence = -1;
	int count = 0;

	sort(numbers.begin(), numbers.end());

	for(int i = 0; i < n; i++) {
		b = numbers[i];
		a = k - b;

		firstOccurrence = lower_bound(numbers.begin() + i + 1, numbers.end(), a) - numbers.begin();
		lastOccurrence = upper_bound(numbers.begin()  + i + 1, numbers.end(), a) - numbers.begin();
		count += (lastOccurrence - firstOccurrence);
	}

	return count;
}

// returns a vector of all the possible pairs whose sum is equal 
// to the target 'k' using the binary search

// Note: this is the worst solution...☻ 
vector<pair<int,int>> getPairsUsingBinarySearch(vector<int>&numbers, int n, int k) {
	vector<pair<int,int>>pairs;
	int left = 0, right = 0, mid = 0;
	int a = 0, b = 0;

	sort(numbers.begin(), numbers.end());

	for(int i = 0; i < n; i++) {
		left = (i+1), right = n-1;
		b = numbers[i];
		a = k - b;

		int index = -1;
		// binary search on (n-1) elements -> i+1 to n each time
		while(left <= right) {
			mid = left + (right - left) / 2;

			if(numbers[mid] == a) {
				index = mid;
				break;
			} else if(a > numbers[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		// finding the first and last occurrence of the a, if
		// any occurrence of a is found using the binary search
		// in the above loop, otherwise this means that the element
		// 'a' doesn't exist in the array
		// cout<<"index of "<<a<<" is: "<<index<<endl;
		if(index != -1) {
			// finding the first occurrence
			int firstOccurrenceIndex = -1, lastOccurrenceIndex = -1;
			for(int j = index-1; j > i; j--) {
				if(numbers[j] != a) {
					break;
				}
				firstOccurrenceIndex = j;	
			}

			// finding the last occurrence
			for(int k = index+1; k < n; k++) {
				if(numbers[k] != a) {
					break;
				}
				lastOccurrenceIndex = k;	
			}

			// calculating the total number of occurrences
			int totalOccurrences = 0;
			if(firstOccurrenceIndex == -1 && lastOccurrenceIndex == -1) {
				totalOccurrences = 1;
			} else if(firstOccurrenceIndex == -1) {
				firstOccurrenceIndex = index;
			} else if(lastOccurrenceIndex == -1) {
				lastOccurrenceIndex = index;
			}

			totalOccurrences = (lastOccurrenceIndex - firstOccurrenceIndex) + 1;

			for(int l = 0; l < totalOccurrences; l++) {
				pairs.push_back({a, b});
			}

		}
	}

	return pairs;
}

// returns number of unique pairs whose sum is equal to the 
// target 'k' by selecting each element only once
int solve(vector<int>&numbers, int n, int k) {
	int a = 0, b = 0, numberOfPairs = 0;
	unordered_set<int>values;

	for(int i = 0; i < n; i++) {
		b = numbers[i];
		a = k - b;
		if(values.find(a) != values.end()) {
			// cout<<a<<","<<b<<endl;
			numberOfPairs++;
		}

		values.insert(b);
	}

	return numberOfPairs;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, testCase = 1, n = 0, k = 0;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		// cout<<"Case #"<<testCase<<": "<<solve(numbers, n, k)<<endl;
		// vector<pair<int,int>> pairs = getPairsUsingBinarySearch(numbers, n, k);
		// if(pairs.size() == 0) {
		// 	cout<<"Case #"<<testCase<<": -1"<<endl;
		// } else {
		// 	cout<<"Case #"<<testCase<<":"<<endl;
		// 	for(auto pair : pairs) {
		// 		cout<<pair.first<<","<<pair.second<<endl;
		// 	}
		// }
		// int result = getPairsUsingHashing(numbers, n, k);
		int result = solve(numbers, n, k);
		cout<<"Case #"<<testCase<<": "<<result<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}