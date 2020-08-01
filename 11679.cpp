#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	
	while(1){
		int b, n;
		scanf("%d%d", &b,&n);

		if(b == 0 and n == 0) break;
		
		vector<int> val(b+1);
		
		REP(i,b) cin>>val[i+1];
		
		int d,c,r;
		REP(i,n) cin>>d>>c>>r, val[d] -= r, val[c] += r;
		
		bool flag = false;
		REP(i,b) if(val[i+1]<0) flag = true;
		
		if(flag) cout<<"N\n";
		else cout<<"S\n";
	}
}