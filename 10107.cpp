#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	set<int> v;
	long long n;
	int i = 0;
    while(sll(n) == 1){
		i++;
		v.insert(n);
		set<int>::iterator x = v.begin();
		if(i%2 == 0){
			advance(x,v.size()/2-1);
			int m = *x;
			advance(x, 1);
			m += *x;
			cout<<m/2<<'\n';
		}
		else{
			advance(x, i/2);
			cout<<*x<<'\n';
		}
	}
}