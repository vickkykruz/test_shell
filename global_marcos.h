#ifndef GLOBAL_MARCOS
#define GLOBAL_MARCOS

/* Rename global datatype*/
typedef int integer;
typedef char * string;
typedef float decimal;
typedef long long_number;

/**
 * struct data_info - created the sturct to store the argument entered
 * @arg: This is an argumen
*/
typedef struct data_into
{
    char *arg;
    char *arg_line;
    int count;
    char *cmd;
    int desc;
    char **env;
    char **segment;
    char **list;
} data_list;

#define PLACEHOLDRS \
	{ NULL, NULL, 0, NULL, 0, NULL, NULL, NULL }

#define HEX {"0123456789abcdef"}
/**
 * BUFF_SIZE - 
*/
#define BUFF_SIZE 1024


#endif
