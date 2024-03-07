/* iaed-23 - ist1106609 - project1 */
/* 
 * File:    project1.c
 * Author:  Sofia Nunes
 * Description: A program that creates and lists bus lines, their stops and other relevant information to the user like the cost and the duration of the line,
 *              the coordinates of the corresponding stop and the intersections in each stop.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXNAMEL 21     /*The maximum number of characters in the name of the line + \0.*/
#define MAXNAMES 51     /*The maximum number of characters in the name of the stops + \0.*/
#define MAXINV 8        /*The maximum number of characters in string inverse + \0.*/
#define MAXLINE 200     /*The maximum amount of lines possible.*/
#define MAXSTOP 10000   /*The maximum amount of stops possible.*/
#define MAXLINK 30000   /*The maximum amount of links possible.*/

typedef struct line{
    char name_line[MAXNAMEL];
    char first_stop[MAXNAMES];
    char last_stop[MAXNAMES];
    float cost;
    float duration;
    char stops[MAXSTOP][MAXNAMES];
} Line;

typedef struct stop{
    char name_stop[MAXNAMES];
    double latitude;
    double longitude;
} Stop;

typedef struct link{
    char name_line[MAXNAMEL];
    char first_stop[MAXNAMES];
    char last_stop[MAXNAMES];
    float cost;
    float duration;
} Link;

/*Checks if line exists in the array of structs lines.
Receives an array of structs lines and a string name_line. Returns 1 if the line exists and 0 otherwise.*/
int check_line(Line lines[], char name_line[]){
    int i;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(strcmp(name_line, lines[i].name_line) == 0)
            return 1;
    }
    return 0;
}

/*Calculates the number of stops in the line.
Receives an array of structs lines and a string name_line. Returns the corresponding number of stops.*/
int number_stops(Line lines[], char name_line[]){   
    int i, j, num = 0;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){             
        if(strcmp(lines[i].name_line, name_line) == 0){
            for(j = 0; lines[i].stops[j][0] != '\0'; j++)
                num++;
            break;
        }
    }
    return num;
}

/*Prints all the stops in the corresponding line in the following format: <first stop>, <stop>, ..., <last stop>.
Receives an array of structs lines and a string name_line.*/
void list_stops_line(Line lines[], char name_line[]){
    int i, j, num = number_stops(lines, name_line);
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(strcmp(lines[i].name_line, name_line) == 0){
            for(j = 0; j < num; j++)
                printf("%s, ", lines[i].stops[j]);
            printf("%s\n", lines[i].last_stop);
            break;
        }
    }
}

/*Prints all the stops in the corresponding line in the following format: <last stop>, <stop>, ..., <first stop>.
Receives an array of structs lines and a string name_line.*/
void list_inverted_stops_line(Line lines[], char name_line[]){
    int i, j, num = number_stops(lines, name_line);
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(strcmp(lines[i].name_line, name_line) == 0){
            for(j = (num - 1); j > 0; j--) 
                printf("%s, ", lines[i].stops[j]);
            printf("%s\n", lines[i].stops[0]);
            break;
        }
    }
}

/*Creates a new line in the array of structs lines.
Receives an array of structs lines and a string name_line.*/
void create_line(Line lines[], char name_line[]){
    int i;
    for(i = 0; i < MAXLINE; i++){
        if(lines[i].name_line[0] == '\0'){
            strcpy(lines[i].name_line, name_line);
            lines[i].cost = 0;
            lines[i].duration = 0;
            break;
        }
    }
}

/*Prints a list of all the lines in the array of structs lines in the following format:
<name of line> <name of first stop> <name of last stop> <number of stops> <cost> <duration>.
Receives an array of structs stops and an array of structs lines.*/
void list_lines(Line lines[]){
    int i;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(lines[i].first_stop[0] == '\0')
            printf("%s %d %.2f %.2f\n", lines[i].name_line, number_stops(lines, lines[i].name_line), lines[i].cost, lines[i].duration);
        else printf("%s %s %s %d %.2f %.2f\n", lines[i].name_line, lines[i].first_stop, lines[i].last_stop, number_stops(lines, lines[i].name_line) + 1, 
            lines[i].cost, lines[i].duration);
    }
}

/*Checks if stop exists in the array of structs stops.
Receives an array of structs stops and a string name_stop. Returns 1 if the stop exists and 0 otherwise.*/
int check_stop(Stop stops[], char name_stop[]){
    int i;
    for(i = 0; i < MAXSTOP; i++){
        if(strcmp(name_stop, stops[i].name_stop) == 0)
            return 1;
    }
    return 0;
}

