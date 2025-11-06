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

void feed() {
    cout << c[curr].update_hunger(2)<<endl;
}

void c_selection() {

}

bool valid_name(string x) {
    return true;
}

void more() {
    cout << "What do you want to do?"<<endl;
    cout<<"1 - SELECT CRITTER"<<"   4 - LOAD CRITTER"<<"          7 - RESET"<<endl;
    cout<<"2 - CHANGE NAME"<<"      5 - CREATE NEW CRITTER"<<"    8 - HELP"<<endl;
    cout<<"3 - SAVE CRITTER"<<"     6 - REMOVE THIS CRITTER"<<"   9 - BACK"<<endl<<endl;
    int x = 0;
    x = stoi(input());
    switch (x) {
        case 1: c_selection();break;
        case 2: {
            cout << "What new name do you want to give "<<c[curr].name<<"?"<<endl;
            string a;
            a = input();
            while(not(valid_name(a))) {
                cout << "Name not valid"<<endl<<"Name has to include at least one letter"<<endl;
                a = input();
            }
            a = c[curr].capitalize(a);
            cout << c[curr].name<<" is now "<< a;
            c[curr].name = a;
            break;
        }
        case 3: cout << "save()"<<endl; break;
        case 4: cout << "load()"<<endl; break;
        case 5:
            cout << "create()"<<endl;
            break;
        case 6:
            cout << "remove()"<<endl;
            break;
        case 7:
            cout << "reset()"<<endl;
            break;
        case 8:
            cout << "help()"<<endl;
            break;
        case 9:
            return;
    }
}

bool selection() {
    cout << "What do you want to do?"<<endl;
    cout<<"1 - INFO"<<"      4 - PLAY"<<endl;
    cout<<"2 - CHECK"<<"     5 - MORE"<<endl;
    cout<<"3 - FEED"<<"      6 - EXIT PROGRAM"<<endl<<endl;
    int x = 0;
    x = stoi(input());
    switch (x) {
        case 1: c[curr].info();break;
        case 2: c[curr].status();break;
        case 3: feed();break;
        case 4: cout << "play"<<endl;break;
        case 5: more();break;
        case 6: cout << "See you later!";return false;
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