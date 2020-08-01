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
	while(si(n) == 1){
		vector<int> v(n);
		REP(i, n)  cin>>v[i];
		
		sort(v.begin(), v.end());

		map<int, vector<int>> m;

		FOR(i, v[0], v[v.size()-1]+1){
			int ab = 0;
			REP(j, v.size()){
				ab += abs(i-v[j]);
			}
			m[ab].push_back(i);
		}

		int count = 0;

		REP(i, n){
			REP(j, m.begin()->second.size()){
				if(v[i] == m.begin()->second[j]) count++;
			}
		}

		cout<<m.begin()->second[0]<<' '<<count<<' '<<m.begin()->second.size()<<'\n';

	}
    
}