/*Prints the coordinates of the corresponding stop in the following format: <latitude> <longitude>.
Receives an array of structs stops and a string name_stop.*/
void coordinates_stop(Stop stops[], char name_stop[]){
    int i;
    for(i = 0; i < MAXSTOP; i++){
        if(strcmp(name_stop, stops[i].name_stop) == 0){
            printf("%16.12f %16.12f\n", stops[i].latitude, stops[i].longitude);
            break;
        }
    }
}

/*Creates a new stop in the array of structs stops.
Receives an array of structs stops, a string name_stop and two doubles latitude and longitude.*/
void create_stop(Stop stops[], char name_stop[], double latitude, double longitude){
    int i;
    for(i = 0; i < MAXSTOP; i++){
        if(stops[i].name_stop[0] == '\0'){
            strcpy(stops[i].name_stop, name_stop);
            stops[i].latitude = latitude;
            stops[i].longitude = longitude;
            break;
        }
    }
}

/*Calculates the number of lines in which the wanted stop appears.
Receives an array of structs lines and a string name_stop. Returns the corresponding number of appearances.*/
int number_lines(Line lines[], char name_stop[]){
    int i, j, num = 0;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        for(j = 0; j < number_stops(lines, lines[i].name_line); j++){
            if(strcmp(lines[i].stops[j], name_stop) == 0 || strcmp(lines[i].last_stop, name_stop) == 0){
                num++;
                break;
            }
        }
    }
    return num;
}

/*Prints a list of all the stops in the array of structs stops in the following format: <name of stop>: <latitude> <longitude> <number of lines>.
Receives an array of structs stops and an array of structs lines.*/
void list_stops(Stop stops[], Line lines[]){
    int i;
    for(i = 0; stops[i].name_stop[0] != '\0'; i ++)
        printf("%s: %16.12f %16.12f %d\n", stops[i].name_stop, stops[i].latitude, stops[i].longitude, number_lines(lines, stops[i].name_stop));
}

/*Checks if the stop is the last one in the corresponding line.
Receives an array of structs lines, a string name_line and a string name_stop. Returns 1 if it's the last stop and 0 otherwise.*/
int its_last_stop(Line lines[], char name_line[], char name_stop[]){
    int i;
    for(i = 0; i < MAXLINE; i++){
        if(strcmp(lines[i].name_line, name_line) == 0 && strcmp(lines[i].last_stop, name_stop) == 0)
            return 1;
    }
    return 0;
}

/*Checks if the stop is the first one in the corresponding line.
Receives an array of structs lines, a string name_line and a string name_stop. Returns 1 if it's the first stop and 0 otherwise.*/
int its_first_stop(Line lines[], char name_line[], char name_stop[]){
    int i;
    for(i = 0; i < MAXLINE; i++){
        if(strcmp(lines[i].name_line, name_line) == 0 && strcmp(lines[i].first_stop, name_stop) == 0)
            return 1;
    }
    return 0;
}

/*Checks if the line doesn't have stops.
Receives an array of structs lines and a string name_line. Returns 1 if the line doesn't have stops and 0 otherwise.*/
int checks_no_stops_line(Line lines[], char name_line[]){
    int i;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(strcmp(lines[i].name_line, name_line) == 0){
            if(lines[i].first_stop[0] == '\0' && lines[i].last_stop[0] == '\0')
                return 1;
        }
    }
    return 0;
}

/*Updates the stops, the cost and the duration of the corresponding line in the array of structs lines when the link is added to the end of the line and
when the line doesn't have any stops.
Receives an array of structs lines, three strings name_line, first_stop and last_stop and two floats cost and duration.*/
void update_line(Line lines[], char name_line[], char first_stop[], char last_stop[], float cost, float duration){
    int i;
    for(i = 0; i < MAXLINE; i++){
        if(strcmp(lines[i].name_line, name_line) == 0){
            if(lines[i].first_stop[0] == '\0')
                strcpy(lines[i].first_stop, first_stop);
            strcpy(lines[i].stops[number_stops(lines, name_line)], first_stop);
            strcpy(lines[i].last_stop, last_stop);
            lines[i].cost += cost;
            lines[i].duration += duration;
        }
    }
}

