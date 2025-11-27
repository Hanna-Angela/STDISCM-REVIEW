
// process = application
// goal: divide process to multiple threads

// THREAD
// main() is a default thread
// inside main() we make other threads
// lightweight process (run inside process)

// examples: 
// in browser, a thread per opened tab
// in ms word, a thread for formatting, for spell check
// in vs code, a thread for auto save, for auto complete

//CODING EXERCUSE
// find addition of all odd and even number from 1 to 1900000000 

#include <iostream>
#include <thread>
#include <chrono>
#include <numeric>
using namespace std;
const long long N = 1900000000;

// typedef = rename existing data type
typedef unsigned long long ull;

// vars for sum (ull = unsigned long long)
ull even_sum = 0;
ull odd_sum = 0;

// function for even sum
void find_even_sum() {
    for (long long i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            even_sum += i;
        }
    }
}

// function for odd sum
void find_odd_sum() {
    for (long long i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            odd_sum += i;
        }
    }
}

int main(){

    // both run once called.
    std::thread t1(find_even_sum); // thread for even sum
    std::thread t2(find_odd_sum);  // thread for odd sum

    // if done na sila tsaka magcontinue w the program
    t1.join(); // wait for t1 to finish
    t2.join(); // wait for t2 to finish

    cout << "Even sum: " << even_sum << endl;
    cout << "Odd sum: " << odd_sum << endl;


    return 0;
}