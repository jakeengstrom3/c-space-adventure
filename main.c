#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<json-c/json.h>

const int MAX_INPUT_SIZE = 256;
void print_welcome_message();
void get_name();
void begin_adventure();
void get_user_planet();
void get_random_planet();

int main(){
    //print_welcome_message();
    //get_name();
    //begin_adventure();

    FILE *fp;
    char buffer[8192];

    struct json_object *parsed_json;
    struct json_object *planets;

    fp = fopen("planetarySystem.json", "r");
    fread(buffer, 8192, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "planets", &planets);
    printf("%ld", json_object_array_length(planets));


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
        get_user_planet();

    }
    else if(check_yes == 0){
        printf("You said Yes\n");
        get_random_planet();
    }
    else{
        printf("Please Enter Valid Input\n");
        begin_adventure();
    }
}

void get_user_planet(){
    printf("Please Enter the name of the planet you want to go to\n");

    char input[MAX_INPUT_SIZE];
    fgets(input, sizeof(input), stdin);
    
    
    
}

void get_random_planet(){
    
}

