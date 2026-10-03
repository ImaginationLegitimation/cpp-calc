#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

double currentInput;
string retry;

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void toggle(double currentInput) {
    bool calculating = 1;
    string operation;
    double temp;
    while (calculating == 1) {
        cout << "then the operation will be... ";
        cin >> operation;
        if (operation == "+") {
            cin >> temp;
            currentInput = currentInput + temp;
            temp = 0;
        }
        else if (operation == "-") {
            cin >> temp;
            currentInput = currentInput - temp;
            temp = 0;
        }
        else if (operation == "*") {
            cin >> temp;
            currentInput = currentInput * temp;
            temp = 0;
        }
        else if (operation == "/") {
            cin >> temp;
            if (temp == 0) {
                cout << "Can't divide by 0.\n";
            } else currentInput = currentInput / temp;
            temp = 0;
        }
        else if (operation == "CALCULATE") {
            cout << "The result is: ";
            cout << currentInput;
            calculating = 0;
        }
        else {
            continue;
        }
    }
}

int main() {
    bool running = 1;
    while (running == 1) {
        cout << "Welcome to the calculator!\n";
        cout << "Available operations are:\n";
        cout << "+ - * /\n";
        cout << "To calculate, type in CALCULATE for your operation!\n";
        cout << "Input your number...\n";
        cin >> currentInput;
        toggle(currentInput);
        cout << "\nDo you want to do it again? [y/else] ";
        cin >> retry;
        if (retry == "y") {
            clearScreen();
        } else {
            running = 0;
        }
    }
    return 0;
}