#include <iostream>
using namespace std;
int main() {
    bool loop = true;
    while (loop) {
        string userInput = "";
        cout << "Enter Word(type EXIT to end): ";
        cin >> userInput;
        if (userInput == "EXIT" || userInput =="exit"){
            loop = false;
            break;
        }
        cout << endl;
        int n = userInput.length();
        for (int i = n - 1; i >= 0; --i) {
            cout << userInput[i];
        }
        cout << endl;
    }
    return 0;
}
