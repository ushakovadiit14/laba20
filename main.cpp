#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    
    int choice;
    do {
        cout << "Выберите задание для запуска:\n";
        cout << "1. Задание 1.2 "<< endl;
        cout << "2. Задание 1.3 "<< endl;
        cout << "3. Задание 2.4 "<< endl;
        cout << "4. Задание 3.4 "<< endl;
        cout << "5. Задание 4.5 "<< endl;
        cout << "6. Задание 5.1 "<< endl;
        cout << "0. Выход"<< endl;
        cout << "Ваш выбор: "<< endl;
        cin >> choice;
        if (choice <= 0) {
        cout << "число должно быть положительным"<< endl;
        return 1;
    }
        cin.ignore();

        switch (choice) {
            case 1:
                runTask1_2();
                break;
            case 2:
                runTask1_3();
                break;
            case 3:
                runTask2_4();
                break;
            case 4:
                runTask3_4();
                break;
            case 5:
                runTask4_5();
                break;
            case 6:
                runTask5_1();
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
