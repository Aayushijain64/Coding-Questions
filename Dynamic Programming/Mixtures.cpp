#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int s, int e){
	int sum = 0;

	for (int i = s; i <= e; ++i){
		sum += arr[i];
		sum %= 100;
	}

	return sum;
}

int memo[101][101];

int mixture(int arr[], int s, int e){

	if (s>=e){
		return 0;
	}

	if (memo[s][e]!=-1){
		return memo[s][e];
	}

	int ans = INT_MAX;

	for (int i = s; i < e; ++i){
		ans = min(ans, mixture(arr,s,i) + mixture(arr, i+1, e) + sum(arr,s,i)*sum(arr,i+1,e));
	}
	memo[s][e] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			memo[i][j] = -1;
		}
	}

	cout<<mixture(arr,0,n-1)<<endl;
	return 0;
}