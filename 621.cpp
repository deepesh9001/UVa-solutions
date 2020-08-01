#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n-->0){
		string str;
		cin>>str;

		if(str == "1" || str == "4" || str == "78") cout<<"+\n";
		else if(str[str.length()-1] == '5' and str[str.length()-2] == '3') cout<<"-\n";
		else if(str[0] == '9' and str[str.length()-1] == '4') cout<<"*\n";
		else if(str[0] == '1' and str[1] == '9' and str[2] == '0') cout<<"?\n";
		else cout<<"moo\n";
	}
}