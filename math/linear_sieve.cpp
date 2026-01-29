#include <bits/stdc++.h>
using namespace std;

// Linear sieve: finds primes up to N
void linear_sieve(int N, vector<int> &primes, vector<int> &spf){
    spf.assign(N+1, 0); // smallest prime factor

    for(int i=2 ; i<=N ; i++){
        if(spf[i] == 0){
            spf[i]= i;
            primes.push_back(i);
        }
        for(int p : primes){
            if (i * p > N) break;
            spf[i * p]= p;
            if (p == spf[i]) break;
        }
    }
}

int main() {
    int N = 50;
    vector<int> primes, spf;
    linear_sieve(N, primes, spf);

    cout<< "Primes up to " << N << ": ";
    for(int p : primes) cout << p << " ";
    cout << endl;

    return 0;
}
