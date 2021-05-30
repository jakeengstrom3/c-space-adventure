#include <stdio.h>
const int MAX_INPUT_SIZE = 256;
void print_welcome_message();
const char* get_name();

int main(){
    
    
    print_welcome_message();
    get_name();

    return 0;
}

void print_welcome_message(){
    printf("Hello and welcome to SPACE ADVENTURES!!!!!\n");
}

const char* get_name(){
    char name[MAX_INPUT_SIZE];
    printf("Please Enter Your Name: ");
    fgets(name, MAX_INPUT_SIZE, stdin);
    printf("\nWelcome %s\n", name);
    
}
