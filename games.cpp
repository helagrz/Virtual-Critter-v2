// Created by Helena Grzelak on 07/11/2025.
//Games for virtual critter
#include <iostream>
#include <string>
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

bool get_3(string a, string b, string c) {
    if((a!= "   " and a==b and c=="   ")or(b!= "   " and b==c and a=="   ")or(a!= "   " and a==c and b=="   ")){
        return true;
    }
    else {
        return false;
    }
}

int advanced_move(string tab[]) {
    int pos[24]={0,1,2,3,4,5,6,7,8, 0,3,6,1,4,7,2,5,8 ,0,4,8,2,4,6};
    int i = 0;
    for (int j=0;j<8;j++) {
        if (get_3(tab[pos[i]],tab[pos[i+1]],tab[pos[i+2]])) {
            if (tab[pos[i]]=="   ") {
                return pos[i];
            }
            else if (tab[pos[i+1]]=="   ") {
                return pos[i+1];
            }
            else {
                return pos[i+2];
            }
        }
        i+=3;
    }
    return -1;
}

bool check(string tab[]) {
    if(((tab[0]==tab[1] and tab[1]==tab[2]) and tab[0]!="   ") or ((tab[3]==tab[4] and tab[4]==tab[5])and tab[3]!="   ") or ((tab[6]==tab[7] and tab[7]==tab[8])and tab[6]!="   ")) {
        return true;
    }
    else if((tab[0]==tab[3] and tab[3]==tab[6]and tab[3]!="   ") or (tab[1]==tab[4] and tab[4]==tab[7]and tab[4]!="   ") or (tab[2]==tab[5] and tab[5]==tab[8]and tab[2]!="   ")) {
        return true;
    }
    else if((tab[0]==tab[4] and tab[4]==tab[8]and tab[4]!="   ")or (tab[2]==tab[4] and tab[4]==tab[6])and tab[2]!="   "){
        return true;
    }
    else{return false;}
}

bool check_space(string tab[]) {
    for (int i=0; i<9;i++) {
        if (tab[i]=="   ") {
            return true;
        }
    }
    return false;
}

int tictactoe(string name) {
    srand(time(0));
    int exp = 0;
    bool play_again = true;
    while (play_again) {
        string tab[9];
        for (int i=0;i<9;i++) {
            tab[i]="   ";
        }
        cout << "You choose to play tictactoe with "<<name<<endl<<endl;
        cout << "    TICTACTOE   "<<endl;
        cout <<"-----------------"<<endl;
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
        int x;
        if (random_int_in_range(0,1)) {
            cout << "You start!"<<endl;;
            show_table(tab);
        }
        else {
            cout << name <<" starts!"<<endl;
            x = random_int_in_range(1,9);
            tab[x-1]=" "+cs+" ";
            show_table(tab);
            cout << "Your turn"<<endl;
        }
        //win - Did someone win?, space - Is there any space available?
        bool win=false, space = true;
        string winner = "";

        while (win==false and space==true) {
            cout << "▷ ";
            cin >> x;
            while (x>9 or x<1) {
                cout << "Enter numbers 1-9"<<endl<< "▷ ";
                cin >> x;
            }
            while (tab[x-1]!="   ") {
                cout << "This space is taken"<<endl<< "▷ ";
                cin >> x;
            }
            tab[x-1]=" "+s+" ";
            show_table(tab);

            win = check(tab);
            space = check_space(tab);
            winner = s;

            if (win==false and space==true) {
                cout << name << "'s turn"<<endl;
                if (advanced_move(tab)==-1) {
                    x = random_int_in_range(1,9);
                    while (tab[x-1]!="   ") {
                        x = random_int_in_range(1,9);
                    }
                    tab[x-1]=" "+cs+" ";
                }
                else {
                    tab[advanced_move(tab)]=" "+cs+" ";
                }
                show_table(tab);
                winner = cs;
                win = check(tab);
                space = check_space(tab);

                if (space==true) {
                    cout << "Your turn"<<endl;
                }
            }
        }
        if(space==false and win==false) {
            cout <<"No space left, nobody wins"<<endl;
            exp+=10;
        }
        else {
            cout << winner<<" wins!"<<endl;
            if(winner ==s){cout << "Congratulations!"<<endl;exp+=30;}
            else{cout << "You lose, "<<name<< " wins!"<<endl;exp+=10;}
        }
        cout << "Do you want to play again? (enter \'yes\')"<<endl;
        string answer;
        cout << "▷ ";
        cin >> answer;
        if (answer=="yes") {
            play_again =  true;
        }
        else {
            cout << "You get "<<exp<<" exp"<<endl;
            play_again =  false;
        }
    }
    return exp;
}

void hangman(string name) {
    srand(time(0));
    cout << "You choose to play hangman with "<<name<<endl<<endl;;
    cout << "    HANGMAN   "<<endl;
    cout <<"-----------------"<<endl;

    int exp=0;
    bool play_again = true;
    while (play_again) {
        string words[8] = {"MEADOW", "HANGMAN", "COMPUTER", "RIVER", "TENNIS", "WORLD", "CRITTER", "FOREST"};
        vector <string> wrong;
        string word = words[random_int_in_range(0,7)], answer="";
        int index = 0;

        for (int i=0; i<word.length(); i++) {
            answer+="_";
        }
        cout << answer << endl;
        while (answer!=word and index<10) {
            string letter="";
            cout << "▷ ";
            cin >> letter;
            transform(letter.begin(),letter.end(),letter.begin(),::toupper);

            //if((letter in word and letter not in wrong) and letter not in answer)
            if ((word.find(letter)!=string::npos and find(wrong.begin(), wrong.end(), letter)==wrong.end()) and answer.find(letter)==string::npos) {
                string ans_array[answer.length()];
                for (int i=0; i<answer.length(); i++) {
                    ans_array[i] = answer[i];
                }
                for (int i=0; i<word.length(); i++) {
                    string s = string() + word[i];
                    if (letter==s) {
                        ans_array[i]=letter;
                    }
                }
                string temp_ans = "";
                for (int i=0; i<answer.length(); i++) {
                    temp_ans += ans_array[i];
                }
                answer = temp_ans;

            }
            //if(letter in answer or letter in wrong)
            else if (answer.find(letter)!=string::npos or find(wrong.begin(), wrong.end(), letter)!=wrong.end()) {
                cout << "You already guessed that letter"<<endl;
            }
            else {
                wrong.push_back(letter);
                index++;
                cout << "No "<<letter<<endl;
                cout << "`wrong letters: "<<"[";
                for (int i=0; i<wrong.size(); i++) {
                    cout << wrong[i]<<", ";
                }
                cout << "]"<<endl;
            }
            cout << answer<<endl;
        }
        if(index>=10) {
            cout <<"You lose"<<endl;
            cout <<"The word was: "<<word << endl;
            exp+=0;
        }
        else {
            cout << "Congratulations!"<<endl;exp+=100;
        }
        cout << "Do you want to play again? (enter \'yes\')"<<endl;
        string x;
        cout << "▷ ";
        cin >> x;
        if (x=="yes") {
            play_again =  true;
        }
        else {
            cout << "You get "<<exp<<" exp"<<endl;
            play_again =  false;
        }
    }

}

int main() {
    hangman("Critter");
    return 0;
}