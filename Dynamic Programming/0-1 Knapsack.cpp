#include <bits/stdc++.h>
using namespace std;

// int memo[6][6]={0};
// int knapsack(int size[], int value[], int capacity, int n, int idx){
// 	if (idx==n){
// 		memo[idx+1][capacity+1]=0;		
// 		return 0;
// 	}

// 	if (memo[idx+1][capacity+1] != -1){
// 		return memo[idx+1][capacity+1];
// 	}

// 	int ans,include=0,exclude=0;

// 	if (size[idx] <= capacity){
// 		include = value[idx] + knapsack(size,value,capacity-size[idx],n,idx+1);
// 	}

// 	exclude = knapsack(size,value,capacity,n,idx+1);

// 	ans = max(include,exclude);

// 	memo[idx+1][capacity+1] = ans;

// 	for(int i=0;i<6;i++){
// 		for(int j=0;j<6;j++){
// 			if(memo[i][j]==-1){
// 				cout<<"* ";
// 			}
// 			else if(memo[i][j]==0){
// 				cout<<"0 ";
// 			}else{
// 				cout<<memo[i][j]<<" ";
// 			}
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"**************"<<endl;

// 	return ans;
// }

int knapsack(int size[], int value[], int capacity, int n){
	
	int dp[n+1][capacity+1] = {0};

	for (int i = 0; i < n+1; ++i){
		for (int j = 0; j < capacity+1; ++j){
			
			if (i==0 or j==0)
			{
				dp[i][j]=0;
				continue;
			}

			if (size[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-size[i-1]]);
			}
		}
	}

	return dp[n][capacity];
}

int main(int argc, char const *argv[])
{
	int n,capacity;
	cin>>n>>capacity;
	int size[n],value[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>size[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>value[i];
	}

	// for (int i = 0; i < 6; ++i){
	// 	for (int j = 0; j < 6; ++j){
	// 		memo[i][j] = -1;
	// 	}
	// }

	cout<<knapsack(size,value,capacity,n)<<endl;
	return 0;
}