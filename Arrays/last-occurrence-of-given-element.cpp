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

int main() {
	int n, m;
	cin>>n>>m;
	vector<int>numbers(n);
	for(int i = 0; i < n; i++) {
		cin>>numbers[i];	
	}
	
	int lastOccurrenceIndex = -1;
	for(int i = n-1; i >= 0; i--) {
		if(numbers[i] == m) {
			lastOccurrenceIndex = i+1;
			break;
		}
	}
	cout<<lastOccurrenceIndex<<endl;
}