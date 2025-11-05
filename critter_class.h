// Created by Helena Grzelak on 05/11/2025.
using namespace std;

class critter {
    public:
        string name;
        critter() {
            cout << "A new critter has been born!" << endl;
            name="";
        }
        void info() {
            cout << "INFO"<< endl << "Name: " << name << endl;
        }
};
