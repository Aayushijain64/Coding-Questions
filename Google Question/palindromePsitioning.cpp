https://www.interviewbit.com/problems/palindrome-partitioning-ii/
int dp[502];
bool check(string& a,int m,int k){  
    int i=m;
    int j=k;
    while(i<=k){
        if(a[i]!=a[k])
        return false;
        i++;
        k--;
    }
    return true;
}
int find(string& a,int i){
    if(i<0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int ans=INT_MAX;
    if(check(a,0,i))
        return 0;
    for(int k=i;k>=0;k--){
        if(check(a,k,i)){
            ans=min(ans,find(a,k-1));
        }
    }
    if(ans!=INT_MAX)
        ans++;
    dp[i]=ans;
    return ans;
}
int Solution::minCut(string A) {
for(int i=0;i<=A.size();i++)
    dp[i]=-1;
return find(A,A.size()-1);

}