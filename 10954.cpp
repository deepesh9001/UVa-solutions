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

		priority_queue<int, vector<int>, greater<int>> pq;
		REP(i, n){
			int a;
			cin>>a;
			pq.push(a);
		}

		int cost = 0;
		int temp = pq.top();
		pq.pop();
		while(!pq.empty()){
			cost += temp + pq.top();
			temp += pq.top();
			pq.pop();
		}

		cout<<cost<<'\n';

	}
	
}