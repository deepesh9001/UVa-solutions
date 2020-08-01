#include <iostream>
using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	int i, a, b, c;
	while(scanf("%d%d%d%d",&i,&a,&b,&c)){
		if(i == 0 and a == 0 and b == 0 and c == 0)  break;
		int ans = 720;
		if(i < a) ans += 360 - (a - i)*9;
		else ans += (i - a)*9;

		ans += 360;
		if(b < a) ans += 360 - (a - b)*9;
		else ans += (b - a)*9;

		if(b < c) ans += 360 - (c - b)*9;
		else ans += (b - c)*9;

		cout<< ans <<'\n';
	}
}