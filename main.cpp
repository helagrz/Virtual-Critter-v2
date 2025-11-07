// Created by Helena Grzelak on 05/11/2025.
#include <iostream>
#include <vector>
#include "critter_class.h"
#include "games.cpp"
using namespace std;

//Array with the critters
vector <critter> c;
//Index of current critter
int curr = 0;

string input() {
    string type;
    cout << "▷ ";
    cin >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    return type;
}

void feed() {
    cout << c[curr].update_hunger(2)<<endl;
}

void play() {
    cout << "What game do you want to play?"<<endl;
    cout << "1 - TICTACTOE"<<endl<<"2 - GAME 2"<<endl<<"3 - BACK"<<endl<<endl;
    int x = 0;
    x = stoi(input());
    switch (x) {
        case 1: {
            while (tictactoe(c[curr].name)) {}
            break;
        }
        case 2: game2(c[curr].name);break;
    }

}

bool valid_name(string x) {
    return true;
}

void c_selection() {
    cout << "You have the total of "<<c.size()<<" critters!" << endl;
    string symbol = "";
    for (int i=0;i<c.size();i++) {
        if (i == curr) {
            symbol = "▶ ";
        }
        else {
            symbol = to_string(i+1);
            symbol += " - ";
        }
        string n = c[i].name;
        transform(n.begin(),n.end(),n.begin(),::toupper);
        cout <<symbol<< n<<endl;
    }
    cout << c.size()+1 << " - BACK" << endl;
    int x = stoi(input());
    if (x>0 and x<=c.size()) {
        curr = x-1;
        cout << "You choose " << c[curr].name << endl;
    }
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
            cout << c[curr].name<<" is now "<< a<<endl;
            c[curr].name = a;
            break;
        }
        case 3: cout << "save()"<<endl; break;
        case 4: cout << "load()"<<endl; break;
        case 5: {
            cout << "Are you sure you want to add another critter? (To proceed enter \'yes\')"<<endl;
            string a = input();
            if (a == "yes") {
                c.push_back(critter());
                curr++;
                c[curr].name_critter();
                c[curr].info();
            }
            break;
        }
        case 6:{
            cout << "Are you sure? (To proceed enter \'yes\')"<<endl;
            string a = input();
            if (a == "yes") {
                c.erase(c.begin()+curr);
                curr=c.size()-1;
            }
            break;
            }
        case 7:
            cout << "reset()"<<endl;
            break;
        case 8:
            cout << "help()"<<endl;
            break;
    }
    return;
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
        case 4: play();break;
        case 5: more();break;
        case 6: cout << "See you later!";return false;
    }
    return true;
}

int main() {
    bool cont = true;
    c.push_back(critter());
    c[curr].name_critter();

    while (cont) {
        cont = selection();
    }

    return 0;
}
