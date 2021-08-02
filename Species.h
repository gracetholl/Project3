#pragma once
#include <string>
#include <vector>
using namespace std;

class Species {
string name;
string kingdom, phylum, order, Class, family, genus;
string status;

public:
Species(string n, string k, string p, string o, string c,string f, string g, string s);
    string GetName();
    vector<string> GetAllTaxons();
    string GetStatus();
};



