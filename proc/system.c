#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h> 
#include <string.h>
#include <ctype.h>

#include "struct_process.h"
#include "functions.h"
#include "functions.c"
#include "system.h"
#include "proc.c"

struct system_t system;
system->
system->process_count = 0;

char fname[128];
	strcpy(fname, PROC_DEVICES_DIR);

    DIR* rep = opendir(PROC_DEVICES_DIR);

    if(rep == NULL)
        return;

    struct dirent *proc_ent;
	while ((proc_ent = readdir(rep))) {
        if(atoi(proc_ent->d_name)){
            //printf("%d\n", atoi(proc_ent->d_name));        
        
            // Set fname to /proc/PID
            strcpy(fname + proc_devices_dir_len, proc_ent->d_name);
	        int proc_dir_len = proc_devices_dir_len + strlen(proc_ent->d_name);  

    		// Load static PROC parameters
            strcpy(fname + proc_dir_len, "/status");
           // printf("%s\n", fname);

            //get caracteristics process
            char Name[50] = {0};
            int Pid, PPid;               
            
            Pid = atoi(proc_ent->d_name);   

            /* Open the file for reading */
            char *line_buf = NULL;
            size_t line_buf_size = 0;
            int line_count = 0;
            ssize_t line_size;
            FILE *fp = fopen(fname, "r");
            if (!fp)
            
                fprintf(stderr, "Error opening file '%s'\n", fname);
                
            

            /* Get the first line of the file. */
            line_size = getline(&line_buf, &line_buf_size, fp);

            /* Loop through until we are done with the file. */
            char * result_Name;
            char * result_PPid;
            while (line_size >= 0)
            {
                
                /* Increment our line count */
                line_count++;
                result_Name = strstr(line_buf, "Name");
                if(result_Name != NULL){
                    char caract[50], content[50];
                    sscanf(result_Name,"%s %s", caract, content);
                    strcat(Name, content);


                                    }
                
                result_PPid = strstr(line_buf, "PPid");
                if(result_PPid != NULL){
                    char caract[50], content[50];
                    sscanf(result_PPid,"%s %c", caract, content);
                    PPid = atoi(content);
                }
                          

                /* Get the next line */
                line_size = getline(&line_buf, &line_buf_size, fp);
            }

            /* Free the allocated line buffer */
            free(line_buf);
            line_buf = NULL;

            /* Close the file now that we are done with it */
            fclose(fp);
 
            
            strcpy(process.name, Name);
            process.pid = Pid;
            process.ppid = PPid;        
    }
    
         
        
    }