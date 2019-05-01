
#include "database.h"
#include "date.h"


 using namespace std;


    void Database::Add(const Date& date, const string& event){
        if (!set_data[date].count(event)){
            vector_data[date].push_back(event);
            set_data[date].insert(event);
        }
    }

    void Database::Print (ostream& os) const {
        for (const auto& a:vector_data){
            for (const auto& v: a.second){
                os<<a.first<<" "<<v<<endl;//
            }
        }
    }

    int Database::RemoveIf (const function<bool(const Date&, const string&)> PRED){
        int sum = 0;
        for (auto& a:vector_data){
            auto it = a.second.begin();
            auto itend=a.second.end();
            for (; it<itend; ){
                if (PRED(a.first,*it)){
                    set_data[a.first].erase(*it);
                    itend=remove (a.second.begin(), itend, *it);
                    sum++;
                }
                else
                it++;
            }
            a.second.erase(itend, a.second.end());
        }
        return sum;
    }

    vector<pair<Date,string>> Database::FindIf(const function<bool(const Date&, const string&)> PRED) const {
        vector<pair<Date,string>> sum;
        for (const auto& a:vector_data){
            for (const auto& v:a.second){
                if (PRED(a.first,v)){
                    sum.push_back(make_pair(a.first, v));
                }
            }
        }
        return sum;
    }

    string Database::Last(const Date& date) const{
        const auto It=vector_data.upper_bound(date);
        if(It==vector_data.begin()){
            return "No entries";
        }

        stringstream str;
        str<< (*prev(It)).first;
        string answer;
        str>>answer;
        return answer+" "+(*prev(It)).second.back();
    }

    ostream& operator<< (ostream& os, const pair<Date, string>& mypair){
        os<<mypair.first<<" "<<mypair.second;
        return os;
    }



