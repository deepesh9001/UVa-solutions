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

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

pair<long, bool> isPalNum(long num){
	long rev = 0;
	long n = num;

	while(n > 0){
		rev *= 10;
		rev += n%10;
		n/=10;
	}

	if(num == rev) return {num, true};
	else return {num + rev, false};
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	si(n);
	while(n-->0){
		long num;
		cin>>num;

		long ans = 0;
		pair<long, bool> res;
		res.first = num;

		while(1){
			res = isPalNum(res.first);
			if(res.second) break;
			ans++;
		}
		cout<<ans <<" "<< res.first<<'\n';
	}	
}