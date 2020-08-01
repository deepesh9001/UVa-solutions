#include <iostream>
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	std::cin>>n;
	while(n-->0){
		int a, b;
		std::cin>>a>>b;
		char ans;
		if(a > b) ans = '>';
		else if (a < b) ans = '<';
		else ans = '=';
		std::cout<<ans<<'\n';
	}
}