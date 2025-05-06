#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Student {
    int roll;
    char name[50];
    char div;
    char address[100];
};
class StudentManager {
public:
    void create();
    void display();
    int search();
    void Delete();
};
void StudentManager::create() {
    char ans;
    ofstream fout("stud.txt", ios::app | ios::binary);
    if (!fout) {
        cout << "\nError opening file!";
        return;
    }
    do {
        Student rec;
        cout << "\nEnter Roll No: ";
        cin >> rec.roll;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(rec.name, 50);
        cout << "Enter Division: ";
        cin >> rec.div;
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(rec.address, 100);

        fout.write(reinterpret_cast<char*>(&rec), sizeof(Student));
        cout << "\nDo you want to add more records? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    fout.close();
}

void StudentManager::display() {
    ifstream fin("stud.txt", ios::binary);
    if (!fin) {
        cout << "\nError opening file!";
        return;
    }
    Student rec;
    cout << "\nStudent Records:\n";
    cout << "\nRoll\tName\tDiv\tAddress";
    while (fin.read(reinterpret_cast<char*>(&rec), sizeof(Student))) {
        if (rec.roll != -1) {
            cout << "\n" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.address;
        }
    }
    fin.close();
}

int StudentManager::search() {
    int r, index = 0;
    ifstream fin("stud.txt", ios::binary);
    if (!fin) {
        cout << "\nError opening file!";
        return -1;
    }
    cout << "\nEnter Roll No to search: ";
    cin >> r;
    Student rec;
    while (fin.read(reinterpret_cast<char*>(&rec), sizeof(Student))) {
        if (rec.roll == r) {
            cout << "\nRecord Found!\n";
            cout << "Roll\tName\tDiv\tAddress\n";
            cout << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.address;
            fin.close();
            return index;
        }
        index++;
    }
    fin.close();
    cout << "\nRecord Not Found!";
    return -1;
}

void StudentManager::Delete() {
    int r;
    cout << "\nEnter Roll No to delete: ";
    cin >> r;

    fstream file("stud.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "\nError opening file!";
        return;
    }
    Student rec;
    while (file.read(reinterpret_cast<char*>(&rec), sizeof(Student))) {
        if (rec.roll == r) {
            rec.roll = -1;
            strcpy(rec.name, "NULL");
            rec.div = 'N';
            strcpy(rec.address, "NULL");
            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
            file.write(reinterpret_cast<char*>(&rec), sizeof(Student));
            cout << "\nRecord Deleted!";
            file.close();
            return;
        }
    }
    file.close();
    cout << "\nRecord Not Found!";
}

int main() {
    StudentManager obj;
    int choice;
    char ans;
    do {
        cout << "\n***** Student Information *****";
        cout << "\n1. Create\n2. Display\n3. Delete\n4. Search\n5. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.Delete();
                break;
            case 4:
                obj.search();
                break;
            case 5:
                return 0;
            default:
                cout << "\nInvalid Choice!";
        }
        cout << "\nDo you want to continue? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

