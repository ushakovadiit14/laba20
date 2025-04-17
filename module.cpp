#include "Header.h"
#include <string>
#include <algorithm>



// Задание 1.2
People1::People1(const string& name1, int height1) : Name1(name1), Height1(height1) {}
void People1::print1() const {
    cout << Name1 << ", рост: " << Height1 << " см" << endl;
}



// Задание 1.3
Names2::Names2(const string& name2, const string& surname2, const string& patronymic2)
    : Name2(name2), Surname2(surname2), Patronymic2(patronymic2) {}

void Names2::print2() const 
{
    if (Surname2.empty() && Name2.empty() && Patronymic2.empty()) 
    {
        cout << "(без данных)" << endl;
        return;
    }
    if (!Surname2.empty()) cout << Surname2 << " ";
    if (!Name2.empty()) cout << Name2 << " ";
    if (!Patronymic2.empty()) cout << Patronymic2;
    cout << endl;
}



// Задание 2.4
Employee3::Employee3(const string& name3, Department3* department3)
    : name3(name3), department3(department3) {}

string Employee3::toString3() const 
{
    if (department3 && department3->manager3) 
    {
        if (department3->manager3 == this)
        {
            return name3 + " начальник отдела " + department3->name3;
        } 
        else 
        {
            return name3 + " работает в отделе " + department3->name3 +
                   ", начальник которого " + department3->manager3->name3;
        }
    }
    return name3 + " не назначен в отдел";
}

// Задание 2.4
Department3::Department3(const string& name3, Employee3* manager3)
    : name3(name3), manager3(manager3) {}




// Задание 3.4
Department4::Department4(const string& name4, Employee4* manager4)
    : name4(name4), manager4(manager4) 
    {
    addEmployee4(manager4);
}

void Department4::addEmployee4(Employee4* emp4) 
{
    employees4.push_back(emp4);
    emp4->department4 = this;
}

// Задание 3.4
Employee4::Employee4(const string& name4, Department4* department4)
    : name4(name4), department4(department4) {}

string Employee4::toString4() const
{
    if (department4 && department4->manager4)
    {
        if (department4->manager4 == this) 
        {
            return name4 + " начальник отдела " + department4->name4;
        } 
        else
        {
            return name4 + " работает в отделе " + department4->name4 +
                   ", начальник которого " + department4->manager4->name4;
        }
    }
    return name4 + " не назначен в отдел";
}

vector<Employee4*> Employee4::getDepartmentEmployees4() const 
{
    if (department4) return department4->employees4;
    return {};
}




// Задание 4.5
Names5::Names5(const string& name5)
    : Name5(name5), Surname5(""), Patronymic5("") {}

Names5::Names5(const string& name5, const string& surname5)
    : Name5(name5), Surname5(surname5), Patronymic5("") {}

Names5::Names5(const string& name5, const string& surname5, const string& patronymic5)
    : Name5(name5), Surname5(surname5), Patronymic5(patronymic5) {}

void Names5::print5() const {
    if (Surname5.empty() && Name5.empty() && Patronymic5.empty())
    {
        cout << "(без данных)" << endl;
        return;
    }
    if (!Surname5.empty()) cout << Surname5 << " ";
    if (!Name5.empty()) cout << Name5 << " ";
    if (!Patronymic5.empty()) cout << Patronymic5;
    cout << endl;
}




// Задание 5.1
Pistol6::Pistol6(int initialBullets6) : bullets6(initialBullets6) {}
Pistol6::Pistol6() : bullets6(5) {}

void Pistol6::shoot6() 
{
    if (bullets6 > 0) 
    {
        cout << "Бах!" << endl;
        bullets6--;
    } 
    else 
    {
        cout << "Клац!" << endl;
    }
}

int Pistol6::getBullets6() const 
{
    return bullets6;
}



// функции 

bool isOnlyLetters(const string& str) // проверка строки
{
    return !str.empty() && all_of(str.begin(), str.end(), [](char c)
     {
        return isalpha(static_cast<unsigned char>(c));
    });
}




