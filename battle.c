#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));

    int playerHealth=100;
    int monsterHealth=100;
    int move;

    printf("Welcome to Free Time Battle\n");
    printf("You vs Monster\n");

    while(playerHealth>0 && monsterHealth>0){
        printf("\n Your Health:%d | Monster Health:%d\n",playerHealth,monsterHealth);
        printf("Choose your move 1-Attack 2-Heal 3-Magic\n");
        scanf("%d",&move);

        if (move==1){
            int dmg= rand()%15+5;
            monsterHealth -=dmg;
            printf("You attacked the Monster for %d damage!\n",dmg);

        }

        else if(move==2){
            int heal=rand()%10+5;
            playerHealth += heal;
            printf("You healed yourself for %d!\n", heal);

        }

        else if(move==3){
            int dmg=rand()%25+10;
            monsterHealth -= dmg;
            printf("You used magic for %d damage!\n", dmg);

        }

        else{
            printf("Invalid move!\n");
            continue;
        }
        if (monsterHealth>0){
            int monsterDmg=rand()%12+3;
            playerHealth -= monsterDmg;
            printf("Monster attacks you for %d damage!\n", monsterDmg);

        }
    if (playerHealth>0){
        printf("Congratulations! You deafeted the monster!\n");
        printf("Score: 100\n");
    }
    else{
        printf("You were defeated...\n");
    }

    }
    return 0;

}