#include <iostream>
using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	while(1){
		int k;
		cin>>k;
		if(k == 0) break;
		int n, m;
		cin>>n>>m;
		while(k-->0){
			int a, b;
			cin>>a>>b;
			
			if(a == n || b == m) cout<<"divisa\n";
			else if(a>n and b>m) cout<<"NE\n";
			else if(a>n and b<m)cout<<"SE\n";
			else if(a<n and b<m) cout<<"SO\n";
			else cout<<"NO\n";
		}
	}
}