void runTask1_2() // для задания 1.2
{
    int kol1;
    cout << "Введите количество людей, которых хотите создать: "<< endl;
    cin >> kol1;
    
    if(kol1 < 0)
    {
        cout << "не может быть отрицательным" << endl;
        return;
    }

    vector<People1> peoples1;
    for (int i = 0; i < kol1; i++) 
    {
        string name1;
        int height1;
        cout << "Введите имя " << (i + 1) << " человека: "<< endl;
        cin >> name1;
        if (!isOnlyLetters(name1)) 
        {
            cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
            break;
        }
        cout << "Введите рост " << name1 << ": "<< endl;
        cin >> height1;
        
        if(kol1 < 0)
        {
        cout << "рост не может быть отрицательным" << endl;
        return;
        }

        peoples1.emplace_back(name1, height1);
    }

    cout << endl<< "Информация о людях:"<< endl;
    for (const auto& person1 : peoples1)
    {
        person1.print1();
    }
}





void runTask1_3() // для задания 1.3
{
    int kol2;
    cout << "Введите количество людей, которых хотите создать: "<< endl;
    cin >> kol2;
    
    if(kol2 < 0)
    {
        cout << "не может быть отрицательным" << endl;
        return;
    }
    cin.ignore();

    vector<Names2> nameses2;
    for (int i = 0; i < kol2; i++)
    {
        string name2, surname2, patronymic2;

        cout << endl<< "Введите данные для человека " << (i + 1) << endl;
        cout << "Имя (можно оставить пустым): ";
        getline(cin, name2);
        if (!isOnlyLetters(name2)) 
        {
            cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
            break;
        }
        cout << "Фамилия (можно оставить пустой): "<< endl;
        getline(cin, surname2);
        if (!isOnlyLetters(surname2)) 
        {
            cout << "Ошибка: фамилия должна содержать только буквы. Пропускаем."<< endl;
            break;
        }
        cout << "Отчество (можно оставить пустым): "<< endl;
        getline(cin, patronymic2);
        if (!isOnlyLetters(patronymic2)) 
        {
            cout << "Ошибка: отчество должно содержать только буквы. Пропускаем."<< endl;
            break;
        }

        nameses2.emplace_back(name2, surname2, patronymic2);
    }

    cout << endl<< "Информация о людях:"<< endl;
    for (const auto& person2 : nameses2) 
    {
        person2.print2();
    }
}


void runTask2_4() // для задания 2.4


{
    cout << "Задание 2.4 Сотрудники и отделы:"<< endl;

    int kolvosotr3;
    cout << "Введите количество сотрудников: "<< endl;
    cin >> kolvosotr3;

    if (kolvosotr3 <= 0) 
    {
        cout << "Количество сотрудников должно быть положительным"<< endl;
        return;
    }

    vector<Employee3> employees3;
    for (int i = 0; i < kolvosotr3; i++) 
    {
        string name3;
        cout << "Введите имя " << (i + 1) << " сотрудника: "<< endl;
        cin >> name3;
        if (!isOnlyLetters(name3)) 
        {
            cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
            break;
        }
        employees3.emplace_back(name3);
    }

    cout << "Кто из них начальник? Введите номер (1-" << kolvosotr3 << "): "<< endl;
    int managerIndex3;
    cin >> managerIndex3;

    if (managerIndex3 < 1 || managerIndex3 > kolvosotr3) 
    {
        cout << "Неверный номер сотрудника"<< endl;
        return;
    }

    Department3 it_department3("IT", &employees3[managerIndex3 - 1]);

    for (auto& emp : employees3) 
    {
        emp.department3 = &it_department3;
    }

    for (const auto& emp : employees3) {
        cout << emp.toString3() << endl;
    }
}


