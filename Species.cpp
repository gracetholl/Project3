#include "Species.h"

Species::Species(string n, string k, string p, string o, string c,string f, string g, string s) {
   name = n;
   kingdom = k;
   phylum = p;
   order = o;
   Class = c;
   family = f;
   genus = g;
   status = s;
}
string Species::GetName() {
    return name;
}
vector<string> Species::GetAllTaxons() {
    vector<string> v {kingdom, phylum, order, Class, family, genus};
    return v;
}
string Species::GetStatus() {
    return status;
}