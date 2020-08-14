#include <bits/stdc++.h>
using namespace std;

void No_ofString(int n){

	long int dp[n+1] = {0};
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; ++i){
		dp[i] = dp[i-1] + dp[i-2];
	}

	cout<<dp[n]<<endl;
	
	return;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		if (n == 0)
		{
			cout<<"0"<<endl;
		}else{
			No_ofString(n+2);
		}
	}
	return 0;
}