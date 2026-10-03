#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int operationChoice;
float number1;
float number2;
string retry;

void toggle(int operationChoice) {
    switch(operationChoice){
        case 1:
        cout << "Masukkan angka pertama: ";
        cin >> number1;
        cout << "Masukkan angka kedua: ";
        cin >> number2;
        cout << "Hasilnya adalah: ";
        cout << number1 + number2;
        cout << "\n";
        break;

        case 2:
        cout << "Masukkan angka pertama: ";
        cin >> number1;
        cout << "Masukkan angka kedua: ";
        cin >> number2;
        cout << "Hasilnya adalah: ";
        cout << number1 - number2;
        cout << "\n";
        break;

        case 3:
        cout << "Masukkan angka pertama: ";
        cin >> number1;
        cout << "Masukkan angka kedua: ";
        cin >> number2;
        cout << "Hasilnya adalah: ";
        cout << number1 * number2;
        cout << "\n";
        break;

        case 4:
        cout << "Masukkan angka pertama: ";
        cin >> number1;
        cout << "Masukkan angka kedua: ";
        cin >> number2;
        if (number2 == 0){
            cout << "Can't divide with 0. \n";
            break;
        }
        cout << "Hasilnya adalah: ";
        cout << number1 / number2;
        cout << "\n";
        break;
    }
}

int main() {
    cout << "Welcome to the calculator! \n";
    cout << "Pick and choose. (1-4) \n";
    cout << "---------------------------- \n";
    cout << "1 - Addition (+) \n";
    cout << "2 - Subtraction (-) \n";
    cout << "3 - Multiplication (x) \n";
    cout << "4 - Division (/) \n";
    cout << "0 - Exit \n";
    cout << "\n";
    cout << "It's... ";
    cin >> operationChoice;
    if (operationChoice == 0) {
        return 0;
    } else if (operationChoice > 4) {
        cout << "\033[2J\033[1;1H";
        main();
    } else if (operationChoice < 1) {
        cout << "\033[2J\033[1;1H";
        main();
    }
    toggle(operationChoice);
    cout << "Do you want to do it again? [y/else] ";
    cin >> retry;
    if (retry == "y") {
        cout << "\033[2J\033[1;1H";
        main();
    }
    return 0;
}
