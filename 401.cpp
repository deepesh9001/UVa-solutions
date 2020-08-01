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

bool isPal(string s){
	int n = s.length();
	if(n == 0) return false;

	if(n%2 == 0){
		REP(i, n/2) if(s[ n/2 -1 - i] != s[n/2 + i]) return false;
	}
	else{
		FOR(i, 0, n/2 +1) if(s[n/2  - i] != s[n/2 + i]) return false;
	}
	return true;
}

char mirrorTable(char ch){
	switch (ch)
	{
	case 'A': return 'A';break;
	case 'E': return '3';break;
	case 'H': return 'H';break;
	case 'I': return 'I';break;
	case 'J': return 'L';break;
	case 'L': return 'J';break;
	case 'M': return 'M';break;
	case 'O': return 'O';break;
	case 'S': return '2';break;
	case 'T': return 'T';break;
	case 'U': return 'U';break;
	case 'V': return 'V';break;
	case 'W': return 'W';break;
	case 'X': return 'X';break;
	case 'Y': return 'Y';break;
	case 'Z': return '5';break;
	case '1': return '1';break;
	case '2': return 'S';break;
	case '3': return 'E';break;
	case '5': return 'Z';break;
	case '8': return '8';break;
	default:return '@';break;
	}
}

bool isMir(string s){
	int n = s.length();
	if(n == 0) return false;

	if(n%2 == 0){
		REP(i, n/2){
			char l = mirrorTable(s[n/2 -1 - i]);
			char r = s[n/2 + i];
			if(l != r) return false;
			else if( l=='@' ) return false;
		}
	}
	else{
		if(mirrorTable(s[n/2]) == '@') return false;
		FOR(i, 0, n/2 +1){ 
			char l = s[n/2 - i];
			char r = mirrorTable(s[n/2 + i]);
			if(l != r ) return false;
			if(r=='@') return false;
		}
	}
	return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	while(getline(cin, str) and str.length() > 0){
		if(isPal(str)){
			if(isMir(str)){
				cout<<str<<" -- is a mirrored palindrome.\n";
				continue;
			}
			cout<<str<<" -- is a regular palindrome.\n";
			continue;
		}
		if(isMir(str)){
			cout<<str<<" -- is a mirrored string.\n";
			continue;
		}
		cout<<str<<" -- is not a palindrome.\n";
	}
	
	
}