#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int n;
	while(si(n) == 1){
		unordered_map<string, int> names;

		REP(i, n) {
			string str;
			cin>>str;

			names[str] = 0;
		}

		REP(i, n){
			string str;
			cin >> str;

			int p, f;
			cin>>p>>f;

			if(f != 0) names[str] -= p - p%f;

			REP(j, f){
				string fname;
				cin>>fname;

				if(f != 0) names[fname] += p/f;
				
			}
		}

		
		stack<pair<string, int>> store;

		for(unordered_map<string, int>::iterator x = names.begin(); x != names.end(); x++ ){
			store.push(make_pair(x->first, x->second));
		}

		REP(i, n){
			pair<string, int> anspair = store.top();
			store.pop();
			cout<<anspair.first<<" "<<anspair.second<<'\n';
		}

		cout<<'\n';
	}

}