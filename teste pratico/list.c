#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Functions for lines.
*/

/*
 * Initializes the linked list of structs that will contain the name of the stops that the line has.
*/

Stopsinline *create_stops_in_line(){
    Stopsinline *aux = malloc(sizeof(Stopsinline));
    if(!aux) return FALSE;
    aux->stop = NULL;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}

/*
 * Inicializes the linked list of structs that will contain every line.
*/

Line *new_line(){
    Line *lines = malloc(sizeof(Line));
    lines->name_line = NULL;
    lines->first_stop = NULL;
    lines->last_stop = NULL;
    lines->cost = 0;
    lines->duration = 0;
    lines->number_stops = 0;
    lines->head = NULL;
    lines->end = NULL;
    lines->next = NULL;
    lines->prev = NULL;
    return lines;
}

/*
 * Creates a new line in the linked list of structs lines.
 * Receives a pointer to the linked list of structs lines and a pointer to the string name_line.
 */

void create_line(Line *lines, char *name_line){
    Line *aux = malloc(sizeof(Line));
    if(!aux) return;
    aux->name_line =  malloc(sizeof(char) * (strlen(name_line) + 1));
    if(!aux->name_line){
        free(aux);
        return;
    }
    strcpy(aux->name_line, name_line);
    aux->first_stop = NULL;
    aux->last_stop = NULL;
    aux->cost = 0;
    aux->duration = 0;
    aux->number_stops = 0;
    aux->head = create_stops_in_line();
    aux->end = aux->head;
    aux->next = NULL;
    aux->prev = NULL;
    if(lines->name_line == NULL){           /*When there's no lines in the linked list of structs lines.*/
        (*lines) = (*aux);
    }
    else{
        Line *end = lines;
        while(end->next != NULL)
            end = end->next;
        end->next = aux;
        aux->prev = end;
    }
}

/*
 * Prints all the stops in the corresponding line in the following format: <first stop>, <stop>, ..., <last stop>.
 * Receives a pointer to the linked list of structs lines and a pointer to the string name_line.
*/

void list_stops_line(Line *lines, char *name_line){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0){
            if(aux->number_stops == 0) return;
            else if(aux->number_stops == 1){
                printf("%s\n", aux->first_stop);
                break;
            }
            else{
                while(aux->head->next != NULL){
                    printf("%s, ", aux->head->stop);
                    aux->head = aux->head->next;
                }
                while(aux->head->prev != NULL)
                    aux->head = aux->head->prev;
                printf("%s\n", aux->last_stop);
                break;
            }
        }
        aux = aux->next;
    }
}

/*
 * Prints all the stops in the corresponding line in the following format: <last stop>, <stop>, ..., <first stop>.
 * Receives a pointer to the linked list of structs lines and a pointer to the string name_line.
*/

void list_inverted_stops_line(Line *lines, char *name_line){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0){
            if(aux->number_stops == 0) return;
            else if(aux->number_stops == 1){
                printf("%s\n", aux->last_stop);
                break;
            }
            else{
                while(aux->end->prev != NULL){
                    printf("%s, ", aux->end->stop);
                    aux->end = aux->end->prev;
                }
                while(aux->end->next != NULL)
                    aux->end = aux->end->next;
                printf("%s\n", aux->first_stop);
                break;
            }
        }
        aux = aux->next;
    }
}

/*
 * Prints a list of all the lines in the linked list of structs lines in the following format:
 * <name of line> <name of first stop> <name of last stop> <number of stops> <cost> <duration>.
 * Receives a pointer to the linked list of structs lines.
*/

void list_lines(Line *lines){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(aux->first_stop == NULL){
            if(aux->name_line != NULL)
                printf("%s %d %.2f %.2f\n", aux->name_line, aux->number_stops, aux->cost, aux->duration);
        }
        else printf("%s %s %s %d %.2f %.2f\n", aux->name_line, aux->first_stop, aux->last_stop, aux->number_stops, 
            aux->cost, aux->duration);
        aux = aux->next;
    }
}

/* 
 * Verifies if a string is a prefix of at least size 3 of the word inverso.
 * Receives a string inverse and returns TRUE if it is a prefix and FALSE otherwise.
*/

int verify_inverse(char inverse[]){
    char inv[] = "inverso";
    int size = strlen(inverse), i;

    if (size < 3 || size > 7)
        return FALSE;
    for (i = 0; i < size; i++)
        if (inv[i] != inverse[i])
            return FALSE;
    return TRUE;
}

