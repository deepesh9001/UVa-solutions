#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int caseNo = 1;
	string str;


	while(cin>>str){
		if(str.length() == 0) break;
		cout<<"Case "<<caseNo++<<":\n";

		vector<int> flip;

		char last = str[0];
		FOR(i, 1, str.length()-1){
			if(last != str[i]) { 
				flip.push_back(i);
				last = str[i];
			}
		}

		int n;
		cin>>n;

		while(n-->0){
			int a,b;
			cin>>a>>b;

			if(a > b) swap(a,b);

			bool flag = false;

			for(auto x:flip){
				if(x > a and x <= b) {
					cout<<"No\n";
					flag = true;
					break;
				}
			}

			if(!flag) cout<<"Yes\n";
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

}