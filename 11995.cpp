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

	int n;
	while(scanf("%d", &n) == 1){

		stack<int> s;
		priority_queue<int> pq;
		queue<int> q;

		int ans = 0;
		
		REP(i, n){
			int c, x;
			cin>>c>>x;

			if(c == 1){
				s.push(x);
				pq.push(x);
				q.push(x);
			}
			else{
				int bs = s.top();
				int bpq = pq.top();
				int bq = q.front();
				s.pop(), pq.pop(), q.pop();
				if(bs != x) ans |= (1<<0);
				if(bpq !=x) ans |= (1<<1);
				if(bq != x) ans |= (1<<2);
			}
		}

		if(ans == 1 || ans == 2 || ans == 4 || ans == 0) cout<<"not sure\n";
		else if(ans == 6) cout<<"stack\n";
		else if(ans == 5) cout<<"priority queue\n";
		else if(ans == 3) cout<<"queue\n";
		else if(ans == 7) cout<<"impossible\n";
		else cout<<"Ye kya hai?\n";
	}
}