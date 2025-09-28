#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int monsterHealth = 100;

    printf("Welcome to C Mode Battle! (Automatic)\n");
    printf("You vs Monster\n");

    while(playerHealth > 0 && monsterHealth > 0) {
        int move = rand() % 3; 

        if(move == 0) {
            int dmg = rand() % 15 + 5;
            monsterHealth -= dmg;
            printf("You attacked the Monster for %d damage!\n", dmg);
        }
        else if(move == 1) {
            int heal = rand() % 10 + 5;
            playerHealth += heal;
            printf("You healed yourself for %d!\n", heal);
        }
        else {
            int dmg = rand() % 25 + 10;
            monsterHealth -= dmg;
            printf("You used magic for %d damage!\n", dmg);
        }

        if(monsterHealth > 0) {
            int monsterDmg = rand() % 12 + 3;
            playerHealth -= monsterDmg;
            printf("Monster attacks you for %d damage!\n", monsterDmg);
        }
    }

    if(playerHealth > 0) {
        printf("🎉 You defeated the monster!\n");
    } else {
        printf("💀 You were defeated...\n");
    }

    return 0;
}
