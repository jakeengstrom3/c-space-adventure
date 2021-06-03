#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <json-c/json.h>
#include <time.h>
#include <stdlib.h>

const int MAX_INPUT_SIZE = 256;
void print_welcome_message();
void get_name();
void begin_adventure();
void get_user_planet();
void get_random_planet();
void go_to_planet();
void continue_adventure();

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
    printf("Should I randomly choose a planet to go to? (Y or N)");
    
    scanf("%s", input);
    
    if(strcmp("N", input) == 0){
        printf("You said No\n");
        get_user_planet();

    }
    else if(strcmp("Y", input) == 0){
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
    scanf("%s", input);

    char planets[9][8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    for(int i = 0; i < sizeof(planets); i++){
        if(strcmp(input, planets[i]) == 0){
            go_to_planet(i);
            return;
        }
    }

    printf("Please enter a valid planet name!\n");
        get_user_planet();
}

void get_random_planet(){
    srand(time(NULL));
    go_to_planet(rand() % 9);
}

void go_to_planet(int planet_num){
    FILE *fp;
    char buffer[8192];

    struct json_object *parsed_json;
    struct json_object *planets;
    struct json_object *planet;
    struct json_object *name;
    struct json_object *description;

    fp = fopen("planetarySystem.json", "r");
    fread(buffer, 8192, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "planets", &planets);
    
    planet = json_object_array_get_idx(planets, planet_num);

    json_object_object_get_ex(planet, "name", &name);
    json_object_object_get_ex(planet, "description", &description);
    
    printf("Travelling to %s...\n", json_object_get_string(name));
    printf("Description: %s\n\n", json_object_get_string(description));
    continue_adventure();
}

void continue_adventure(){
    char input[MAX_INPUT_SIZE];
    printf("Do you wish to continue your adventrue? (Y or N)");
    
    scanf("%s", input);

    if(strcmp("N", input) == 0){
        printf("Okay, Goodbye!\n");
    }
    else if(strcmp("Y", input) == 0){
        printf("Okay, lets continue the adventue!\n");
        begin_adventure();
    }
    else{
        printf("Please Enter Valid Input\n");
        continue_adventure();
    }
}