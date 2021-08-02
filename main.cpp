#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "Species.h"
#include "BST.h"
#include "RBT.h"
using namespace std;
void printMenu() { // basic menu
    cout << "Select a Menu Option to Continue:" << endl;
    cout << "1. Check IUCN Status (BST)" << endl;
    cout << "2. Check IUCN Status (RBT)" << endl;
    cout << "3. List Endangered Species by Type" << endl;
    cout << "4. Exit" << endl;
}
void printTwo() { // option 3 menu
    cout << "See Endangered Species By: " << endl;
    cout << "1. Kingdom" << endl;
    cout << "2. Phylum" << endl;
    cout << "3. Order" << endl;
    cout << "4. Class" << endl;
    cout << "5. Family" << endl;
    cout << "6. Genus" << endl;
}
void TaxonPrint(vector<Species> EN, string taxon, int index) { // print option 3 species
    cout << "--------------------------" << endl;
    int count = 1;
    for(int i = 0; i < EN.size(); i++) {
        if(EN.at(i).GetAllTaxons().at(index) == taxon) {
            cout << count << ". " << EN.at(i).GetName() << endl;
            count++;
        }

    }
    if (count == 1) // taxon does not exist or contains no endangered species
        cout << "There are no endangered species within the " << taxon << " taxon." << endl;
    cout << endl;
}
string formatString(string s) { // converts all to uppercase
    string format;
    for(int i = 0; i < s.size(); i++){
        format += toupper(s.at(i));
    }
    return format;
}
int main() {
    // read in data
    BST tree;
    RBT rbt;
    Node* root = nullptr;
    RBTNode* rt = nullptr;
    vector<Species> endangered;
    ifstream file("species.csv");
    if(file.is_open()) {
        string line;
        getline(file,line);
        while(getline(file,line)) { // reads all rows in file
            istringstream stream(line);
            string temp, name, k, p, o, c, f, g, status;
            getline(stream, temp, ',');
            getline(stream, temp, ',');
            getline(stream, name, ',');
            getline(stream, k, ',');
            getline(stream, p, ',');
            getline(stream, o, ',');
            getline(stream, c, ',');
            getline(stream, f, ',');
            getline(stream, g, ',');
            getline(stream, temp, ',');
            getline(stream, status, ',');
            name = formatString(name);
            g = formatString(g);
            Species s(name,k,p,o,c,f,g,status);
            root = tree.insert(root, s);
            rt = rbt.basicInsert(rt, s);
            rbt.fixTree(rt);
            if(status == "Endangered" || status == "Critically Endangered") {
                endangered.push_back(s);
            }

        }

    }
    // menu
    cout << "Hello, Welcome to the Conservation Status Checker!" << endl;
    cout << endl;
    printMenu();
    int userNum;
    cin >> userNum;
    string blank;
    getline(cin, blank);
    while (userNum != 4) {
        if (userNum == 1) { // BST search for species
            cout << endl;
            cout << "Please Enter a Scientific Name: " << endl;
            string userData;

            getline(cin, userData);
            string f = formatString(userData);
            Node* temp = tree.search(root, f);
            if (temp == nullptr)
                cout << userData << " is not on the IUCN Red List." << endl;
            else
                cout << userData << " has an IUCN status of " << temp->s.GetStatus() << endl;
            cout << endl;
        }
        if (userNum == 2) { // RBT search for species
            cout << endl;
            cout << "Please Enter a Scientific Name: " << endl;
            string userData;

            getline(cin, userData);
            string f = formatString(userData);
            RBTNode* temp = rbt.search(rt, f);
            if (temp == nullptr)
                cout << userData << " is not on the IUCN Red List." << endl;
            else
                cout << userData << " has an IUCN status of " << temp->s.GetStatus() << endl;
            cout << endl;
        }
        if (userNum == 3) { // Choose taxon, prints endangered species
            cout << endl;
            printTwo();
            int userChoice;
            cin >> userChoice;
            string kingdom, phylum, order, clss, family, genus;
            switch(userChoice) {
                case 1: {
                    cout << "Enter Kingdom Name: ";
                    cin >> kingdom;
                    cout << endl;
                    cout << "Endangered Species of Kingdom " << kingdom << endl;
                    string temp = formatString(kingdom);
                    TaxonPrint(endangered, temp, 0);
                    break;
                }
                case 2: {
                    cout << "Enter Phylum Name: ";
                    cin >> phylum;
                    cout << endl;
                    cout << "Endangered Species of Phylum " << phylum << endl;
                    string temp = formatString(phylum);
                    TaxonPrint(endangered, temp, 1);
                    break;
                }
                case 3: {
                    cout << "Enter Order Name: ";
                    cin >> order;
                    cout << endl;
                    cout << "Endangered Species of Order " << order << endl;
                    string temp = formatString(order);
                    TaxonPrint(endangered, temp, 2);
                    break;
                }
                case 4: {
                    cout << "Enter Class Name: ";
                    cin >> clss;
                    cout << endl;
                    cout << "Endangered Species of Class " << clss << endl;
                    string temp = formatString(clss);
                    TaxonPrint(endangered, temp, 3);
                    break;
                }
                case 5: {
                    cout << "Enter Family Name: ";
                    cin >> family;
                    cout << endl;
                    cout << "Endangered Species of Family " << family << endl;
                    string temp = formatString(family);
                    TaxonPrint(endangered, temp, 4);
                    break;
                }
                case 6: {
                    cout << "Enter Genus Name: ";
                    cin >> genus;
                    cout << endl;
                    cout << "Endangered Species of Genus " << genus << endl;
                    string temp = formatString(genus);
                    TaxonPrint(endangered, temp, 5);
                    break;
                }
                default: // other cases not selected
                    cout << "Invalid Selection" << endl;

            }
            // time of traversals for comparison
            auto start = chrono::high_resolution_clock::now();
            tree.InOrder(root);
            auto stop = chrono::high_resolution_clock::now();
            auto time = chrono::duration_cast<chrono::nanoseconds>(stop - start);
            cout << "BST Traversal Time: " << time.count() << " nanoseconds" << endl;
            start = chrono::high_resolution_clock::now();
            rbt.InOrder(rt);
            stop = chrono::high_resolution_clock::now();
            time = chrono::duration_cast<chrono::nanoseconds>(stop - start);
            cout << "RBT Traversal Time: " << time.count() << " nanoseconds" << endl;
            cout << endl;

        }
        printMenu();
        cin >> userNum; // repeat or exit
        getline(cin, blank);
    }
    cout << "Bye!" << endl;


    return 0;
}
