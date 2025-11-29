// PROBLEM 1B: barriers a() < Y(), X() < b()

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

binary_semaphore Sa(0);
binary_semaphore SX(0);

void T1(){
	a();
	Sa.release();
	SX.acquire();
	b();
}

void T2(){
	X();
	SX.release();
	Sa.acquire();
	Y();
}

int main(){
	cout << "PROBLEM 1B: barriers a() < Y(), X() < b()\n";

	thread thread1(T1);
	thread thread2(T2);

	thread1.join();
	thread2.join();

	return 0;
}