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

char *remove_all_spaces(char * str) {
   imt i=0 ,j = 0;
   /* Check if the input string is NULL */
    if (str == NULL) {
        return NULL;
    }
     /* Allocate memory for the new string, assuming the worst case where no spaces are removed */
    int len = strlen(str);
    char *result = (char *)malloc(len + 1); /* +1 for the null terminator */
    if (result == NULL) {
        return NULL;  /* Memory allocation failed */
    }

    int j = 0;  /* Index for the result string */
    for (int i = 0; i < len; i++) {
        /* If the current character is not a white space, copy it to the result */
        if (!isspace(str[i])) {
            result[j++] = str[i];
        }
    }
    /* Null-terminate the new string */
    result[j] = '\0';

    return result;
}

/* function for identifying parameters */
bool identify_parameters(const char *input, command *cmd) {
    int paramCount = 0;
    char *token;
    /* Temporary buffer to hold input as we split it */
    char buffer[MAX_LINE_LENGTH + 1];
    strcpy(buffer, input);
    /* Split the string by comma */
    token = strtok(buffer, ",");
    
    /* first char of parameter string is comma */
    if (*char == ',') {
        fprintf(stderr, "error: there cannot be a comma before first parameter");
        return false;
    }
    /* last char of parameter string is comma */
    if (cha[strlen(str)-1] == ',') {
        fprintf(stderr, "error: there cannot be a comma after last parameter");
        return false;
    }
    /* 2 consecutive commas between parameters */
    if (strstr(str, ",,") != NULL) {
        fprintf(stderr, "error: there cannot be 2 consecutive commas between parameters");
        return false;
    }

    /* Store the  and parameters */
    while (token != NULL) {
        if (paramCount == 0) {
            /* store token in first parameter */
            strncpy(cmd->firstParam, token, MAX_LABEL_LENGTH + 1);
            cmd->firstParam[MAX_LABEL_LENGTH + 1] = '\0';
        } else if (paramCount == 1) {
            /* store token in second parameter */
            strncpy(cmd->secondParam, token, MAX_LABEL_LENGTH + 1);
            cmd->secondParam[MAX_LABEL_LENGTH + 1] = '\0';
        } else {  /* If there are more than 2 parameters, return an error */
            fprintf(stderr, "too many parameters");
            return false;
        }
        /* Get the next token */
        token = strtok(NULL, ",");
        paramCount++;
    }

    return true;  
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
    
    
    

