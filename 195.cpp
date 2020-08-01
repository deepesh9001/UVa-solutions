#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t_cases;
	cin>>t_cases;
	cin.ignore();
	while(t_cases-->0){
		string str;
		getline(cin, str);

		sort(str.begin(), str.end());
		set<string> s;

		do{
			cout<<str<<'\n';
			
		}while(next_permutation(str.begin(), str.end()));
	}

    
}