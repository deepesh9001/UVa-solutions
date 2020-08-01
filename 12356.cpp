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
		int s, b;
		cin>>s>>b;
		
		if(s == 0 and b == 0) break;

		vector<pair<int, int>> sol;
		sol.push_back({1,s});

		REP(reps, b){
			int l, r;
			cin>>l>>r;

			int L, R;

			REP(i, sol.size()){
				if(sol[i].first < l and sol[i].second > r){
					sol.push_back({r+1, sol[i].second});
					sol[i].second = l -1;
					L = l -1;
					R = r +1;
					break;
				}
				else if(sol[i].first == l and sol[i].second == r){
					R = (i != sol.size() -1) ? sol[i+1].first : 0;
					L = (i != 0) ? sol[i-1].second : 0;

					FOR(j,i,sol.size()-1) sol[j] = sol[j+1];
					sol.pop_back();
					break;
				}
				else if(sol[i].first == l){
					L = (i != 0) ? sol[i-1].second : 0;
					R = r +1;

					sol[i].first = r+1;
					break;
				}
				else if(sol[i].second == r){
					R = (i != sol.size() -1) ? sol[i+1].first : 0;
					L = l -1;
					
					sol[i].second = l-1;
					break;
				}
			}
			sort(sol.begin(), sol.end());
			
			if(L == 0) cout<<"* ";
			else cout<<L<<' ';

			if(R == 0) cout<<"*\n";
			else cout<<R<<'\n';
		}
		cout << "-\n";
	}
    
}