#include <bits/stdc++.h>
using namespace std;

// int memo[100001][100001] = {0};
int count1(int arr[], int n, int k, int idx){

	if (idx == n){
		return 0;
	}

	int count = 0;
	
	if (arr[idx]){
		count = 1 + count1(arr, n, k, idx+1);
	}else{

		if (k>0){
			count = 1 + count1(arr, n, k-1, idx+1);
		}

		count = max(count, count1(arr, n, k, idx+1));
	}
	
	return count;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}

	// for (int i = 0; i <= n; ++i){
	// 	for (int j = 0; j <= k; ++j){
	// 		memo[i][j] = -1;
	// 	}
	// }

	int idx=0;
	cout<<count1(arr,n,k,idx);
	return 0;
}