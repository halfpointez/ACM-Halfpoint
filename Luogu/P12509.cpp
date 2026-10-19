#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int Alice(std::string S) {
	int X = 0;
	for(int i = 0; i < S.size(); i++) {
		if(S[i] == '1') X ^= (i + 1);
	}
	return X;
}

int Bob(std::string T, int X) {
	int P = 0;
	for(int i = 0; i < T.size(); i++) {
		if(T[i] == '1') P ^= (i + 1);
	}
	return P ^ X;
}
