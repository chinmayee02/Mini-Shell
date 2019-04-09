# Mini-Shell
 Mini Shell
Part A
This assignment helps you learn about processes and basic process management in a shell. You are asked to write a simple shell program called minish. This shell must work as follows. When you start your mini shell, it prints the following prompt and waits for a command from user.

minish>
From here onwards, you should be able to execute and control any binary executable just as you would in a normal shell. For instance
minish> Command

[ OUTPUT OF COMMAND SHOWN HERE ]

minish>
Additionally, your shell should be able to do the following:

Execute commands with multiple arguments. For example:
		minish> Command arg1 arg2 arg3
		
Execute commands in either foreground or background mode. In foreground mode, the shell just waits for the command to complete before displaying the shell prompt again (as in the above example). For background mode, a command (say Command 1) is executed with an ampersand & suffix. The shell prints the process ID of the backgrounded process and immediately prints the prompt to accept and execute the next command (say Command2), even as Command1 continues executing in the background. For example:
		minish> Command1 &
		Process print_process_id_1_here in background mode
		minish> Command2

		[OUTPUT OF Command1 AND Command2 MAY INTERLEAVE IN ARBITRARY ORDER]
		
Maintain multiple processes running in background mode simultaneously. For example:
		minish> Command1 &
		Process print_process_id_1_here in background mode
		minish> Command2 &
		Process print_process_id_2_here in background mode
		minish> Command3 &
		Process print_process_id_3_here in background mode
		minish> 

		[OUTPUT OF Command1, Command2, AND Command3 MAY INTERLEAVE IN ARBITRARY ORDER]

		
Redirect the input of a command from a file. For example:
		minish> Command < input_file
		
Redirect the output of a command to a file. For example:
		minish> Command > output_file
		
Part B
Implement command filters, i.e., redirect the stdout of one command to stdin of another using pipes. For example:
		minish> ls -l | wc -l
		
		minish> cat somefile | grep somestring | less
		
Ideally, your shell should be able to handle any number of filter components.
Terminate a foreground process by pressing [Ctrl-C]. Your shell must not get killed; only the process running in foreground mode must terminate. If executing a chain of filters (as in the above example), all processes in the filter chain must terminate.
Kill a process in background using the kill command.
		minish> kill give_process_id_here
		
Be able to execute any feasible combinations of filters and file I/O redirection.
The exit command should terminate your shell. Clean up any orphan processes as your shell exits.
Do Nots:
DO NOT use any special wrapper libraries or classes to borrow the basic functionality required in this assignment. If in doubt, ask the instructor first BEFORE doing so.
DO NOT use the system(...) syscall to execute the programs in your shell directly.
DO NOT write five or six different programs, one for each feature. Write one single program that includes all the above features.
You do not need to implement any scripting functionalities.
You do not need to implement wild character expansions such as *,?,[0-9], etc.
Hints:
Build and test one feature at a time.
Use Github to save and track changes to your code. Make backup copies of partially working versions of your code. This way, if you irreparably mess up your code, then you can at least roll back to your last backup copy.
First design your data structures and code-structure before you begin coding each feature. Anticipate specific problems you will face.
Check out man page for the following, which might be useful:
fork()
execv() and execl() (which one should you use?)
waitpid()
dup2() (for stdin/stdout redirection)
pipe()
open()
close()
fileno()
kill()
killpg()
setsid()
getgrp()
getpgid()
tcsetpgrp()
