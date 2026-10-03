#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

double obtainValidNumber() {
    double value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number. ";
    }
    return value;
}

string makeUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return toupper(c);
    });
    return str;
}

string makeLower(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return str;
}

void toggle(double currentInput) {
    bool calculating = true;
    string operation;
    double temp;
    while (calculating) {
        cout << "then the operation will be... ";
        cin >> operation;
        if (operation == "+") {
            temp = obtainValidNumber();
            currentInput = currentInput + temp;
            temp = 0;
        }
        else if (operation == "-") {
            temp = obtainValidNumber();
            currentInput = currentInput - temp;
            temp = 0;
        }
        else if (operation == "*") {
            temp = obtainValidNumber();
            currentInput = currentInput * temp;
            temp = 0;
        }
        else if (operation == "/") {
            temp = obtainValidNumber();
            if (temp == 0) {
                cout << "Can't divide by 0.\n";
                temp = obtainValidNumber();
            } else currentInput = currentInput / temp;
            temp = 0;
        }
        else if (makeUpper(operation) == "CALCULATE") {
            cout << "The result is: ";
            cout << currentInput;
            calculating = false;
        }
        else {
            continue;
        }
    }
}

int main() {
    bool running = true;
    double currentInput;
    string retry;
    while (running) {
        cout << "Welcome to the calculator!\n";
        cout << "Available operations are:\n";
        cout << "+ - * /\n";
        cout << "To calculate, type the word \'calculate\' for your operation!\n";
        cout << "Input your number...\n";
        currentInput = obtainValidNumber();
        toggle(currentInput);
        cout << "\nDo you want to do it again? [y/else] ";
        cin >> retry;
        if (makeLower(retry) == "y") {
            clearScreen();
        } else {
            running = false;
        }
    }
    return 0;
}