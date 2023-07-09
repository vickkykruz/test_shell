#ifndef SHELL_PROJECT
#define SHELL_PROJECT

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include "global_marcos.h"

/*** PROTOTYPES ***/

/*** SHELL_LOOP.C FILE ****/
void shell_loop(string prompt, data_list *ptr);

/*** PRINT.C FILE ****/
integer printerr_ch(string str);
integer print(string str);
integer print_err(integer statusCode, data_list *ptr);

/*** GETLINE.C FILE ****/
integer _getline(data_list *ptr);

/*** FUNC1.C FILE ****/
integer _strlen(string str);
void str_rev(string str);
void convertstr(long_number num, string str, integer b);
string _strdup(string str);

/*** TOKENIZE.C FILE ****/
integer islogic(string arr_cmd[], integer idx, char arr_opt[]);
string _strtoken(string line, string delim);

/*** FREE.C ****/
void free_ptr(string *ptr);
void free_repetitive_data(data_list *ptr);
void free_data(data_list *ptr);
#endif
