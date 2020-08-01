#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	while(cin>>n and n > 0){
		map<vector<int>, int> m;
		vector<int> v(5);
		
		REP(j, n){
			REP(i, 5) cin>>v[i];
			sort(v.begin(), v.end());
			m[v]++;
		}

		int maximo = 0;
		for(auto x : m) if(x.second > maximo) maximo = x.second;

		int count = 0;
		for(auto x: m) if(x.second == maximo) count++;

		cout<<count*maximo<<'\n';
	}
}