/*Updates the stops, the cost and the duration of the corresponding line in the array of structs lines when the link is added to the beginning of the line.
Receives an array of structs lines, two strings name_line and first_stop and two floats cost and duration.*/
void update_inv_line(Line lines[], char name_line[], char first_stop[], float cost, float duration){
    int i, j, num = 0;
    for(i = 0; lines[i].name_line[0] != '\0'; i++){
        if(strcmp(lines[i].name_line, name_line) == 0){
            num = number_stops(lines, lines[i].name_line);
            for(j = num; j > 0; j--)
                strcpy(lines[i].stops[j], lines[i].stops[j - 1]);
            lines[i].cost += cost;
            lines[i].duration += duration;
            strcpy(lines[i].stops[0], first_stop);
            strcpy(lines[i].first_stop, first_stop);
            break;
        }
    }
}

/*Creates a new link in the array of structs links.
Receives an array of structs links, three strings name_line, first_stop and last_stop and two floats cost and duration.*/
void create_link(Link links[], char name_line[], char first_stop[], char last_stop[], float cost, float duration){
    int i;
    for(i = 0; i < MAXLINK; i++){
        if(links[i].name_line[0] == '\0'){
            strcpy(links[i].name_line, name_line);
            strcpy(links[i].first_stop, first_stop);
            strcpy(links[i].last_stop, last_stop);
            links[i].cost = cost;
            links[i].duration = duration;
            break;
        }
    }
}

/*Analises and separates the input regarding stops and computes the correct function.
Receives as arguments a string of input from the user, an array of structs stops and an array of structs lines.*/
void command_p(char command[], Stop stops[], Line lines[]){
    char name_stop[MAXNAMES] = {'\0'}, letter;
    double latitude = 0, longitude = 0;
    if(command[2] == '\"')
        sscanf(command, "%c \"%[^\"]\" %lf %lf", &letter, name_stop, &latitude, &longitude);
    else sscanf(command, "%c %s %lf %lf", &letter, name_stop, &latitude, &longitude);
    
    if(name_stop[0] == '\0'){
        list_stops(stops, lines);
    }
    else if(latitude == 0 && longitude == 0){
        if(check_stop(stops, name_stop) == 1)
            coordinates_stop(stops, name_stop);
        else
            printf("%s: no such stop.\n", name_stop);
    }
    else{
        if(check_stop(stops, name_stop) == 1)
            printf("%s: stop already exists.\n", name_stop);
        else create_stop(stops, name_stop, latitude, longitude);
    }
}

/*Analises and separates the input regarding lines and computes the correct function.
Receives as arguments a string of input from the user and an array of structs lines.*/
void command_c(char command[], Line lines[]){
    char name_line[MAXNAMEL] = {'\0'}, inverse[MAXINV] = {'\0'}, letter;
    if(strlen(command) > 1){
        sscanf(command, "%c %s %s", &letter, name_line, inverse);
    }

    if(name_line[0] == '\0')
        list_lines(lines);
    else if(inverse[0] == '\0'){
        if(check_line(lines, name_line) == 1)
            list_stops_line(lines, name_line);           
        else{
            create_line(lines, name_line);
        }
    }
    else if(strcmp(inverse, "inverso") || strcmp(inverse, "invers") || strcmp(inverse, "inver") || strcmp(inverse, "inve") || strcmp(inverse, "inv"))
        list_inverted_stops_line(lines, name_line);
    else printf("incorrect sort option.\n");
}

/*Analises and separates the input regarding links and computes the correct function.
Receives as arguments a string of input from the user, an array of structs lines, an array of structs stops and an array of structs links.*/
void command_l(char command[], Line lines[], Stop stops[], Link links[]){
    char name_line[MAXNAMEL], first_stop[MAXNAMES], last_stop[MAXNAMES], letter;
    float cost = 0, duration = 0;
    int i, num_quot_mark = 0, num_arg = 0, arg_with = 0;
    for(i = 0; command[i] != '\0' ; i++){
        if(command[i] == ' ' && (num_quot_mark == 0 || num_quot_mark % 2 == 0)) num_arg++;
        if(command[i] == '\"'){
            num_quot_mark++;
            if(num_arg == 2) arg_with = 3;
            else if(num_arg == 3) arg_with = 4;
        } 
    }
    if(num_quot_mark == 4)
        sscanf(command, "%c %s \"%[^\"]\" \"%[^\"]\" %f %f", &letter, name_line, first_stop, last_stop, &cost, &duration);
    else if(num_quot_mark == 2 && arg_with == 3) 
        sscanf(command, "%c %s \"%[^\"]\" %s %f %f", &letter, name_line, first_stop, last_stop, &cost, &duration);
    else if(num_quot_mark == 2 && arg_with == 4)
        sscanf(command, "%c %s %s \"%[^\"]\" %f %f", &letter, name_line, first_stop, last_stop, &cost, &duration);
    else 
        sscanf(command, "%c %s %s %s %f %f", &letter, name_line, first_stop, last_stop, &cost, &duration);

    if(check_line(lines, name_line) == 0)
        printf("%s: no such line.\n", name_line);
    else if(check_stop(stops, first_stop) == 0)
        printf("%s: no such stop.\n", first_stop);
    else if(check_stop(stops, last_stop) == 0)
        printf("%s: no such stop.\n", last_stop);
    else if(cost < 0 || duration < 0)
        printf("negative cost or duration.\n");
    else if(checks_no_stops_line(lines, name_line) == 1){
        create_link(links, name_line, first_stop, last_stop, cost, duration);
        update_line(lines, name_line, first_stop, last_stop, cost, duration);
    }
    else if(its_last_stop(lines, name_line, first_stop) == 1){
        create_link(links, name_line, first_stop, last_stop, cost, duration);
        update_line(lines, name_line, first_stop, last_stop, cost, duration);
    }
    else if(its_first_stop(lines, name_line, last_stop) == 1){
        create_link(links, name_line, first_stop, last_stop, cost, duration);
        update_inv_line(lines, name_line, first_stop, cost, duration);
    }
    else{
        printf("link cannot be associated with bus line.\n");
    }
}

