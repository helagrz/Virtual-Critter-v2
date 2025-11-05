// Created by Helena Grzelak on 05/11/2025.
using namespace std;

class critter {
public:
    string name, personality;
    int mood=3, hunger=5, level=11;
    critter() {
        cout << "A new critter has been born!" << endl;
        name="";
    }
    void info() {
        cout << "   INFO"<< endl;
        cout<<"---------------"<<endl;
        cout<< "Name: " << name << endl<<"Level: "<<to_string((level-(level%10))/10)<<endl;
        cout<<"---------------"<<endl<<endl;
    }
    void status() {
        cout << "   STATUS"<< endl;
        cout<<"---------------"<<endl;
        cout << "Hunger "<<status_str(hunger)<<endl;
        cout << "LV "<< to_string((level-(level%10))/10) << " "<<status_str(level)<<endl;
        cout<<"---------------"<<endl<<endl;
    }

    string status_str(int n) {
        string x = "";
        if (n>10) {
            n = n%10;
        }
        for (int i=0; i<n;i++) {
            x += "■";
        }
        for (int i=0; i<(10-n);i++) {
            x += "□";
        }
        return x;
    }
};
