/* **********************************************************************
-----.h header file
Author:      Tony Fountain
Purpose:     Created because I wanted to challenge myself, learn, and 
             expand knowledge.
start date:  12/31/2019
finish date: 01/05/2020
Description of program: It allows the user to input a name to be used as 
the account, play 1v1, play vs 2 others so 1v1v1, and a ranked system 
using 1v1 with a simple ranking score gain equation in place.
-----
********************************************************************** */
#ifndef ROCK_PAPER_SCI_H_
#define ROCK_PAPER_SCI_H_
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <time.h>

using namespace std;
//-----
struct RankedPlay
{
    string name;
    bool winRankedStreak(int streakCh);
    void updateRanked(int wlCheck);
    int rankedStreakChUpd(int wlCheck);
    int getRanked();
private:
    double rankScore = 0;
    int streak = 0;
};
RankedPlay player1;
RankedPlay computer1;
//-----
void welcomeScreen();
void proceed();
void menuSelect();
void genProfile();
void selOption(int selector);
void opt1();
void opt2();
void opt3();
void opt4();
int rpcAi();
void checkWinLose(int optCompare);
void endOpt1();
void checkWL1v1v1(int playerSel, int ai1, int ai2);
void endOpt2();
void settleTie();
void initTieAi();
void checkWinLoseAi(int opponent1, int opponent2);
bool rerollCheck(int chPlayer, int chAi1,int chAi2);
void invRerollAi(int play1, int &invAi1, int &invAi2);
void checkWinLoseRanked(int optCompare);
void endOpt3();
#endif ROCK_PAPER_SCI_H_