/*
 * Checks if the line exists in the linked list of structs lines.
 * Receives a pointer to the linked list of structs lines and a pointer to the string name_line.
 * Returns TRUE if the line exists and FALSE otherwise.
*/

int check_line(Line *lines, char *name_line){
    Line *aux = lines;
    if(aux == NULL) return FALSE;
    while(aux != NULL){
        if(strcmp(name_line, aux->name_line) == 0){
            return TRUE;
        }
        aux = aux->next;
    }
    return FALSE;
}

/*
 * Analises and separates the input regarding lines and computes the correct function.
 * Receives as arguments a string of input from the user and a pointer to the linked list of structs lines.
*/

void command_c(char command[], Line *lines){
    char *name_line = malloc(MAXINPUT + 2), inverse[MAXINV] = {'\0'}, letter;
    long unsigned int i;
    if(command[1] == '\n'){
        if(lines == NULL) return;
        list_lines(lines);
        return;
    }
    if(name_line == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
    sscanf(command, "%c %s %s", &letter, name_line, inverse);
    if(lines == NULL){
        lines = new_line();
        
    }
    if(lines->name_line == NULL){
        for(i = 0; i < strlen(name_line); i++){
            if(name_line[i] < 'A' || name_line[i] > 'Z'){
                fputs(ERROR8, stdout);
                return;
            }
        }
        create_line(lines, name_line);
    }
    else if(inverse[0] == '\0'){
        if(check_line(lines, name_line))
            list_stops_line(lines, name_line);           
        else{
            for(i = 0; i < strlen(name_line); i++){
                if(name_line[i] < 'A' || name_line[i] > 'Z'){
                    fputs(ERROR8, stdout);
                    return;
                }
            }
            create_line(lines, name_line);
        }
    }
    else if(verify_inverse(inverse))
        list_inverted_stops_line(lines, name_line);
    else fputs(ERROR1, stdout);
    free(name_line);
    return;
}

/*
 * Functions for stops.
*/

/*
 * Initializes the linked list of structs that will contain the name of the lines that pass in the stop.
*/

Linesinstop *create_lines_in_stop(){
    Linesinstop *aux = malloc(sizeof(Linesinstop));
    if(!aux) return FALSE;
    aux->line = NULL;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}

/*
 * Initializes the linked list of structs that will contain every stop.
*/

Stop *new_stop(){
    Stop *stops = malloc(sizeof(Stop));
    if(!stops) return FALSE;
    stops->name_stop = NULL;
    stops->latitude = 0;
    stops->longitude = 0;
    stops->number_lines = 0;
    stops->head = NULL;
    stops->end = NULL;
    stops->next = NULL;
    stops->prev = NULL;
    return stops;
}

/*
 * Creates a new stop in the linked list of structs stops.
 * Receives a pointer to the linked list of structs stops, a pointer to the string name_stop and two doubles latitude and longitude.
*/

void create_stop(Stop *stops, char *name_stop, double latitude, double longitude){
    Stop *aux = malloc(sizeof(Stop));
    if(!aux) return;
    aux->name_stop =  malloc(sizeof(char) * (strlen(name_stop) + 1));
    if(!aux->name_stop){
        free(aux);
        return;
    }
    strcpy(aux->name_stop, name_stop);
    aux->latitude = latitude;
    aux->longitude = longitude;
    aux->number_lines = 0;
    aux->head = create_lines_in_stop();
    aux->end = aux->head;
    aux->next = NULL;
    aux->prev = NULL;
    if(stops->name_stop == NULL){           /*When there's no stops in the linked list of structs stops.*/
        (*stops) = (*aux);
    }
    else{
        Stop *end = stops;
        while(end->next != NULL)
            end = end->next;
        end->next = aux;
        aux->prev = end;
    }
    return;
}

/*
 * Prints the coordinates of the corresponding stop in the following format: <latitude> <longitude>.
 * Receives a pointer to the linked list of structs stops and a pointer to the string name_stop.
*/

void coordinates_stop(Stop *stops, char *name_stop){
    Stop *aux = stops;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(name_stop, aux->name_stop) == 0){
            printf("%16.12f %16.12f\n", aux->latitude, aux->longitude);
            break;
        }
        aux = aux->next;
    }
}

