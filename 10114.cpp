#include <iostream>
#include <vector>

using namespace std;
int main(){
	freopen("in.txt", "r", stdin);
	
	while(1){
		double downpayment, amt;
		int months, k;
		
		scanf("%d%lf%lf%d", &months, &downpayment, &amt, &k);
		if(months < 0) break;

		vector<double> v(200);

		for(int i = 0; i < k; i++){
			int a;
			double b;

			scanf("%d%lf", &a, &b);
			v[a] = b;

		}
		double temp = v[0];
		for(int i = 1; i < 200; i++) {
			if(v[i] == 0) v[i] = temp;
			else temp = v[i];
		}
		
		temp = amt+downpayment;
		for(int i = 0; i < 200; i++){
			temp -= temp*v[i];
			if(amt - (amt/months)*(i+1) < temp){
				cout<<i+1;
				if(i > 0) cout<<" months\n";
				else cout<<" month\n";
				break;
			}
		}

	}
}