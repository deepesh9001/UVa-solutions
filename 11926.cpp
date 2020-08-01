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

	while(1){
		int n, m;
		si(n), si(m);

		if(n == 0 and m == 0) break;

		string ans = "NO CONFLICT\n";

		vector<pair<int, int>> s;
		REP(i, n){
			int a, b;
			scanf("%d %d", &a, &b);

			REP(j, s.size()){
				if((s[j].first < a and s[j].second > a) or (s[j].first < b and s[j].second > b)){
					ans = "CONFLICT\n";
				}
				break;
			}

			s.push_back({a,b});
		}

		REP(i, m){
			int a, b, r;
			scanf("%d %d %d", &a, &b, &r);

			while(a < 1000000){
				REP(j, s.size()){
					if((s[j].first < a and s[j].second > a) or (s[j].first < b and s[j].second > b)){
						ans = "CONFLICT\n";
						break;
					}
				}
				s.push_back({a,b});
				a += r;
				b += r;
			}
		}

		cout<<ans;
	}
}