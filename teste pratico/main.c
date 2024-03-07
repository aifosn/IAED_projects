/* iaed-23 - ist1106609 - project2 */
/* 
 * File:    project2.c
 * Author:  Sofia Nunes
 * Description: A program that creates, lists and removes bus lines, their stops and other relevant information to the user like the cost and the duration 
 *              of the line, the coordinates of the corresponding stop and the intersections in each stop.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Main function.
*/

/*
 *Receives input from the user, stores it in the string command and analyses the first letter of the input computing the corresponding function.
 *When 'q' exits the program. Initializes pointers to the first element of the corresponding linked lists.
 */

int main(){
    Stop *stops = new_stop();
    Line *lines = new_line();
    char command[MAXINPUT + 2];
    if(!stops) return 2;
    if(!lines) return 2;
    while(1){
        if(fgets(command, MAXINPUT + 2, stdin) != NULL){
            switch(command[0]){
                case 'q':
                    exit(0);

                case 'c':
                    command_c(command, lines);
                    break;

                case 'p':
                    command_p(command, stops);
                    break;

                case 'l':
                    command_l(command, lines, stops);
                    break;

                case 'i':
                    list_intersections(stops);
                    break;

                case 'r':
                    command_r(command, lines, stops);
                    break;

                case 'e':
                    command_e(command, stops, lines);
                    break;
                    
                case 'a':
                    command_a(lines, stops);
                    lines = NULL;
                    stops = NULL;
                    break;
                case 's':
                    command_s(command, lines, stops);
                    break;
            }
        }
    }
    return 0;
}
