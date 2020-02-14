/* **********************************************************************
-----.cpp implementation file
Author:      Tony Fountain
Purpose:     Created because I wanted to challenge myself, learn, and 
             expand knowledge.
start date:  12/31/2019
Description of program: It allows the user to input a name to be used as 
the account, play 1v1, play vs 2 others so 1v1v1, and a ranked system 
using 1v1 with a simple ranking score gain equation in place.
-----
********************************************************************** */
#ifndef ROCK_PAPER_SCI_IMPL_
#define ROCK_PAPER_SCI_IMPL_
#include "rps.h"

void welcomeScreen()
{
    cout << "Welcome to Rock/Paper/Scissors!" << endl;
}
//-----
void proceed()
{
    string ent;
    cout << "Press ENTER to proceed";
//    cin.ignore(); // used if there was a 'cin >>' statement before it
    getline (cin, ent);
}

//-----
void menuSelect()
{
    cout << "Rock Paper Scissors Version 1." << endl;
    cout << "Enter the number that comes after 'Option' to select." << endl;
    cout << "Option 1. 1v1" << endl;
    cout << "Option 2. 1v1v1" << endl;
    cout << "Option 3. Ranked 1v1" << endl;
    cout << "Option 4. Quit game" << endl;
    cout << "Current Ranked 1v1 rating: " << player1.getRanked() << endl;
    int selNum;
    cout << "Enter Option #: ";
    cin >> selNum;
    selOption(selNum);
    
}

//-----
void selOption(int selector)
{
    do
    {
        if(selector == 1)
        {// 1v1
            opt1();
            proceed();
        }
        if(selector == 2)
        {// 1v1v1
            opt2();
        }
        if(selector == 3)
        {// ranked 1v1
            opt3();
        }
        if(selector == 4)
        {// quit game option
            return;
        } 
    }while(selector > 4 || selector < 1);
}

//-----
void genProfile()
{
    cout << "Creating player profile. Enter name: ";
    getline (cin, player1.name);
    // player1.rankScore = 0;
}
//-----
void opt1()
{
    cout << "Setting up game mode.." << endl;
    cout << endl;
    cout << "Opponent(s): Azuri Kamenari, world renowned Rock Paper Scissors god!" << endl;
    sleep(1);
    cout << "Raised up in the slums, she had no other option but to take up the skill that allowed her a better life." << endl;
    cout << "Match ready: 1. Rock       2. Paper       3. Scissors" << endl;
    cout << "Enter a number with corresponding action: ";
    int rpcSelOpt1;
    cin >> rpcSelOpt1;
    checkWinLose(rpcSelOpt1);
    endOpt1();
}
//-----
void opt2()
{
    // p1 == ai1, p1 == ai2 means ai1 == ai2 by default
    cout << "Setting up game mode.." << endl;
    cout << endl;
    cout << "Opponent(s): Opponent1 and Opponent2" << endl;
    sleep(1);
    cout << "Match ready: 1. Rock       2. Paper       3. Scissors" << endl;
    cout << "Enter a number with corresponding action: ";
    cout << "Enter action #: ";
    int rpcSelOpt2;
    cin >> rpcSelOpt2;
    int bot1 = rpcAi(), bot2 = rpcAi();
    cout << player1.name << ": " << rpcSelOpt2 << "   Opponent1: " << bot1 << "   Opponent2: " << bot2 << endl;
    if( rerollCheck(rpcSelOpt2, bot1, bot2) )
    {
        invRerollAi(rpcSelOpt2, bot1, bot2);
    }
    checkWL1v1v1( rpcSelOpt2, bot1, bot2 );
}
//-----
void opt3()
{
    cout << "Setting up game mode.." << endl;
    cout << endl;
    cout << "Opponent(s): " << computer1.name << endl;
    sleep(1);
    cout << "Match ready: 1. Rock       2. Paper       3. Scissors" << endl;
    cout << "Enter a number with corresponding action: ";
    int rpcSelOpt3;
    cin >> rpcSelOpt3;
    checkWinLoseRanked(rpcSelOpt3);
}
//-----
void opt4()
{
    return;
}
//-----
int rpcAi()
{// 1 is rock, 2 is paper, 3 is scissors
    int ranNum;
    ranNum = rand() % 3 + 1;
    return ranNum;
}
//-----
void checkWinLose(int optCompare)
{
    int aiNum = rpcAi();
    if( optCompare == aiNum )
    {// tie if they're the same value
        cout << "Tie" << endl;
    }
    else if( optCompare == 2 && aiNum == 1)
    {// playerPaper vs aiRock = playerPaper
        cout << "Congratulations! You win with paper against your opponent's rock!" << endl;
    }
    else if( optCompare == 1 && aiNum == 2)
    {// playerRock vs aiPaper = aiPaper
        cout << "You lose. You had rock verses your opponent's paper." << endl;
    }
    else if( optCompare == 1 && aiNum == 3)
    {// playerRock vs aiScissors = playerRock
        cout << "Congratulations! You win with rock against your opponent's scissors!" << endl;
    }
    else if( optCompare == 3 && aiNum == 1)
    {// playerScissors vs aiRock = aiRock
        cout << "You lose. You had scissors verses your opponent's rock." << endl;
    }
    else if( optCompare == 3 && aiNum == 2)
    {// playerScissors vs aiPaper = playerScissors
        cout << "Congratulations! You win with scissors against your opponent's paper!" << endl;
    }
    else
    // unspoken of if-statement which is ( optCompare == 2 && aiNum == 3)
    {// playerPaper vs aiScissors = aiScissors
        cout << "You lose. You had paper verses your opponent's scissors ." << endl;
    }
}
//-----
void endOpt1()
{
    int endSel;
    cout << "Option 1. Play again " << endl;
    cout << "Option 2. Game Menu" << endl;
    cout << "Enter option #: ";
    cin >> endSel;
    if(endSel == 1) 
    {
        opt1();
    }
    else
    {
        menuSelect();
    }
    
}

