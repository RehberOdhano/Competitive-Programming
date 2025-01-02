// LeetCode Problem 1013: Partition Array Into Three Parts With Equal Sum

#include<iostream>
#include<vector>
using namespace std;

bool canThreePartsEqualSum(vector<int>& arr) {
	int i = 0, k = arr.size() - 1;
	int partOneSum = arr[i], partTwoSum = arr[k], partThreeSum = 0;

	int arrSum = 0;
	for(int num : arr) arrSum += num;

	if(arrSum % 3 != 0) return false;

	int eachPartValue = arrSum / 3;
	int j;
	bool flag = false;

	while(i < k) {
		if(partOneSum < partTwoSum && arr[i] != eachPartValue) {
			i++;
			partOneSum += arr[i];
		} else if(partOneSum > partTwoSum && arr[k] != eachPartValue) {
			k--;
			partTwoSum += arr[k];
		} else if(arr[i] == eachPartValue) {
			j = i + 1;
			partOneSum = partTwoSum = arr[i];
			break;
		} else if(arr[k] == eachPartValue) {
			j = k - 1;
			partOneSum = partTwoSum = arr[k];
			break;
		} else if(partOneSum == partTwoSum) {
			j = i + 1;
			flag = true;
			break;
		}
	}

	if(flag) {
		while(j < k) {
			if(arr[j] != eachPartValue) {
				partThreeSum += arr[j];
			}
			j++;
		}
	} else {
		if(j > i) {
			while(j >= i) {
				if(arr[j] != eachPartValue) {
					partThreeSum += arr[j];
				}
				j--;
			}
		} else if(j < k) {
			while(j <= k) {
				if(arr[j] != eachPartValue) {
					partThreeSum += arr[j];
				}
				j++;
			}
		}
	}

	cout<<i<<" | "<<j<<" | "<<k<<endl;
	cout<<partOneSum<<" | "<<partTwoSum<<" | "<<partThreeSum<<endl;

	if(partOneSum == partTwoSum && partTwoSum == partThreeSum) return true;

	return false;
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
		canThreePartsEqualSum(numbers) ? cout<<"true" : cout<<"false";
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE
    	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	#endif

	return 0;
}