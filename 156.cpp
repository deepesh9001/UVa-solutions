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

bool pred(pair<string, int> a, pair<string, int> b){
	if(a.first == b.first) return true;
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	vector<string> dict;

    string str;
	while(getline(cin, str) and str != "#"){
		stringstream sin;
		sin << str;

		string in;
		while(sin >> in){
			dict.push_back(in);
		}
	}


	vector<string> copy(dict.begin(), dict.end());

	REP(i, copy.size()){
		REP(j, copy[i].length()){
			if(copy[i][j] >= 'A' and copy[i][j] <= 'Z') copy[i][j] += ' ';
		}
		sort(copy[i].begin(), copy[i].end());
	}
	
	unordered_map<string, pair<int, int>> m;

	REP(i, copy.size()){
		m[copy[i]].first++;
		m[copy[i]].second = i;
	}

	copy.clear();
	for(auto x : m){
		if(x.second.first == 1){
			copy.push_back(dict[x.second.second]);
		}
	}

	sort(copy.begin(), copy.end());
	REP(i, copy.size()) cout<<copy[i]<<'\n';

}