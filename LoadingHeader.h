//
// Created by Illya on 2021/3/17.
//

#ifndef HEAVEN_LOADINGHEADER_H
#define HEAVEN_LOADINGHEADER_H
#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

class task_2
{
private:
    set<int> data;

public:
    void creative()
    {
        int temp;
        cout << "Enter, 123 to quit:";
        while ( cin>>temp, temp!=123 )
        {
            data.insert(temp);
        }
        display();
    }
    void display()
    {
        cout << "data: ";
        if ( data.empty() )
        {
            cout << "empty." << endl;
        }
        for (auto i : data )
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void intersect(const task_2& s2, task_2 store)
    {
        for (auto i : data)
        {
            if ( s2.data.find(i)!=s2.data.end() )
            {
                store.data.insert(i);
            }
        }
        store.display();
    }
};

class Demo {
public:
    int* data;
    int size;
    explicit Demo(int maxn)
    {
        size = maxn;
        data = new int[maxn];
    }
    ~Demo() {
        delete data;
    }
};
void print(const Demo& obj) {
    cout << obj.data[0] << obj.data[1] << endl;
}

class Array
{
    int* data{};
    int size = 0;
public:
    Array() = default;
    Array(initializer_list<int> il1)
    {
        data = new int[il1.size()];
        for (auto i: il1)
        {
            data[size++] = i;
        }
    }
    ~Array() = default;
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class Parse
{
private:
    int first{};
    int last{};

public:
//    主要思路是利用字符串流进行顺序读取，依据题目意思，前面没有数字（若有，可接着判断之后是否是“-number”）。
//    更简单的方法大概就是find（-）找到迭代器进行前后字符读取，判断与写入。
    explicit Parse(const string& s1)
    {
        stringstream ss(s1);    //creative a string stream to read.
        int temp;
        char tempChar;
        while (ss.peek() != EOF )   //judge the tail or not.
        {
            ss >> tempChar;         //read one after one.
            if (ss.peek() >= '0' && ss.peek() <= '9' )  //judge digital or not.
            {
                ss >> temp; //digital and then read in temp.
                if ( !first )
                {
                    first = temp;
                }
                else
                {
                    last = temp;
                }
            }
        }
    }

    int getFirst() const
    {
        return first;
    }
    int getLast() const
    {
        return last;
    }
};

class people {
protected:
    // 是个人总得有个名字吧
    string name = "null";
};
class student : virtual public people
{
public:
    // 写作业
    void doHomework()
    {
        cout << name << " is doing homework." << endl;
    }
};
class teacher : virtual public people
{
public:
    // 发工资
    void getPaid()
    {
        cout << name << " got paid." << endl;
    }
};
class assistant : public teacher, public student
{

public:

    // 批改作业
    void gradeHomework()
    {
        cout << name << " grade homework." << endl;
    }
};// 助教类，既是学生，也算老师，在学生和老师的基础上，还要批改作业

class life
{
public:
    virtual~ life() = default;

    virtual void canFly() = 0;
    virtual void fly() = 0;
};

class Yasuo : public life
{
private:
    bool can = false;

public:

    void canFly() override;
    void fly() override;
};

void Yasuo::canFly()
{
    cout << "Yasuo can fly?<y/n>";
    char temp;
    cin >> temp;
    if( temp == 'y' )
    {
        can = true;
    }
}

void Yasuo::fly()
{
    if ( can )
    {
        cout << "Hasaki!" << endl;
    }
    else
    {
        cout << "yasuo cant Fly!" << endl;
    }
}


#endif //HEAVEN_LOADINGHEADER_H
