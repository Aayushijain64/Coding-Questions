#include <bits/stdc++.h>
using namespace std;

// bool IsSum(int arr[], int n, int target, int idx, int sum){

// 	if (idx==n){
// 		if (sum == target){
// 			return true;
// 		}
// 		return false;
// 	}

// 	bool a = IsSum(arr,n,target,idx+1,sum);
// 	bool b = IsSum(arr,n,target,idx+1,sum+arr[idx]);

// 	return a or b;
// }

int main(int argc, char const *argv[])
{
	int n,target;
	cin>>n>>target;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}

	// if (IsSum(arr,n,target,0,0)){
	// 	cout<<"Yes"<<endl;
	// }else{
	// 	cout<<"No"<<endl;
	// }

	unordered_map<int, int> mp;
	mp[0]++;
	int sum = 0;
	for (int i = 0; i < n; ++i){
		sum += arr[i];
		mp[sum]++;
		if (mp.find(k-arr[i]) != mp.end()){
			cout<<"Yes"<<endl;
			exit(0);
		}
	}

	cout<<"No"<<endl;
	return 0;
}