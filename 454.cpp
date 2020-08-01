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

    int cases;
	cin>>cases;

	cin.ignore();
	
	while(cases-->0){
		cin.ignore();
		vector<string> dict;
		REP(i, 101){
			string str;
			getline(cin, str,'\n'); 
			if(str.length()==0) break;
			dict.push_back(str);
		}
		sort(dict.begin(), dict.end());
		vector<string> ans(dict.begin(), dict.end());
		map<string, vector<int>> m;

		REP(i, ans.size()){
			stringstream sin;
			sin << ans[i];

			string in, wstr;
			while(sin >> in) wstr += in;

			sort(wstr.begin(), wstr.end());

			m[wstr].push_back(i);
		}

		for(auto x : m){
			REP(i, x.second.size() -1){
				FOR(j, i+1, x.second.size()){
					cout<<dict[x.second[i]]<<" = "<<dict[x.second[j]]<<'\n';
				}
			}
		}

		// REP(i, ans.size()) cout<<ans[i]<<'\n';
	}
}