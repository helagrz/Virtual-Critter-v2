// Created by Helena Grzelak on 05/11/2025.
#include <iostream>
#include "critter_class.h"
using namespace std;

int main() {
    critter a;
    a.name = "Bebe";
    a.info();
    a.status();
    cout << "Testing feeding and hunger:"<<endl;
    cout << "+ 2"<<endl<<a.update_hunger(2)<<endl;
    cout << "+ 5"<<endl<<a.update_hunger(5)<<endl;
    cout << "+ 4"<<endl<<a.update_hunger(4)<<endl;
    cout << "+ 4"<<endl<<a.update_hunger(4)<<endl;

    cout << "Testing levels:"<<endl;
    cout << "+ 4"<<endl<<a.update_level(4)<<endl;
    cout << "+ 12"<<endl<<a.update_level(12)<<endl;
    cout << "+ 4"<<endl<<a.update_level(4)<<endl;
    cout << "+ 42"<<endl<<a.update_level(42)<<endl;
    return 0;
}