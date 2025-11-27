// we dk which thread runs first when multiple are created simultaneously
// so we use join() to make sure main thread waits for other threads to finish before continuing

//types of thread creation

#include <iostream>
#include <thread>
using namespace std;

//1. FUNCTION POINTER
// void fun(int x){
//     // (x--) > 0
//     while(x --> 0){
//         cout << x << endl;
//     }
// }

// int main(){
//     std::thread t1(fun, 5);
//     std::thread t2(fun, 1);

//     t1.join();
//     t2.join();

//     return 0;
// }




// 3. FUNCTOR (function object)
// class Base{
//     public:        
//         void operator()(int x){
//             // (x--) > 0
//             while(x --> 0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){
//     std::thread t1((Base()), 5);
//     std::thread t2((Base()), 1);

//     t1.join();
//     t2.join();

//     return 0;
// }





// // 4. NON-STATIC MEMBER FUNCTION
// if u want to change stuff inside class
// class Base{
//     public:        
//         void fun(int x){
//             // (x--) > 0
//             while(x --> 0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){
//     // create object of class
//     Base b;

//     // 1st arg address of member function
//     // 2nd arg is object of the class
//     std::thread t1(&Base::fun, &b, 5);
//     std::thread t2(&Base::fun, &b, 1);

//     t1.join();
//     t2.join();

//     return 0;
// }





// 5. STATIC MEMBER FUNCTION (no need to create instance)
// traditional, no need to change stuff reuse lng
// class Base{
//     public:        
//         static void fun(int x){
//             // (x--) > 0
//             while(x --> 0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){

//     // 1st arg address of member function
//     std::thread t1(&Base::fun, 5);
//     std::thread t2(&Base::fun, 1);

//     t1.join();
//     t2.join();

//     return 0;
// }