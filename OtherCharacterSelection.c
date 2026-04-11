////
///
//https://stackoverflow.com/questions/6316987/should-struct-definitions-go-in-h-or-c-file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STATS.h"

void OtherCharacterSelection(Character team[4]) {
    int x;

    for (x = 1; x <= 3; x++) { // 1–3 = sidekicks
        int Choice;

        while (1) {
            printf("\nSelect sidekick %d:\n", x);
            printf("(1) Banker, (2) Hunter, (3) Farmer, (4) Doctor, (5) Carpenter, (6) Lawyer\n");

            if (scanf("%d", &Choice) != 1) {
                printf("Invalid input. Enter a number 1-6.\n");
                while (getchar() != '\n'); // clear buffer
                continue;
            }

            if (Choice < 1 || Choice > 6) {
                printf("Choice out of range. Enter 1-6.\n");
                continue;
            }

            break; // valid input
        }

        // Assign stats based on choice
        switch (Choice) {
            case 1:
                strcpy(team[x].name, "Banker");
                team[x].dabloons = 1600;
                team[x].LuckOfIllness = 0.5;
                team[x].resources = 50;
                break;
            case 2:
                strcpy(team[x].name, "Hunter");
                team[x].dabloons = 450;
                team[x].LuckOfIllness = 0.4;
                team[x].resources = 90;
                break;
            case 3:
                strcpy(team[x].name, "Farmer");
                team[x].dabloons = 400;
                team[x].LuckOfIllness = 0.8;
                team[x].resources = 100;
                break;
            case 4:
                strcpy(team[x].name, "Doctor");
                team[x].dabloons = 500;
                team[x].LuckOfIllness = 1.0;
                team[x].resources = 30;
                break;
            case 5:
                strcpy(team[x].name, "Carpenter");
                team[x].dabloons = 800;
                team[x].LuckOfIllness = 0.4;
                team[x].resources = 75;
                break;
            case 6:
                strcpy(team[x].name, "Lawyer");
                team[x].dabloons = 700;
                team[x].LuckOfIllness = 0.6;
                team[x].resources = 25;
                break;
        }

        team[x].health = 100; // ensure health is set
        printf("Added %s with %d dabloons.\n", team[x].name, team[x].dabloons);
    }

    // Print final team
    int j; 
    for (j = 1; j <= 3; j++) {
         printf("------------------------------------------------------------------------------------\nCharacter %d: %s | Health: %d | Dabloons: %d | Resources: %d\n------------------------------------------------------------------------------------\n\n",
               j, team[j].name, team[j].health, team[j].dabloons, team[j].resources);
    }
}

//int main() {
  //  Character team[4]; // 0 = main, 1–3 = sidekicks
    //OtherCharacterSelection(team);      // team array can now be used later
    //return 0;
//}
// - this is just checking it works in main
