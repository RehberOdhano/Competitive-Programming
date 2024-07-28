// You are given an array of strings products and a string searchWord.

// Design a system that suggests at most three product names from products after each character
// of searchWord is typed. 
// Suggested products should have common prefix with searchWord. If there are more than three 
// products with a common prefix return the three lexicographically minimums products.

// Return a list of lists of the suggested products after each character of searchWord is typed.

// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],
//         ["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]


#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> findSuggestedProducts(vector<string> products, string query) {
// 	sort(products.begin(), products.end());
// 	int start = 2, stop = query.size() - 1;

// }

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	string str = "hello";
	reverse(str.begin(), str.end());
	cout<<str;

	return 0;
}