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
	cin>>n;
	while(n-->0){
		int p;
		cin>>p;
		
		map<int, int> s;
		int mx = 0;
		REP(i, p){
			int a;
			cin>>a;
			if(s[a] == 0) s[a] = i+1;
			else {
				if(s.size() > mx)  mx = s.size();
				stack<int> u;
				for(auto it = s.begin(); it != s.end(); ++it){
					if(it->second <= s[a]) u.push(it->first);
				}
				while(!u.empty()){
					s.erase(u.top());
					u.pop();
				}
				s[a] = i+1;
			}
		}

		cout<<mx<<'\n';
	}
}