
#include <iostream>
#include <windows.h>
#include "Test.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków


    cout << "Autor: Kasper Radom 264023" << endl << endl;

    Test* test = new Test;
//todo dodac komentarze!!!!!!!!
//todo 2**412 i sie wyłącza
    delete test;
}

















//#include <iostream>
//#include <windows.h>
//#include "old/Test.h"
//
//using namespace std;
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków
//
//
//    cout << "Autor: Kasper Radom 264023" << endl << endl;
//
//    Test* test = new Test;
//
//    delete test;
//
//}
//
