////
///
//https://stackoverflow.com/questions/6316987/should-struct-definitions-go-in-h-or-c-file


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "STATS.h"

int main() {

    Character characters[4]; // 0 = main, 1-3 = sidekicks
    int i;
    // Initialize health
    for (i = 0; i < 4; i++) {
        characters[i].health = 100;
    }

    int Choice;
    int x;
    // Loop for Character2, Character3, Character4
    for (x = 1; x <= 3; x++) {

        printf("\nSelect sidekick %d:\n", x);
        printf("(1) Banker, (2) Hunter, (3) Farmer, (4) Doctor, (5) Carpenter, (6) Lawyer\n");

        scanf("%d", &Choice);

        // Input validation loop
        while (Choice < 1 || Choice > 6) {
            printf("Invalid choice. Enter 1–6: ");
            scanf("%d", &Choice);
        }

        if (Choice == 1) {
            strcpy(characters[x].name, "Banker");
            characters[x].dabloons = 1600;
            characters[x].LuckOfIllness = 0.5;
            characters[x].resources = 10;
        }
        else if (Choice == 2) {
            strcpy(characters[x].name, "Hunter");
            characters[x].dabloons = 450;
            characters[x].LuckOfIllness = 0.4;
            characters[x].resources = 5;
        }
        else if (Choice == 3) {
            strcpy(characters[x].name, "Farmer");
            characters[x].dabloons = 400;
            characters[x].LuckOfIllness = 0.8;
            characters[x].resources = 10;
        }
        else if (Choice == 4) {
            strcpy(characters[x].name, "Doctor");
            characters[x].dabloons = 500;
            characters[x].LuckOfIllness = 1.0;
            characters[x].resources = 10;
        }
        else if (Choice == 5) {
            strcpy(characters[x].name, "Carpenter");
            characters[x].dabloons = 800;
            characters[x].LuckOfIllness = 0.4;
            characters[x].resources = 10;
        }
        else if (Choice == 6) {
            strcpy(characters[x].name, "Lawyer");
            characters[x].dabloons = 700;
            characters[x].LuckOfIllness = 0.6;
            characters[x].resources = 10;
        }

        printf("Added %s with %d dabloons.\n",
               characters[x].name,
               characters[x].dabloons);
    }

    // Final array output
    printf("\n--- Your Team ---\n");
    int j;
    for ( j = 1; j <= 3; j++) {
        printf("Character %d: %s | Health: %d | Dabloons: %d | Resources: %d\n",
               j + 1,
               characters[j].name,
               characters[j].health,
               characters[j].dabloons,
               characters[j].resources);
    }

    return 0;
}
//MainCharacter, Character2, Character3, Character4; rest will be decided in another file
// do array to keep track of stats in main to be able to alter them throughout gameplay - health, resources, dabloons