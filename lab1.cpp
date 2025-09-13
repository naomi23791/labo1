#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct pipe
{
    string name;
    float length;
    int diameter;
    bool repair;
};
struct company
{
    string name;
    int workshop;
    int workshop_in_operation;   
    string classes;
};

int main()
{
    cout << "Hello World!" << endl;
    pipe p1;
    company c1;

    // Saisie sécurisée pour pipe
    cout << "Enter the informations of pipe in this order:\nname, length, diameter, repair (0 for no, 1 for yes)\n";
    cout << "Name: ";
    getline(cin, p1.name);

    // Saisie sécurisée pour length
    while (true) {
        cout << "Length: ";
        if (cin >> p1.length) break;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    

    // Saisie sécurisée pour diameter
    while (true) {
        cout << "Diameter: ";
        if (cin >> p1.diameter) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Saisie sécurisée pour repair
    int repairInput;
    while (true) {
        cout << "Repair (0 for no, 1 for yes): ";
        if (cin >> repairInput && (repairInput == 0 || repairInput == 1)) {
            p1.repair = repairInput;
            break;
        }
        cout << "Invalid input. Please enter 0 or 1.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    // Saisie sécurisée pour company
    cout << "Enter the informations of the company in this order:\nname, number of workshops, number of workshops in operation, classes\n";
    getline(cin, c1.name);

    // Saisie sécurisée pour workshop
    while (true) {
        cout << "Number of workshops: ";
        if (cin >> c1.workshop) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Saisie sécurisée pour workshop_in_operation
    while (true) {
        cout << "Number of workshops in operation: ";
        if (cin >> c1.workshop_in_operation) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    cout << "Classes: ";
    getline(cin, c1.classes);

    cout << "\nThe informations of pipe are:\n"
         << "name: " << p1.name << endl
         << "length: " << p1.length << endl
         << "diameter: " << p1.diameter << endl
         << "repair or not: " << (p1.repair ? "yes" : "no") << endl;

    cout << "The informations of the company are:\n"
         << "name: " << c1.name << endl
         << "workshop: " << c1.workshop << endl
         << "workshop_in_operation: " << c1.workshop_in_operation << endl
         << "classes: " << c1.classes << endl;

    return 0;
}