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

// implement using dfs
vector<vector<char>> ans;
int l1;

void go(string s1, string s2, vector<char> v, stack<char> u){
	
	int n1 = s1.length();
	int n2 = s2.length();

	if(n2 != n1 + u.size()) return;

	if(n2 == 0 and n1 == 0 and u.size() == 0){
		ans.push_back(v);
		return;
	}


	vector<char> tv = v;
	stack<char> tu = u;
	string str1 = "", str2 = "";

	int i = 0;
	if(tu.size() > 0) while(tu.top() == s2[i]){
		tu.pop();
		tv.push_back('o');
		i++;
		str2 = "";
		if(n2 > 1) str2 = s2.substr(1, n2 -1);
		go(s1, str2, tv, tu);
		if(tu.size() == 0) break;
	}

	u.push(s1[0]);
	v.push_back('i');

	str1 = "", str2 = "";
	if(n1 > 1) str1 = s1.substr(1, n1 -1);
	if(n2 > 1) str2 = s2.substr(1, n2 -1);
	go(str1, s2, v, u);

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(1){
		string str1, str2;
		getline(cin, str1);
		if(str1 == "") break;

		getline(cin, str2);

		vector<char> s;
		stack<char> u;

		l1 = 2*str1.length();

		ans.clear();

		go(str1, str2, s, u);

		sort(ans.begin(), ans.end());

		cout<<"[\n";
		REP(i, ans.size()){
			REP(j, ans[i].size()){
				cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
		cout<<"]\n";
	}
}