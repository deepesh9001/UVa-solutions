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

vector<string> rotate90(vector<string> s){
	int n = s[0].size();
	vector<string> ans(n);

	REP(i, n) REP(j, n) ans[i].push_back(s[n-1-j][i]);
	
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(1){
		int N, n;
		cin>>N>>n;

		if(N == 0 or n == 0) break;

		vector<string> badaBox(N);
		vector<string> chotaBox(N);

		cin.ignore();

		REP(i, N){
			cin>>badaBox[i];
		}

		REP(i, n){
			cin>>chotaBox[i];
		}

		vector<string> lcBox = rotate90(chotaBox);
		vector<string> ucBox = rotate90(lcBox);
		vector<string> rcBox = rotate90(ucBox);

		int *ans = new int[4];

		REP(i, N -n+1){
			REP(j, N -n+1){
				bool flagc = false;
				bool flagu = false;
				bool flagl = false;
				bool flagr = false;
				
				REP(k, n){
					if(chotaBox[k] != badaBox[i+k].substr(j,2)){
						flagc = true;
					}
					if(lcBox[k] != badaBox[i+k].substr(j,2)){
						flagl = true;
					}
					if(ucBox[k] != badaBox[i+k].substr(j,2)){
						flagu = true;
					}
					if(rcBox[k] != badaBox[i+k].substr(j,2)){
						flagr = true;
					}
					
				}
				if(!flagc) ans[0]++;
				if(!flagl) ans[1]++;
				if(!flagu) ans[2]++;
				if(!flagr) ans[3]++;
				
			}
		}
		
		REP(i, 4) cout<<ans[i]<<' ';
		cout<<'\n';
	}
    
}