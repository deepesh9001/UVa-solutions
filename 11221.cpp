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



bool magic(char** arr, int n){
	vector<string> strs(n);

	REP(i,n){
		strs[i] = arr[i];
	}

	REP(i, n) REP(j,n){
		if(arr[i][j] != arr[j][i]) return false;
		if(arr[i][j] != arr[n-1-j][n-1-i]) return false;
		if(arr[i][j] != arr[n-1-i][n-1-j]) return false;
	}
	return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int z;
	cin>>z;
	cin.ignore();
	while(z-->0){
		cout<<"Case #"<<caseNo++<<":\n";
		string str;
		getline(cin, str, '\n');

		string s = "";
		REP(i, str.length()){
			if(str[i] >= 'a' and str[i] <= 'z') s += str[i];
		}

		int l = s.length();
		int n = sqrt(l);
		if( n * n != l) {
			cout<< "No magic :(\n";
			continue;
		}

		char** square = new char*[n];
		REP(i,n) square[i] = new char[n];

		REP(i, n) REP(j, n) square[i][j] = s[i*n + j%n];

		if(magic(square, n)) cout<<n<<'\n';
		else cout<< "No magic :(\n";

	}
	
	
}