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
	cin>>n;

	cin.ignore();
	cin.ignore();
	
	while(n-->0){


		map<string, int> m;

		string str;
		int total = 0;

		while(getline(cin, str) and str != "")  m[str]++, total++;

		for(auto x : m){
			cout<<x.first<<' ';
			printf("%.4f\n", x.second*100./total);
		}
		cout<<'\n';
		
	}
}