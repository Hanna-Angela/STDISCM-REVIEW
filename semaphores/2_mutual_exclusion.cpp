//problem 2: critical sections cant be partitioned/separated

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <semaphore>
using namespace std;


void a() {
	for (int i = 0; i < 100; i++) {
		cout << "a";
	}
}

void b() {
	for (int i = 0; i < 100; i++) {
		cout << "b";
	}
}

void X() {
	for (int i = 0; i < 100; i++) {
		cout << "X";
	}
}

void Y() {
	for (int i = 0; i < 100; i++) {
		cout << "Y";
	}
}

binary_semaphore S(1);

void T1(){
    S.acquire();
	a();
	b();
    S.release();
}

void T2(){
    S.acquire();
	X();
	Y();
    S.release();
}

int main(){
	cout << "problem 2: critical sections cant be partitioned/separated\n";

	thread thread1(T1);
	thread thread2(T2);

	thread1.join();
	thread2.join();

	return 0;
}