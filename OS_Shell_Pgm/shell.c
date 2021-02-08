#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> // exec function comes under this
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

#define MAXCOM 1000 // max number of letters  
#define MAXLIST 100 // max number of commands 

#define clear() printf("\033[H\033[J") 

void firstScreen() { 
	clear(); 
	printf("******************"
		"*********************"); 
	printf("\n\n\n\t****  MY SHELL  ****"); 
	printf("\n\n\t-USE AT YOUR OWN RISK-"); 
	printf("\n\n\n*******************"
		"********************"); 
	char* username = getenv("USER"); 
	printf("\n\n\nUSER is: @%s", username); 
	printf("\n"); 
	sleep(1);  
	clear(); 
} 

void curWorkingDir() { 
	char cwd[1024]; // current working directory
    getcwd(cwd, sizeof(cwd)); 
    printf("\nDir: %s", cwd); 
}

void openHelp() { 
	puts("\n***WELCOME TO MY SHELL HELP***"
		"\n-Use the shell at your own risk..."
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>exit"
		"\n>history"
		"\n>all other general commands available in UNIX shell"
		"\n>pipe handling"
		"\n>improper space handling"); 
	return; 
} 

// Function where the system command is executed 
// exec process generate krega jo baki ko replace kar dega
// child parent process kaa copy
// execvp - child process create kar skta hai which is not a copy of parent process
// 
void execArgs(char** parsed) { 
	// Forking a child 
	pid_t pid = fork(); 
	// child process ki madad se karate hai
	if (pid == -1) { 
		printf("\nFailed forking child.."); 
		return; 
	} else if (pid == 0) { 
		if (execvp(parsed[0], parsed) < 0) { 
			printf("\nCould not execute command.."); 
		} 
		exit(0); 
	} else { 
		// waiting for child to terminate 
		wait(NULL); 
		return; 
	} 
} 

void execArgsPiped(char** parsed, char** parsedpipe) { 
	// 0 is read end, 1 is write end 
	int pipefd[2]; // 2 kaa kuch array
	pid_t p1, p2; 
 	// pipefd[1]
	if (pipe(pipefd) < 0) { 
		printf("\nPipe could not be initialized"); 
		return; 
	} 
	// basically ek pipe bana dega jismein we can read as well as write
	// 1 wala end write kaa hoga or 0 wala read kaa hoga
	// negative matlab we can't initialize

	p1 = fork(); // parent + c1 -> first command

	if (p1 < 0) { 
		printf("\nCould not fork"); 
		return; 
	} else if (p1 == 0) { 
		// Child 1 executing.. 
		// it will write its output at the pipe' s write end
		close(pipefd[0]); 
		dup2(pipefd[1], STDOUT_FILENO); // output file uspe write karwa rha hai 
		close(pipefd[1]); 

		if (execvp(parsed[0], parsed) < 0) { 
			printf("\nCould not execute command 1.."); 
			exit(0); 
		} 
	} else { 
		// Parent executing 
		p2 = fork(); 

		if (p2 < 0) { 
			printf("\nCould not fork"); 
			return; 
		} 

		// command 2 executing.. 
		// this is second command so it needs to read output of first command
		if (p2 == 0) { 
			close(pipefd[1]); 
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]); 
			if (execvp(parsedpipe[0], parsedpipe) < 0) { 
				printf("\nCould not execute command 2.."); 
				exit(0); 
			} 
		} else { 
			wait(NULL); 
			wait(NULL);
			// parent waiting for the two children to process 
		} 
	} 
} 
  
void printHistory(){
    HISTORY_STATE *myhist = history_get_history_state();

    HIST_ENTRY **mylist = history_list ();

    printf ("\n\t\tHistory\n\n");
    for (int i = 0; i < myhist->length; i++) { 
        printf ("\t%s\n", mylist[i]->line);
    }
}

int builtCmdExecuter(char** parsed) { 
	char *builtinCmds[5], *username;

	builtinCmds[0] = "exit"; 
	builtinCmds[1] = "cd"; 
	builtinCmds[2] = "help"; 
	builtinCmds[3] = "hello";
	builtinCmds[4] = "history";

	int f = 0;
	for (int i = 0; i < 5; i++) {
		if (strcmp(parsed[0], builtinCmds[i]) == 0) {
			f = i + 1;
			break;
		}
	} 
	switch (f) {
		case 1:
			printf("\nGoodbye.\n");
			exit(0);
		case 2:
			if (parsed[1] == NULL) {
				chdir("/.");
			} else {
				chdir(parsed[1]);
			}
			return 1;
		case 3:
			openHelp();
			return 1;
		case 4:
			username = getenv("USER");
			printf("Hello %s\n. Hope you are doing fine. Use help to know more", username);
		case 5:
			printHistory();
			return 1;
		default:
			break;
	}
	return 0; 
} 

int parsePipe(char* str, char** strpiped) { 
	for (int i = 0; i < 2; i++) { 
		strpiped[i] = strsep(&str, "|"); //similar to python separator
		if (strpiped[i] == NULL) 
			return 0;
	}  
	return 1;
}

void parseSpace(char* str, char** parsed) { 
    int i; 
    for (i = 0; i < MAXLIST; i++) { 
        parsed[i] = strsep(&str, " "); 
        if (parsed[i] == NULL) 
            break; 
        if (strlen(parsed[i]) == 0) 
            i--; 
    } 
}

int checkUserCommand(char* str, char** parsed, char** parsedpipe) { 
	char* strpiped[2];
	int piped = parsePipe(str, strpiped); // is there a pipe or not
	if (piped) { 
		parseSpace(strpiped[0], parsed); // split 1st command by space
		parseSpace(strpiped[1], parsedpipe); // split 2nd command by space
	} else { 
		parseSpace(str, parsed); // there is only one so split it simply
	} 
	if (builtCmdExecuter(parsed)) return 0; // check if it is built in or not
	return 1 + piped; 
}

int main() { 
	char *userCommand; // command entered by user to execute
	char *parsedArgs[MAXLIST]; // basically represent command before pipe(if any) split by spaces
	char *parsedArgsPiped[MAXLIST]; // basically represent command after pipe(if any) split by spaces

	firstScreen(); // starting screen for the user

	while (1) { 
		curWorkingDir(); // to print cwd

		userCommand = readline("\n$ ");
		if (strlen(userCommand) == 0) {
			continue;
		}
		add_history(userCommand);

		int flag = checkUserCommand(userCommand, parsedArgs, parsedArgsPiped); 
		// flag is 0 if there is no command or built in command
		// flag being 1 represents that there is only one command to run
		// flag being 2 represents that there is pipe and we need to execute two commands

		if (flag == 1) {
			execArgs(parsedArgs);
		} else if (flag == 2) {
			execArgsPiped(parsedArgs, parsedArgsPiped);
		} 
	} 
	return 0; 
} 