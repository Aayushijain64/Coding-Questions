#include <bits/stdc++.h>
using namespace std;

set<string> s;
void SubSequence(string str, string ans){

	if (str.length() == 0){
		s.insert(ans);
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	SubSequence(ros, ans);
	SubSequence(ros, ans+ch);

	return;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		SubSequence(str,"");
		int count = 0;
		for(auto var:s){
			count++;
		}
		cout<<count<<endl;
		s.clear();
	}
	return 0;
}