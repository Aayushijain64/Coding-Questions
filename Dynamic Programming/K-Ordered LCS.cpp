#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001][6] = {0};
int K_orderedLCS(int arr1[], int arr2[], int n, int m, int i, int j, int k){

	if (i==n or j==m){
		return 0;
	}

	if (dp[i][j][k] != -1){
		return dp[i][j][k];
	}

	int ans = 0;
	if (arr1[i] == arr2[j]){
		ans = 1 + K_orderedLCS(arr1,arr2,n,m,i+1,j+1,k);
	}else{
		if (k>0){
			ans = 1 + K_orderedLCS(arr1,arr2,n,m,i+1,j+1,k-1);
		}

		ans = max(ans,max(K_orderedLCS(arr1,arr2,n,m,i+1,j,k),K_orderedLCS(arr1,arr2,n,m,i,j+1,k)));
	}

	dp[i][j][k] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	int arr1[n],arr2[m];

	for (int i = 0; i < n; ++i){
		cin>>arr1[i];
	}
	for (int i = 0; i < m; ++i){
		cin>>arr2[i];
	}

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			for (int l = 0; l <=k ; ++l){
				dp[i][j][l] = -1;
			}
		}
	}

	cout<<K_orderedLCS(arr1,arr2,n,m,0,0,k)<<endl;
	return 0;
}