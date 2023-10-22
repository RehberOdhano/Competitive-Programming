#include<bits/stdc++.h>
using namespace std;

// segregating the zeroes and ones using two-pointer
// technique
void segregateZerosAndOnes(vector<int>&numbers, int n) {
	int left = 0, right = n - 1;
	while(left < right) {
		if(numbers[left] > numbers[right]) {
			swap(numbers[left], numbers[right]);
			left++, right--;
		} else if(numbers[left] == numbers[right]) {
			if(numbers[left] == 1) right--;
			else left++;
		} else {
			left++, right--;
		}
	}	
}

// segregating the zeroes and ones using fill array
// method by counting number of zeroes
void segregateZerosAndOnesByCountingZeroes(vector<int>&numbers, int n) {
	int numberOfZeroes = 0;
	for(int number : numbers) {
		if(number == 0) numberOfZeroes++;
	}

	if(numberOfZeroes == n || numberOfZeroes == 0) return;

	for(int i = 0; i < numberOfZeroes; i++) {
		numbers[i] = 0;
	}

	for(int i = numberOfZeroes+1; i < n; i++) {
		numbers[i] = 1;
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
		segregateZerosAndOnesByCountingZeroes(numbers, n);
		for(int element : numbers) {
			cout<<element<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}