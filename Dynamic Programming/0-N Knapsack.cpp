#include <bits/stdc++.h>
using namespace std;

int Nknapsack(int size[], int value[], int capacity, int n){

	int ans[capacity+1] = {0};

	for (int i = 0; i <= capacity; ++i){
		for (int j = 0; j < n; ++j){
			if (size[j]<=i){
				ans[i] = max(ans[i], value[j]+ans[i-size[j]]);
			}
		}
	}
	return ans[capacity];
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

	cout<<Nknapsack(size,value,capacity,n)<<endl;
	return 0;
}