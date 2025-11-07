// Created by Helena Grzelak on 07/11/2025.
//Games for virtual critter
#include <iostream>
using namespace std;

void tictactoe(string name) {
    cout << "You choose to play tictactoe with "<<name<<endl<<endl;
    cout << "    TICTACTOE   "<<endl;
    cout<<"-----------------"<<endl;
    cout <<"    1 | 2 | 3 "<<endl<<"    ---------"<<endl;
    cout <<"    4 | 5 | 6 "<<endl<<"    ---------"<<endl;
    cout <<"    7 | 8 | 9 "<<endl;

    //s - symbol (O or X)
    //cs - critter's symbol, if s=O, cs=X and if s=X, cs=O
    string s ="", cs="";
    while (s!="O" and s !="X") {
        cout << "Choose symbol (O or X)" << endl;
        cout << "▷ ";
        cin >> s;
        transform(s.begin(),s.end(),s.begin(),::toupper);
    }
    if(s=="X"){cs = "O";}
    else {cs = "X";}

    cout << "You play "<<s<<endl;
    cout << name << " plays "<<cs<<endl;
}

void game2(string name) {
    cout << "You choose to play game2 with "<<name<<endl;
}

//function "int main(){}" for testing purposes
int main() {
    tictactoe("Critter");
    return 0;
}