#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;



int points(char ch){
	switch (ch)
	{
	case 'A':
		return 4;
		break;

	case 'K':
		return 3;
		break;

	case 'Q':
		return 2;
		break;

	case 'J':
		return 1;
		break;

	default:
		return 0;
		break;
	}
}

int suits(char ch){
	switch (ch)
	{
	case 'S':
		return 0;
		break;
	case 'H':
		return 1;
		break;
	case 'D':
		return 2;
		break;
	case 'C':
		return 3;
		break;
	
	default:
		return -1;
		break;
	}
}

char suitDecode(int i){
	switch (i)
	{
	case 0:
		return 'S';
		break;
	case 1:
		return 'H';
		break;
	case 2:
		return 'D';
		break;
	case 3:
		return 'C';
		break;
	
	default:
		return '$';
		break;
	}
}


int main(){
	freopen("in.txt", "r", stdin);

	while(!flag1){

		int point = 0;
		int suit[4];
		bool asuit[4], ksuit[4], qsuit[4], jsuit[4], isStopped[4];
		clr(asuit),clr(ksuit), clr(qsuit), clr(jsuit), clr(suit), clr(isStopped);
		
		REP(i, 13){
			string str;
			cin >> str;

			if(str.length() == 0) {flag1 = true; break;}

			int whatPoint = points(str[0]);
			int whatSuit = suits(str[1]);

			point += whatPoint;
			suit[whatSuit]++;

			switch (whatPoint)
			{
			case 4:
				asuit[whatSuit] = true;
				break;
			case 3:
				ksuit[whatSuit] = true;
				break;
			case 2:
				qsuit[whatSuit] = true;
				break;
			case 1:
				jsuit[whatSuit] = true;
				break;
			default:
				break;
			}
		}

		REP(i, 4){
			if(ksuit[i] and suit[i] < 2) {
				point--;
				isStopped[i] = true;
			}
			if(qsuit[i] and suit[i] < 3 ) {
				point--;
				isStopped[i] = true;
			}
			if(jsuit[i] and suit[i] < 4) {
				point--;
			}
			if(asuit[i]) isStopped[i] = true;
		}

		
		flag2 = false;
		if(point >= 16) {
			REP(i, 4){
				if(!isStopped[i]) flag2 = true;
			}
			if(!flag2){
				cout<<"BID NO-TRUMP\n";
				continue;
			}
		}

		int max = 0;
		int suitCode;
		REP(i, 4){
			
			if(suit[i] > max){
				max = suit[i];
				suitCode = i;
			}
			if(suit[i] == 2) point++;
			else if(suit[i] == 1 or suit[i] == 0) point += 2;
		}

		if(!flag1){
			if(point < 14) cout<<"PASS\n";
			else cout<<"BID "<<suitDecode(suitCode)<<'\n';		
		}
	}

}