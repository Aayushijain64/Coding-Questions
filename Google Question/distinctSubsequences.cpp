//https://www.interviewbit.com/problems/distinct-subsequences/
#define ll long long int
const ll n=7e2+3;
ll dp[n][n];
ll go(string &a,string &b,ll i=0,ll j=0)
{
if(dp[i][j]!=-1)
    return dp[i][j];
if(j==b.length())
    return 1;
if(i==a.length())
    return 0;
if(a[i]!=b[j])
    return dp[i][j]=go(a,b,i+1,j);
else
    return dp[i][j]=go(a,b,i+1,j+1)+go(a,b,i+1,j);
}

int Solution::numDistinct(string A, string B) {
memset(dp,-1,sizeof(dp));
return (A==B)?1:go(A,B);
}