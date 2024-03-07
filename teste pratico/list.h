#ifndef list_h
#define list_h

/*
 * Global constants.
*/
#define TRUE 1
#define FALSE 0
#define MAXINPUT 65535  /*The maximum number of characters in a instruction.*/
#define MAXINV 8        /*The maximum number of characters in string inverse + \0.*/

#define ERROR1 "incorrect sort option.\n"
#define ERROR2 "no such stop.\n"
#define ERROR3 "stop already exists.\n"
#define ERROR4 "no such line.\n"
#define ERROR5 "negative cost or duration.\n"
#define ERROR6 "link cannot be associated with bus line.\n"
#define ERROR7 "No memory.\n"
#define ERROR8 "invalid line name.\n"

/*
 * Structs.
*/

typedef struct stopsinline{
    char *stop;
    struct stopsinline *prev, *next;
} Stopsinline;

typedef struct line{
    char *name_line;
    char *first_stop;
    char *last_stop;
    float cost;
    float duration;
    int number_stops;
    struct stopsinline *head, *end;
    struct line *prev, *next;
} Line;

typedef struct linesinstop{
    char *line;
    struct linesinstop *prev, *next;
} Linesinstop;

typedef struct stop{
    char *name_stop;
    double latitude;
    double longitude;
    int number_lines;
    struct linesinstop *head, *end;
    struct stop *prev, *next;
} Stop;

/*
 * Functions for lines.
*/

Stopsinline *create_stops_in_line();
Line *new_line();
void create_line(Line *lines, char *name_line);
void list_stops_line(Line *lines, char *name_line);
void list_inverted_stops_line(Line *lines, char *name_line);
void list_lines(Line *lines);
int verify_inverse(char inverse[]);
int check_line(Line *lines, char *name_line);
void command_c(char command[], Line *lines);

/*
 * Functions for stops.
*/

Linesinstop *create_lines_in_stop();
Stop *new_stop();
void create_stop(Stop *stops, char *name_stop, double latitude, double longitude);
void coordinates_stop(Stop *stops, char *name_stop);
void list_stops(Stop *stops);
int check_stop(Stop *stops, char *name_stop);
void command_p(char command[], Stop *stops);

/*
 * Functions for links.
*/

void append_lines_in_stop(Stop *aux, char *line);
void append_stops_in_line(Line *aux, char *stop);
void insert_stops_in_line(Line *aux, char *first_stop);
void update_line(Line *lines, char *name_line, char *first_stop, char *last_stop, float cost, float duration);
void update_inv_line(Line *lines, char *name_line, char *first_stop, float cost, float duration);
void update_stop(Stop *stops, char *name_line, char *stop);
int its_last_stop(Line *lines, char *name_line, char *name_stop);
int its_first_stop(Line *lines, char *name_line, char *name_stop);
int checks_no_stops_line(Line *lines, char *name_line);
void command_l(char command[], Line *lines, Stop *stops);

/*
 * Functions for intersections.
*/

void bubble(Linesinstop *head, Linesinstop *end);
void list_intersections(Stop *stops);

/*
 * Functions to remove lines.
*/

void remove_name_line(Linesinstop *lst, char *name_line);
void removes_line(Line *lines, char *name_line, Stop *stops);
void command_r(char command[], Line *lines, Stop *stops);

/*
 * Functions to remove stops.
*/

void remove_name_stop(Line *lines, char *name_line, char *name_stop);
void removes_stop(Stop *stops, char *name_stop, Line *lines);
void command_e(char command[], Stop *stops, Line *lines);

/*
 * Functions to remove everything.
*/

void remove_all_lines(Line *lines);
void remove_all_stops(Stop *stops);
void command_a(Line *lines, Stop *stops);

/*
 * Functions to list the lines that start with a certain stop.
*/

void list_lines_stop(Line *lines, char *name_stop);
void command_s(char command[], Line *lines, Stop *stops);

#endif 
