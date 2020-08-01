#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	REP(c, 1e9){

		int n, p;
		cin>>n>>p;

		if(n==0 and p==0) break;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string ans;
		double ansp = 1e9;
		int ansr = 0;

		REP(i, n){
			string s;
			getline(cin, s, '\n');
		}

		REP(i, p){
		
			string str;
			double d;
			int r;

			getline(cin, str, '\n');
			cin>>d>> r;

			

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			REP(i, r){
				string s;
				getline(cin, s, '\n');
			}

			if(r >= ansr){
				if(r == ansr){
					if(d < ansp){
						ansp = d;
						ans = str;
					}
				}
				else{
					ansr = r;
					ans = str;
					ansp = d;
				}
			}
		}

		cout<<"RFP #"<<c+1<<'\n';
		cout<<ans<<'\n'<<'\n';


	}

}