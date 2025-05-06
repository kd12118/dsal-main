
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    char label[60];
    int chcount;
    node *child[50];
} *root;

class General {
public:
    void insert();
    void display();
    General() {
        root = NULL;
    }
};

void General::insert() {
    root = new node();
    cout << "Enter the name of the book: ";
    cin >> root->label;

    cout << "Enter the total number of chapters in the book: ";
    cin >> root->chcount;

    for(int i = 0; i < root->chcount; i++) {
        root->child[i] = new node();
        cout << "Enter the name of chapter: ";
        cin >> root->child[i]->label;

        cout << "Enter the number of sections: ";
        cin >> root->child[i]->chcount;

        for(int j = 0; j < root->child[i]->chcount; j++) {
            root->child[i]->child[j] = new node();
            cout << "Enter the name of section: ";
            cin >> root->child[i]->child[j]->label;

            cout << "Enter the number of sub-sections: ";
            cin >> root->child[i]->child[j]->chcount;

            for(int k = 0; k < root->child[i]->child[j]->chcount; k++) {
                root->child[i]->child[j]->child[k] = new node();
                cout << "Enter the name of sub-section: ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
            break;
        }
    }
}

void General::display() {
    if(root != NULL) {
        cout << "\n********** Hierarchy of Book **********\n";
        cout << "Book Name: " << root->label << endl;
        
        for(int i = 0; i < root->chcount; i++) {
            cout << "-- " << root->child[i]->label << endl;

            for(int j = 0; j < root->child[i]->chcount; j++) {
                cout << "---- " << root->child[i]->child[j]->label << endl;

                for(int k = 0; k < root->child[i]->child[j]->chcount; k++) {
                    cout << "------ " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    } else {
        cout << "No book data available.\n";
    }
}

int main() {
    General g;
    int ch;

    do {
        cout << "\n~~~~~ MENU ~~~~~\n";
        cout << "1. Insert\n2. Display\n3. Exit\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                g.insert();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    } while(ch != 3);

    return 0;
}