/*Sorts the names in the array of names in alphabetic order.
Receives an array of strings and an integral(the number of lines that pass in a certain stop).*/
void bubble(char name_of_lines[MAXLINE][MAXNAMEL], int num){
    int i, j;
    char temp[MAXNAMEL];
    for(i = 0; i < num; i++){
        for (j = num - 1; j >= 0; j--){
            if(strcmp(name_of_lines[j - 1], name_of_lines[j]) > 0){
                strcpy(temp, name_of_lines[j - 1]);
                strcpy(name_of_lines[j - 1], name_of_lines[j]);
                strcpy(name_of_lines[j], temp);
            }
        }
    }
}

/*Prints, for every stop where more than one line pass, the number of lines that pass there as well as their names in alfabetic order.
Receives an array of structs stops, an array of structs lines and an array of strings name_of_lines.*/
void list_intersections(Stop stops[], Line lines[], char name_of_lines[MAXLINE][MAXNAMEL]){
    int i, j, k, l, m, num = 0;
    for(i = 0; stops[i].name_stop[0] != '\0'; i++){
        num = number_lines(lines, stops[i].name_stop);
        if(num > 1){
            j = 0;
            memset(name_of_lines, '\0', MAXLINE);
            for(k = 0; lines[k].name_line[0] != '\0'; k++){
                while(name_of_lines[j][0] == '\0'){                     /*I'm checking every stop in every line to see if the name of the stop is in that line.*/
                    for(l = 0; lines[k].stops[l][0] != '\0'; l++){      /*If it is I add it to an array of strings where the names of the lines that have the stop.*/
                        if(strcmp(lines[k].stops[l], stops[i].name_stop) == 0 || strcmp(lines[k].last_stop, stops[i].name_stop) == 0){
                            strcpy(name_of_lines[j], lines[k].name_line);
                            break;
                        }
                    }
                    j++;
                    break;
                }
            }       
        bubble(name_of_lines, num);
        printf("%s %d: ", stops[i].name_stop, num);
        for(m = 0; m < num; m++){
            if(m == num - 1)
                printf("%s\n", name_of_lines[m]);
            else printf("%s ", name_of_lines[m]);
        }
        }
    }
}

Line lines[MAXLINE] = {'\0'};   /*Global variable: array of structs lines with size of the maximum amount of lines possible, initialized as '\0.*/
Stop stops[MAXSTOP] = {'\0'};   /*Global variable: array of structs stops with size of the maximum amount of stops possible, initialized as '\0.*/
Link links[MAXLINK] = {'\0'};   /*Global variable: array of structs links with size of the maximum amount of links possible, initialized as '\0.*/
char name_of_lines[MAXLINE][MAXNAMEL] = {'\0'}; /*Global variable: array of strings with size of the maximum amount fof lines possible, initialized as \0.*/

/*Receives input from the user, stores it in the string command and analyses the first letter of the input computing the corresponding function.
When 'q' exits the program.*/
int main(){
    char command[BUFSIZ];
    while(1){
        if(fgets(command, BUFSIZ, stdin) != NULL){
            switch(command[0]){
                case 'q':
                    exit(0);

                case 'c':
                    command_c(command, lines);
                    break;

                case 'p':
                    command_p(command, stops, lines);
                    break;

                case 'l':
                    command_l(command, lines, stops, links);
                    break;

                case 'i':
                    list_intersections(stops, lines, name_of_lines);
                    break;
            }
        }
    }
    return 0;
}
