#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

main()
{
	int fd, status;

	fd = open("/dev/scull", O_RDONLY);
	if (ioctl(fd, SCULL_IOCRESET, &status) == -1)
		printf("failed: %s\n", strerror(errno));
	else {
		printf("set as default.\n");
	}
	close(fd);
}
