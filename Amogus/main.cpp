#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include "amogus.h"
#include <limits>

using namespace std;

int main() {
    string player, guess;
    int maxPlayers, impostorIndex;
    vector<string> Players;

    gameIntro();
    system("cls");

    while (true) {
        cout << "Set max players count (greater than 2): ";
        cin >> maxPlayers;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            system("cls");
            printDelay("Invalid Input! Please enter a number greater than 2.");
            cout << endl;
            continue; 
        }

        if (maxPlayers <= 2) {
            system("cls");
            printDelay("MAXIMUM PLAYER COUNT MUST BE GREATER THAN 2.");
            cout << endl;
        } else {
            break;
        }
    }
    system("cls");
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, player);

    Players.push_back(player);
    string self = player;

    for (int x = 0; x < maxPlayers - 1; x++) {
        while (true) {
            cout << "Player " << x + 2 << " Name: ";
            getline(cin, player);

            bool isDuplicate = false;
            for (const string& p : Players) {
                if (p == player) {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate) {
                cout << "The name is already on the list. Please enter a different name." << endl;
            } else {
                Players.push_back(player);
                break;
            }
        }
    }


    system("cls");
    chooseImpostor(Players, impostorIndex, self);

    while (true) {
        cout << "The Impostor is Player Number: " << impostorIndex + 1 << endl << endl;
        showUI(Players);

        cout << "Your Guess: ";
        getline(cin, guess);

        bool isValid = false;
        for (const string& p : Players) {
            if (p == guess) {
                isValid = true;
                break;
            }
        }

        if (!isValid) {
            system("cls");
            printDelay("Invalid Name! Try again.");
            cout << endl;
            continue;
        }

        if (guess == Players[impostorIndex]) {
            system("cls");
            Sleep(1000);
            printDelay(guess + " is now ejected.");
            cout << endl;
            Sleep(1000);
            printDelay(guess + " is the Impostor. YOU WIN!");
            return 0;
        } else if (guess == self) {
            system("cls");
            printDelay("You cannot eliminate yourself!");
            cout << endl;
        } else {
            ejectPlayer(Players, guess, self);
            killPlayer(Players, Players[impostorIndex], self);
        }
    }

    return 0;
}
