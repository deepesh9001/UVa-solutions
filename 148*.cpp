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

vector<string> dict;
vector<vector<int>> dchar;
vector<int> letters(26);
set<string> s;
string test;

void dfs(int i, int len, string si){

	if(len < 0 || i == dict.size()) return;

	if(len == 0){
		int c_ar[26]; clr(c_ar);

		for(auto x: si) c_ar[x-'A']++;
		REP(i, 26) if(c_ar[i] != letters[i]) return; 

		cout<<test<<" = "<<si<<'\n';
		return;
	}

	FOR(k, i, dict.size()){
		if(s.find(dict[k]) != s.end()) continue;

		bool flag = false;
		REP(j, 26) if(dchar[k][j] > letters[j]) flag = true;
		
		if(!flag){
			if(si.length() != 0) 
				dfs(k+1, len - dict[k].length(), si+ " " + dict[k]);
			else dfs(k+1, len - dict[k].length(), dict[k]);
		}
	}

	return;
}


int main(){
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	string str;
	
	
	while(getline(cin, str, '\n') and str != "#"){
		dict.push_back(str);
	}

	
	REP(i, dict.size()) {
		vector<int> carr(26);
		for(char c : dict[i]) carr[c-'A']++;
		dchar.push_back(carr);
	}

	while(getline(cin, test, '\n') and test != "#"){

		stringstream sin;
		sin<<test;

		string in, wstr = "";
		while (sin >> in)  s.insert(in), wstr += in;

		REP(i, 26) letters[i] = 0;
		for(char c : wstr) letters[c-'A']++;

		string si = "";
		dfs(0, wstr.size(), si);
	
	}
}