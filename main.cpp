#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

// 1.2
class People1 {
private:
    string Name1;
    int Height1;
public:
    People1(const string& name1, int height1);
    void print1() const;
};

// 1.3
class Names2 {
private:
    string Name2, Surname2, Patronymic2;
public:
    Names2(const string& name2, const string& surname2, const string& patronymic2);
    void print2() const;
};

// 2.4
class Employee3; // Forward declaration

class Department3 {
public:
    string name3;
    Employee3* manager3;
    Department3(const string& name3, Employee3* manager3);
};

class Employee3 {
public:
    string name3;
    Department3* department3;
    Employee3(const string& name3, Department3* department3 = nullptr);
    string toString3() const;
};

// 3.4
class Department4;

class Employee4 {
public:
    string name4;
    Department4* department4;
    Employee4(const string& name4, Department4* department4 = nullptr);
    string toString4() const;
    vector<Employee4*> getDepartmentEmployees4() const;
};

class Department4 {
public:
    string name4;
    Employee4* manager4;
    vector<Employee4*> employees4;

    Department4(const string& name4, Employee4* manager4);
    void addEmployee4(Employee4* emp4);
};

// 4.5
class Names5 {
private:
    string Name5, Surname5, Patronymic5;
public:
    Names5(const string& name5);
    Names5(const string& name5, const string& surname5);
    Names5(const string& name5, const string& surname5, const string& patronymic5);
    void print5() const;
};
 
// 5.1
class Pistol6 {
private:
    int bullets6;
public:
    Pistol6(int initialBullets6);
    Pistol6();
    void shoot6();
    int getBullets6() const;
};

void runTask1_2();
void runTask1_3();
void runTask2_4();
void runTask3_4();
void runTask4_5();
void runTask5_1();

bool isValidName(const string& name);
bool oshibkibukvi (const string& input);
