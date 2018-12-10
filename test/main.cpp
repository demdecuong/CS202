#include <thread>
#include <iostream>
using namespace std;

void doNothing() {
    cout <<"here"<<endl;
    return;
}

int main() {
    thread t1(doNothing);
    t1.join();
    cout << "main here"<<endl;

    return 0;
}