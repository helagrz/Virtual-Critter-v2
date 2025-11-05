// Created by Helena Grzelak on 05/11/2025.
using namespace std;

class critter {
public:
    string name, personality;
    int mood=3, hunger=2, level=10;
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
        cout << update_hunger(0)<<endl;
        cout << update_level(0)<<endl;
        cout<<"---------------"<<endl<<endl;
    }

    string update_level(int amount) {
        string x = "";
        level += amount;
        x= x+ "LV " + to_string((level-(level%10))/10) +" "+status_str(level);
        return x;
    }
    string update_hunger(int amount) {
        string x = "";
        hunger += amount;
        if (hunger>10) {
            hunger = 10;
            x = name + " is full! \n";
            x += "Hunger ";
            for (int i=0; i<10;i++) {
                x += "■";
            }
        }
        else {
            x= x+ "Hunger " + status_str(hunger);
        }
        return x;
    }

private:
    string status_str(int n) {
        string x = "";
        if (n>=10) {
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
