#include <iostream>
using namespace std;

int main() {
    int* pPointer = nullptr;

    int intergerVar = 5;

    pPointer = &intergerVar;
    cout << "intergerVar: " << intergerVar << endl;
    cout << "Address of intergerVar:  "<< &intergerVar << endl;
    cout << "pPointer: " << pPointer << endl;
    cout << "Address of pPointer: " << &pPointer << endl;

    return 0;
}