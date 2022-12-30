#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
if argc == 1 => print 10 lines from STDIN
   argc == 2 => print 10 lines from a file
   argc == 3 => print n lines from a file

1)open the file
2)read lines, if buffer[i] == endl => is a new line => increment current_lines
3)if currnet_lines < num_lines => print
else dont print and stop
*/

#define MAX_SIZE 100


int main(int argc, char *argv[])
{


if(argc < 2)
{
	ssize_t reader;
	int num_of_lines = 10;
	char buffer[MAX_SIZE];
	while( (reader = read(STDIN_FILENO, buffer, MAX_SIZE)) > 0)
	{
		buffer[MAX_SIZE] = '\0';
		//printf("buffer = %s", buffer);
		//write(STDOUT_FILENO, buffer, reader);
		for(int i = 0 ; i < reader; i = i + 1)
		{
		write(STDOUT_FILENO, &buffer[i], reader);

		if(buffer[i] == '\n')
		{
			num_of_lines = num_of_lines - 1;
			if(num_of_lines == 0)
				return 5;
		}

		}
	} //end while reader

}

if( argc == 2) // no line arg
{
	ssize_t reader;
	int num_of_lines_to_print = 10;
	int current_lines = 0;
	char buffer[MAX_SIZE];
	int i;
	int fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
	fprintf(stderr, "file did not open");
	}

	while((reader = read(fd, buffer, MAX_SIZE)) > 0)
	{
		for(i = 0 ; i < reader; i = i + 1)
		{
			write(STDOUT_FILENO, &buffer[i], 1);
		if(buffer[i] == '\n')
		{	//printf("ENDLINE");
			current_lines = current_lines + 1;
			if(current_lines >= num_of_lines_to_print)
				return -1;
		}//end if endl
		}//END FOR ghoing through file
	}

}


if(argc == 3)
{
	ssize_t reader;
	//printf(argv[2]);
	char *char_number = argv[2];
	//printf("\n char_number = %s\n\n", char_number);
	int number = 0;
	for(int i = 0 ; char_number[i] != NULL; i = i + 1)
	{
		number = number * 10 + ((char_number[i]) - '0');
		//printf("number = %d", number);
	}

	printf("the number of lines = %d", number);

	int current_lines = 0;
        char buffer[MAX_SIZE];
        int i;
        int fd = open(argv[1], O_RDONLY);

        if(fd == -1)
        {
        fprintf(stderr, "file did not open");
        }

        while((reader = read(fd, buffer, MAX_SIZE)) > 0)
        {
                for(i = 0 ; i < reader; i = i + 1)
                {
                        write(STDOUT_FILENO, &buffer[i], 1);
                if(buffer[i] == '\n')
                {       printf("ENDLINE");
                        current_lines = current_lines + 1;
                        if(current_lines >= number)
                                return -1;
                }//end if endl
                }//END FOR ghoing through file
        }

}

if(argc > 3)
{
fprintf(stderr, "cant use the command that way");
}


}

