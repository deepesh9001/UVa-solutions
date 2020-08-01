#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;


int main(){
	freopen("in.txt", "r", stdin);

	int l;
	cin>>l;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while(l-->0){
		string s;
		getline(cin, s, '\n');

		int m = 0, f = 0;
		for(auto x : s){
			if(x == 'M') m++;
			if(x == 'F') f++;
		}

		if(m != f) cout<<"NO ";
		cout<<"LOOP\n";
	}

}