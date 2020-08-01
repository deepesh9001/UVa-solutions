#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tests;
	cin >> tests;

	
	while(tests-->0){
		
		int people, tree;
		cin >> people >> tree;

		vector<set<int>> adj(people+1);

		cin.ignore();

		string str;
		while(getline(cin, str) and str.length() > 0){
			stringstream ss;
			ss << str;
			int a, b;
			ss >> a >> b;

			adj[a].insert(b);
		}

		map<set<int>, int> m;
		FOR(i, 1, people+1){
			
			m[adj[i]]++;
		}

		cout<<m.size()<<'\n';
		if(tests > 0)
		cout<<'\n';
		
	}
	
}