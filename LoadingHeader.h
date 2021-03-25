//
// Created by Illya on 2021/3/17.
//

#ifndef HEAVEN_LOADINGHEADER_H
#define HEAVEN_LOADINGHEADER_H
#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;
class student
{
public:
    int ID{};
    string name{};
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
void input( shared_ptr<vector<int>> *pv )
{
    int x;
    while ( cin >> x )
    {
        (*pv)->push_back(x);
    }
}

//int i = 1;
//class numbered
//{
//public:
//    numbered() { a = i++;};
//    numbered(numbered& );
//    numbered& operator= (const numbered& );
//    int a;
//};
//numbered &numbered::operator=(const numbered &s) {
//    a = s.a + 1;
//    return *this;
//}
//
//numbered::numbered(numbered &s) {
//    a = i++;
//}
//
//void f(const numbered& s)
//{
//    cout << s.a << endl;
//}
//class HasPtr
//{
//    friend void swap(HasPtr&,HasPtr&);
//public:
//    ~HasPtr(){ if ( i == 0 ) delete p; else i--;};
//    explicit HasPtr(const string& s);
//    HasPtr(HasPtr&);
//    HasPtr& operator=(HasPtr);
//private:
//    string* p = new string;
//    int i = 0;
//};
//
//void swap(HasPtr& p1,HasPtr&p2)
//{
//    using std::swap;
//    swap(p1.p,p2.p);
//    cout << "Swap ptr." << endl;
//    swap(p1.i,p2.i);
//    cout << "Swap i." <<endl;
//}
//
//HasPtr::HasPtr(const string& s) {
//    *p = s;
//    i++;
//}
//
//HasPtr::HasPtr(HasPtr &inl) {
//    swap(*this,inl);
//}
//
//HasPtr &HasPtr::operator=(HasPtr pl) {
//    using std::swap;
//    swap(*this,pl);
//    return *this;
//}
//class Quote
//{
//public:
//    Quote() = default;
//    Quote(string &book, string &name,double sales_price)
//            : bookNo(book), bookName(name), price(sales_price) {};
//
//    istream& read(istream&);
//    string isbn() const { return bookNo; };
//    string name() const { return bookName; };
//    virtual double net_price(size_t n) const { return n*price; };
//    virtual ~Quote() = default;
//private:
//    string bookNo;
//    string bookName;
//protected:
//    double price = 0.0;
//};
//
//istream &Quote::read(istream &is) {
//    cout << "Enter book's isbn ,book name and book price." << endl;
//    is >> bookNo >> bookName >> price;
//    return is;
//}
//
//class bulk_Quote : public Quote
//{
//public:
//    bulk_Quote() = default;
//    bulk_Quote(string &book, string &name,double sales_price, size_t n, double dc)
//            : Quote(book,name,sales_price), min_qty(n), discount(dc) {};
//
//    double net_price(size_t n) const override {
//        if ( n > min_qty )
//            return n*price*(1-discount);
//    } ;
//private:
//    size_t min_qty{};
//    double discount = 0.0;
//};
//double print_total(ostream& os, const Quote& item, size_t n)
//{
//    double ret = item.net_price(n);
//    os <<  "Book : " << item.name() << endl
//       << "ISBN: " << item.isbn() << endl
//       << "#sold: " << n << " total due: " << ret << endl;
//    return ret;
//}

#endif //HEAVEN_LOADINGHEADER_H
