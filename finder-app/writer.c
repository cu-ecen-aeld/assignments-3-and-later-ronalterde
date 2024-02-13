/*
One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

Setup syslog logging for your utility using the LOG_USER facility.

Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

Use the syslog capability to log any unexpected errors with LOG_ERR level.
*/

#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
	openlog(argv[0], 0, LOG_USER);

	if (argc != 3)
	{
		syslog(LOG_ERR, "Wrong number of arguments specified.");
		return 1;
	}
	else
	{
		int fd = open(argv[1], O_CREAT | O_WRONLY, S_IRWXU);
		if (fd == -1)
		{
			syslog(LOG_ERR, "Could not open file.");
			return 1;
		}
		syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
		write(fd, argv[2], strlen(argv[2]));
		close(fd);
	}

	return 0;

}
