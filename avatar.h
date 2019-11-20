#ifndef H_AVATAR
#define H_AVATAR

#include <string>

using namespace std;

class avatar{
    public:
        string name;
        bool empty = true; // A value that determines if the avatar in the inventory is empty.

        // Stats of the avatar
        int agility;
        int power;
        int sturdiness;
        avatar(int a=0, int p=0 , int s=0);
    private:
};

#endif