void runTask3_4()// для задания 3.4
{ 
    cout << "Задание 3.4 Сотрудники и отделы:"<< endl<< endl;

    int count4;
    cout << "Введите количество сотрудников: "<< endl<< endl;
    cin >> count4;
    
    if (count4 <= 0) {
        cout << "Количество сотрудников должно быть положительным"<< endl;
        return;
    }

    vector<Employee4> employees4;
    for (int i = 0; i < count4; i++)
    {
        string name4;
        cout << "Введите имя " << (i + 1) << " сотрудника: ";
        cin >> name4;
        if (!isOnlyLetters(name4)) 
        {
            cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
            break;
        }
        employees4.emplace_back(name4);
    }

    cout << "Кто из них начальник? Введите номер (1-" << count4 << "):" << endl;
    int managerIndex4;
    cin >> managerIndex4;

    Department4 dep4("IT", &employees4[managerIndex4 - 1]);

    for (int i = 0; i < count4; i++) 
    {
        if (i != managerIndex4 - 1) dep4.addEmployee4(&employees4[i]);
    }

    cout << endl << "Информация о сотрудниках:"<< endl;
    for (const auto& e : employees4) 
    {
        cout << e.toString4() << endl;
    }

    cout << endl << "Выберите сотрудника (1-" << count4 << "), чтобы увидеть его коллег: "<< endl;
    int selected4;
    cin >> selected4;
    Employee4& emp4 = employees4[selected4 - 1];

    cout << endl << "Сотрудники отдела " << emp4.department4->name4 << endl;
    for (const auto& c : emp4.getDepartmentEmployees4()) 
    {
        cout << "- " << c->name4;
        if (c == emp4.department4->manager4) cout << " (начальник)";
        if (c == &emp4) cout << " (выбран)";
        cout << endl;
    }
}


void runTask4_5() // для задания 4.5
{
    int count5;
    cout << "Сколько людей вы хотите создать? "<< endl;
    cin >> count5;
    
    if (count5 <= 0)
    {
        cout << "Количество людей должно быть положительным"<< endl;
        return;
    }
    
    cin.ignore();

    vector<Names5> people5;

    for (int i = 0; i < count5; ++i)
    {
        cout << endl <<"Создание человека " << (i + 1) << endl;
        cout << "1. Только имя"<< endl;
        cout << "2. Имя и фамилия"<< endl;
        cout << "3. Имя, фамилия и отчество"<< endl;
        cout << "Ваш выбор (1-3): ";

        int choice5;
        cin >> choice5;
        cin.ignore();

        string name5, surname5, patronymic5;

        switch (choice5) 
        {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name5);
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                people5.emplace_back(name5);
                break;
            case 2:
                cout << "Введите имя: ";
                getline(cin, name5);
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                cout << "Введите фамилию: ";
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: фамилия должна содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                getline(cin, surname5);
                people5.emplace_back(name5, surname5);
                break;
            case 3:
                cout << "Введите имя: ";
                getline(cin, name5);
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: имя должно содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                cout << "Введите фамилию: ";
                getline(cin, surname5);
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: фамилия должна содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                cout << "Введите отчество: ";
                getline(cin, patronymic5);
                if (!isOnlyLetters(name5)) 
                {
                    cout << "Ошибка: отчество должно содержать только буквы. Пропускаем."<< endl;
                    break;
                }
                people5.emplace_back(name5, surname5, patronymic5);
                break;
            default:
                cout << "Неверный выбор. Пропускаем человека."<< endl;
                break;
        }
    }

    cout << "Информация о людях:"<< endl;
    for (const auto& person : people5) 
    {
        person.print5();
    }
}


void runTask5_1() // для задания 5.1
{
    cout << "Задание 5.1 Пистолет стреляет:"<< endl;

    int initialBullets6;
    char choice6;

    cout << "Хотите ввести количество патронов? (y/n): "<< endl;
    cin >> choice6;
  

    if (choice6 == 'y' || choice6 == 'Y') {
        cout << "Введите начальное количество патронов: "<< endl;
        cin >> initialBullets6;
        
        if (initialBullets6 <= 0) {
        cout << "Количество патронов должно быть положительным"<< endl;
        return;
    }
        
    } else 
    {
        initialBullets6 = 3;
        cout << "Используется значение по умолчанию: " << initialBullets6 << " патрона."<< endl;
    }

    Pistol6 myPistol6(initialBullets6);

    for (int i = 0; i < 5; i++)
    {
        myPistol6.shoot6();
        cout << "Осталось патронов: " << myPistol6.getBullets6() << endl;
    }
}
