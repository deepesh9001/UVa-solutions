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

int main(){
	freopen("in.txt", "r", stdin);
	
	int cases;
	si(cases);
	while(cases-->0){
		int n, ladder, c;
		cin>>n>>ladder>>c;

		vector<int> players(n, 1);
		vector<pair<int, int>> laddersOrSnakes(ladder);

		REP(i,ladder){
			cin>>laddersOrSnakes[i].first>>laddersOrSnakes[i].second;
		}

		REP(i, c){
			int roll;
			cin>>roll;

			players[i%n] += roll;
			REP(j, ladder){
				if(players[i%n] == laddersOrSnakes[j].first){
					players[i%n] = laddersOrSnakes[j].second;
				}
			}
		}

		REP(i, n) cout<<"Position of player "<<i+1<<" is "<<players[i]<<".\n";
	}
	
	
}