/*
 * Prints a list of all the stops in the following format: <name of stop>: <latitude> <longitude> <number of lines>.
 * Receives a pointer to the linked list of structs stops.
*/

void list_stops(Stop *stops){
    Stop *aux = stops;
    if(!aux) return;
    while(aux != NULL){
        if(strlen(aux->name_stop) > 10)
            printf("%s: %16.12f %16.12f %d\n", aux->name_stop, aux->latitude, aux->longitude, aux->number_lines);
        aux = aux->next;
    }
}

/*
 * Checks if stop exists in the linked list of structs stops.
 * Receives a pointer to the linked list of structs stops and a pointer to the string name_stop.
 * Returns TRUE if the stop exists and FALSE otherwise.
*/

int check_stop(Stop *stops, char *name_stop){
    Stop *aux = stops;
    if(aux == NULL) return FALSE;
    while(aux != NULL){
        if(strcmp(name_stop, aux->name_stop) == 0){
            return TRUE;
        }
        aux = aux->next;
    }
    return FALSE;
}

/*
 * Analises and separates the input regarding stops and computes the correct function.
 * Receives as arguments a string of input from the user and a pointer to the linked list of structs stops.
*/

void command_p(char command[], Stop *stops){
    char *name_stop = malloc(MAXINPUT + 2);
    char letter;
    double latitude = 0, longitude = 0;
    if(!stops) 
        stops = new_stop();
    if(name_stop == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
    if(stops == NULL){
        stops = malloc(sizeof(Stop));
        stops = new_stop();
    }

    if(command[2] == '\"')
        sscanf(command, "%c \"%[^\"]\" %lf %lf", &letter, name_stop, &latitude, &longitude);
    else sscanf(command, "%c %s %lf %lf", &letter, name_stop, &latitude, &longitude);

    if(command[1] == '\n'){
        list_stops(stops);
    }
    else if(latitude == 0 && longitude == 0){
        if(check_stop(stops, name_stop))
            coordinates_stop(stops, name_stop);
        else{
            printf("%s: ", name_stop);
            fputs(ERROR2, stdout);
        }
    }
    else if(stops->name_stop == NULL)
        create_stop(stops, name_stop, latitude, longitude);
    else{
        if(check_stop(stops, name_stop)){
            printf("%s: ", name_stop);
            fputs(ERROR3, stdout);
        }
        else create_stop(stops, name_stop, latitude, longitude);
    }
    free(name_stop);
}

/*
 * Functions for links.
*/

/*
 * Adds a line to the linked list of names of lines in the corresponding stop.
 * Receives a pointer to the linked list of structs stops and a pointer to the string line.
*/

void append_lines_in_stop(Stop *aux, char *line){
    Linesinstop *a = malloc(sizeof(Stopsinline));
    if(!a) return;
    a->line = malloc(sizeof(char) * (strlen(line) + 1));
    if(!a->line){
        free(a);
        return;
    }
    strcpy(a->line, line);
    a->next = NULL;
    a->prev = NULL;
    if(aux->head->line == NULL ){       /*Adds the first line that passes in the stop.*/
        (*aux->head) = (*a);
        (*aux->end) = (*a);
        aux->number_lines = 1;
    }
    else{
        Linesinstop *end = aux->head;
        while(end->next != NULL){
            if(strcmp(end->line, a->line) == 0){
                free(a->line);
                free(a);
                return;
            }
            end = end->next;
        }
        if(strcmp(end->line, a->line) == 0){
            free(a->line);
            free(a);
            return;
        }
        end->next = a;
        a->prev = end;
        aux->end = a;
        aux->number_lines++;
    }
    return;
}

/*
 * Adds a stop to the end of the linked list of names of stops in the corresponding line.
 * Receives a pointer to the linked list of structs lines and a pointer to the string stop.
*/

void append_stops_in_line(Line *aux, char *stop){
    Stopsinline *a = malloc(sizeof(Stopsinline));
    if(!a)return;
    a->stop = malloc(sizeof(char) * (strlen(stop) + 1));
    if(!a->stop){
        free(a);
        return;
    }
    strcpy(a->stop, stop);
    a->next = NULL;
    a->prev = NULL;
    if(aux->head->stop == NULL ){           /*Adds the first stop in the line.*/
        (*aux->head) = (*a);
    }
    else{
        Stopsinline *end = aux->end;
        end->next = a;
        a->prev = end;
        aux->end = aux->end->next;
    }
    return;
}

/*
 * Adds a stop to the beginning of the linked list of names of stops in the corresponding line.
 * Receives a pointer to the linked list of structs lines and a pointer to the string stop.
*/

void insert_stops_in_line(Line *aux, char *first_stop){
    Stopsinline *a = malloc(sizeof(Stopsinline));
    Stopsinline *end = aux->head;
    if(!a) return;
    a->stop = malloc(sizeof(char) * (strlen(first_stop) + 1));
    if(!a->stop){
        free(a);
        return;
    }
    strcpy(a->stop, first_stop);
    a->next = NULL;
    a->prev = NULL;   
    end->prev = a;
    a->next = end;
    aux->head = aux->head->prev;
    return;
}

/*
 * Updates the stops, the cost and the duration and the number of stops of the corresponding line in the linked list of structs lines when the link 
 * is added to the end of the line and when the line doesn't have any stops.
 * Receives a pointer to the linked list of structs lines, three poiters to the strings, name_line, first_stop and last_stop, and two floats, cost and duration.
*/
void update_line(Line *lines, char *name_line, char *first_stop, char *last_stop, float cost, float duration){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0){
            if(aux->first_stop == NULL){            /*When there's no stops at the line.*/
                aux->first_stop = malloc(sizeof(char) * (strlen(first_stop) + 1));
                strcpy(aux->first_stop, first_stop);
                append_stops_in_line(aux, first_stop);
                aux->number_stops = 1;
            }
            append_stops_in_line(aux, last_stop);
            aux->last_stop = malloc(sizeof(char) * (strlen(last_stop) + 1));
            strcpy(aux->last_stop, last_stop);
            aux->cost += cost;
            aux->duration += duration;
            aux->number_stops++;
            break;
        }
        aux = aux->next;
    }
}

