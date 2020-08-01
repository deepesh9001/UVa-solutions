#include<iostream>
using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	while(n-->0){
		int a;
		cin>>a;
		int ans = (((a*63 + 7492)*5 - 498)%100)/10;
		ans = (ans > 0) ? ans : -1*ans;
		cout<<ans<<'\n';
	}
}