#include <bits/stdc++.h>
using namespace std;

int MIN_MONEY(int price[], int n, int w, int idx){

	if (idx == n){
		return 0;
	}

	int ans = INT_MAX;

	if (idx <= w){
		ans = min(ans, price[idx] + MIN_MONEY(price,n,w-idx, idx+1));
	}

	ans = min(ans, MIN_MONEY(price,n,w, idx+1));

	return ans;
}

int main(int argc, char const *argv[])
{
	int n,w;
	cin>>n>>w;

	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}

	cout<<MIN_MONEY(arr, n, w, 0)<<endl;
	return 0;
}