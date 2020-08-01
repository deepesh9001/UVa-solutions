#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int main(){
	freopen("in.txt", "r", stdin);

	while(1){
		bool taken[53];
		clr(taken);

		vector<int> v(5);
		REP(i, 5) cin>>v[i], taken[v[i]] = true;

		flag1 = false;
		REP(i, 5) if(v[i] != 0) flag1 = true;
		if(!flag1) break;
	
		sort(v.begin(), v.begin() + 3);

		flag1 = false;
		REP(i, 3) REP(j, 2) if(v[i] > v[3+j]) flag1 = true;
		if(!flag1) {
			REP(i,52){
				if(!taken[i+1]){
					cout<<i+1<<'\n';
					break;
				}
			}
			continue;
		}

		flag1 = false;
		REP(i, 2) REP(j, 2) if(v[i] > v[3+j]) flag1 = true;
		if(!flag1) {
			FOR(i, v[1], 53){
				if(!taken[i]){
					cout<<i<<'\n';
					break;
				}
			}
			continue;
		}

		flag1 = false;
		REP(i, 3) REP(j, 1) if(v[i] > v[4+j]) flag1 = true;
		if(!flag1) {
			FOR(i, v[2], 53){
				if(!taken[i]){
					cout<<i<<'\n';
					break;
				}
			}
			continue;
		}

		cout<<"-1\n";
	}
}