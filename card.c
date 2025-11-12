#include <stdio.h> <stdbool.h> <stdbool.h>

typedef struct{
    int card_nr;
    char card_name[20];
}card;

card *cards = NULL;
int count = 0;


int option;

void card_menu(){
    while (true){
    printf("1. Create new card user"\n);
    printf("2. Remove card access"\n);
    printf("3. Exit"\n);
    }
}
//val i meny
    scanf("%d", &option);
    if scanf("%d", &option) == 1{
        //Registrera kort funktion
    if scanf("%d", &option) == 2{
        //remove card access funktion
    }
    if scanf("%d", &option) == 3{
        break;
    }


    //Val 1 funktion:

    void creatnewcard(card *newcard){
    printf("Enter new card number / 0 to exit:"\n);
   scanf("%d", &card -> card_nr);
    if (card -> card_nr == 0){ break;
    }
    printf("Enter card registration name:"\n);
    scanf("%c", &card -> card_name);

    //+ på count så att kortet läggs till i "card_list"
    }
    
voidremovecard(){
    int id;
    printf("Enter card number to remove:\n");
    scanf("%d", &id);
    for(int x = 0; x < count; i++){
        if(cards[x].card_nr == id){
            for(int y; y < count - 1; y++){
                cards[y] = cards[y + 1];
            }
            count--;
            printf("Card access removed\n");
        }
    }

}


}






