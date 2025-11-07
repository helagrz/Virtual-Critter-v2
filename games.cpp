// Created by Helena Grzelak on 07/11/2025.
//Games for virtual critter
#include <iostream>
using namespace std;

int random_int_in_range(int a, int b) {
    int answer = rand()%(b-a+1)+a;
    return answer;
}

void show_table(string tab[]) {
    cout << tab[0]<<"|"<<tab[1]<<"|"<<tab[2]<<endl;
    cout << "---------"<<endl;
    cout << tab[3]<<"|"<<tab[4]<<"|"<<tab[5]<<endl;
    cout << "---------"<<endl;
    cout << tab[6]<<"|"<<tab[7]<<"|"<<tab[8]<<endl;
}

void tictactoe(string name) {
    string tab[9];
    for (int i=0;i<9;i++) {
        tab[i]="   ";
    }
    /*
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
    cout << name << " plays "<<cs<<endl<<endl;
    cout<<"Who will start will be chosen randomly..."<<endl;
    */
    string s ="X", cs="O";
    if (random_int_in_range(0,1)) {
        cout << "You start!"<<endl;;
    }
    else {
        cout << name <<" starts!"<<endl;
    }
    //win - Did someone win?, space - Is there any space available?
    bool win=false, space = true;
    string winner = "";
    int x;

    while (win==false and space==true) {
        cout << "▷ ";
        cin >> x;
        while (x>9 and x<1) {
            cout << "Enter numbers 1-9"<<endl<< "▷ ";
            cin >> x;
        }
        while (tab[x-1]!="   ") {
            cout << "This space is taken"<<endl<< "▷ ";
            cin >> x;
        }
        tab[x-1]=" "+s+" ";
        show_table(tab);
    }

}

void game2(string name) {
    cout << "You choose to play game2 with "<<name<<endl;
}

//function "int main(){}" for testing purposes
int main() {
    srand(time(0));
    tictactoe("Critter");
    return 0;
}