#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 100


/*

1)if we have at least 1 arg(file) => argc >= 2
2)we open every file (argv[i]) O_RDONLY mode
3)we read from the file while it's possible
4)we write the text to stdout
5)we close the current file argv[i]


1*)if argc < 2 => we read and display from stdinput


*/


int main(int argc, char *argv[]){

//printf("%d", argc);
int i; // go through files
int fd; //file desc
char buffer[MAX_SIZE];

ssize_t reader;

if(argc > 1) // 2 or more files
{
	for(i = 1; i < argc; i = i + 1)
	{	//printf("file name = %s", argv[i]);
		fd = open(argv[i], O_RDONLY);
		if(fd < 2)
		{
			fprintf(stderr, "file didnt open");
			return 5;
		} //end if fd error

		while( (reader = read(fd, buffer, MAX_SIZE)) > 0)
		{	//printf("sfsd");
			buffer[sizeof(buffer)] = '\0';
			//printf("buffer = %s", buffer);
			write(STDOUT_FILENO, buffer, sizeof(buffer)-1);
		} //end reader while
		close(fd);

	}//end argc for



}//end if argc > 1
else
{

	while( (reader = read(STDIN_FILENO, buffer, MAX_SIZE)) > 0)
	{
		buffer[MAX_SIZE] = '\0';
		//printf("buffer = %s", buffer);
		write(STDOUT_FILENO, buffer, reader);
	} //end while reader

} //end else argc == 1


} //end of main
