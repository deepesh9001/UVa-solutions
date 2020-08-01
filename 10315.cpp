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

int SuitInt(char ch){
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

int CardInt(char ch){
	switch (ch)
	{
	case 'A':
		return 14;
		break;
	case 'K':
		return 13;
		break;
	case 'Q':
		return 12;
		break;
	case 'J':
		return 11;
		break;
	case 'T':
		return 10;
		break;
	default:
		return ch - '0';
		break;
	}
}

bool mySort(const string &s1, const string &s2){
	return CardInt(s1[0]) < CardInt(s2[0]);
}

bool isFlush(vector<string> s){
	int suitCount[4];
	clr(suitCount);
	REP(i,5)  suitCount[SuitInt(s[i][1])]++;
	
	REP(i, 5) if(suitCount[i] == 5) 
		return true;
	
	return false;
}

bool isStraight(vector<string> s){

	char last = CardInt(s[0][0]);
	
	FOR(i, 1, 5){
		int cur = CardInt(s[i][0]);
		if(cur - last != 1){
			if(!(last == 5 and cur == 14 and i == 4)){
				return false;
			}
		}
		last = cur;
	}

	return true;
}

pair<pair<int, int>, pair<int, int>> whatPair(vector<string> s){
	
	int num[15];
	clr(num);

	REP(i, 5)  num[CardInt(s[i][0])]++;

	pair<pair<int, int>, pair<int, int>> p;

	REP(i, 15){
		if(num[i] >= p.first.first){
			p.first.second = i;
			p.first.first = num[i];
		}
	}

	REP(i, 15){
		if(i == p.first.second) continue;
		if(num[i] >= p.second.first){
			p.second.second = i;
			p.second.first = num[i];
		}
	}

	return p;
}

char higherCard(vector<string> s1, vector<string> s2){
	RREP(i, 5){
		if(CardInt(s1[i][0]) > CardInt(s2[i][0])) return '1';
		else if(CardInt(s1[i][0]) < CardInt(s2[i][0])) return '2';
	}

	return 'D';
}

pair<int, pair<int, int>> handAnalysis(vector<string> s){

	bool flush = isFlush(s);
	bool straight = isStraight(s);
	pair<pair<int, int>, pair<int,int>> p = whatPair(s);

	if(flush){
		if(straight) return {9, {CardInt(s[4][0]), 0}};
		else return{6, {CardInt(s[4][0]), CardInt(s[3][0])}};
	}
	else if(straight) return {5, {CardInt(s[4][0]), CardInt(s[3][0])}};
	else if(p.first.first == 4) return {8, {p.first.second, p.second.second}};
	else if(p.first.first == 3){
		if(p.second.first == 2) return {7, {p.first.second, p.second.second}};
		else return {4 , {p.first.second, p.second.second}};
	}
	else if(p.first.first == 2){
		if(p.second.first == 2) return {3, {p.first.second, p.second.second}};
		else return{2, {p.first.second, p.second.second}};
	}
	else return {1, {p.first.second, p.second.second}};
}

void printHand(pair<int, pair<int, int>> p){
	cout<<"first :"<<p.first<<'\n';
	cout<<"high :"<<p.second.first<<" low :"<<p.second.second<<'\n';
}


int main(){
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(1){
		string ans;

		vector<string> s1(5);
		vector<string> s2(5);
		
		REP(i, 5){
			cin>>s1[i];
		}

		sort(s1.begin(), s1.end(), mySort);

		if(s1[0].length() == 0) break;

		pair<int, pair<int, int>> handValue1 = handAnalysis(s1);

		REP(i, 5){
			cin>>s2[i];
		}

		sort(s2.begin(), s2.end());

		pair<int, pair<int, int>> handValue2 = handAnalysis(s2);		

		if(handValue1.first > handValue2.first) ans = "Black";
		else if(handValue1.first < handValue2.first) ans = "White";
		else if(handValue1.second.first > handValue2.second.first) ans = "Black";
		else if(handValue1.second.first < handValue2.second.first) ans = "White";
		else if(handValue1.second.second > handValue2.second.second) ans = "Black";
		else if(handValue1.second.second < handValue2.second.second) ans = "White";
		else{
			char res = higherCard(s1, s2);
			if(res == '1') ans = "Black";
			else if(res == '2')ans = "White";
			else {
				cout<<"Tie.\n";
				continue;
			}
		}

		cout<<ans<<" wins.\n";		
	}
}