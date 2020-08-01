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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	
	while(1){
		string str;
		cin>>str;

		if(str[0] == '#') break;

		int q_num, period;
		cin>>q_num>>period;

		REP(i, 10000) pq.push(make_pair((i+1)*period, q_num));
		
	}

	int n;
	cin>>n;
	REP(i, n){
		cout<<pq.top().second<<'\n';
		pq.pop();
	}
}