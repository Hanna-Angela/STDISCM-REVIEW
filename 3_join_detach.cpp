// join()
// outputs thread only when its done executing
// can only join ONCE
// check if joinable() first to avoid errors

// detach()
// thread runs independently
// main thread does not wait for it to finish
// can only detach ONCE
// when to use: background tasks such as logging, monitoring, etc.

//ADDITIONAL INFO
// cant use BOTH on same thread
// cant use NONE on a thread. program will terminate abnormally because thread handle might leak

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void print_hi(){
    for (int i = 0; i < 5; i++)
    {
        cout << "hi!" << endl;
    }

    std::this_thread::sleep_for(chrono::seconds(3));
    
}

int main(){
    std::thread t1(print_hi);

    cout << "main()" << endl;

    // output of t1 only shows after its done executing
    // t1.join();

    // thread is running independently.
    // so, main is not waiting for it to finish. kung ano lang umabot ung output lang na un ipprint
    // t1.detach(); 


    cout << "End of main()" << endl;

    return 0;
}