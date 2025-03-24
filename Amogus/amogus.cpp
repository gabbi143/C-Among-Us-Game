#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include "amogus.h"

using namespace std;

void printDelay(const string& text) {
    for (char c : text) {
        cout << c;
        Sleep(20);
    }
    cout << endl;
}

void showUI(vector<string>& Players) {
    printDelay("Players:");
    cout << endl;

    for (size_t i = 0; i < Players.size(); i++) {
        cout << i + 1 << ". " << Players[i] << endl;
    }
    cout << endl;
}

void gameIntro() {
    string playerChoice;

    cout << "-------------------------------" << endl;
    cout << "   Welcome to Among Us game!" << endl;
    cout << "-------------------------------" << endl << endl;

    printDelay("To win, eliminate the imposter before they eliminate you.");

    while (true) {
        cout << endl << "Play the game? (y/n): ";
        getline(cin, playerChoice);

        if (playerChoice == "Y" || playerChoice == "y") {
            break;
        } else if (playerChoice == "N" || playerChoice == "n") {
            system("cls");
            printDelay("Maybe next time.");
            exit(0);
        } else {
            system("cls");
            cout << "Invalid Input." << endl << endl;
        }
    }
}

void chooseImpostor(vector<string>& Players, int& impostorIndex, string& self) {
    srand(time(0));
    while (true) {
        impostorIndex = rand() % Players.size(); // Generate a random index
        if (Players[impostorIndex] != self) { // Ensure the impostor is not the player
            break;
        }
    }
}


void ejectPlayer(vector<string>& Players, string& player, string& self) {
    if (player == self) {
        printDelay("You cannot eliminate yourself!");
        cout << endl;
        return;
    }

    bool removed = false;
    for (size_t i = 0; i < Players.size(); i++) {
        if (Players[i] == player) {
                system("cls");
                Sleep(1000);
            printDelay(player + " is now ejected.");
            cout << endl;
                Sleep(1000);
            printDelay(player + " is not the Impostor.");
            cout << endl;
                Sleep(2000);
            Players.erase(Players.begin() + i);
            removed = true;
            break;
        }
    }

    if (!removed) {
        printDelay("Invalid Name! Player not found.");
        cout << endl;
    }
}

void killPlayer(vector<string>& Players, const string& impostorIndex, const string& self) {
    srand(time(0));
    while (true) {
        int victimIndex = rand() % Players.size();
        string victim = Players[victimIndex];

        if (victim != impostorIndex) {
            if (victim == self) {
                system("cls");
                Sleep(1000);
                printDelay("Game Over! The impostor killed you.");
                exit(0);
            } else {
                system("cls");
                Sleep(1000);
                printDelay(victim + " was killed by the impostor.");
                Players.erase(Players.begin() + victimIndex);
                Sleep(1000);
                cout << endl;
                break;
            }
        }
    }
}
