/* **********************************************************************
-----driver/main
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
#include "rps.cpp"

int main()
{
    srand(time(0));
    genProfile();
    //ai for ranked play
    computer1.name = "Suzora Kunitsuna";
    
    welcomeScreen();
    proceed();
    menuSelect();
    
    
    
    return 0;
}