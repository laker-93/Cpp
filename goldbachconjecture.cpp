/*
 * Program to return two primes that sum to make the input of an even, positive
 * integer.
 * Thought process:
 * First find list of primes less than input and iterate through until correct
 * sum is found. Time complexity of this implmentation dominated by time compl-
 * exity of finding list of primes with Sieve of Eratosthenes O(n log log n).
 * Thus an improvement can be made by using a faster implementation of Sieve -
 * however, once primes are generated, algorithm needs to iterate through the
 * list of primes: an operation taking O(n) time. There are sublinear sieves
 * however, due to above limitation of O(n) iteration these would be superfluous
 *
 * Potential difficulties/problems encountered:
 *    - integer gets too big
 *        - one solution is to use sieve for integers up to a certain amount.
 *        For larger integers, a more sophisticated approach would have to be
 *        used.
 *
 */

#include <iostream> //for input and output
#include <sstream>  //for handling input
#include <math.h> // for sqrt
#include <algorithm> // for binary search
#include <vector> // to make vectors
#include <limits> // for max int

/*
 *  Create a class to contain return of the program: two primes.
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
 * Modified Sieve of Eratosthenes that runs in O(n) time. Algorithm requires 
 * O(n) space too but this can be used to store the primes which are needed
 * later.
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
 * Iterate backwards through list of primes then form difference between prime
 * and input. Then perform a binary search for this difference.
 * Number of primes less than n is O (n / log n) so searching takes 
 * O ( log (n / log n) ) = O ( log n - log log n ) = O ( log n )
 * Iterating through primes and binary searching thus takes:
 * O(n / log n * log n) = O(n)
 */
std::vector<TwoPrimes> find_goldbachs(std::vector<int> &primes, int input,
                                      bool all_pairs) {

    int num_primes = primes.size();
    std::vector<TwoPrimes> result;
    
    for(int i = num_primes - 1; i >= 0; --i) {
 
        int p1 = primes[i];
        int p2 = input - p1;
        //binary search for p2 in primes
        bool found_p2 = std::binary_search(primes.begin(), primes.end(), p2);
            if(found_p2) {
                if(all_pairs == false) {
                    TwoPrimes tp(p1, p2);
                    result.push_back(tp);
                    return result;
                }
                TwoPrimes tp(p1, p2);
                result.push_back(tp);
            };
    }
    return result;
}

 /*
  * need to check if input is valid (positive, even and less than some big
  * number...)
  * Tried various ways of handling input. Using cin is problematic as requires 
  * multiple lines to handle errors and clean incorrect input. Using getline
  * provides cleaner code.
  * Since 2 cannot be expressed as sum of two primes, require user to input an
  * integer greater than 2.
  */

int user_input() {
    int int_input = 0;
    std::string str_input = "";
    bool is_valid_int = false;
    while(!is_valid_int) {
        std::cout << "Enter a positive, even number greater than 2." << std::endl;
        //copy user input into str_input
        getline(std::cin, str_input);
        //convert str_inpt into a string stream object
        std::stringstream input_stream(str_input);
        //test to see if input_stream is of integer type and even and greater than 2.
        if(input_stream >> int_input && int_input > 2 && int_input % 2 ==0) {
            is_valid_int = true; }

    }
    std::cout << "you entered " << int_input << std::endl;

    return int_input;
}

/*
 * pass arguments into main to set user option of returning all goldbach pairs
 */


 int main(int argc, char *argv[]) {


     bool all_pairs = false;
     if(argc > 2) { std::cerr << "Unknown arguments passed in. Pass flag: " <<
         "'-all-pairs' if you want the program to list all pairs of primes."
             << std::endl;
         return 0;
     }

     if(argc == 2) {
         if(strcmp(*(argv + 1), "-all-pairs") == 0) { all_pairs = true; }
         else { std::cerr << "Unknown arguments passed in. Pass flag: " <<
         "'-all-pairs' if you want the program to list all pairs of primes."
             << std::endl;
         return 0;
         }
     }
         
    int input =  user_input();
    std::vector<int> mod_s = modified_sieve(input);
    std::vector<TwoPrimes> tpv = find_goldbachs(mod_s, input, all_pairs);

    std::cout << "found " << tpv.size() << " pairs:" << std::endl;
    for(auto tp : tpv) {
    int p1=tp.get_prime_1();
    int p2=tp.get_prime_2();
    std::cout << p1 << " " << p2 << std::endl;
    }
    return 0;
}
///*
// * Logic to find list of primes less than or equal to user's input using the
// * Sieve of Eratosthenes. Run time of Sieve is O(n log log n) but only requires
// * O(n) space.
// */
//
//std::vector<bool> sieve(int n) {
//    std::vector<bool> numbers(n, true);
//    /*
//     * 1 is not a prime so always mark first number as false.
//     */
//    numbers.at(0) = false;
//    /*
//     * only need to search up to sqrt(n) since one factor of n is always guara-
//     * nteed to be less than or equal to sqrt(n)
//     */
//    for(int i = 1; i < sqrt(n); i++) {
//        /*
//         * continue searching until we hit the next true value.
//         */
//        if(numbers.at(i) == false) { continue; }
//
//        /*
//         * vectors start at position 0, list of primes starts at 1, therefore
//         * need to add + 1 to j.
//        */ 
//        for(int j = 2*i + 1; j < n; j += i+1) {
//            numbers.at(j) = false;
//        }
//    }
//    return numbers;
//}
///
///*
// * If Goldbach's conjecture is true the following will always produce two valid
// * primes that sum to give input. Runs in O(n) time, O(1) space.
// */
//TwoPrimes find_primes(std::vector<bool> sieved, int input) {
//    int counter = 1;
//
//    int p1, p2 = 0;
//    for(bool b: sieved) {
//
//        if(b) {
//            std::cout << counter << std::endl;
//            p1 = counter;
//            p2 = input - counter;
//            if(sieved.at(p2 - 1)) {break;}
//        }
//        counter++;
//    }
//    TwoPrimes tp(p1, p2);
//    std::cout << "first prime " << p1 << " p2 = " << p2 << std::endl;
//    return tp;
//}
//

