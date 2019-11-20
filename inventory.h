#ifndef H_INVENTORY
#define H_INVENTORY

#include "avatar.h"
#include <string>
using namespace std;

class inventory{
    public:
        avatar avatar_storage[3]; // An object array of avatars, this is the inventory.
        void display(); // A function to display the current avatars the player posses.
        void addAvatar(int position, avatar newAvatar); // A function that swaps current avatar with the enemy avatar
        int currentAvatar =0; // A value that holds the current avatar
    private:
};
#endif