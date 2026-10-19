#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> Prime;
const int MAXN = 2e5 + 5;
vector<bool> is_not_prime(MAXN, 0);


void eula_sieve() {
	is_not_prime[0] = 1;
	is_not_prime[1] = 1;
	for(i64 i = 2; i <= MAXN; i++) {
		if(!is_not_prime[i]) Prime.push_back(i);
		for(auto &j:Prime) {
			if((i64) j * i > MAXN) break;
			is_not_prime[j * i] = 1;
			if(i & j == 0) break;;
		}
	}
}

void get_sieve_factor() {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	eula_sieve();



}