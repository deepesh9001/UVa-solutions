#include <iostream>
using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	while(n-->0){
		int a, b;
		cin>>a>>b;
		int ans = 0;
		if(a > 2) ans += a/3;
		else ans += 1;
		if(b > 2) ans *= b/3;
		cout<<ans <<'\n';
	}
}