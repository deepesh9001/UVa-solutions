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

	int N, K;
	cin>>N >> K;
	cin.ignore();

	map<string, vector<int>> m;
	REP(i , N){
		string str, in;
		getline(cin, str);

		stringstream sin;
		sin<<str;
		sin>>in;
		
		vector<int> some;

		int a;
		while(sin>>a){
			some.push_back(a);
		}

		vector<int> Ci;
		Ci.push_back(some[1]);

		REP(i, some[2] -1){
			int cd = Ci.back()*(some[some.size()-1 -2*i] - some[some.size()-2 -2*i] +1);
			Ci.push_back(cd);
		}

		int ye = 0;
		REP(i, Ci.size()) ye += Ci[i]*some[some.size()-2-2*i];
		
		int c0 = some[0] - ye;
		Ci.push_back(c0);

		reverse(Ci.begin(), Ci.end());
		m[in] = Ci;
	}

	REP(i, K){
		string str, cname;
		vector<int> cval;
		getline(cin, str);

		stringstream sin;
		sin << str;
		sin >> cname;
		cout<<cname<<"[";

		int a;
		while(sin>>a){
			cval.push_back(a);
		}

		int ans = m[cname][0];
		REP(i, cval.size()){
			cout<<cval[i];
			if(i != cval.size()-1) cout<<", ";
			ans += cval[i]*m[cname][i+1];
		}

		cout<<"] "<<ans<<'\n';
	}
}