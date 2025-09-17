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
    bool exists = false; 
};

struct kc
{
    string name;
    int workshop;
    int workshop_in_operation;
    string classes;
    bool exists = false; 
};

void readPipe(pipe& p) {
    cout << "Enter the informations of pipe in this order:\nname, length, diameter, repair (0 for no, 1 for yes)\n";
    cout << "Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.name);

    while (true) {
        cout << "Length: ";
        if (cin >> p.length && p.length>=0 ) break;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Diameter: ";
        if (cin >> p.diameter && p.diameter > 0) break;
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
    p.exists = true; // Marquer comme existant
}

void readCompany(kc& c) {
    cout << "Enter the informations of the company in this order:\nname, number of workshops, number of workshops in operation, classes\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.name);

    while (true) {
        cout << "Number of workshops: ";
        if (cin >> c.workshop && c.workshop>0) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Number of workshops in operation: ";
        if (cin >> c.workshop_in_operation && c.workshop_in_operation<=c.workshop) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Classes: ";
    getline(cin, c.classes);

    c.exists = true; // Marquer comme existant
}

void displayPipe(const pipe& p) {
    if (!p.exists) {
        cout << "No pipe data available. Please add a pipe first.\n";
        return;
    }
    cout << "\nThe informations of pipe are:\n"
         << "name: " << p.name << endl
         << "length: " << p.length << endl
         << "diameter: " << p.diameter << endl
         << "repair or not: " << (p.repair ? "yes" : "no") << endl;
}

void displayCompany(const kc& c) {
    if (!c.exists) {
        cout << "No company data available. Please add a company first.\n";
        return;
    }
    cout << "The informations of the company are:\n"
         << "name: " << c.name << endl
         << "workshop: " << c.workshop << endl
         << "workshop_in_operation: " << c.workshop_in_operation << endl
         << "classes: " << c.classes << endl;
}

void modifyRepair(pipe& p) {
    if (!p.exists) {
        cout << "No pipe data available. Please add a pipe first.\n";
        return;
    }
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

void modifyWorkshops(kc& c) {
    if (!c.exists) {
        cout << "No company data available. Please add a company first.\n";
        return;
    }
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

void saveToFile(const pipe& p, const kc& c, const string& filename) {
    if (!p.exists || !c.exists) {
        cout << "Cannot save. Please add both pipe and company data first.\n";
        return;
    }
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

bool loadFromFile(pipe& p, kc& c, const string& filename) {
    if (!p.exists || !c.exists) {
        cout << "Cannot loadFromFile. Please add both pipe and company data first.\n";
        return false;
    }
    ifstream file(filename);
    if (file.is_open()) {
        file >> p.name >> p.length >> p.diameter >> p.repair;
        p.exists = true;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, c.name);
        file >> c.workshop >> c.workshop_in_operation;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, c.classes);
        c.exists = true;
        file.close();
        cout << "Data loaded from file successfully." << endl;
        return true;
    } else {
        cout << "Unable to open file for loading." << endl;
        return false;
    }
}

int main() {
    pipe p1;
    kc c1;
    string filename = "pipeline_data.txt";
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add pipe\n";
        cout << "2. Add company\n";
        cout << "3. Display all\n";
        cout << "4. Edit pipe\n";
        cout << "5. Edit company\n";
        cout << "6. Save to file\n";
        cout << "7. Load from file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                 readPipe(p1);
                break;
            case 2:
                readCompany(c1);
                break;
            case 3:
                displayPipe(p1);
                displayCompany(c1);
                break;
            case 4:
                modifyRepair(p1);
                break;
            case 5:
                modifyWorkshops(c1);
                break;
            case 6:
                saveToFile(p1, c1, filename);
                break;
            case 7:
                if (!loadFromFile(p1, c1, filename)) {
                    cout << "Error loading data from file." << endl;
                }
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}