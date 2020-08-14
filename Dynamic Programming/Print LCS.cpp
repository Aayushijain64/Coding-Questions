#include <bits/stdc++.h>
using namespace std;

int counter;
// int LCS(string s1, string s2){

// 	counter++;
// 	if (s1.length()==0 or s2.length()==0){
// 		return 0;
// 	}

// 	int ans = 0;
// 	char ch1 = s1[0];
// 	char ch2 = s2[0];
// 	string ros1 = s1.substr(1);
// 	string ros2 = s2.substr(1);

// 	if (ch1 == ch2){
// 		ans = 1 + LCS(ros1, ros2);
// 	}else{
// 		int q1 = LCS(s1, ros2);
// 		int q2 = LCS(ros1, s2);
// 		ans = max(q1,q2);
// 	}

// 	return ans;
// }

// int LCS_memo(string s1, string s2, int memo[][100]){

// 	counter++;
// 	int i = s1.length();
// 	int j = s2.length();
// 	if (i==0 or j==0){
// 		return 0;
// 	}

// 	if (memo[i][j] != -1){
// 		return memo[i][j];
// 	}

// 	int ans = 0;
// 	char ch1 = s1[0];
// 	char ch2 = s2[0];
// 	string ros1 = s1.substr(1);
// 	string ros2 = s2.substr(1);

// 	if (ch1 == ch2){
// 		ans = 1 + LCS_memo(ros1, ros2, memo);
// 	}else{
// 		int q1 = LCS_memo(s1, ros2, memo);
// 		int q2 = LCS_memo(ros1, s2, memo);
// 		ans = max(q1,q2);
// 	}

// 	memo[i][j] = ans;

// 	for (int r = 0; r <= 8; ++r){
// 		for (int s = 0; s <= 6 ; ++s){
// 			if (memo[r][s] == -1)
// 			{
// 				cout<<"* ";
// 			}else{
// 				cout<<memo[r][s]<<" ";
// 			}
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"*******************************"<<endl;
// 	return memo[i][j];
// }

int pure_DP(string s1, string s2){
	int row = s1.length()+1;
	int col = s2.length()+1;
	int dp[row][col] = {0};
	string ans = "";

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			
			if (i==0 or j==0){
				dp[i][j] = 0;
				continue;
			}

			if (s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			
		}
	}

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col ; ++j){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	int i = row, j = col;
	while (i > 0 && j > 0){
		if (s1[i-1] == s2[j-1]){
			ans = s1[i-1] + ans;
			i--;
			j--;
		}
		else if (dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}

	cout<<ans<<endl;
	return dp[0][0];
}

int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	int row = s1.length()+1;
	int col = s2.length()+1;

	// int memo[row][100];
	// for (int i = 0; i < row; ++i){
	// 	for (int j = 0; j < col ; ++j){
	// 		memo[i][j] = -1;
	// 	}
	// }
	// counter = 0;
	// int ans = LCS(s1,s2);
	// cout<<"Recursion "<<ans<<" "<<counter<<endl;
	// counter = 0;
	// cout<<"Recursion_memo "<<LCS_memo(s1,s2,memo)<<" "<<counter<<endl;
	cout<<pure_DP(s1,s2);
	return 0;
}