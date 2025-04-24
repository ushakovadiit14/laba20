
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

bool oshibki (const string& input) {
    // проверяем длинну: либо просто 0, либо другое число, но длинна тогда должна быть больше 10
    if (input != "0" && input.length() < 1) {
        return false;
    }
    // Число не может начинаться с "0" (если это не сам 0). например: 0000566445656
    if (input.length() > 1 && input[0] == '0') {
        return false; // начинается с 0, но при этом не 0
    }
    // проверка на цифры и знак
    if (input[0] == '-' && input.length() == 1)
    {
        return false; // только знак 
    }
    if(input == "0"){
        return false;
    }
    // В числе не может быть букв и каких то других символов, кроме минуса вначале. например: 345677ваап56898
    for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
        {
            return false; // не является цифрой
        }
    }
    return true; // все символы - цифры
}


bool OshibkiBukvi(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) { // Проверяем, является ли символ буквой
            return false; // Если хотя бы один символ не буква, возвращаем false
        }
    }
    return true; // Все символы - буквы
}



void runTask1_2() // для задания 1.2
{
    int kol1;
    string kol1str;
    cout << "Задание 1.2 Человек:"<< endl<< endl;
    do
    {
    cout << "Введите количество людей, которых хотите создать: "<< endl;
    cin >> kol1str;
    
    // проверяем, чтобы все условия выполнились
        if (!oshibki(kol1str))
        {
            cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
        }
    }
    while (!oshibki(kol1str)); // цикл будет, пока есть ошибки при вводе
    kol1=stoi(kol1str);
    if (kol1 <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 1"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> kol1;
    }

    

    vector<People1> peoples1;
    for (int i = 0; i < kol1; i++) 
    {
        string name1;
        int height1;
        string height1str;
    
    do {
        cout << "Введите имя " << (i + 1) << " человека: "; // Используем wcout
        cin >> name1; // Используем wcin

        // Проверяем, чтобы все условия выполнились
        if (!OshibkiBukvi(name1)) {
            cout << "Ошибка! Введите корректное имя." << endl;
            cout << "Попробуйте еще раз!" << endl;
        }
    } while (!OshibkiBukvi(name1));

    
    do
    {
    cout << "Введите рост " << name1 << ": "<< endl;
    cin >> height1str;
        
    // проверяем, чтобы все условия выполнились
    if (!oshibki(height1str))
        {
            cout << "Введите рост заново от 30 до 250 " << endl << "Попробуйте еще раз!)" << endl ;
        }
        
    }
    while (!oshibki(height1str)); // цикл будет, пока есть ошибки при вводе
    height1=stoi(height1str);
    
    if (height1 <= 30 || height1 >= 250) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите рост заново от 30 до 250"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> height1;
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
    string kol2str;
    cout << "Задание 1.3 Имена:"<< endl<< endl;
    do
        {
        cout << "Введите количество людей, которых хотите создать: "<< endl;
        cin >> kol2str;
        
        // проверяем, чтобы все условия выполнились
        if (!oshibki(kol2str))
            {
                cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
            }
        
    }
    while (!oshibki(kol2str)); // цикл будет, пока есть ошибки при вводе
    kol2=stoi(kol2str);
    
    if (kol2 <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 1"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> kol2;
    }
    
    cin.ignore();

    vector<Names2> nameses2;
    for (int i = 0; i < kol2; i++)
    {
        string name2, surname2, patronymic2;

        cout << endl<< "Введите данные для человека " << (i + 1) << endl;
        do
        {
        do {
        cout << "Имя (можно оставить пустым): "<< endl;
        getline(cin, name2);

            // Проверяем, чтобы все условия выполнились
            if (!OshibkiBukvi(name2)) {
                cout << "Ошибка! Введите корректное имя." << endl;
                cout << "Попробуйте еще раз!" << endl;
            }
        } while (!OshibkiBukvi(name2));

        
        do {
        cout << "Фамилия (можно оставить пустой): "<< endl;
        getline(cin, surname2);

            // Проверяем, чтобы все условия выполнились
            if (!OshibkiBukvi(surname2)) {
                cout << "Ошибка! Введите корректную фамилию." << endl;
                cout << "Попробуйте еще раз!" << endl;
            }
        } while (!OshibkiBukvi(surname2));
        
        
        do {
        cout << "Отчество (можно оставить пустым): "<< endl;
        getline(cin, patronymic2);

            // Проверяем, чтобы все условия выполнились
            if (!OshibkiBukvi(patronymic2)) {
                cout << "Ошибка! Введите корректное отчество." << endl;
                cout << "Попробуйте еще раз!" << endl;
            }
        } while (!OshibkiBukvi(patronymic2));
        
            if ( name2.empty() && surname2.empty() && patronymic2.empty() ){
                cout<<"человек должен иметь хотя бы что то одно"<< endl;
            }
        }while(name2.empty() && surname2.empty() && patronymic2.empty());

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
    string kolvosotr3str;

    do
    {
    cout << "Введите количество сотрудников: "<< endl;
    cin >> kolvosotr3str;
        
        // проверяем, чтобы все условия выполнились
        if (!oshibki(kolvosotr3str))
            {
                cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
            }
        
    }
    while (!oshibki(kolvosotr3str)); // цикл будет, пока есть ошибки при вводе
    kolvosotr3=stoi(kolvosotr3str);
    
    if (kolvosotr3 <= 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 2"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> kolvosotr3;
    }

    vector<Employee3> employees3;
    for (int i = 0; i < kolvosotr3; i++) 
    {
        string name3;
        
        do {
        cout << "Введите имя " << (i + 1) << " сотрудника: "<< endl;
        cin >> name3;

            // Проверяем, чтобы все условия выполнились
            if (!OshibkiBukvi(name3)) {
                cout << "Ошибка! Введите корректное отчество." << endl;
                cout << "Попробуйте еще раз!" << endl;
            }
        } while (!OshibkiBukvi(name3));
        
        employees3.emplace_back(name3);
    }
    
    int managerIndex3;
    do
    {
    cout << "Кто из них начальник? Введите номер (1-" << kolvosotr3 << "): "<< endl;

    cin >> managerIndex3;

        if ((managerIndex3 < 1 ) || (managerIndex3 > kolvosotr3)) 
        {
            cout << "Неверный номер сотрудника"<< endl;
        }
    }
    while((managerIndex3 < 1 )|| (managerIndex3 > kolvosotr3));

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
    string count4str;

    do
    {
    cout << "Введите количество сотрудников: "<< endl;
    cin >> count4str;
        
        // проверяем, чтобы все условия выполнились
        if (!oshibki(count4str))
            {
                cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
            }
        
    }
    while (!oshibki(count4str)); // цикл будет, пока есть ошибки при вводе
    count4=stoi(count4str);
    
    if (count4 <= 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 2"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> count4;
    }


    vector<Employee4> employees4;
    for (int i = 0; i < count4; i++)
    {
        string name4;
        
        do {
        cout << "Введите имя " << (i + 1) << " сотрудника: ";
        cin >> name4;

            // Проверяем, чтобы все условия выполнились
            if (!OshibkiBukvi(name4)) {
                cout << "Ошибка! Введите корректное имя." << endl;
                cout << "Попробуйте еще раз!" << endl;
            }
        } while (!OshibkiBukvi(name4));
        
        employees4.emplace_back(name4);
    }

    int managerIndex4;
    do
    {
    cout << "Кто из них начальник? Введите номер (1-" << count4 << "): "<< endl;
    cin >> managerIndex4;

        if ((managerIndex4 < 1) || (managerIndex4 > count4)) 
        {
            cout << "Неверный номер сотрудника"<< endl;
        }
    }
    while((managerIndex4 < 1 )||( managerIndex4 > count4)) ;

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

    int selected4;
    do
    {
    cout << endl << "Выберите сотрудника (1-" << count4 << "), чтобы увидеть его коллег: "<< endl;
    cin >> selected4;

        if ((selected4 < 1) || (selected4 > count4)) 
        {
            cout << "Неверный номер сотрудника"<< endl;
        }
    }
    while((selected4 < 1 )||( selected4 > count4)) ;


    
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
    string count5str;
    cout << "Задание 4.5 Создаем Имена:"<< endl<< endl;
    
    do
    {
    cout << "Сколько людей вы хотите создать? "<< endl;
    cin >> count5str;
        
        // проверяем, чтобы все условия выполнились
        if (!oshibki(count5str))
            {
                cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
            }
        
    }
    while (!oshibki(count5str)); // цикл будет, пока есть ошибки при вводе
    count5=stoi(count5str);
    
    if (count5 <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 1"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> count5;
    }

    cin.ignore();

    vector<Names5> people5;

    for (int i = 0; i < count5; ++i)
    {
        cout << endl <<"Создание человека " << (i + 1) << endl;
        cout << "1. Только имя"<< endl;
        cout << "2. Имя и фамилия"<< endl;
        cout << "3. Имя, фамилия и отчество"<< endl;

        int choice5;
        do
        {
        cout << "Ваш выбор (1-3): ";
        cin >> choice5;
        cin.ignore();

            if ((choice5 < 1) || (choice5 > 3)) 
            {
                cout << "от 1 до 3!!!"<< endl;
            }
        }
        while ((choice5 < 1 ) || (choice5 > 3));
        


        string name5, surname5, patronymic5;

        switch (choice5) 
        {
            case 1:
                
                do {
                cout << "Введите имя: ";
                getline(cin, name5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(name5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(name5));
                
                people5.emplace_back(name5);
                break;
            case 2:
            
                do {
                cout << "Введите имя: ";
                getline(cin, name5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(name5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(name5));
            
                do {
                cout << "Введите фамилию: ";
                getline(cin, surname5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(surname5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(surname5));
                
                people5.emplace_back(name5, surname5);
                break;
            case 3:
                do {
                cout << "Введите имя: ";
                getline(cin, name5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(name5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(name5));
                
                do {
                cout << "Введите фамилию: ";
                getline(cin, surname5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(surname5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(surname5));
                
                do {
                cout << "Введите отчество: ";
                getline(cin, patronymic5);

                    // Проверяем, чтобы все условия выполнились
                    if (!OshibkiBukvi(patronymic5)) {
                        cout << "Ошибка! Введите корректное имя." << endl;
                        cout << "Попробуйте еще раз!" << endl;
                    }
                } while (!OshibkiBukvi(patronymic5));
                
                people5.emplace_back(name5, surname5, patronymic5);
                break;
            default:
                cout << "Неверный выбор. Пропускаем человека."<< endl;
                break;
        }
    }
    cout << endl;
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
    string  initialBullets6str;
    do
    {
    cout << "Введите начальное количество патронов: "<< endl;
    cin >> initialBullets6str;
        
        // проверяем, чтобы все условия выполнились
        if (!oshibki(initialBullets6str))
            {
                cout << "Ошибка! введите корректное число " << endl << "Попробуйте еще раз!)" << endl ;
            }
        
    }
    while (!oshibki( initialBullets6str)); // цикл будет, пока есть ошибки при вводе
    initialBullets6=stoi( initialBullets6str);
    
    if (initialBullets6 <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Недопустимое значение." << endl;
        cout << "Введите количество людей заново от 1"<< endl << "Попробуйте еще раз!)" << endl;
        cin >> initialBullets6;
    }

    Pistol6 myPistol6(initialBullets6);

    for (int i = 0; i < 5; i++)
    {
        myPistol6.shoot6();
        cout << "Осталось патронов: " << myPistol6.getBullets6() << endl;
    }
}