/*
 * Updates the stops, the cost and the duration and the number of stops of the corresponding line in the linked list of structs lines when the link is added to the
 * beginning of the line.
 * Receives a pointer to the linked list of structs lines, two poiters to the strings, name_line and first_stop, and two floats, cost and duration.
*/

void update_inv_line(Line *lines, char *name_line, char *first_stop, float cost, float duration){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0){
            insert_stops_in_line(aux, first_stop);
            aux->cost += cost;
            aux->duration += duration;
            aux->first_stop = malloc(sizeof(char) * (strlen(first_stop) + 1));
            strcpy(aux->first_stop, first_stop);
            aux->number_stops++;
            break;
        }
        aux = aux->next;
    }
}

/*
 * Updates the linked list of names of lines and the number of lines that pass in the corresponding stop.
 * Receives a pointer to the linked list of structs stops and two poiters to the strings, the name of the line and the name of the stop.
*/

void update_stop(Stop *stops, char *name_line, char *stop){
    Stop *aux = stops;
    if(!aux) return;
    while(aux != NULL){
        if(strcmp(aux->name_stop, stop) == 0){
            append_lines_in_stop(aux, name_line);
            break;
        }
        aux = aux->next;
    }
}

/*
 * Checks if the stop is the last one in the corresponding line.
 * Receives a pointer to the linked list of structs lines, a pointer to the string name_line and a pointer to the string name_stop.
 * Returns TRUE if it's the last stop and FALSE otherwise.
*/

int its_last_stop(Line *lines, char *name_line, char *name_stop){
    Line *aux = lines;
    if(!aux) return FALSE;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0 && strcmp(aux->last_stop, name_stop) == 0){
            return TRUE;
        }
        aux = aux->next;
    }
    return FALSE;
}

/*
 * Checks if the stop is the first one in the corresponding line.
 * Receives a pointer to the linked list of structs lines, a pointer to the string name_line and a pointer to the string name_stop.
 * Returns TRUE if it's the first stop and FALSE otherwise.
*/

int its_first_stop(Line *lines, char *name_line, char *name_stop){
    Line *aux = lines;
    if(!aux) return FALSE;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0 && strcmp(aux->first_stop, name_stop) == 0){
            return TRUE;
        }
        aux = aux->next; 
    }
    return FALSE;
}

/*
 * Checks if the line doesn't have stops.
 * Receives a pointer to the linked list of structs lines and a pointer to the string name_line. Returns TRUE if the line doesn't have stops and FALSE otherwise.
*/

