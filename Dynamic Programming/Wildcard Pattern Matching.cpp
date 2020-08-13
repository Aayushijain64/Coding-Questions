#include <bits/stdc++.h>
using namespace std;

bool max_gold(string s1, string pattern){

	int i=0;
	int j=0;
	while(i<s1.length() or j < pattern.length()){

		if (s1[i] == pattern[j])
		{
			i++;
			j++;
		}else if(pattern[j] == '?'){
			i++;
			j++;
		}else if(pattern[j] == '*'){
			while(s1[i+1] != pattern[j+1]){
				i++;
			}
		}else{
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	string s1,pattern;
	cin>>s1>>pattern;
	cout<<max_gold(s1,pattern);
	return 0;
}