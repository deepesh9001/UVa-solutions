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

bool isValid(string s){
	REP(i, s.length() -1)  if(s[i+1] - s[i] <= 0) return false;
	return true;
}

string nextStr(string s){
	int n = s.length();
	int i = 0;
	s[n-1]++;
	while(s[n-1-i]> 'z'){
		s[n-1-i] = 'a';
		if(n -2 -i >= 0) s[n-2-i]++, i++;
		else s.push_back('a');
	}
	return s;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	map<string, int> m;

	string s = "a";
	int count = 1;
	while(s.length() < 6){
		if(isValid(s))  m[s] = count++;
		s = nextStr(s);
	}
	

	while(1){
		string str;
		getline(cin, str);

		if(str.length() == 0) break;

		cout<<m[str]<<'\n';
	}
}