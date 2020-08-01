#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int go(int n, int m){
	if(n == 1 || m == 1) return max(n,m);

	if(n == 2 || m == 2){
		int c = (max(m, n) / 4) * 4;

		if(max(n,m)%4 == 1) c += 2;
		else if(max(m,n)%4 > 1) c+=4;

		return c;

	}
	else return (m*n+1)/2;
	
}

int main(){
	freopen("in.txt", "r", stdin);
	
	int n, m;
	while(cin>>n>>m){
		if(n == 0 and m == 0) break;

		cout<<go(n, m)<<" may be placed on a "<<n<<" row "<<m<<" column board.\n";
	}
	
	
	
}