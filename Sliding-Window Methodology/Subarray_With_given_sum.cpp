#include <bits/stdc++.h>

using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,sum;
	    cin>>n>>sum;
	    int arr[n];
	    int currsum=0,last=0,start=0;
	    bool flag=false;
	    for(int j=0;j<n;j++){
	        cin>>arr[j];
	    }
	    for(int k=0;k<n;k++){
	       currsum +=arr[k];
	       
	       if(currsum>=sum){
	            last = k;
	            while(currsum>sum && start<last){
	                currsum-=arr[start];
	                start++;
	            }
	            if(currsum == sum){
	                cout<<start+1<<" "<<last+1<<endl;
	                flag=true;
	                break;
	            }
	        }
	    }
	    if(flag==false){
	        cout<< -1<<endl;
	    }
	    
	}
	
	return 0;
}