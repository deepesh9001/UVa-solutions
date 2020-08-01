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

	int t;
	si(t);

	while(t-->0){
		int n;
		si(n);

		map<char, int> m;
		REP(i, n) {
			char ch;
			cin>>ch;
			cin>>m[ch];
		}

		si(n);
		cin.ignore();
		int ans = 0;
		while(n-->0){
			string str;
			getline(cin, str);

			REP(i, str.length()) ans += m[str[i]];
		}
		printf("%.2f$\n",ans/100.);
	}
    
}