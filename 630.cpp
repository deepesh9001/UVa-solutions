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

    int n;
	cin>>n;
	cin.ignore();

	while(n-->0){
		vector<string> dict;

		int n1;
		cin>>n1;
		cin.ignore();
		while(n1-->0){
			string str;
			getline(cin, str);
			dict.push_back(str);
		}
		sort(dict.begin(), dict.end());
		vector<string> deconstructed_dict(dict.begin(), dict.end());
		REP(i, dict.size()) sort(deconstructed_dict[i].begin(), deconstructed_dict[i].end());

		while(1){
			string str, str_copy;
			getline(cin, str);
			str_copy = str;
			if(str == "END") break;
			sort(str.begin(), str.end());
			bool flag = false;
			int count = 1;
			cout<<"Anagrams for: "<<str_copy<<'\n';
			REP(i, dict.size()) 
				if(str == deconstructed_dict[i]) {
					flag = true;
					cout<<"   "<<count++<<") "<<dict[i]<<'\n';
				}
			if(!flag) cout<<"No anagrams for:"<<str_copy<<"\n";
		}
	}
}