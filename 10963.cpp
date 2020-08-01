#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int n;
	si(n);

	while(n-->0){
		cin.ignore();
		int w;
		si(w);

		int temp = 0;
		bool flag = false;

		while(w-->0){
			int a, b;
			si(a),si(b);

			if(temp == 0) temp = a-b;
			else if(temp != a-b) flag = true;
		}

		if(flag) cout<<"no\n";
		else cout<<"yes\n";
	}
}