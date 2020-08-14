#include <bits/stdc++.h>
using namespace std;

// int LCS(string s1, string s2,string s3){

// 	if (s1.length()==0 or s2.length()==0 or s3.length()==0)
// 	{
// 		return 0;
// 	}

// 	int count = 0;
// 	char ch1=s1[0],ch2=s2[0],ch3=s3[0];
// 	string ros1 = s1.substr(1),ros2=s2.substr(1),ros3=s3.substr(1);

// 	if (ch1==ch2 and ch1==ch3)
// 	{
// 		count = 1 + LCS(ros1,ros2,ros3);
// 	}else{
// 		int q1 = LCS(ros1,s2,s3);
// 		int q2 = LCS(s1,ros2,s3);
// 		int q3 = LCS(s1,s2,ros3);
// 		count = max(q1,max(q2,q3));
// 	}

// 	return count;
// }

int LCS(string s1, string s2,string s3){

	int row = s1.length()+1;
	int col = s2.length()+1;
	int channel = s3.length()+1;

	int dp[row][col][channel] = {0};

	for (int i = 1; i < row; ++i){
		for (int j = 1; j < col; ++j){
			for (int k = 1; k < channel; ++k){
				
				if (s1[i-1]==s2[j-1] and s1[i-1]==s3[k-1]){
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				}else{
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[row-1][col-1][channel-1];
}


int main(int argc, char const *argv[])
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	cout<<LCS(s1,s2,s3)<<endl;
	return 0;
}