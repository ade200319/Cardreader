#include <stdio.h> 
#include <stdbool.h>
#include <windows.h>
#include <safeinput.h>
#include "functions.c"


//------------------------------------------------------
typedef struct{           // struct för card 
    int card_nr;
    char card_name[20];
}card;
card *cards = NULL;
int count = 0;  
//--------------------------------------------------------

  //Skapa nytt kort i systemet
  bool creatnewcard(card *newcard){
    printf("Enter new card number / 0 to exit:\n");
   GetInputInt("%d", &newcard -> card_nr);
    if (newcard -> card_nr == 0){ return false;  //tydligen funkar inte break i funktioner så provar detta sålänge
    }
    GetInputChar("Enter card registration name:\n", newcard -> card_name);
     count++; 
    cards = realloc(cards, count * sizeof(card));       
    cards[count - 1] = *newcard;
    return true;
    printf("Card added!\n");
    }

   



 /// 
 /// Ta bort kort i system funktion
 bool removecard(){
    int id;
    printf("Enter card number to remove:\n");
    GetInputInt("%d", &id);
    for(int x = 0; x < count; x++){
        if(cards[x].card_nr == id){
            for(int y; y < count - 1; y++){
                cards[y] = cards[y + 1];
            }
            count--;
            if (count == 0) {
                free(cards);
                cards = NULL;
            } else {
                cards = realloc(cards, count * sizeof(card));
            }

            printf("Card access removed\n");
            return true; 
        
        }
    }
    printf("Card not found\n");
    return false;
}



// Remote open door funktion


    int remote_open(){
    printf("Door unlocked, closing in:\n");
    for(int timer = 10; timer >= 0; timer--){
        printf("%d\n", timer);
        fflush(stdout);   //gör att den printas direkt
        Sleep(1000);
    }
    return 0;

}


void listcards(){
    if (count == 0){
        printf("No cards in system.\n");
        return;
    }

    printf("Cards currently in system:\n");
    for (int i = 0; i < count; i++) {
        printf("Card %d: Number = %d, Name = %s\n", i + 1, cards[i].card_nr, cards[i].card_name);
    }
}

//Meny för lägga till nya kort funktion
int card_menu(){
    int option;
    while (true){
    printf("1. Create new card user\n");
    printf("2. Remove card access\n");
    printf("3. Exit\n");
     GetInputInt("%d", &option);
    if (option == 1){
    card newcard;
    creatnewcard(&newcard);
    }   

    else if (option == 2){
    removecard();         //remove card access funktion
    }
    else if(option == 3){
        break;
    }
    }
    return 0;

test_scan();
    

}