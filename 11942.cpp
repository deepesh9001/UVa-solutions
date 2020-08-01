#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int caseNo;
	si(caseNo);

	printf("Lumberjacks:\n");

	while(caseNo-->0){
		int first; si(first);

		bool flag1 = true, flag2 = true;
		REP(i, 9) {
			int a; si(a);
			if(first > a) flag1 = false;
			if(a > first) flag2 = false;
		}

		if(flag1 or flag2) printf("Ordered\n");
		else printf("Unordered\n");
	}
}