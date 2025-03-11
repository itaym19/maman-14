# maman-14
line length: 80
label length: 31


i need to write a program in c that reads a text file that contains instructions. each line can be an empty line or contain a command. the program should go through each line and identify the command and it's parameters. it then checks to see if the command is a legit command.
each command should have the following structure: 
command name, then one or more white spaces, then the parameters where each parameter is seperated from the  next one with a ",". there cannot be mor than 1 "," between parameters.
commands can have between 0 and 2 parameters.
if the command line is wrong there should be an error that specifies the issue for example:
wrong command name, not enough parameters, too many parameters, no comma between parameters, two many commas between parameters and so on.
