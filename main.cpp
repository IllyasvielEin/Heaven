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
#include <memory>
#include "LoadingHeader.h"
//#include "BinaryTree.h"

class Aggregate
{
public:
    Aggregate() = default;
    Aggregate(initializer_list<int> list1)
    {
        int it = 0;
        for ( auto i : list1 )
        {
            num[it] = i;
            size++;
        }
    }
    explicit Aggregate(const vector<int>& v1)
    {
        int it = 0;
        for (auto i = v1.cbegin(), j = v1.cend(); i!=j ; ++i, ++it)
        {
            num[it] = *i;
            size++;
        }
    }
    Aggregate& operator=(Aggregate &B)
    {
        num = B.num;
    }

    int Find(const Aggregate &B);
    bool isSub(const Aggregate &B);
    Aggregate input(istream& is);
private:
    int num[100]{};
    int size = 0;
};

bool Aggregate::isSub(const Aggregate &B) {
    {
        if  ( size > B.size )
        {
            cout << "Error compare, size A is bigger than B." << endl;
            return false;
        }
        else if ( size == B.size && num[0] != B.num[0])
        {
            return false;
        }
        else
        {
            int itA = 0;
            for (auto itB = Find(B); itB+1 <= B.size && itA+1 <= size; itA++,itB++)
            {
                if ( num[itA] != B.num[itB] )
                {
                    return false;
                }
            }
        }
        return true;
    }
}

int Aggregate::Find(const Aggregate &B)
{
    int it = 0;
    for ( auto j : B.num)
    {
        if ( num[0] == j )
        {
            cout << "The head has found: " << it << endl;
            return it;
        }
        it++;
    }
    cout << "Not Found." << endl;
    return 114514;
}

Aggregate Aggregate::input(istream& is)
{
    int tempNum;
    vector<int> tempNumArray;
    while( is >> tempNum,tempNum!=114514 )
    {
        tempNumArray.push_back(tempNum);
    }
    display(tempNumArray);
    Aggregate A(tempNumArray);
    return A;
}

void distinguish(bool flag)
{
    if  ( flag )
    {
        cout << "A is a subAggregate of B.";
    }
    else
    {
        cout << "A is Not a subAggregate of B.";
    }
}

int main()
{


    cout << "Enter Aggregate A:" << endl;

    Aggregate A;

    cout << "Enter Aggregate B:" << endl;
    tempNumArray.clear();
    while( cin >> tempNum )
    {
        tempNumArray.push_back(tempNum);
    }
    display(tempNumArray);
    Aggregate B(tempNumArray);
    distinguish( A.isSub(B) );
    return 0;
}