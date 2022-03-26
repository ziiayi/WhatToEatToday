/*
Solution to What2Eat.c problem 
by Esrah Zahid (S020289)
using C language
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Initialize{
    int no_of_people;
    int threshold;
}Initialize;

typedef struct key_value {//key-value pairs to store [points:foodchoice] eg [5:kebab]{
    int key;
    char* value;
}key_value;

int main(){
    struct Initialize test1;
    test1.threshold = 10;
    int number_of_items = 5; 
    struct key_value *round_one = malloc(sizeof(struct key_value) * number_of_items); //creating key-value pair for round one
    printf("Enter number of people: ");
    scanf("%d", &test1.no_of_people);
    printf("Your food Choices are the following: \n1. Kebab\n2. Burger\n3. Pasta\n4. Lahmachun\n5. Salad\n"); 
    round_one[0].value = "Kebab"; //inserting values into key-value pait
    round_one[1].value = "Burger";
    round_one[2].value = "Pasta";
    round_one[3].value = "Lahmacun";
    round_one[4].value = "Salad";
    
    //round one
    int points;
    int current_choice = 0; 
    for (int i=0; i<test1.no_of_people; i++){
        points = 5;
        printf("Person %d make 5 choices in order of your preferences using numbers from 1-5 corresponding to each menu item above respectively\n", i+1);
        for (int i=0; i<5; i++){
                printf("Enter choice number %d: \n", i+1);
                scanf("%d", &current_choice);
                round_one[current_choice-1].key = round_one[current_choice-1].key + points;
                points = points - 1;
        }
    current_choice = 0;
    }
    
    //round two
    bool dorm = true; 
    int short_list_items = 0;
    for (int item=0; item<5; item++){
        //printf("Key = %d\nKey value = %s\n", round_one[item].key, round_one[item].value); //print key-value pairs
        if (round_one[item].key > test1.threshold){
            dorm = false;
            short_list_items = short_list_items + 1;
        }
    }
    int short_list_count = 0;
    if (dorm){
        printf("You are eating at home today!");
    } else {
        struct key_value *short_list = malloc(sizeof(struct key_value) * short_list_items);
        printf("\n\nFood choices that made it to the shortlist are: \n");
        for (int item=0; item<5; item++){
            if (round_one[item].key > test1.threshold){
                printf("%d. %s\n",short_list_count+1, round_one[item].value);
                short_list[short_list_count].value = round_one[item].value;
                short_list_count = short_list_count + 1;
            }
        }
        if (short_list_count > 1) { //if there is more than one food choice on the short list else print food choice
            for (int i=0; i<test1.no_of_people; i++){
                points = 5;
                printf("Person %d make %d choices in order of your preferences using numbers corresponding to each short list item above respectively\n",i+1, short_list_count);
                for (int i=0; i<short_list_count; i++){
                    printf("Enter choice number %d: \n", i+1);
                    scanf("%d", &current_choice);
                    short_list[current_choice-1].key = short_list[current_choice-1].key + points;
                    points = points - 1;
                }  
            }
            char* eating_today = short_list[0].value;
            for (int i=0; i<short_list_count; i++){
                if (short_list[i+1].key>short_list[i].key){
                    eating_today = short_list[i+1].value;
                }
            }
            printf("Results: \n");
            for (int i=0; i<short_list_count; i++){
                printf("%d points for %s\n", short_list[i].key, short_list[i].value); //print key-value pairs
            }
            
            printf("\n\nYou are eating %s today! It got the most points!\n", eating_today);
        } else {
            printf("\n\nYou are eating %s today! It got the %d points!\n", short_list[0].value, round_one[0].key);
        }
    }  
   free(round_one);
   return 0;
}