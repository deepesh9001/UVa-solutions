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

bool check(vector<vector<int>> b){
	REP(i, 5){
		flag1 = false;
		flag2 = false;
		REP(j, 5){
			if(b[i][j] != -1) flag1 = true;
			if(b[j][i] != -1) flag2 = true;
		}
		if(!flag1 || !flag2) return true;
	}

	flag2 = false, flag1 = false;
	REP(i, 5){
		if(b[4-i][i] != -1) flag1 = true;
		if(b[i][i] != -1) flag2 = true;
	}
	if(!flag1 || !flag2) return true;

	return false;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	cin>>n;
	while(n-->0){
		vector<vector<int>> bingo(5,vector<int>(5 , -1));

		REP(i, 5) REP(j,5){
			if(i == 2 and j == 2) continue;
			cin>>bingo[i][j];
		}

		

		int ans;

		bool flag = false;

		REP(i, 75){
			int a;
			cin>>a;

			REP(i, 5) REP(j, 5) if(bingo[i][j] == a){
				bingo[i][j] = -1;
				break;
			}

			if(!flag){ 
				if(check(bingo)){
					ans = i+1; 
					flag = true;
				}
			}
		}

		cout<<"BINGO after "<<ans<<" numbers announced\n";
	}
	
	
	
}