#include <iostream>
#include <fstream>
#include <string>
#include <limits>

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

// Fonction pour lire les données d'un pipe
pipe readPipe() {
    pipe p;
    cout << "Enter the informations of pipe in this order:\nname, length, diameter, repair (0 for no, 1 for yes)\n";
    cout << "Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.name);

    while (true) {
        cout << "Length: ";
        if (cin >> p.length) break;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Diameter: ";
        if (cin >> p.diameter) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int repairInput;
    while (true) {
        cout << "Repair (0 for no, 1 for yes): ";
        if (cin >> repairInput && (repairInput == 0 || repairInput == 1)) {
            p.repair = repairInput;
            break;
        }
        cout << "Invalid input. Please enter 0 or 1.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return p;
}

// Fonction pour lire les données d'une company
company readCompany() {
    company c;
    cout << "Enter the informations of the company in this order:\nname, number of workshops, number of workshops in operation, classes\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.name);

    while (true) {
        cout << "Number of workshops: ";
        if (cin >> c.workshop) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Number of workshops in operation: ";
        if (cin >> c.workshop_in_operation) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Classes: ";
    getline(cin, c.classes);

    return c;
}

// Fonction pour afficher les données d'un pipe
void displayPipe(const pipe& p) {
    cout << "\nThe informations of pipe are:\n"
         << "name: " << p.name << endl
         << "length: " << p.length << endl
         << "diameter: " << p.diameter << endl
         << "repair or not: " << (p.repair ? "yes" : "no") << endl;
}

// Fonction pour afficher les données d'une company
void displayCompany(const company& c) {
    cout << "The informations of the company are:\n"
         << "name: " << c.name << endl
         << "workshop: " << c.workshop << endl
         << "workshop_in_operation: " << c.workshop_in_operation << endl
         << "classes: " << c.classes << endl;
}

// Fonction pour modifier l'indicateur "repair" d'un pipe
void modifyRepair(pipe& p) {
    int repairInput;
    while (true) {
        cout << "Set repair status (0 for no, 1 for yes): ";
        if (cin >> repairInput && (repairInput == 0 || repairInput == 1)) {
            p.repair = repairInput;
            break;
        }
        cout << "Invalid input. Please enter 0 or 1.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Fonction pour démarrer ou arrêter un atelier dans une company
void modifyWorkshops(company& c) {
    int choice;
    cout << "Do you want to start (1) or stop (0) a workshop? ";
    cin >> choice;

    if (choice == 1) {
        if (c.workshop_in_operation < c.workshop) {
            c.workshop_in_operation++;
        } else {
            cout << "All workshops are already in operation." << endl;
        }
    } else if (choice == 0) {
        if (c.workshop_in_operation > 0) {
            c.workshop_in_operation--;
        } else {
            cout << "No workshops are in operation." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }
}

// Fonction pour sauvegarder les données dans un fichier
void saveToFile(const pipe& p, const company& c, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << p.name << " " << p.length << " " << p.diameter << " " << p.repair << endl;
        file << c.name << " " << c.workshop << " " << c.workshop_in_operation << " " << c.classes << endl;
        file.close();
        cout << "Data saved to file successfully." << endl;
    } else {
        cout << "Unable to open file for saving." << endl;
    }
}

// Fonction pour charger les données depuis un fichier
bool loadFromFile(pipe& p, company& c, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> p.name >> p.length >> p.diameter >> p.repair;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, c.name);
        file >> c.workshop >> c.workshop_in_operation;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, c.classes);
        file.close();
        cout << "Data loaded from file successfully." << endl;
        return true;
    } else {
        cout << "Unable to open file for loading." << endl;
        return false;
    }
}

int main() {
    
    return 0;
}
