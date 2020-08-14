#include <bits/stdc++.h>
using namespace std;

long long memo[10000][10000];

long long  game(long long arr[], long long s, long long e){
	if (s>e){
		return 0;
	}

	if (memo[s][e] != -1){
		return memo[s][e];
	}

	long long ans = 0;

	long long q1 = arr[s] + min(game(arr,s+2,e),game(arr,s+1,e-1));
	long long q2 = arr[e] + min(game(arr,s+1,e-1),game(arr,s,e-2));

	ans = max(q1,q2);

	return memo[s][e] = ans;
}

int main()
{
	long long n;
	cin>>n;
	long long arr[n];

	for (long long i = 0; i < n; ++i){
		cin>>arr[i];
	}

	for (long long i = 0; i < n; ++i){
		for (long long j = 0; j < n; ++j){
			memo[i][j] = -1;
		}
	}

	cout<<game(arr,0,n-1)<<endl;
	return 0;
}