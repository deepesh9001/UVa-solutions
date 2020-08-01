#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int caseNo;
	si(caseNo);
	REP(i,caseNo){
		int n;
		si(n);

		int last, lowJ = 0, highJ = 0;
		si(last);
		while(n-->1){
			int a;
			si(a);

			if(a > last) highJ++;
			else if( a < last) lowJ++;

			last = a;
		}

		cout<<"case "<<i+1<<": "<<highJ <<" "<<lowJ<<"\n";
	}
}