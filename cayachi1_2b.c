
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<string.h>
#include<sys/wait.h>
#define _GNU_SOURCE         
#include <fcntl.h>   
#define MAX_CAP 1024
#define MAX 15 

int pid_c; 
void ctrl_c(int); 
struct datStr{
	char arr[100];
};	
 
void ctrl_c(int num_c)
{
kill(pid_c,SIGKILL);
fflush(stdout);
return;
}	
int main() 
{ 
    pid_c=getpid();
	signal(SIGINT,ctrl_c);
	int dup2fd;
	int dup1fd;
    char buf[MAX];
	pid_t pid;
	int back_proc;
	int leng, i=0,k=0, argIsThere,j;
	
  while(1)
  {
	struct datStr dat[100];
	struct datStr dat2[100];
	waitpid(-1,NULL,WNOHANG);
    printf("minish>"); 
    gets(buf); 
    //printf("string is: %s\n", buf);
	j=0;
	char *token = strtok(buf, " "); 
	while (token != NULL) 
	{ 

		strcpy(dat[j++].arr, token);
		//printf("\nstring2 - %s", dat[j].arr);
		token = strtok(NULL, " "); 
		
	}
	//printf("\n 1.value of J is: %d",j);
	if(strcmp(dat[j-1].arr,"exit")==0)
	{
	 exit(EXIT_SUCCESS);	
	}
	
	if (j == 1)
	{
			//printf("\n arg not there"); 
			argIsThere = 0;
			//if()
	}
	else {
		//printf("\n arguent is there");
		argIsThere = 1;
		
		if(strcmp(dat[j-1].arr,"&")!=0){
		//printf("\n no ampersent");
		}
		else{
			dat[j-1].arr==NULL;
			back_proc=1;
			j--;
			
			if(j == 1)
			{
					argIsThere = 0;
			}	
			else
			{
					argIsThere = 1;
			}	
		}
		
	}
	
	
	
	//printf("\n 2.value of J is: %d",j);
	
	pid = fork();
	if(pid==0)
    {
		if(strcmp(dat[j-1].arr,"kill")==0)
		{
			char *ar_pid;
			strcpy(ar_pid,dat[j].arr);
			pid_t pid_n=(int)ar_pid;
			kill(pid_n, SIGKILL);
		}
		for(k=0;k<j;k++)
		{
			if(strcmp(dat[k].arr,"<")==0)
			{
				//printf("\n here in file");
				char *ar1=dat[k+1].arr;
				//printf("value of %s",ar1);
			    dat[k].arr[0]='\0';
				//printf("\n print current arr: %s \n ",dat[k].arr);
				int fd1 = open(ar1, O_RDONLY);
				dup1fd=dup2(fd1,0);
				close(fd1);
				execlp(dat[0].arr,dat[0].arr, NULL);
			}
			else if(strcmp(dat[k].arr,">")==0)
			{
				char *ar2=dat[k+1].arr;
				//printf("value of %s",ar2);
				dat[k].arr[0]='\0';
				//printf("\n print current arr: %s \n ",dat[k].arr);
				//printf("before open \n");
				int fd2 = open(ar2, O_WRONLY | O_APPEND );
				//printf("after open %d \n",fd2);
				dup2fd=dup2(fd2,1);
				close(fd2);
				//printf("\n print dat[0].arr: %s \n ",dat[0].arr);
				//printf("\n print dat[1].arr: %s \n ",dat[1].arr);
				if(j==3){
					//printf("\n\n\n\n val of j %d \n\n\n\n",j);
					execlp(dat[0].arr,dat[0].arr, NULL);
				}
				else if(j==4){
					//printf("\n\n\n\n val of j %d \n\n\n\n",j);
					execlp(dat[0].arr,dat[0].arr, dat[1].arr , NULL);
				}	
				
			}	
		}
		
		printf("\n The PID is: %d \n",pid);
		//printf("\n In child \n");
		if(argIsThere == 1){
			
			switch(j){
				
				case 2:
						//printf("\n case 2");
						
						strcpy(dat2[2].arr, "");
						strcpy(dat2[3].arr, "");
						strcpy(dat2[0].arr, dat[0].arr);
						strcpy(dat2[1].arr, dat[1].arr);
					execlp(dat2[0].arr,dat2[0].arr, dat2[1].arr , NULL);
				break;
					
				case 3:
						//printf("\n case 3");
					execlp(dat[0].arr,dat[0].arr, dat[1].arr, dat[2].arr , NULL);

				break;
				
				case 4:
						//printf("\n case 4");
					execlp(dat[0].arr,dat[0].arr, dat[1].arr, dat[2].arr ,dat[3].arr , NULL);
					
				break;
				
				case 5:
						//printf("\n case 4");
					execlp(dat[0].arr,dat[0].arr, dat[1].arr, dat[2].arr ,dat[3].arr ,dat[4].arr, NULL);
					
				break;
				
				case 6:
						//printf("\n case 4");
					execlp(dat[0].arr,dat[0].arr, dat[1].arr, dat[2].arr ,dat[3].arr ,dat[4].arr,dat[5].arr, NULL);
					
				break;
				
				
				
				//close(dup2fd);
			}
		
		
		}
		else{
		//printf("\n successful exit from child");
		strcpy(dat2[1].arr, "");
		strcpy(dat2[2].arr, "");
		strcpy(dat2[3].arr, "");
		strcpy(dat2[0].arr, dat[0].arr);
		execlp(dat2[0].arr,dat2[0].arr, NULL);

		}
		
	
		
		exit(0);
			
	}
	else if(pid < 0)
	{
			printf("\n error");
			exit(-1);
	}
	else
	{
		if(back_proc==1){
			printf("\n Background process \n");
			printf("\n The PID is: %d \n ",pid);
			back_proc=0;
			continue;
	    }	
		else{
			waitpid(pid,NULL,NULL);
		}
		//printf("\n in parent");
		//exit(0);
	}	
}
    return 0; 
} 



