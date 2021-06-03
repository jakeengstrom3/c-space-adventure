#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    char input[2];
    printf("Should I randomly choose a planet to go to? (Y or N)");
    fgets(input, sizeof(input), stdin);
    char no[] = "N";
    char yes[] = "Y";
    
    
    int check_yes;
    int check_no;
    check_yes = strcmp(yes, input);
    check_no = strcmp(no, input);

    
    if(check_no == 0){
        printf("You said No\n");
        
    }
    else if(check_yes == 0){
        printf("You said Yes\n");
    }
    else{
        printf("Please Enter Valid Input\n");
        begin_adventure();
    }
}
