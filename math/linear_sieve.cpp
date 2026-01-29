#include <bits/stdc++.h>
#include <cassert>
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

// Test the linear sieve
void tests() {
    int N = 20;
    vector<int> primes, spf;
    linear_sieve(N, primes, spf);

    // Expected primes up to 20
    vector<int> expected_primes{2, 3, 5, 7, 11, 13, 17, 19};
    assert(primes == expected_primes);

    // Expected smallest prime factors up to 20
    vector<int> expected_spf{
        0, 0, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2
    };
    assert(spf == expected_spf);

    cout << "All tests passed!" << endl;
}

int main() {
    tests(); // run automated tests

    int N = 50;
    vector<int> primes, spf;
    linear_sieve(N, primes, spf);

    cout << "Primes up to " << N << ": ";
    for(int p : primes) cout << p << " ";
    cout << endl;

    return 0;
}