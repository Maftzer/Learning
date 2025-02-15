#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


// Да довърша:
// Когато сложа две едни и съши букви, слага на тази на правилното място G, а на другата слага Y, а трябва да не е Y, а "_"
// Да проверя когато думата има две едни и съши бувки като в Apple, как се държи програмата.
// В момента когато спечеля, не печеля поради някаква причинаs


int main(){
    srand(time(NULL));

    char *arr[] = {"Plane", "Train", "Pilot", "Brick", "Flame", "Grasp","Happy",
        "Plant","Light","Cloud","Sharp","Dream","Stone","Quick","Table", 
    };
    int random_index = rand() % 14;
    char *random_word = arr[random_index];
    char guess_word[6];
    char random_word_lower[5];
    char guess_word_lower[5];

    printf("Guess a 5-letter word: \n");
    
    
    printf("%s\n", random_word_lower); // за debugване, може да го махнеш ако ти пречи, ппц не трябва да е тук
    for(int i = 0; i <=5; i++){
        char result_word[6] = {'_', '_', '_', '_', '_','\0'};
        
        printf("%s\n", random_word);
        scanf("%s", guess_word);
        
        for(int i = 0; i<=4; i++){
            random_word_lower[i] = tolower(random_word[i]);
            guess_word_lower[i] = tolower(guess_word[i]);
        }

        while(strlen(guess_word) != 5){
            printf("Incorrect lenght, enter a 5-letter word %ld!\n", strlen(guess_word));
            scanf("%s", guess_word);
        }

        printf("Your guess: %s\n", guess_word);

        for(int i = 0; i < 5; i++){
            if(guess_word_lower[i] == random_word_lower[i]){
                result_word[i]= 'G';
            }
            else if(result_word[i] == '_'){
                for(char j = 0; j <= 5; j++ ){
                    if(guess_word_lower[i] == random_word_lower[j]){
                        result_word[i] = 'Y';
                    }
                }

            }
        }



        if(strcmp(guess_word_lower, random_word_lower) == 0){
            printf("You guessed the word! It is %s\n", random_word);
            break;
        }
        else{
            printf("%s\n", result_word);
        }
        
    
    }
    printf("You did not guess, the word was: %s", random_word);
    return 0;

}
