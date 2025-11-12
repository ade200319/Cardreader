#include <stdio.h> 
#include <stdbool.h>
#include <windows.h>
#include <safeinput.h>



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
   getinputint("%d", &newcard -> card_nr);
    if (newcard -> card_nr == 0){ return false;  //tydligen funkar inte break i funktioner så provar detta sålänge
    }
    printf("Enter card registration name:\n");
    getinput("%19s", &newcard -> card_name);
     count++; //---------------------------Vetefan vad detta gör än men ska kolla upp
    cards = realloc(cards, count * sizeof(card));       
    cards[count - 1] = *newcard;
    return true;
    if true(printf("Card added!\n"));
    }

   



 /// 
 /// Ta bort kort i system funktion
 bool removecard(){
    int id;
    printf("Enter card number to remove:\n");
    getinputint("%d", &id);
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
            return true; // lägg gärna till så vi slipper loopa vidare
        
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
        sleep(1000);
    }
}




//Meny för lägga till nya kort funktion
int card_menu(){
    int option;
    while (true){
    printf("1. Create new card user\n");
    printf("2. Remove card access\n");
    printf("3. Exit\n");
     getinputint("%d", &option);
    if (option == 1){
        createnewcard();
    }

    else if (option == 2){
    removecard();         //remove card access funktion
    }
    else if(option == 3){
        break;
    }
    }
}