#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

// all the below implemented functions are used to find
// the unique element in the array, if present. If not
// present, then return -1;

// array manipulation
int findUniqueElementUsingXOR(vector<int>&numbers, int n) {
	int ans = numbers[0];
	for(int i = 1; i < n; i++) {
		cout<<(ans ^ numbers[i])<<" ";
		ans = ans ^ numbers[i];
	}
	cout<<endl;
	return ans;
}

// using formula
int findUniqueElementUsingMath(vector<int>&numbers, int n) {
	int uniquneSum = 0, duplicatesSum = 0;
	map<int,int>mp;

	for(int i = 0; i < n; i++) {
		if(mp[numbers[i]] == 0)	{
			uniquneSum += numbers[i];
			mp[numbers[i]]++;
		}

		duplicatesSum += numbers[i];
	}

	return (2 * uniquneSum - duplicatesSum);
}

// using binary search + with and without XOR
int findUniqueElementUsingBinarySearch(vector<int>&numbers, int n) {
	sort(numbers.begin(), numbers.end());
	// int key;
	// int left = 0, right = 0, mid = 0;
	// bool isFound;

	// for(int i = 0; i < n; ) {
	// 	if(!isFound && i == (n-1)) {
	// 		return numbers[i];
	// 	}

	// 	left = i+1, right = n-1;
	// 	key = numbers[i];
	// 	isFound = false;
	// 	while(left <= right) {
	// 		mid = left + (right - left)/2;
	// 		if(numbers[mid] == key) {
	// 			i = mid+1;
	// 			isFound = true;
	// 			break;
	// 		}

	// 		if(key < numbers[mid]) {
	// 			right = mid - 1;
	// 		} else {
	// 			left = mid + 1;
	// 		}
	// 	}

	// 	if(!isFound) return key;
	// }

	// return -1;

	// this method works only if it is guaranteed that
	// the unique element exists in the array
	int low = 0, high = n-2;
	int mid = 0;
	// bool isMatched = false;
	while(low <= high) {
		mid = low + (high - low)/2;
		if(numbers[mid] == numbers[mid ^ 1]) {
			low = mid+1;
			// isMatched = true;
		} else {
			high = mid-1;
		}
	}

	// if(isMatched) return -1;

	return numbers[low];

}

int findUniqueElementUsingSorting(vector<int>&numbers, int n) {
	sort(numbers.begin(), numbers.end());

	int uniqueElement = -1;
	for(int i = 0; i < n; ) {
		if(i == (n-1) && uniqueElement == -1) {
			uniqueElement = numbers[i];
			break;
		}

		if(numbers[i] != numbers[i+1]) {
			uniqueElement = numbers[i];
			i++;
		} else i += 2;
	}

	return uniqueElement;
}

int findUniqueElement(vector<int>&numbers, int n) {
	unordered_map<int, int>mp;

	// calculating the frequency of each element
	for(int i = 0; i < n; i++) {
		mp[numbers[i]]++;
	}

	//checking if there exist a number having frequency 1
	for(auto pair : mp) {
		if(pair.second == 1) {
			return pair.first;
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

	int t, n = 0, testCase = 1;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}
		cout<<"Case #"<<testCase<<": "<<findUniqueElementUsingBinarySearch(numbers, n)<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}