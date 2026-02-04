/**
 * @file linear_sieve.cpp
 * @brief Linear sieve algorithm to generate primes and smallest prime factors.
 *
 * This implementation finds all prime numbers up to N in O(N) time
 * and computes the smallest prime factor (SPF) for each number.
 */

#include <cassert>
#include <vector>

namespace math{

/**
 * @brief Computes all prime numbers up to N and the smallest prime factor for
 * each number.
 *
 * @param N Upper bound for prime generation.
 * @param primes Vector to store all prime numbers up to N.
 * @param spf Vector where spf[x] is the smallest prime factor of x.
 */

void linear_sieve(int N, std::vector<int>& primes, std::vector<int>& spf){
    spf.assign(N+1, 0);

    for(int i=2 ; i<=N ; i++){
        if(spf[i]==0){
            spf[i]= i;
            primes.push_back(i);
        }
        for(int p:primes){
            if(i*p > N){
                break;
            }
            spf[i*p]= p;
            if(p== spf[i]){
                break;
            }
        }
    }
}

/**
 * @brief Self-test function for the linear sieve.
 */
void test_linear_sieve(){
    int N= 20;
    std::vector<int> primes, spf;
    linear_sieve(N, primes, spf);

    std::vector<int> expected_primes{2, 3, 5, 7, 11, 13, 17, 19};
    assert(primes == expected_primes);

    std::vector<int> expected_spf{0,  0, 2,  3, 2, 5, 2,  7, 2,  3, 2,
                                  11, 2, 13, 2, 3, 2, 17, 2, 19, 2};
    assert(spf==expected_spf);
}

}  // namespace math

int main() {
    math::test_linear_sieve();
    return 0;
}