https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
int Solution::maximalRectangle(vector<vector<int> > &A) {
        int n=A.size(),m=A[0].size(),ans=0;
        vector<int>B(m,-1);
        for(int i=0;i<n;i++){
            vector<int>l(m,-1),r(m,m);
            for(int j=0;j<m;j++){
                if(A[i][j]==0)B[j]=i;
            }
            stack<int>s;
            for(int j=0;j<m;j++){
                while(s.empty()==0 and B[s.top()]<=B[j])s.pop();
                if(s.empty()==0)l[j]=s.top();
                s.push(j);
            }
            s=stack<int>();
            for(int j=m-1;j>-1;j--){
                while(s.empty()==0 and B[s.top()]<=B[j])s.pop();
                if(s.empty()==0)r[j]=s.top();
                s.push(j);
            }
            for(int j=0;j<m;j++)
                ans=max(ans,(r[j]-l[j]-1)*(i-B[j]));
        }
        return ans;
    }