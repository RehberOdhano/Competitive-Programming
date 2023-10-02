#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

// returns the second largest element in the array, if
// present otherwise returns -1
int findSecondLargestElementUsingSet(vector<int>&numbers, int n) {
	set<int>values;
	for(int number : numbers) {
		values.insert(number);
	}
	n = values.size();
	return values.size() == 1 ? -1 : *(next(values.begin(), (n-2)));
}

// working 50/50
// returns the second largest element of the array, if
// present otherwise returns -1
// solved using two-pointer approach
int findSecondLargestElement(vector<int>&numbers, int n) {
	int firstMax = INT_MIN, secondMax = INT_MIN;
	int left = 0, right = (n-1);
	int temp = 0;
	
	cout<<"before while loop: "<<firstMax<<" "<<secondMax<<endl;
	while(left <= right) {
		if(numbers[right] < secondMax) {
			if(numbers[left] > firstMax) {
				firstMax = numbers[left];
			}
			if(numbers[left] > secondMax) {
				secondMax = numbers[left];
			}
		} 
		// checks if the element on the 'right' index is greater
		// than the secondMax and less the element at 'left' index
		// then set firstMax to left index element and secondMax
		// to the right index element
		else if(numbers[right] > secondMax && numbers[right] < numbers[left]) {
			secondMax = numbers[right];
			firstMax = numbers[left];
		} else {
			if(left == right) {
				if(numbers[left] > firstMax) {
					temp = firstMax;
					firstMax = numbers[right];
					secondMax = temp;
				} else {
					secondMax = numbers[left];
				}
			} else {
				temp = firstMax;
				firstMax = numbers[right];
				// secondMax = numbers[left] > secondMax ? secondMax : temp;
				secondMax = temp;
			}
		}
		cout<<"in while loop: "<<firstMax<<" "<<secondMax<<endl;
		left++, right--;
	}
	if(firstMax < secondMax) swap(firstMax, secondMax);
	cout<<"after while loop: "<<firstMax<<" "<<secondMax<<endl;
	return firstMax == secondMax ? -1 : secondMax;
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
		cout<<"Case #"<<testCase<<": "<<findSecondLargestElementUsingSet(numbers, n)<<endl;
		testCase++;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}