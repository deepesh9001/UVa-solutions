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

int main(){
	freopen("in.txt", "r", stdin);
	
	string str;
	while(1){
		getline(cin, str);
		if(str == "Game Over") break;

		int score = 0;
		char last = '0';

		int frame = 0;
		int roll = 0;
		FOR(i, 0, str.length()){
			char ch = str[i];
			if(frame == 10) break;

			if(ch == '/'){
				score += (10 - last + '0');
				if(str[i+2] != 'X') score += str[i+2] - '0';
				else score += 10;
			}
			else if(ch == 'X'){
				score += 10;
				if(str[i+2] == 'X') score += 10;
				else score += str[i+2] - '0';
				
				if(str[i+4] == 'X') score += 10;
				else if(str[i+4] == '/') score += 10 - str[i+2] + '0';
				else score += str[i+4] - '0';
			}
			else {
				score += (ch - '0');
				roll++;
			}

			if(roll == 2 || ch == '/' || ch == 'X'){
				roll = 0;
				frame++;
			}

			last = str[i];

			i++;
		}

		std::cout<<score<<'\n';
		
		
	}
	
	
	
}