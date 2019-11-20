
// Aeybel Varghese PP1 Project
// This program is a adventure game that demonstrates a array based inventory.

// Include neccesary libraries
#include <iostream>
#include <string>
#include <stdlib.h>     
#include <time.h>   

// Include inventory and avatar classes.
#include "inventory.h"
#include "avatar.h"

using namespace std;

int main(){

    // Show Intro
    cout << endl << endl << "           :::::::::::::: |    T E X T       F I G H T E R     | ::::::::::::::" << endl;
    cout << endl << endl << endl << "You are a wielder of Avatars. You posses the ability to have avatars inhabit you and utilize their abilities.\nHowever the Evil Avatar King Dio desires to destroy all avatar wielders. You find yourself trapped in Dio's castle. In order to escape you have to defeat all the Avatars in the castle and DIO himself\n" << endl << endl << endl;
    srand (time(NULL)); //Seed number generator
    bool gameActive = true;

    // Game Loop
    while(gameActive){

        inventory i; // Declare the inventory
        int level = 0; // Intiialize the level holder.
        int HP = 200; // Initilize the player HP

        // A array that holds the name of the avatars of each level.
        string avatarNames[10] = {"Joe", "Sam", "Artemis", "Carl", "Jupiter", "Will" , "Josuke", "Bert", "Jimmy", "Dio"};
        string avatarIntroductions[10] = {"You run into your first Avatar, it is wary of your precense.", "After defeating Joe, you continue to travel until you encounter another Avatar","Another Avatar appears, evidently enraged at what you had done to his companions", "You managed to escape your predicament, however you are ambushed by yet another avatar. He is different than the others","You are slowly making progress to Dio, just a couple more!","You find yourself at a corridor with two doors. You of course take the most suspicious one and find your self face to face with another Avatar","Another Avatar appears, this one has a much more intimidating appearance. You know you are close.", "In front of you is one of Dio's trusted pawns, this will surely be a challenge","At last there is only one Avatar remaining before you face off against Dio himself. However the Avatar you are dealing with is Dio's second in command.","Fear and Adrenaline are running through your body right now. Only few meters away from you stands DIO with his menacing demeanor. It is time to for a valiant battle."};
        // Initiazlize the three avatars that the player will possess intially.
        avatar initialAvatar1 = avatar(2,4,2);
        initialAvatar1.name = "Bob";
        initialAvatar1.empty = false;
        i.addAvatar(0,initialAvatar1);

        avatar initialAvatar2 = avatar(5,2,2);
        initialAvatar2.name = "Kyle";
        initialAvatar2.empty = false;
        i.addAvatar(1,initialAvatar2);

        avatar initialAvatar3 = avatar(1,2,5);
        initialAvatar3.name = "Zim";
        initialAvatar3.empty = false;
        i.addAvatar(2,initialAvatar3);



        while(level < 10){
            int lowerStats = 1;
            int higherStats = 6;

            // The stats of the enemy adjust as you progress the game;
            if(level > 3){
                int lowerStats = 4;
                int higherStats = 8;
            }
            if(level > 6){
                int lowerStats = 6;
                int higherStats = 10;
            }
            if(level > 8){
                int lowerStats = 9;
                int higherStats = 14;
            }

            // Creates stats for the enemy
            int enemy_agility =  rand() % (higherStats - lowerStats + 1) + lowerStats; 
            int enemy_power =  rand() % (higherStats - lowerStats + 1) + lowerStats; 
            int enemy_sturdiness =  rand() % (higherStats - lowerStats + 1) + lowerStats; 

            int enemy_HP = 17;

            // Creates the enemy avatar and sets the avatar stats.
            avatar enemy = avatar(enemy_agility, enemy_power, enemy_sturdiness);
            enemy.name = avatarNames[level];
            bool inCombat = true;
            cout << endl << endl << avatarIntroductions[level] << endl << endl;
            // Checks if the player is still in combat with the current avatar
            while(inCombat){

                // Prints Enemy Stats
                cout << "   === HP: "<<enemy_HP<<" =========================================================" << endl << endl;
                cout << "   Enemy: " << enemy.name << endl;
                cout << "   AGILITY: " << enemy.agility << " POWER: " << enemy.power << " STURDINESS: " << enemy.sturdiness << endl;
                cout << "   =====================================================================" << endl << endl;

                i.display(); // Displays the avatars the player posseses.

                int userInput;

                // Prompt the user on what action to do
                cout << "HP: "<< HP <<" | [0] FIGHT, [1] CAPTURE, [2] SWAP AVATAR" << endl;
                cin >> userInput;


                if(userInput == 0){
                    // Inflicts damage to the player and the enemy
                    enemy_HP -= 0.25*(enemy.sturdiness * i.avatar_storage[i.currentAvatar].power)+0.25*(enemy_agility * i.avatar_storage[i.currentAvatar].power);
                    HP -= 0.25*(enemy.power * i.avatar_storage[i.currentAvatar].sturdiness)+0.25*(enemy.power * i.avatar_storage[i.currentAvatar].agility);
                }
                else if(userInput == 1){
                    // Capture the avatar
                    // Avatar can only be captures if the enemy health is below or equal to 5.
                    if(enemy_HP <= 5){
                        // Sets the current avatar the player has to the enemy avatar (capturing)
                        i.avatar_storage[i.currentAvatar] = enemy;
                        cout << "You captured this avatar! Of course at the expense of your current one." << endl;
                        i.avatar_storage[i.currentAvatar].empty = false;
                        enemy_HP = 0;
                    }
                    else{
                        cout << endl << endl << "               *** | Enemy needs to be below health 5 to capture| ***" << endl << endl << endl;
                    }
                }
                else if(userInput == 2){

                    int newAvatar;
                    cout << "You chose to swap avatar" << endl;
                    cout << "Input which avatar you want to swap to" << endl << ":: | ";
                    // Prompts the user for what avatar to change into.
                    cin >> newAvatar;

                    // Makes sure the avatar the player wants to change into is in bounds of the inventory.s
                    if(newAvatar <= 2){
                        i.currentAvatar = newAvatar;
                    }
                    else{
                        cout << endl << "Not a valid choice" << endl;
                    }
                    
                }
                else{
                    cout << "Not a valid choice" << endl;
                }

                // If the enemy died, progress to the next level/enemy
                if(enemy_HP <= 0){
                    inCombat = false;
                    level += 1;
                }
                // If the player dies, end the game.
                if(HP <=0 ){
                    gameActive = false;
                }
            }
        }  
        cout << "GAME OVER: Reached Level " << level << "/10";
        gameActive = false;  
    }
}