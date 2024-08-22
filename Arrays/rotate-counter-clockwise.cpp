#include<bits/stdc++.h>
using namespace std;

void reverseTheArr(int arr[], int start, int end) {
    int temp = 0;
    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++, end--;
    }
}

void rotateArr(int arr[], int d, int n) {
	// if the length of array is same as the number of
	// steps to rotate the return then just return the
	// array because we'll get the same array
	if(d == n) return;

	// check if number steps to rotate the array is greater
	// than size of the array, and if size of the array is 
	// a factor of number of steps then don't rotate the
	// array because we'll get the same array otherwise,
	// calculate the actual value of d (number of steps)
	if(d > n) {
		// e.g. if d = 94 & n = 47, then this means that
		// first we've to rotate the array 47 steps, which
		// we'll return the same array because n is also 47
		// and rotating the array again 47 steps, we'll
		// get the same array again.
		if(d % n == 0) return;
		// e.g. d = 77 and n = 47, first we've to rotate the
		// array 47 steps, which we'll return the same array,
		// and then we've to rotate the array again by the 
		// remaining steps (30) and we'll get the resultant
		// array. This means that we've to rotate only 30
		// steps instead of 77 steps to get the result
		// Therefore, here we're calculating the actual
		// number of steps to rotate the array in order
		// to avoid unnecessary rotation operations
		d = d % n;
	}

    int start = d, end = n-1;
    
    // first reverse the elements starting from index d
    // to the end
    reverseTheArr(arr, start, end);
    
    // after that reverse the entire array
    reverseTheArr(arr, 0, end);

    // then reverse the elements starting from index (n-d)
    // to the end
    reverseTheArr(arr, n-d, end);
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, d = 0;
	cin>>t;
	while(t--) {
		cin>>n>>d;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		rotateArr(arr, d, n);
		for(int element : arr) {
			cout<<element<<" ";
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}