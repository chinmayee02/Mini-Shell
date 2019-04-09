#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<string.h>
#include<sys/wait.h>
 
#define MAX 15 
  
struct datStr{
	char arr[100];
};	
  
int main() 
{ 
    char buf[MAX];
	pid_t pid;
	int back_proc;
	int leng, i=0, argIsThere;
	//char *const cmd[] = {"ls", "-el", NULL};
  while(1)
  {
	struct datStr dat[100];
	struct datStr dat2[100];
	waitpid(-1,NULL,WNOHANG);
    printf("minish >"); 
    gets(buf); 
   // printf("string is: %s\n", buf);
	int j=0;
	char *token = strtok(buf, " "); 
	while (token != NULL) 
	{ 

		strcpy(dat[j++].arr, token);
		//printf("\nstring2 - %s", dat[j].arr);
		token = strtok(NULL, " "); 
		
	}
	//printf("\n value of J is: %d",j);
	if (j == 1){
			//printf("\n arg not there"); 
			argIsThere = 0;
	}
	else {
		//printf("\n arguent is there");
		argIsThere = 1;
		
		if(strcmp(dat[j-1].arr,"&")!=0){
		printf(" ");
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
	
	
	//printf("\n value of J is: %d",j);
	//printf("%s", dat[0].arr);
	//printf("%s", dat[1].arr);
	
	// tokens created
	pid = fork();
	if(pid==0)
    {
		printf("\n The PID is: %d",pid);
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
					//strcpy(dat[0].arr,NULL);
					//strcpy(dat[1].arr,NULL);
					//strcpy(dat[2].arr,NULL);
				break;
				
				case 4:
						//printf("\n case 4");
					execlp(dat[0].arr,dat[0].arr, dat[1].arr, dat[2].arr ,dat[3].arr , NULL);
					//strcpy(dat[0].arr,NULL);
					//strcpy(dat[1].arr,NULL);
					//strcpy(dat[2].arr,NULL);
					//strcpy(dat[3].arr,NULL);
				break;
			}
		
		
		}
		else{
			
			//redirection
			//int q=0;
			//while(strcmp(dat[q].arr,"<")!=0)
			//{q++;}
			//if(strcmp(dat[q].arr,"<")==0)
			//{
			//	dat[q]=NULL;
				//file=open dat[q+1] read file RD 
			//	dup(file);
			//	close(file);
			//}
			
			//printf("%s", dat[0].arr);
			//printf("%s", dat[1].arr);

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
			printf("\n background process");
			printf("\n The PID is: %d",pid);
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

