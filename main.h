#ifndef MAIN_H
#define MAIN_H

void program_loop(void);
void prompt(void);
/*char **line_into_args();*/
int read_command(void);
int start_program(char **args);
void bg_job(char *cmdline);
/*void execute(void);*/

#endif /** MAIN_H */
