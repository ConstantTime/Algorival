#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 123456;

// spf array will be calculated with the help of
// sieve algorihtm
int spf[N];

map < ll , ll > getFactorization(ll x) {
    map < ll , ll > ret;
    while (x != 1){
        ret[spf[x]]++;
        x = x / spf[x];
    }
    return ret;
}

int main() {
	return 0;
}