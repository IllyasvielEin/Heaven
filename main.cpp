#include <iostream>
#include <fstream>
#include <sstream>
#include "vector"
#include <initializer_list>
#include <utility>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <set>
#include <map>
#include <utility>
using namespace std;
using namespace std::placeholders;

class student
{
public:
    int ID;
    string name;
};
inline bool compareID(const student& stu1,const student& stu2)
{
    return stu1.ID < stu2.ID;
}

bool isShorter(const string a, const string b)
{
    if ( a.size() < b.size() )
        return true;
    else
        return false;
}
bool Smaller(const string& a,int n)
{
    if ( a.size() < n )
        return true;
    else
        return false;
}
void Clear(vector<string> &v1)
{
    fill_n(v1.begin(),v1.size(),"");
}
void enter(vector<string> &v)
{
    string temp;
    while ( cin >> temp , temp != "-p-")
    {
        v.push_back(temp);
    }
}
void display(const vector<int>& v)
{
    for ( const auto& i : v )
    {
        cout << i;
    }
    cout << endl;
}
void display(const deque<int>& d)
{
    for ( const auto& i : d )
    {
        cout << i;
    }
    cout << endl;
}
void display(vector<string> &v)
{
    for ( const auto& i : v )
    {
        cout << i << " ";
    }
    cout << endl;
}
void display(vector<string> &v,vector<string>::iterator& it )
{
    for (;it != v.end();it++ )
    {
        cout << *it << " ";
    }
    cout << endl;
}
void elimDups(vector<string> &v)
{
    stable_sort(v.begin(),v.end(),isShorter);
    auto it = unique(v.begin(),v.end());
    v.erase(it,v.end());
}

int main()
{
    student stu1{1,"Yasuo"};
    student stu2{2,"Yongen"};
    vector<student> temp{stu1,stu2};
    multiset<student, decltype(compareID)*> studentList(compareID);
    studentList.insert(temp.rbegin(),temp.rend());
    for ( const auto& i : studentList )
    {
        cout << i.ID << " " << i.name << endl;
    }


    return 0;
}