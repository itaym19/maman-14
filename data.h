#define MAX_LINE_LENGTH 80
#define MAX_LABEL_LENGTH 31  
#define MAX_COMMAND_LENGTH 4

typedef struct {
    char commandName[10];
    char firstParam[33];
    char secondParam[33];
} command;

char *trim_white_spaces(char *);
void identify_command(char *, command *);
