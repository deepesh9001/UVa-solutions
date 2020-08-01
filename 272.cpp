#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	string output_string;

	string str;

	int i = 0;
	while(getline(cin, str, '\n')){
		for(auto x : str){
			if(x == '\"') output_string.push_back('`');
			if (x == '\'' || x=='\"') output_string.push_back('`');
			else output_string.push_back(x);
		}
		output_string.push_back('\n');
	}

	cout << output_string;
}