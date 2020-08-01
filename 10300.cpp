#include <iostream>

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	while(n-->0){
		int f;
		cin>>f;

		int sum = 0;

		while(f-->0){
			int a, b, c;
			cin>>a>>b>>c;

			sum += a*c;
		}

		cout<<sum<<'\n';
	}
}