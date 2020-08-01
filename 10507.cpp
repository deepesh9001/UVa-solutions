#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(1){

		string data;
		stringstream ss;

		getline(cin, data);
		
		if(data.length() == 0) break;
		ss.clear();
		ss << data;
		int n; ss >> n;

		getline(cin, data);
		ss.clear();
		ss << data;
		int m; ss >> m;

		string awake;
		getline(cin, awake);

		map<char, set<char>> connect;

		REP(reps, m){
			getline(cin, data);
			ss.clear();
			ss << data;

			char c1, c2;
			ss >> c1 >> c2;
			
			connect[c1].insert(c2);
			connect[c2].insert(c1);
			
		}

		int years = 0;
		string oneplus = awake;
		while(1){
			for(auto x: connect){
				if(awake.find(x.first) != -1) continue;
				int count = 0;
				REP(j, awake.length()){
					if(x.second.count(awake[j]) > 0) count++;
					if(count == 3) oneplus.push_back(x.first);
					
				}
			}
			if(awake.length() == oneplus.length()) break;
			awake = oneplus;
			years++;
		}

		if(oneplus.length() == n) cout<<"WAKE UP IN, "<<years<<", YEARS\n";
		else cout<<"THIS BRAIN NEVER WAKES UP\n";

		getline(cin, data);
	}



	
}