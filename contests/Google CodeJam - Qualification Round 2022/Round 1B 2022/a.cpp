#include <iostream>
#include <math.h>
#include <deque>
#define ll long long
using namespace std;

int solve(deque<int>pc, int n) {
	int ans = 0, start = 0, end = (n - 1), prev = 0;
	while(start <= end) {
		if(pc[start] <= pc[end]) {
			if(pc[start] >= prev) ans += 1;
			prev = max(pc[start], prev);
			start++;
		} else {
			if(pc[end] >= prev) ans += 1;
			prev = max(pc[end], prev);
			end--;
		}
	}
	return ans;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		int N;
		cin>>N;
		deque<int>pancakes(N, 0);
		for(int i = 0; i < N; i++) cin>>pancakes[i];
		cout<<"Case #"<<test<<": "<<solve(pancakes, N)<<endl;
		test++;
	}
	return 0;
}