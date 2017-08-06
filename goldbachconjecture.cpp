/*
 * program to return two primes that sum to make the input of an even, positive
 * integer
 * Thought process:
 * First find list of primes less than input and iterate through until correct
 * sum if found. Time complexity of this implmentation dominated by time compl-
 * exity of finding list of primes with Sieve of Eratosthenes O(n log log n).
 * Thus an improvement can be made by using a faster implementation of Sieve -
 * however, once primes are generated, algorithm needs to iterate through the
 * list of primes: an operation taking O(n) time. There are sublinear sieves
 * however, due to above limitation of O(n) iteration these would be superfluous
 *
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <limits>

/*
 *  create a class to contain return of the program: if valid input then return
 *  the two primes that sum to give the input, else return invalid input.
 */ 
class TwoPrimes {
    public:
        int get_prime_1() { return prime_1; };
        int get_prime_2() { return prime_2; };
        TwoPrimes(int p1, int p2) {
            prime_1 = p1; prime_2 = p2;};

    private:
        /* 
         * make primes only accessible from within the TwoPrimes class. This way
         * the getters and setters have to be used to access and change these
         * values. This decreases the chance of the return values being acciden-
         * tally modified.
         */
        int prime_1;
        int prime_2;
};

/*
 * Logic to find list of primes less than or equal to user's input using the
 * Sieve of Eratosthenes. Run time of Sieve is O(n log log n) but only requires
 * O(n) space.
 */
std::vector<bool> sieve(int n) {
    std::vector<bool> numbers(n, true);
    /*
     * 1 is not a prime so always mark first number as false.
     */
    numbers.at(0) = false;
    /*
     * only need to search up to sqrt(n) since one factor of n is always guara-
     * nteed to be less than or equal to sqrt(n)
     */
    for(int i = 1; i < sqrt(n); i++) {
        /*
         * continue searching until we hit the next true value.
         */
        if(numbers.at(i) == false) { continue; }

        /*
         * vectors start at position 0, list of primes starts at 1, therefore
         * need to add + 1 to j.
        */ 
        for(int j = 2*i + 1; j < n; j += i+1) {
            numbers.at(j) = false;
        }
    }
    return numbers;
}

/*
 * If Goldbach's conjecture is true the following will always produce two valid
 * primes that sum to give input. Runs in O(n) time, O(1) space.
 */
TwoPrimes find_primes(std::vector<bool> sieved, int input) {
    int counter = 1;

    int p1, p2 = 0;
    for(bool b: sieved) {

        if(b) {
            std::cout << counter << std::endl;
            p1 = counter;
            p2 = input - counter;
            if(sieved.at(p2 - 1)) {break;}
        }
        counter++;
    }
    TwoPrimes tp(p1, p2);
    std::cout << "first prime " << p1 << " p2 = " << p2 << std::endl;
    return tp;
}

/*
 * Modified Sieve of Eratosthenes that runs in O(n) time. Algorithm requires 
 * O(n) space too but this can be used to store the primes which are needed
 * later. Thus is a much more favourable algorithm.
 */
std::vector<int> modified_sieve(int input) {
    std::vector<bool> isprime(input, true);
    std::vector<int> primes;
    std::vector<int> SPF(input);

    isprime[0] = isprime[1] = false;
    for(int i = 2; i < input; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
            SPF[i] = i;
        }
        //remove all multiples of i*prime[j] and set SPF[i*prime[j]] = prime[j]
        for(int j = 0; j < primes.size() && i*primes[j] < input && 
            primes[j] <= SPF[i]; ++j) {
            isprime[i*primes[j]] = false;
            SPF[i*primes[j]] = primes[j];
        }
    }
    return primes;
}

/*
 * Iterate through list of primes until match is found. This takes O(n^2)
 * Iterate backwards through list of primes then form difference between prime
 * and input. Then perform a binary search for this difference.
 * Number of primes less than n is O (n / log n) so searching takes 
 * O ( log (n / log n) ) = O ( log n - log log n ) = O ( log n )
 */
TwoPrimes find_goldbachs(std::vector<int> primes, int input) {

    int p1, p2 = 0;
    int num_primes = primes.size();
    bool sum_found = false;
    while(!sum_found) {
        for(int i = num_primes - 1; i > 0; --i) {

            p1 = primes[i];
            p2 = input - p1;
            for(int j = 0; primes[j] <= p2; ++j) {
                if(p2 == primes[j]) {sum_found = true;};
            }
        }
    }
    TwoPrimes tp(p1, p2);
    std::cout << "first prime " << p1 << " p2 = " << p2 << std::endl;
    return tp;
}

TwoPrimes goldbach_conjecture(int input) {
       
    std::vector<bool> sieved = sieve(input);
    //now have list of primes, iterate through to see if sum makes input.
    TwoPrimes tp = find_primes(sieved, input);
    return tp;
}

 /*
  * need to check if input is valid (positive, even and less than some big
  * number...)
  */

int user_input() {
    int input;
    std::cout << "Enter a positive, even number" << std::endl;
    std::cin >> input;
    while(std::cin.fail() || (input - 1) % 2 == 0 || input <= 0 ) {
        std::cerr << "Enter a positive, even number." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> input;
    }
    std::cout << "you entered " << input << std::endl;

    return input;
}
 int main() {


     std::vector<int> test(3);
     for(auto a : test) {std::cout << a;}
     int max_int = std::numeric_limits<int>::max() + 1;
        std::cout << max_int << std::endl;
    int input =  user_input();
    std::vector<int> mod_s = modified_sieve(input);
    TwoPrimes tp1 = find_goldbachs(mod_s, input);

    int p1=tp1.get_prime_1();
    int p2=tp1.get_prime_2();
    std::cout << p1 << " " << p2 << std::endl;
//    TwoPrimes tp = goldbach_conjecture(input);
// 
//        int p1=tp.get_prime_1();
//        int p2=tp.get_prime_2();
//        std::cout << p1 << " " << p2 << std::endl;
//
    return 0;
}
 