//-----
void checkWL1v1v1(int playerSel, int ai1, int ai2)
{
    /*if paper wins..*/
    if( ( (playerSel + ai1) == ai2 && ai2 == 2 ) || ( playerSel == (ai1 + ai2) && playerSel == 2 ) || 
        ( (ai1 - playerSel) == ai2 && ai1 == 2 ) || ( (playerSel - ai1) == ai2 && ai1 == 1 ) )
    {
        if(playerSel == ai1 && ai2 == 2)
        {
            cout << "Opponent2 had paper and won against Opponent1 and " << player1.name << "'s rock." << endl;
            endOpt2();
        }/*end inner if*/
        else if(playerSel == 2 && ai1 == ai2)
        {
            cout << player1.name << " had paper against Opponent1 and Opponent2's rock." << endl;
            endOpt2();
        }/*end else if*/
        /*unspoken of else if playerSel == ai2 && ai1 == 2*/
        else
        {
            cout << "Opponent1 had paper and won against Opponent2 and " << player1.name << "'s rock." << endl;
            endOpt2();
        }/*end else*/
    }/*end outer if*/
    else if( (playerSel == 1 && ai1 == 2 && ai2 == 2) || (playerSel == 2 && ai1 == 2 && ai2 == 1) || (playerSel == 2 && ai1 == 1 && ai2 == 2))
    {
        if(playerSel == 1)
        {
            cout << "Opponent1 and Opponent2 had paper and won against " << player1.name << "'s rock." << endl;
            initTieAi();
            endOpt2();
        }/*end if*/
        else if(ai2 == 1)
        {
            cout << player1.name << " and Opponent1 won with paper against Opponent2's rock." << endl;
            settleTie();
            endOpt2();
        }/*end else if*/
        /*unspoken of if ai1 == 1*/
        else
        {
            cout << player1.name << " and Opponent2 had paper against Opponent1's rock." << endl;
            settleTie();
            endOpt2();
        }
    }/*end else if*/
    /*if it ties..*/
    else if( playerSel == ai1 && playerSel == ai2)
    {
        if(playerSel == 1)
        {
            cout << "Tie. All subjects had rock." << endl;
            endOpt2();
        }/*end if*/
        if(playerSel == 2)
        {
            cout << "Tie. All subjects had paper." << endl;
            endOpt2();
        }/*end if*/
        if(playerSel == 3)
        {
            cout << "Tie. All subjects had scissors." << endl;
            endOpt2();
        }/*end if*/
    }/*end else if*/
    /*if rock wins..*/
    else if( (ai2 - ai1) == (playerSel + ai1) || (playerSel - ai1) == (ai1 + ai2) || (playerSel == 3 && ai1 == 1 && ai2 == 3) || (playerSel == 1 && ai1 == 3 
            && ai2 == 3) || (playerSel == 3 && ai1 == 3 && ai2 == 1) || (playerSel == 1 && ai1 == 3 && ai2 == 1) )
    {
        if(playerSel == 1 && ai1 == 1 && ai2 == 3)
        {
            cout << player1.name << " and Opponent1 had rock and won against Opponent2's scissors." << endl;
            settleTie();
            endOpt2();
        }/*end if*/
        if(playerSel == 3 && ai1 == 1 && ai2 == 1)
        {
            cout << "Opponent1 and Opponent2 had rock against " << player1.name << "'s scissors." << endl;
            initTieAi();
            endOpt2();
        }/*end if*/
        if(playerSel == 3 && ai1 == 1 && ai2 == 3)
        {
            cout << "Opponent1 had rock and won against Opponent2 and " << player1.name << "'s scissors." << endl;
            endOpt2();
        }/*end if*/
        if(playerSel == 1 && ai1 == 3 && ai2 == 3)
        {
            cout << player1.name << " had rock and won against Opponent1 and Opponent2's scissors" << endl;
            endOpt2();
        }/*end if*/
        if(playerSel == 3 && ai1 == 3 && ai2 == 1)
        {
            cout << "Opponent2 had rock and won against Opponent1 and " << player1.name << "'s scissors" << endl;
            endOpt2();
        }/*end if*/
        if(playerSel == 1 && ai1 == 3 && ai2 == 1)
        {
            cout << player1.name << " and Opponent2 had rock and won against Opponent1's scissors." << endl;
            settleTie();
            endOpt2();
        }/*end if*/
    }/*end else if*/
    /*if scissor wins..*/
    else if( (playerSel == 2 && ai1 == 2 && ai2 == 3) || (playerSel == 2 && ai1 == 3 && ai2 == 2) || (playerSel == 2 && ai1 == 3 && ai2 == 3) ||
            (playerSel == 3 && ai1 == 2 && ai2 == 2) || (playerSel == 3 && ai1 == 2 && ai2 == 3) || (playerSel == 3 && ai1 == 3 && ai2 == 2) )
            {
                if(playerSel == ai1 && ai2 == 3)
                {
                    cout << "Opponent2 had scissors and won against Opponent1 and " << player1.name << "'s paper." << endl;
                    endOpt2();
                }/*end if*/
                else if(playerSel == ai2 && ai1 == 3)
                {
                    cout << "Opponent1 had scissors and won against Opponent2 and " << player1.name << "'s paper." << endl;
                    endOpt2();
                }/*end else if*/
                else if(playerSel == 2 && ai1 == ai2)
                {
                    cout << "Opponent1 and Opponent2 had scissors and won against " << player1.name << "'s paper." << endl;
                    initTieAi();
                    endOpt2();
                }/*end else if*/
                else if(playerSel == 3 && ai1 == ai2)
                {
                    cout << player1.name << " had scissors against Opponent1 and Opponent2's paper." << endl;
                    endOpt2();
                }/*end else if*/
                else if(playerSel == ai2 && ai1 == 2)
                {
                    cout << player1.name << " and Opponent2 had scissors and won against Opponent1's paper." << endl;
                    settleTie();
                    endOpt2();
                }/*end else if*/
                else/*unspoken of else if 332*/
                {
                    cout << player1.name << " and Opponent1 had scissors and won against Opponent2's paper." << endl;
                    settleTie();
                    endOpt2();
                }/*end else*/
            }/*end else if*/
}/*end function*/
/*-----*/
void settleTie()
{
    cout << "Initiating Sudden Death.." << endl;
    cout << endl;
    sleep(1);
    cout << "Match ready: 1. Rock       2. Paper       3. Scissors" << endl;
    cout << "Enter a number with corresponding action: ";
    int rpcSelTie;
    cin >> rpcSelTie;
    checkWinLose(rpcSelTie);
}
//-----
void endOpt2()
{
    int endSel;
    cout << "Option 1. Play again " << endl;
    cout << "Option 2. Game Menu" << endl;
    cout << "Enter option #: ";
    cin >> endSel;
    if(endSel == 1) 
    {
        opt2();
    }
    else
    {
        menuSelect();
    }
    
}
//-----
void initTieAi()
{
    cout << "Initiating Sudden Death.." << endl;
    cout << endl;
    sleep(1);
    cout << "Match ready: 1. Rock       2. Paper       3. Scissors" << endl;
    int rpcSelTie1, rpcSelTie2;
    rpcSelTie1 = rpcAi();
    rpcSelTie2 = rpcAi();
    cout << "Opponent1: " << rpcSelTie1 << "   Opponent2: " << rpcSelTie2 << endl;
    checkWinLoseAi(rpcSelTie1, rpcSelTie2);
}
//-----
void checkWinLoseAi(int opponent1, int opponent2)
{
    if( opponent1 == opponent2 )
    {// tie if they're the same value
        cout << "Opponent1 and Opponent2 Tied." << endl;
    }
    else if( opponent1 == 2 && opponent2 == 1)
    {// aiPaper vs aiRock = aiPaper
        cout << "Opponent1 Wins. Opponent1 had paper and Opponent2 had rock." << endl;
    }
    else if( opponent1 == 1 && opponent2 == 2)
    {// aiRock vs aiPaper = aiPaper
        cout << "Opponent2 Wins. Opponent2 had paper and Opponent1 had rock." << endl;
    }
    else if( opponent1 == 1 && opponent2 == 3)
    {// aiRock vs aiScissors = aiRock
        cout << "Opponent1 Wins. Opponent1 had rock and Opponent2 had scissors." << endl;
    }
    else if( opponent1 == 3 && opponent2 == 1)
    {// aiScissors vs aiRock = aiRock
        cout << "Opponent2 Wins. Opponent2 had rock and Opponent1 had scissors." << endl;
    }
    else if( opponent1 == 3 && opponent2 == 2)
    {// aiScissors vs aiPaper = aiScissors
        cout << "Opponent1 Wins. Opponent1 had scissors and Opponent2 had paper." << endl;
    }
    else
    /*unspoken of if-statement which is ( optCompare == 2 && aiNum == 3)*/
    {/*aiPaper vs aiScissors = aiScissors*/
        cout << "Opponent2 Wins. Opponent2 had scissors and Opponent1 had paper." << endl;
    }
}
//-----
bool rerollCheck(int chPlayer, int chAi1,int chAi2)
{
    if( (chPlayer == 1 && chAi1 == 2 && chAi2 == 3) || (chPlayer == 1 && chAi1 == 3 && chAi2 == 2) || (chPlayer == 2 && chAi1 == 1 && chAi2 == 3) 
        || (chPlayer == 2 && chAi1 == 3 && chAi2 == 1) || (chPlayer == 3 && chAi1 == 1 && chAi2 == 2) || (chPlayer == 3 && chAi1 == 2 && chAi2 == 1) )
    {
//        cout << "TEST REROLL TRUE" << endl;
        return true;
    }/*end if*/
    else
    {
//        cout << "TEST REROLL FALSE" << endl;
        return false;
    }/*end else*/
}
/*-----*/
void invRerollAi(int play1, int &invAi1,int &invAi2)
{
    cout << endl;
    cout << "Everyone had different options, rerolling Oppenent1 and Opponent2.." << endl;
    
for(int i = rand() % 3 + 1, j = rand() % 3 + 1; rerollCheck(play1, invAi1, invAi2); i = rand() % 3 + 1, j = rand() % 3 + 1 )
    {
        invAi1 = i;
        invAi2 = j;
    }
    sleep(1);
    cout << endl;
    cout << player1.name << ": " << play1 << "   Opponent1: " << invAi1 << "   Opponent2: " << invAi2 << endl;
}
/*-----*/
void checkWinLoseRanked(int optCompare)
{
    int aiNum = rpcAi();
    int winloseCheck;
    if( optCompare == aiNum )
    {// tie if they're the same value
        cout << "Tie" << endl;
        /*0 means it resets the win streak*/
        winloseCheck = 2;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;;
        endOpt3();
    }
    else if( optCompare == 2 && aiNum == 1)
    {// playerPaper vs aiRock = playerPaper
        cout << "Congratulations! You win with paper against your opponent's rock!" << endl << endl;
        /*1 means.......*/
        winloseCheck = 1;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    else if( optCompare == 1 && aiNum == 2)
    {// playerRock vs aiPaper = aiPaper
        cout << "You lose. You had rock verses your opponent's paper." << endl << endl;
        winloseCheck = 0;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    else if( optCompare == 1 && aiNum == 3)
    {// playerRock vs aiScissors = playerRock
        cout << "Congratulations! You win with rock against your opponent's scissors!" << endl << endl;
        winloseCheck = 1;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    else if( optCompare == 3 && aiNum == 1)
    {// playerScissors vs aiRock = aiRock
        cout << "You lose. You had scissors verses your opponent's rock." << endl << endl;
        winloseCheck = 0;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    else if( optCompare == 3 && aiNum == 2)
    {// playerScissors vs aiPaper = playerScissors
        cout << "Congratulations! You win with scissors against your opponent's paper!" << endl << endl;
        winloseCheck = 1;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    else
    // unspoken of if-statement which is ( optCompare == 2 && aiNum == 3)
    {// playerPaper vs aiScissors = aiScissors
        cout << "You lose. You had paper verses your opponent's scissors ." << endl << endl;
        winloseCheck = 0;
        player1.updateRanked(winloseCheck);
        cout << "Adjusted rank for: -" << player1.name << "- Ranked 1v1 rating: " << player1.getRanked() << endl << endl;
        endOpt3();
    }
    
}
/*-----*/
bool RankedPlay::winRankedStreak(int streakCh)
{
    if(streakCh == 2)
    {
        streak = 0;
        return false;
    }
    if(streakCh == 1 && streak == 0)
    {
        streak = 1;
        return true;
    }
    if(streakCh == 1 && streak == 1)
    {
        streak = 1;
        rankScore = rankScore + 1;
        return true;
    }
    if(streakCh == 0)
    {
        streak = 0;
        return false;
    }
}
/*-----*/
void RankedPlay::updateRanked(int wlCheck)
{
    if(wlCheck == 0)
    {
        rankScore = rankScore - 1;
        winRankedStreak(0);
    }
    if(wlCheck == 1)
    {
        rankScore = rankScore + 1;
        winRankedStreak(1);
        
    }
    if(wlCheck == 2)
    {
        winRankedStreak(2);
    }
    if( getRanked() < 0)
    {
        rankScore = 0;
    }
    // player1.winRankedStreak();
}
/*-----*/
int RankedPlay::rankedStreakChUpd(int wlCheck)
{
    
}
/*-----*/
int RankedPlay::getRanked()
{
    return rankScore;
}
/*-----*/
void endOpt3()
{
    int endSel;
    cout << "Option 1. Play again " << endl;
    cout << "Option 2. Game Menu" << endl;
    cout << "Enter option #: ";
    cin >> endSel;
    if(endSel == 1) 
    {
        opt3();
    }
    else
    {
        menuSelect();
    }
}
#endif ROCK_PAPER_SCI_IMPL_









