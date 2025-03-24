#ifndef AMOGUS_H_INCLUDED
#define AMOGUS_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

void gameIntro();
void showUI(vector<string>& Players);
void printDelay(const string& text);
void chooseImpostor(vector<string>& Players, int& impostorIndex, string& self);

void ejectPlayer(vector<string>& Players, string& player, string& self);
void killPlayer(vector<string>& Players, const string& impostorIndex, const string& self);

#endif // AMOGUS_H_INCLUDED
