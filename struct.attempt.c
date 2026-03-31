////
//// sources: Copilot & slides & Chat for debugging
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Character {
  char name[50];
  float LuckOfIllness; //chance out of 10 of surviving an illness
	int dabloons;
  int health;
  int food; 
} Character;

//real name of file should be Assign_Main_Character.c but I want it the typedef to be universal 
int main() {

Character MainCharacter;
int Choice;
MainCharacter.health = 100;

    printf ("Hello traveler! Would you rather be a (1)banker, (2)hunter, (3)farmer, (4)doctor, (5)carpenter, or (6)lawyer? \n");	
    scanf ("%d", &Choice);
    
   // if (scanf ("%d", &Choice) != 1) {
    //printf ("Please enter a number 1-6 to select your character. \n");
     // scanf ("%d", &Choice);
      //}
      //figure out error-checking with proper scanf and repeating 
      
  if (Choice==1) {
    strcpy(MainCharacter.name, "Banker");
      MainCharacter.dabloons = 1600;
		  MainCharacter.LuckOfIllness = 5/10;
      MainCharacter.food = 10;
      printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
		 }

      else if (Choice==2) {
        strcpy(MainCharacter.name, "Hunter");
        MainCharacter.dabloons = 450;
		    MainCharacter.LuckOfIllness = 4/10;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
	      }
        
      else if (Choice==3) {
		    strcpy(MainCharacter.name, "Farmer");
        MainCharacter.dabloons = 400;
		    MainCharacter.LuckOfIllness= 8/10;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
	      }

	     else if (Choice==4) {
		     strcpy(MainCharacter.name, "Doctor");
         MainCharacter.dabloons = 500;
         MainCharacter.LuckOfIllness = 10/10;
         printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
       		}

	    else if (Choice==5) {
	       strcpy(MainCharacter.name, "Carpenter");
         MainCharacter.dabloons = 800;
         MainCharacter.LuckOfIllness= 4/10;
         printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
         }
	
	    else if (Choice==6) {
        strcpy(MainCharacter.name, "Lawyer");
        MainCharacter.dabloons = 700;
        MainCharacter.LuckOfIllness = 6/10;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.money);
        }
 
return MainCharacter.name, MainCharacter.dabloons, MainCharacter.health;
}