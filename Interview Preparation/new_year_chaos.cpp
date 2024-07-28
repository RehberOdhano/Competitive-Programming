#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

void minimumBribes(vector<int> q) {
    int diff;
    int n = q.size();
    int bribes = 0, number_of_swaps = 0, start = 0;
    int end = n - 1;

    for(int i = 0; i < n; ) {
        if(i+1 >= n) break;
        else if(q[i] == i+1) {
        	cout<<"1. "<<bribes<<endl;
        	i++;
        }
        else {
            diff = q[i] - (i+1);
            if(diff > 2) {
                cout<<"Too chaotic"<<endl;
                return;
            }
            else if(q[i] == i+diff+1 && q[i] > q[i+diff]) {
            	if(q[i+1] == i+1) {
            		swap(q[i], q[i+1]);
            		bribes++;
            		i++;
            		cout<<"2. "<<bribes<<endl;
            	} 
            	// if the value that should be at the ith index is present at pointer end,
            	// then swap the values
            	else if((i+1) == q[end]) {
        			swap(q[i], q[end]);
        			bribes += diff;
        			i++;
        			cout<<"3. "<<bribes<<endl;
        		}
            } else {
            	// swapping the value until it reaches at its required index
	            number_of_swaps = diff;
	            start = i;
	            while(number_of_swaps-- && start < n-1) {
	                if(q[start] > q[start + 1]) {
	                    swap(q[start], q[start+1]);
	                    bribes++;
	                }
	                if((start+1) == q[end]) {
        				swap(q[start], q[end]);
        				bribes++;
	                }
	                start++;
	            }
	            cout<<"6. "<<bribes<<endl;
	            i++;
        	}
        }
    }

    for(int num : q) {
    	cout<<num<<" ";
    }
    cout<<endl;
    cout<<bribes<<endl;
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
		vector<int>queue(n);
		for(int i = 0; i < n; i++) cin>>queue[i];
		minimumBribes(queue);
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}