int checks_no_stops_line(Line *lines, char *name_line){
    Line *aux = lines;
    if(!aux) return FALSE;
    while(aux != NULL){
        if(strcmp(aux->name_line, name_line) == 0){
            if(aux->first_stop == NULL && aux->last_stop == NULL){
                return TRUE;
            }
        }
        aux = aux->next;
    }
    return FALSE;
}

/*
 * Analises and separates the input regarding links and computes the correct function.
 * Receives as arguments a string of input from the user, a pointer to the linked list of structs lines and a pointer to the linked list of structs stops.
*/

void command_l(char command[], Line *lines, Stop *stops){
    char *name_line = malloc(MAXINPUT + 2), *first_stop = malloc(MAXINPUT + 2), *last_stop = malloc(MAXINPUT + 2), letter;
    float cost = 0, duration = 0;
    int i, num_quot_mark = 0, num_arg = 0, arg_with = 0;
    if(name_line == NULL || first_stop == NULL || last_stop == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
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

    if(check_line(lines, name_line) == FALSE){
        printf("%s: ", name_line);
        fputs(ERROR4, stdout);
    }
    else if(check_stop(stops, first_stop) == FALSE){
        printf("%s: ", first_stop);
        fputs(ERROR2, stdout);
    }
    else if(check_stop(stops, last_stop) == FALSE){
        printf("%s: ", last_stop);
        fputs(ERROR2, stdout);
    }
    else if(cost < 0 || duration < 0)
        fputs(ERROR5, stdout);
    else if(checks_no_stops_line(lines, name_line) || its_last_stop(lines, name_line, first_stop)){
        update_line(lines, name_line, first_stop, last_stop, cost, duration);
        update_stop(stops, name_line, first_stop);
        update_stop(stops, name_line, last_stop);
    }
    else if(its_first_stop(lines, name_line, last_stop)){
        update_inv_line(lines, name_line, first_stop, cost, duration);
        update_stop(stops, name_line, first_stop);
    }
    else
        fputs(ERROR6, stdout);
    free(name_line);
    free(first_stop);
    free(last_stop);
}

/*
 * Functions for intersections.
*/

/*
 * Sorts the names in the linked list of names of lines in alphabetic order.
 * Receives two pointers, one to the beginning of the linked list of names of lines and one to the end.
*/

void bubble(Linesinstop *head, Linesinstop *end){
    int change = TRUE;
    Linesinstop *i = head, *j = end;
    if(!i || !j) return;
    while(change && i->next != NULL){
        change = FALSE;
        while(j->prev != NULL){
            if(strcmp(j->prev->line, j->line) > 0){
                Linesinstop *temp = malloc(sizeof(Linesinstop));
                if(!temp) return;
                temp->line = malloc(sizeof(char) * strlen(j->prev->line));
                if(!temp->line){
                    free(temp);
                    return;
                }
                strcpy(temp->line, j->prev->line);
                strcpy(j->prev->line, j->line);
                strcpy(j->line, temp->line);
                change = TRUE;
                free(temp->line);
                free(temp);
            }
            j = j->prev;
        }
        i = i->next;
        j = end;
    }
}

/*
 * Prints, for every stop where more than one line pass, the number of lines that pass there as well as their names in alfabetic order.
 * Receives a pointer to the linked list of structs stops.
*/

void list_intersections(Stop *stops){
    Stop *aux = stops;
    if(!aux) return;
    while(aux != NULL){
        if(aux->number_lines > 1){
            bubble(aux->head, aux->end);
            printf("%s %d: ", aux->name_stop, aux->number_lines);
            while(aux->head->prev != NULL)
                aux->head = aux->head->prev;
            while(aux->head->next != NULL){
                printf("%s ", aux->head->line);
                aux->head = aux->head->next;
            }
            printf("%s\n", aux->head->line);
        }
        aux = aux->next;      
    }
}

/*
 * Functions to remove lines.
*/

/*
 * Removes the name of the corresponding line from the linked list of names of lines.
 * Receives a pointer to the linked list of names of lines and a pointer to the string name_line.
*/

void remove_name_line(Linesinstop *lst, char *name_line){
    Linesinstop *aux;
    for(aux = lst->next; aux; aux = aux->next){
        if(strcmp(lst->line, name_line) == 0)
            break;
    }
    if(!aux) return;
    if(aux->next && aux->prev){         /*Removes in the middle.*/
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
        return;
    }
    if(aux->next){                      /*Removes at the beginning.*/
        aux->next->prev = NULL;
        lst->next = aux->next;
    }
    if(aux->prev){                      /*Removes at the end.*/
        aux->prev->next = NULL;
        lst->prev = aux->prev;
    }
    free(aux);
}

/*
 * Removes the line from the linked list of structs lines.
 * Receives a pointer to the linked list of structs lines, a pointer to the string name_line and a pointer to the linked list of structs stops.
*/

void removes_line(Line *lines, char *name_line, Stop *stops){
    Line *aux;
    for(aux = lines->next; aux; aux = aux->next){
        if(strcmp(aux->name_line, name_line) == 0)
            break;
    }
    if(!aux) return;
    if(aux->next && aux->prev){                 /*Removes in the middle.*/
        if(aux->number_stops > 0){
            while(aux->head != NULL){           /*Looking for the stops where the line passes to remove it there.*/
                Stop *temp = stops;
                while(temp->name_stop != NULL){
                    if(strcmp(temp->name_stop, aux->head->stop) == 0)
                        break;
                    temp = temp->next;
                }
                remove_name_line(temp->head, name_line);
                temp->number_lines--;
                aux->head = aux->head->next;
            }
        }
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
        return;
    }
    if(aux->next && aux->prev == NULL){        /*Removes at the beginning.*/
        if(aux->number_stops > 0){
            while(aux->head != NULL){           /*Looking for the stops where the line passes to remove it there.*/
                Stop *temp = stops;
                while(temp->name_stop != NULL){
                    if(strcmp(temp->name_stop, aux->head->stop) == 0)
                        break;
                    temp = temp->next;
                }
                remove_name_line(temp->head, name_line);
                temp->number_lines--;
                aux->head = aux->head->next;
            }
        }                
        aux->next->prev = NULL;
        lines->next = aux->next;
    }
    if(aux->prev){                              /*Removes at the end.*/
        if(aux->number_stops > 0){
            while(aux->head != NULL){           /*Looking for the stops where the line passes to remove it there.*/
                Stop *temp = stops;
                while(temp->name_stop != NULL){
                    if(strcmp(temp->name_stop, aux->head->stop) == 0)
                        break;
                    temp = temp->next;
                }
                remove_name_line(temp->head, name_line);
                temp->number_lines--;
                aux->head = aux->head->next;
            }
        }              
        aux->prev->next = NULL;
        lines->prev = aux->prev;
    }
    free(aux);
}

/*
 * Analises the input regarding removing lines and computes the corresponding function.
 * Receives as arguments a string of input from the user, a pointer to the linked list of structs lines and a pointer to the linked list of structs stops.
*/

void command_r(char command[], Line *lines, Stop *stops){
    char *name_line = malloc(MAXINPUT + 2), letter;
    if(name_line == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
    sscanf(command, "%c %s", &letter, name_line);
    if(strlen(command) > 1){
        sscanf(command, "%c %s", &letter, name_line);
    }
    if(!check_line(lines, name_line))
        fputs(ERROR4, stdout);
    else removes_line(lines, name_line, stops);
    free(name_line);
}

/*
 * Functions to remove stops.
*/

/*
 * Removes the name of the corresponding stop from the linked list of names of stops.
 * Receives a pointer to the linked list of structs lines, a pointer to the string name_line and a pointer to the string name_stop.
*/

void remove_name_stop(Line *lines, char *name_line, char *name_stop){
    Line *temp = lines;
    if(!temp) return;
    while(temp->name_line != NULL){                         /*Looking for the lines that paas in the stop to remove it there.*/
        if(strcmp(temp->name_line, name_line) == 0){
            Stopsinline *a = temp->head;
            if(!a) return;
            while(a != NULL){
                if(strcmp(a->stop, name_stop) == 0){
                    if(a->prev != NULL){                    /*Removes at the beginning.*/
                        a->prev->next = a->next;
                        if(a->next != NULL)
                            a->next->prev = a->prev;
                        if (temp->head == a)
                            temp->head = a->next;
                    }
                    else{                                   /*Removes in the middle and at the end.*/
                        temp->head = a->next;
                        if(temp->head != NULL)
                            temp->head->prev = NULL;
                        if(a->next != NULL)
                            a->next->prev = NULL;
                        if (temp->head == a)
                            temp->head = a->next;
                    }
                    free(a->stop);
                    free(a);
                    return;
                }
                a = a->next;
            }
        }
        temp = temp->next;
    }
    return;
}

/*
 * Removes the stop from the linked list of structs stops.
 * Receives a pointer to the linked list of structs stops, a pointer to the string name_stop and a pointer to the linked list of structs lines.
*/

void removes_stop(Stop *stops, char *name_stop, Line *lines){
    Stop *temp = stops;
    if(!temp) return;
    while(temp != NULL){
        if(strcmp(temp->name_stop, name_stop) == 0){
            while(temp->head != NULL){
                remove_name_stop(lines, temp->head->line, name_stop);
                temp->head = temp->head->next;
            }
            if(temp->prev != NULL){             /*Removes at the beginning.*/
                temp->prev->next = temp->next;
                if(temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            else{                               /*Removes in the middle and at the end.*/
                stops = temp->next;
                if(stops != NULL)
                    stops->prev = NULL;
                if(temp->next != NULL)
                    temp->next->prev = NULL;
            }
            free(temp->name_stop);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    return;
}

/*
 * Analises the input regarding removing stops and computes the corresponding function.
 * Receives as arguments a string of input from the user, a pointer to the linked list of structs stops and a pointer to the linked list of structs lines.
*/

void command_e(char command[], Stop *stops, Line *lines){
    char *name_stop = malloc(MAXINPUT + 2), letter;
    if(name_stop == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
    sscanf(command, "%c %s", &letter, name_stop);
    if(!check_stop(stops, name_stop))
        fputs(ERROR2, stdout);
    else removes_stop(stops, name_stop, lines);
    free(name_stop);
}

/*
 * Functions to remove everything.
*/

/*
 * Removes every line from the linked list of structs lines.
 * Receives a pointer to the linked list of structs lines.
*/

void remove_all_lines(Line *lines){
    while(lines != NULL){
        Line *temp = lines;
        while(temp->head != NULL){
            Stopsinline *aux = temp->head;
            temp->head = aux->next;
            if(temp->head != NULL)
                temp->head->prev = NULL;
            free(aux->stop);
            free(aux);
        }
        lines = temp->next;
        if(lines != NULL)
            lines->prev = NULL;
        free(temp->name_line);
        free(temp->first_stop);
        free(temp->last_stop);
        free(temp);
    }
    free(lines);
}

/*
 * Removes every stop from the linked list of structs stops.
 * Receives a pointer to the linked list of structs stops.
*/

void remove_all_stops(Stop *stops){
    while(stops != NULL){
        Stop *temp = stops;
        while(temp->head != NULL){
            Linesinstop *aux = temp->head;
            temp->head = aux->next;
            if(temp->head != NULL)
                temp->head->prev = NULL;
            free(aux->line);
            free(aux);
        }
        stops = temp->next;
        if(stops != NULL)
            stops->prev = NULL;
        free(temp->name_stop);
        free(temp);
    }
    free(stops);
}

/*
 * Removes every line and every stop from the corresponding linked lists.
 * Receives a pointer to the linked list of structs lines and a pointer to the linked list of structs stops.
*/

void command_a(Line *lines, Stop *stops){
    remove_all_lines(lines);
    remove_all_stops(stops);
}

/*
 * Functions to list the lines that start with a certain stop.
*/

void list_lines_stop(Line *lines, char *name_stop){
    Line *aux = lines;
    if(!aux) return;
    while(aux != NULL){
        if(aux->first_stop == NULL)
            return;
        else if(strcmp(aux->first_stop, name_stop) == 0)
            printf("%s ", aux->name_line);
        aux = aux->next;
    }
    printf("\n");
    free(aux);
}

void command_s(char command[], Line *lines, Stop *stops){
    char *name_stop = malloc(MAXINPUT + 2), letter;
    if(name_stop == NULL){
        fputs(ERROR7, stdout);
        exit(0);
    }
    if(lines == NULL)
        return;
    sscanf(command, "%c %s", &letter, name_stop);
    if(check_stop(stops, name_stop))
        list_lines_stop(lines, name_stop);
    else{
        printf("%s: ", name_stop);
            fputs(ERROR2, stdout);
    }
    free(name_stop);
}

