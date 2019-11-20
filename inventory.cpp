#include <iostream>
#include "inventory.h"
#include <string>

using namespace std;

void inventory::display(){
    // Displays the inventory
    cout << "==================" << endl;
    cout << "YOUR AVATARS:" << endl << endl;
    cout << "**** | [Selected: " << avatar_storage[currentAvatar].name <<" ] | ****"<< endl << endl;
    for(int i = 0; i<3; i++){
        if(!avatar_storage[i].empty){
            cout << "[" << i << "] " << avatar_storage[i].name << endl;
            cout << "AGILITY: " << avatar_storage[i].agility << " POWER: " << avatar_storage[i].power << " STURDINESS: " << avatar_storage[i].sturdiness << endl << endl;
        }
        else{
            cout << "[" << i << "] EMPTY"  << endl;
        }
    }
    cout << "==================" << endl;
}
void inventory::addAvatar(int position, avatar newAvatar){
    avatar_storage[position] = newAvatar; // Sets the specified position in the inventory to the new avatar.
}


