#include <stdio.h>
const int MAX_INPUT_SIZE = 256;
void print_welcome_message();
void get_name();
void begin_adventure();

int main(){
    print_welcome_message();
    get_name();
    begin_adventure();
    return 0;
}

void print_welcome_message(){
    printf("Hello and welcome to SPACE ADVENTURES!!!!!\n");
}

void get_name(){
    char name[MAX_INPUT_SIZE];
    printf("Please Enter Your Name: ");
    fgets(name, MAX_INPUT_SIZE, stdin);
    printf("\nWelcome %s\n", name);
    
}

void begin_adventure(){
    char input[MAX_INPUT_SIZE];
    int planet = rand() % 10;

    printf("Randomly Chose Planet number%d\n", planet);
}
