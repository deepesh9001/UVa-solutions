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
		cin>>n;

		if(n == 0) break;

		while(1){

			stack<int> s;
			int a;
			REP(i, n){
				cin>>a;
				s.push(a);
				if(a == 0) break;
			}

			if(a == 0) break;

			stack<int> u;
			
			REP(j, n){
				if(j+1 == s.top()){
					s.pop();
				}
				else{
					u.push(j+1);
				}
			}

			if(u.size() > 0) while(u.top() == s.top()){
				s.pop();
				u.pop();
				if(s.size() == 0) break;
			}

			if(u.size() == 0) cout<<"Yes\n";
			else cout<<"No\n";
		}

		cout<<'\n';
	}
}