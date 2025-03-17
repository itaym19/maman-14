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
    
    if (strstr(line, ",,") {
        fprintf(stderr, "error: there cannot be multiple commas in the command");
        return false;
    }
    
    /* go through first word */
    while ( (!isspace(line[i]) ) && (line[i] != '\0' ) { 
        i++
    }
    /* copy first word to command's name */
    if ( (i-j) > MAX_COMMAND_LENGTH) {
        strncpy(command->commandName, line[j], MAX_COMMAND_LENGTH + 1);
    }
    else {
        strncpy(command->commandName, line[j], i-j + 1);
    }
    /* advance j to reach i */
    for (j<i; j++); 
    
    /* go to start of second the parameters section */
    while ( (isspace(line[i])) && (line[i] != '\n') ) {
        i++;
        j++;
    }
    
    if (line[i] == ",") {
        fprintf(stderr, "error: there is a comma before first parameter");
        return false;
    }
    
    if (line[i] == "\n") return true;
    
    /* go through second word */
    while ( (!isspace(line[i]))  && (line[i] != ',') && (line[i] != '\0') && (line[i] != '\n') ) {
        i++;
    }
    /* copy second word to first parameter */
    if ( (i-j) > MAX_LABEL_LENGTH) {
        strncpy(command->firstParam, line[j], MAX_LABEL_LENGTH + 1);
    }
    else {
        strncpy(command->firstParam, line[j], i-j + 1);
    }
    /* advance j to reach i */
    for (j<i; j++);
    
    if (line[i] == '\n') return true;
    
    /* skip optional spaces between parameters */
    while ( (isspace(line[i])) && (line[i] != '\n') && (line[i] != '\0') ) {
        i++;
        j++;
    }
    
    if (line[i] == '\n') return true;
    
    if (line[i] == '\n') return true;
    
}
    
    
    

