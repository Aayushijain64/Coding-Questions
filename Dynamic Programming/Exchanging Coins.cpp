#include <bits/stdc++.h>
using namespace std;

long long max_gold(long long n){

	if (n<12){
		return n;
	}

	long long dp[n+1] = {0};

	for (int i = 0; i < 12; ++i){
		dp[i] = i;
	}

	for (long long i = 12; i <= n; ++i){
		dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
	}
	return dp[n];
}

int main()
{
	long long n;
	cin>>n;
	
	cout<<max_gold(n)<<endl;
	return 0;
}