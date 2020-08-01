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
	
	int n, m;
	cin>>n>>m;

	int wall;
	cin>>wall;

	int nBumpers;
	cin>>nBumpers;

	pair<int, int> bumpers[m+1][n+1];

	//memset(bumpers, {0,0}, sizeof bumpers);

	REP(i, nBumpers){
		int a, b;
		cin>>a>>b;
		cin>>bumpers[a][b].first>>bumpers[a][b].second;
	}

	int total = 0;

	int x, y, dir, life;
	while(scanf("%d%d%d%d", &x, &y, &dir, &life) == 4){
		int cost = 0;
		if(life == 1){
			cout<<"0\n";
			continue;
		}

		while(life-->0){
			switch (dir)
			{
			case 0:
				x++;
				if(life > 0){
					if(x == m) dir += 3, dir%= 4, x--, cost += wall;
					else if(bumpers[x][y].first > 0) {
						dir += 3, dir%= 4, life -= bumpers[x][y].second;
						if(life > 0)
							cost += bumpers[x][y].first;
						x--;
					}
				}
				break;
			case 1:
				y++;
				if(life > 0){
					if(y == n) dir += 3, dir%= 4, y--, cost += wall;
					else if(bumpers[x][y].first > 0) {
						dir += 3, dir%= 4, life -= bumpers[x][y].second;
						if(life > 0)
							cost += bumpers[x][y].first;
						y--;
					}
				}
				break;
			case 2:
				x--;
				if(life > 0){
					if(x == 1) dir += 3, dir%= 4, x++, cost += wall;
					else if(bumpers[x][y].first > 0) {
						dir += 3, dir%= 4, life -= bumpers[x][y].second;
						if(life > 0)
							cost += bumpers[x][y].first;
						x++;
					}
				}
				break;
			case 3:
				y--;
				if(life > 0){
					if(y == 1) dir += 3, dir%= 4, y++, cost += wall;
					else if(bumpers[x][y].first > 0) {
						dir += 3, dir%= 4, life -= bumpers[x][y].second;
						if(life > 0)
							cost += bumpers[x][y].first;
						y++;
					}
				}
				break;			
			default:
				break;
			}
		}
		cout<<cost<<'\n';
		total += cost;
	}
	cout<<total<<'\n';
	
	
}