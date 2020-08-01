#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	while(1){
		int n;
		si(n);

		if(n <= 0) break;

		while(n>9){
			int sum = 0;
			while(n > 0){
				sum += n%10;
				n/=10;
			}
			n = sum;
		}

		cout<<n<<'\n';
	}
}