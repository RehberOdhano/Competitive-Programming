// Leetcode Problem: 09: Palindrome Number

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(int n) {
	if(n < 0) return false;

	string reversedNumber = "";
	int actualNumber = n, remainder, reversedInteger;

	while(n != 0) {
		remainder = n%10;
		n /= 10;
		reversedNumber += to_string(remainder);
	}

	reversedInteger = stol(reversedNumber);

	if(reversedInteger == actualNumber) return true;

	return false;
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		isPalindrome(n) ? cout<<"true" : cout<<"false";
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}