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

int main(){
	freopen("in.txt", "r", stdin);
	
	int n, m;
	while(cin>>n>>m){
		if(n == 0 and m == 0) break;

		vector<int> arr(m);
		REP(i, m) cin>>arr[i];

		bool num[n+1];
		clr(num);

		REP(i, m-1) FOR(j, i+1, m){
			num[abs(arr[i] - arr[j])] = true;
		}

		flag2 = false;
		FOR(i, 1, n+1) if(!num[i]) flag2 = true;
	
		if(flag2) cout<<"N\n";
		else cout<<"Y\n";
	}
	
	
}