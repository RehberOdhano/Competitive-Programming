// Leetcode Problem 03: Longest Substring Without Repeating Characters

// 11
// abcabcbb
// bbbbb
// pwwkew
// aabbef
// c
// bb
// ab
// dvdf
// pwwkkewsw
// tmmzuxt
// wobgrovw

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


#include<string>
using namespace std;

int solve(string s) {
    int lengthOfStr = s.size();
	
	if(lengthOfStr == 1) return 1;

    unordered_map<char,int>charFreqs;
    
    int lengthOfLongestSubstr = 0;
    int start = 0, end = 0;

    while(end < lengthOfStr) {
        auto it = charFreqs.find(s[end]);
        if(it == charFreqs.end()) {
            charFreqs[s[end]] = 1;
            lengthOfLongestSubstr = max(lengthOfLongestSubstr, (end - start + 1));
            end++;
        } else {
        	if(s[end] == s[end-1]) {
	        	start = end;
	            end++;
	        } else {
	        	start = end-1;
	        	cout<<"before backtracking: start = "<<start<<" and end = "<<end<<endl;
	        	while(s[start] != s[start-1] && s[start-1] != s[end]) {
	        		cout<<s[start]<<" "<<s[start-1]<<"->"<<charFreqs[start-1]<<" and start = "<<start<<endl;
	        		start--;
	        		cout<<"start = "<<start<<endl;
	        	}
	        	cout<<"after backtracking: start = "<<start<<" and end = "<<end<<endl;
	        	lengthOfLongestSubstr = max(lengthOfLongestSubstr, (end - start + 1));
	        	end++;	
	        }
        }
    }

    return lengthOfLongestSubstr;
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
		string str;
		cin>>str;
		cout<<solve(str)<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}