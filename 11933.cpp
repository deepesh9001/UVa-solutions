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
		int n;
		si(n);

		if(n == 0) break;

		int a = 0, b = 0;
		bool flag = false;
		REP(i, 32){
			if(!flag and (n & (1<<i))) a += (n & (1<<i)), flag = true;
			else if(flag and (n & (1<<i))) b += (n & (1<<i)), flag = false;
			
		}

		cout<<a<<' '<<b<<'\n';
		
	}
}