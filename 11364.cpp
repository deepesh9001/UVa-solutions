#include <iostream>
using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	while(n-->0){
		int a;
		cin>>a;
		int min = 1e9, max = 0;
		while(a-->0){
			int b;
			cin>>b; 
			min = (min > b) ? b : min;
			max = (b > max) ? b : max;
		}
		cout<<(max - min)*2<<'\n';
	}
}