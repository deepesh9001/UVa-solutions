#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int n, m, p;

	REP(c, 1e9){
		cin>>n>>m>>p;
		if(n==0 and m == 0 and p == 0) break;

		vector<int> ni(n);
		REP(i, n) cin>>ni[i];

		bool state[25];
		memset(state, false, sizeof state);

		int Power = 0, max = 0;
		bool flag = false;

		REP(i, m){
			int a;
			cin>>a;

			if(state[a]) state[a] = false;
			else state[a] = true;

			if(state[a]) Power += ni[a-1];
			else Power -= ni[a-1];

			if(Power > p) flag = true;
			if(Power > max) max = Power;

		}

		cout<<"Sequence "<<c+1<<'\n'<<"Fuse was ";
		if(!flag) cout << "not ";
		cout<<"blown.\n";
		if(!flag) cout<<"Maximum power consumption was "<<max;
		if(max > 1)cout<<" amperes.\n";
		else cout<<" ampere.\n";

	}
}