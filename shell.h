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
integer _print_alias(data_list *ptr, string str);
void print_env(data_list *ptr);

/*** GETLINE.C FILE ****/
integer _getline(data_list *ptr);

/*** FUNC1.C FILE ****/
integer _strlen(string str);
void str_rev(string str);
void convertstr(long_number num, string str, integer b);
string _strdup(string str);
integer _strcomp(string s1, string s2, integer num);

/*** TOKENIZE.C FILE ****/
integer islogic(string arr_cmd[], integer idx, char arr_opt[]);
string _strtoken(string line, string delim);
void partition(data_list *ptr);

/***** ENV.C FILE *****/
string access_env_key(string key, data_list *ptr);
integer remove_env(string key, data_list *ptr);
integer set_env(string key, string val, data_list *ptr);

/*** FREE.C ****/
void free_ptr(string *ptr);
void free_repetitive_data(data_list *ptr);
void free_data(data_list *ptr);

/**** ALIAS.C FILE ****/
integer buff_add(string buff, string str);
string access_alias(data_list *ptr, string str);
integer insert_alias(string str, data_list *ptr);
void alias_expansion(data_list *ptr);
integer _alias(data_list *ptr);

/***** VAR.C FILE *****/
void var_expansion(data_list *ptr);

/***** CMD_EXECUTE.C FILE *****/
integer execute(data_list *ptr);

/***** CMD_ENV.C FILE ******/
integer _env(data_list *ptr);
integer _unsetenv(data_list *ptr);
integer _setenv(data_list *ptr);

/***** FUNC2.C FILE *****/
void str_rev(string str);
string _strcon(string s1, string s2);

/***** BUILTIN.C FILE ******/
integer get_bulllet(data_list *ptr);

/***** CD.C FILE ******/
integer set_directory(data_list *ptr, string dir);
integer _cd(data_list *ptr);

/****** EXIT.C FILE ******/
integer exit_fun(data_list *ptr);

/**** NUM.C FILE *****/
integer char_count(string str, string ch);
integer _atoi(string str);

/** SEARCH_PROGRAM.C FILE **/
integer validate_file(string path);
string *segment_path(data_list *ptr);
#endif
