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
		multiset<int> s;
		int cost = 0;
		REP(i, n){
			int b;
			cin>>b;
			REP(j, b){
				int a;
				cin>>a;

				s.insert(a);
			}
			auto low = s.begin();
			auto high = s.end();
			high--;

			s.erase(high);
			s.erase(low);
			cost += *high - *low;
		}
		cout<<cost<<'\n';
	}
}