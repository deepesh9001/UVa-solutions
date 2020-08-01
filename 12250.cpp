#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int i = 1;
	while(1){
		string str, ans;
		cin>>str;

		if(str == "HELLO"){
			ans = "ENGLISH";
		}
		else if (str == "HOLA"){
			ans = "SPAIN";
		}
		else if (str == "HALLO"){
			ans = "GERMAN";
		}
		else if (str == "CIAO"){
			ans = "ITALY";
		}
		else if (str == "BONJOUR"){
			ans = "FRENCH";
		}
		else if (str == "ZDRAVSTVUJTE"){
			ans = "RUSSIAN";
		}
		else if(str == "#"){
			break;
		}
		else{
			ans = "UNKNOWN";
			break;
		}
		
		printf("Case %d: %s\n", i++, ans.c_str());
	}
}