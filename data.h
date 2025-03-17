#define MAX_LINE_LENGTH 80
#define MAX_LABEL_LENGTH 31  
#define MAX_COMMAND_LENGTH 4

typedef struct {
    char commandName[MAX_COMMAND_LENGTH + 2];
    char firstParam[MAX_LABEL_LENGTH + 2];
    char secondParam[MAX_LABEL_LENGTH + 2];
} command;

char *trim_white_spaces(char *);
void identify_command(char *, command *);
