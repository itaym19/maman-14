/* function for trimming leading and trailing spaces */
char *trim_white_spaces(char *s) {
    char *end;
    while( isspace(*s) ) s++;  /* Trim leading space */
    if(*s == 0) return s;  /* all white spaces */ 
    /* Trim trailing space */
    end = s + strlen(s) - 1;
    while( end > s && isspace(*end) ) end--;
    end[1] = '\0';  /* Write new null terminator character */
    
    return s;
}

/* function for identifying command name and parameters */
bool identify_command(char *line, command *command) {
    int i=0, j=0;
    bool isLastCharComma = false;
    /* go through first word */
    while ( (!isspace(*line[i]) ) && (*line[i] != '\0' ) { 
        i++
    }
    /* copy first word to command's name */
    for(j = 0; j < i; j++) {
        if (j <= MAX_COMMAND_LENGTH) {
            (command -> commandName[j]) = *line[j];
        }
        (command -> commandName[j+1]) = '\0';
    }
    /* go to start of second word */
    while (isspace(*line[i])) {
        i++;
        j++;
    }
    
    if (*line[i] == ",") {
        fprintf(stderr, "error: there is a comma before first parameter");
        return false;
    }
    /* go through second word */
    while ( (!isspace(*line[i] && (*line[i] != ',') && (*line[i] != '\0' ) ) {
        i++;
    }
    /* copy second word to first parameter */
    for( ; j < i; j++) {
        if (j <= MAX_LABEL_LENGTH) {
            (command -> commandName[j]) = *line[j];
        }
        (command -> commandName[j+1]) = '\0';
    }
    
}
    
    
    

