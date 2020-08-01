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

	int a;
	while(si(a) == 1){
		vector<int> v(a);
		REP(i, a) cin>>v[i];

		vector<bool> b(a);
		REP(i, a-1) b[abs(v[i+1] - v[i])] = true;

		bool flag = false;
		FOR(i, 1, a) if(!b[i]) flag = true;

		if(flag) cout<<"Not jolly\n";
		else cout<<"Jolly\n";
	}
    
}