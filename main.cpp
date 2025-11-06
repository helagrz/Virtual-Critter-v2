// Created by Helena Grzelak on 05/11/2025.
#include <iostream>
#include <vector>
#include "critter_class.h"
using namespace std;

//Array with the critters
vector <critter> c;
//Index of current critter
int curr = 0;

string input() {
    string type;
    cout << "▷ ";
    cin >> type;
    return type;
}

bool selection() {
    cout << "What do you want to do?"<<endl;
    cout <<"1 - INFO"<<"      4 - PLAY"<<endl<<"2 - CHECK"<<"     5 - MORE"<<endl<<"3 - FEED"<<"      6 - EXIT PROGRAM"<<endl<<endl;
    int x = 0;
    x = stoi(input());
    switch (x) {
        case 1: c[curr].info();break;
        case 2: c[curr].status();break;
        case 3: cout << "feed"<<endl;break;
        case 4: cout << "play"<<endl;break;
        case 5: cout << "more"<<endl;break;
        case 6: return false;
    }
    return true;
}



int main() {
    bool cont = true;
    critter first_critter;
    first_critter.name_critter();
    c.push_back(first_critter);

    while (cont) {
        cont = selection();
    }

    return 0;
}