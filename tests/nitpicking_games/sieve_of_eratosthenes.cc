// Use Sieve of Eratosthenes to generate a list of primes up to N:
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <bits/stdc++.h>

using namespace std;

static const int N = 100;

// Driver program to test above function
int main()
{
    vector<bool> prime;
    prime.resize(N);
    std::fill(prime.begin(), prime.end(), true);

    // Perform sieve
    for(long long i = 2; i*i < N; i++) {
        if(prime[i]) {
            for(long long j = i*i; j < N; j+=i) {
                prime[j] = false;
            }
        }
    }
    // Print primes
    for(long long i = 2; i < N; i++) {
        if(prime[i]) {
            cout<<i<<" is prime!\n";
        }
    }
}
