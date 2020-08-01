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


int CardInt(char ch){
	switch (ch)
	{
	case 'A':
		return 10;
		break;
	case 'K':
		return 10;
		break;
	case 'Q':
		return 10;
		break;
	case 'J':
		return 10;
		break;
	case 'T':
		return 10;
		break;
	default:
		return ch - '0';
		break;
	}
}

int main(){
	freopen("in.txt", "r", stdin);

	int n;
	cin>> n;

	

	while(n-->0){
		vector<string> deck1(26);
		vector<string> deck2(24);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		REP(i, 26) cin>>deck1[i];
		REP(i, 24) cin>>deck2[i];

		int y = 0;
		
		REP(i, 3){
			string str = deck1.back();
			deck1.pop_back();

			int x = CardInt(str[0]);
			y += x;

			REP(j, 10 - x) deck1.pop_back();
		}

		string ans;
		
		if(deck1.size() > y) ans = deck1[y-1];
		else {
			y -= deck1.size();
			ans = deck2[y-1];
		}

		cout<<"Case "<<caseNo++<<": "<<ans<<'\n';
	}
}