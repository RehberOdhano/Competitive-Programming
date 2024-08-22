#include<bits/stdc++.h>
using namespace std;

#define SIZE 10e5

int solve(vector<int>&numbers, int n, int val) {
	vector<int>freqArr(SIZE, 0);
	for(int number : numbers) {
		freqArr[number]++;
	}

	if(freqArr[val] > 0) return 1;

	return -1;
}

void manipulateTheArray(vector<int>&numbers, int n, vector<vector<int>>&queries) {
	int numberOfQueries = queries.size();
	unordered_map<int,int>mp;

	// storing the elements in the vector 'numbers' and their respective
	// indices in a map where key is the element and the value is it
	// index
	for(int i = 0; i < n; i++) {
		mp[numbers[i]] = i;
	}	

	int queryType = 0;
	int isArrayReversed = 1;
	for(int i = 0; i < numberOfQueries; i++) {
		vector<int>queryArr = queries[i];
		queryType = queryArr[0];

		/*int x = 0, y = 0;
		int index1 = 0, index2 = 0;*/
		switch(queryType) {
			case 1:
				isArrayReversed *= -1;
				break;
			case 2:
				if(isArrayReversed == -1) cout<<(n - mp[queryArr[1]] - 1)<<endl;
				else cout<<mp[queryArr[1]]<<endl;
				break;		
			case 3: {
				int x = queryArr[1], y = queryArr[2];
				int index1 = x, index2 = y;
				if(isArrayReversed == -1) {
					x = n - x - 1;
					y = n - y - 1;	
				}

				x = numbers[x];
				y = numbers[y];

				swap(numbers[index1], numbers[index2]);
				swap(mp[x], mp[y]);
				break;
			}
			default:
				cout<<"Query type is invalid"<<endl;
				break;		
		}
	}
}

int main() {

	// FAST I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, n = 0, q = 0, val = 0;
	cin>>t;
	vector<int>indices(SIZE, -1);
	while(t--) {
		cin>>n;
		vector<int>numbers(n);
		for(int i = 0; i < n; i++) {
			cin>>numbers[i];
		}

		cin>>q;
		vector<vector<int>>queries;
		int queryType = 0, x = 0, y = 0;
		while(q--) {
			/*cin>>val;
			cout<<solve(numbers, n, val)<<endl;*/
			cin>>queryType;
			switch(queryType) {
				case 1:
					reverse(numbers.begin(), numbers.end());
					queries.push_back({1});
					break;
				case 2:
					cin>>x;
					queries.push_back({2, x});
					break;
				case 3:
					cin>>x>>y;
					queries.push_back({3, x, y});
					break;
				default:
					cout<<"Please enter a valid query type"<<endl;
					break;
			}
		}
		manipulateTheArray(numbers, n, queries);
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}