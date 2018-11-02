// example of running cat top10.c | grep 'if'
// to compile type 'gcc top10.c -o top10'
// to run type './top10'
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
//cat $1 | grep 01/Oct/2006 | cut -d ' ' -f 1 
int main() {

	int fd[2], status;                                         
	pipe(fd);
	pid_t child1 = fork();                
		       
	if (!child1) {

		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);      

		execlp("cat","cat","log.txt" , NULL);
		exit(EXIT_FAILURE);
	}                                                          

	int fd_2[2];
	pipe(fd_2);
	pid_t child2 = fork();  

	if (!child2) {                                               
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);

		dup2(fd_2[1], 1);
		close(fd_2[0]); 
		close(fd_2[1]); 

		execlp("cut","cut","-f4,12","-d ", NULL);
		exit(EXIT_FAILURE);                            
	}

	close(fd[0]);
	close(fd[1]);

	int fd_3[2];
	pipe(fd_3);
	pid_t child3 = fork();

	if (!child3) {
		dup2(fd_2[0], 0);
		close(fd_2[0]); 
		close(fd_2[1]);

		dup2(fd_3[1], 1);
		close(fd_3[0]); 
		close(fd_3[1]); 

		execlp("grep","grep",".10/Oct/2006", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_2[0]); 
	close(fd_2[1]); 

	int fd_4[2];
	pipe(fd_4);
	pid_t child4 = fork();

	if (!child4) {
		dup2(fd_3[0], 0);
		close(fd_3[0]); 
		close(fd_3[1]);

		dup2(fd_4[1], 1);
		close(fd_4[0]);
		close(fd_4[1]);

		execlp("cut","cut", "-f2","-d ", NULL);
		exit(EXIT_FAILURE); 

	}

	close(fd_3[0]);
	close(fd_3[1]);

	int fd_5[2];
	pipe(fd_5);
	pid_t child5 = fork();

	if (!child5) {
		dup2(fd_4[0], 0);
		close(fd_4[0]); 
		close(fd_4[1]);

		dup2(fd_5[1], 1);
		close(fd_5[0]);
		close(fd_5[1]);		

		execlp("grep","grep", "-v", "<a", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_4[0]);
	close(fd_4[1]);

	int fd_6[2];
	pipe(fd_6);
	pid_t child6 = fork();

	if (!child6) {
		dup2(fd_5[0], 0);
		close(fd_5[0]); 
		close(fd_5[1]);	

		dup2(fd_6[1], 1);
		close(fd_6[0]);
		close(fd_6[1]);	

		execlp("grep","grep", "-v", "\"-\"", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_5[0]);
	close(fd_5[1]);

	int fd_7[2];
	pipe(fd_7);
	pid_t child7 = fork();

	if (!child7) {
		dup2(fd_6[0], 0);
		close(fd_6[0]); 
		close(fd_6[1]);	

		dup2(fd_7[1], 1);
		close(fd_7[0]);
		close(fd_7[1]);	

		execlp("sort","sort", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_6[0]);
	close(fd_6[1]);

	int fd_8[2];
	pipe(fd_8);
	pid_t child8 = fork();

	if (!child8) {
		dup2(fd_7[0], 0);
		close(fd_7[0]); 
		close(fd_7[1]);	

		dup2(fd_8[1], 1);
		close(fd_8[0]);
		close(fd_8[1]);	

		execlp("uniq","uniq", "-c", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_7[0]);
	close(fd_7[1]);

	
	int fd_9[2];
	pipe(fd_9);
	pid_t child9 = fork();

	if (!child9) {
		dup2(fd_8[0], 0);
		close(fd_8[0]); 
		close(fd_8[1]);	

		dup2(fd_9[1], 1);
		close(fd_9[0]);
		close(fd_9[1]);	

		execlp("sort","sort", "-rn", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_8[0]);
	close(fd_8[1]);

	

	int fd_10[2];
	pipe(fd_10);
	pid_t child10 = fork();

	if (!child10) {
		dup2(fd_9[0], 0);
		close(fd_9[0]); 
		close(fd_9[1]);	

		dup2(fd_10[1], 1);
		close(fd_10[0]);
		close(fd_10[1]);	

		execlp("head","head", "-n 10", NULL);
		exit(EXIT_FAILURE); 
	}

	close(fd_9[0]);
	close(fd_9[1]);

pid_t child11 = fork();

if (!child11) {
dup2(fd_10[0], 0);
close(fd_10[0]); 
close(fd_10[1]);		
execlp("awk","awk", "{ print ++count[$3]\". \" $2\" - \"$1\" - \"$1/339*100\"%\";}", NULL);
exit(EXIT_FAILURE); 
	}

	close(fd_10[0]);
	close(fd_10[1]);
	waitpid(child11, 0 , 0);

}
