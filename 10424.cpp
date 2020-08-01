#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	while(1){
		string s1,s2;
		cin>>s1>>s2;

		if(s1.length() == 0 or s2.length() == 0) break;

		int a1 = 0, a2 = 0;
		for(auto x : s1){
			if('a' <= x and x <= 'z' ){
				a1 += x - 'a' +1;
			}
			else if('A' <= x and x <= 'Z' ){
				a1 += x - 'A' +1;
			}
		}

		while(a1 > 9){
			int sum = 0;
			while(a1 > 0){
				sum += a1%10;
				a1 /= 10;
			}
			a1 = sum;
		}

		for(auto x : s2){
			if('a' <= x and x <= 'z' ){
				a2 += x - 'a' +1;
			}
			else if('A' <= x and x <= 'Z' ){
				a2 += x - 'A' +1;
			}
		}

		while(a2 > 9){
			int sum = 0;
			while(a2 > 0){
				sum += a2%10;
				a2 /= 10;
			}
			a2 = sum;
		}

		if(a2 > a1) swap(a1, a2);

		printf("%.2f %%\n",100.*a2/a1);
	}
}