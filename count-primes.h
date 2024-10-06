#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countPrimes(int n)
    {
    if (n <= 2) return 0;  // No prime numbers less than 2

        // Create a boolean vector "prime[0..n-1]" and initialize all entries as true
        vector<bool> prime(n, true); // Use vector instead of array
        prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

        // Implement the Sieve of Eratosthenes
        for (int p = 2; p * p < n; ++p)
        {
            if (prime[p])  // If prime[p] is true, it is a prime
            {
                // Mark multiples of p as false starting from p^2
                for (int i = p * p; i < n; i += p)
                {
                    prime[i] = false;
                }
            }
        }

        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (prime[i])
                count++;
        }

        return count;
    }
};