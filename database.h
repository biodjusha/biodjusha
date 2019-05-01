#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include "date.h"
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<algorithm>
#include<iterator>
#include<utility>
#include<sstream>

class Database{
public:
    void Add (const Date& date, const string& event);
    void Print (ostream& os) const;
    int RemoveIf (const function<bool(const Date&, const string&)> PRED);
    vector<pair<Date,string>> FindIf (const function<bool(const Date&, const string&)> PRED) const ;
    string Last (const Date& date) const;
private:
    map<Date,vector<string>> vector_data;
    map<Date,set<string>> set_data;
};

ostream& operator<< (ostream& os, const pair<Date, string>& mypair);

#endif // DATABASE_H_INCLUDED
