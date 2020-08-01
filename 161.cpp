#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag1 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	vector<int> remains;
    while (1)
	{
		bool flag = false;
		
		vector<int> val(remains.begin(), remains.end());
		remains.clear();
		while(1){
			string str;
			getline(cin, str);
			if(str == "0 0 0") {
				flag = true;
				break;
			}

			stringstream sin;
			sin<<str;

			int a;
			bool flag2 = false;
			while(sin >> a){
				if(a == 0) {
					flag2 = true;
					continue;
				}
				if(flag2) remains.push_back(a);
				else val.push_back(a);
			}
			if(flag2) break;


		}
		if(flag) break;

		vector<vector<char>> lights(val.size());
	
		int min = 100;
		REP(i, val.size()) {
			lights[i].resize(2*val[i],'Q');
			REP(j, 2*val[i]){
				if(j < val[i] - 5) lights[i][j] = 'G';
				else if(j >= val[i] - 5 and j < val[i]) lights[i][j] = 'O';
				else lights[i][j] = 'R';
			}
			if(val[i] < min) min = val[i];
		}

		bool flag4 = false;
		FOR(i, min-5, 18001){
			bool flag3 = false;
			REP(j, val.size()){
				if(lights[j][i%(2*val[j])] != 'G') flag3 = true;
			}
			if(!flag3){
				flag4 = true;
				int minute = ((i/60)%60);
				cout<<setw(2)<<setfill('0')<<i/36000<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<(i%60)<<'\n';
				break;
			}
		}

		if(!flag4) cout<<"Signals fail to synchronise in 5 hours\n";
	}
}