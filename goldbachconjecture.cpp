/*
 * program to return two primes that sum to make the input of an even, positive
 * integer
 */

#include <iostream>
#include <math.h>
#include <vector>

/*
 *  create a class to contain return of the program: if valid input then return
 *  the two primes that sum to give the input, else return invalid input.
 */ 
class TwoPrimes {
    public:
        int get_prime_1() { return prime_1; };
        int get_prime_2() { return prime_2; };
        TwoPrimes(int p1, int p2, bool valid) {
            prime_1 = p1; prime_2 = p2; valid_input = valid; };
        bool is_valid() { return valid_input; };

    private:
        /* 
         * make primes only accessible from within the TwoPrimes class. This way
         * the getters and setters have to be used to access and change these
         * values. This decreases the chance of the return values being acciden-
         * tally modified.
         */
        int prime_1;
        int prime_2;
        bool valid_input;
};

/*
 * Logic to find list of primes less than or equal to user's input using the
 * Sieve of Eratosthenes.
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

TwoPrimes find_primes(std::vector<bool> sieved, int input) {
    int counter = 1;

    int p1, p2 = 0;
    /*
     * By Goldbach's conjecture the following will always produce two valid
     * primes that sum to give input.
     */
    for(bool b: sieved) {

        if(b) {
            std::cout << counter << std::endl;
            p1 = counter;
            p2 = input - counter;
            if(sieved.at(p2 - 1)) {break;}
        }
        counter++;
    }
    TwoPrimes tp(p1, p2, true);
    std::cout << "first prime " << p1 << " p2 = " << p2 << std::endl;
    return tp;
}

//TwoPrimes find_sum(std::vector<bool> sieved, int input) {
//
//    TwoPrimes tp;
//    int i, p1, p2 = 1;
//    for(bool n : sieved) {
//        if(n) { 
//            p1 = i;
//            p2 = input - p1;
//            std::cout << p1 << " " << p2 << std::endl;
//            break;
//            /*
//             * if index at p2 is prime then we are done
//             */
//            if(sieved.at(p2)) { 
//                tp.set_prime_1(p1);
//                tp.set_prime_2(p2);
//                break;
//            }
//        }
//        ++i;
//    }
//    return tp;
//}

TwoPrimes goldbach_conjecture(int input) {
    /*
     * need to check if input is valid (positive, even and less than some big
     * number...)
     */
    if(input % 2 == 0 || input < 0 ) {
        TwoPrimes tp(0,0,false);
        return tp;
    }
    std::vector<bool> sieved = sieve(input);
    //now have list of primes, iterate through to see if sum makes input.
    TwoPrimes tp = find_primes(sieved, input);
    return tp;
}

 int main() {

    int input;

    std::cout << "Enter a positive, even number" << std::endl;
    std::cin >> input;
    while(std::cin.fail() || (input - 1) % 2 == 0 || input <= 0 ) {
        std::cout << "Enter a positive, even number." << std::endl;
        std::cin >> input;
    }
    TwoPrimes tp = goldbach_conjecture(input);
    if(tp.is_valid()) {
        int p1=tp.get_prime_1();
        int p2=tp.get_prime_2();
        std::cout << p1 << " " << p2 << std::endl;
    } else {
        std::cout << "Enter a positive, even number." << std::endl;
    }

    return 0;
}
 
