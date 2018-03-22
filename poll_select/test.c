#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define DEVFILE "/dev/test_select0"

int main()
{
	int fd;
	fd_set rfds;
	struct timeval tv;
	int retval;
	unsigned char buf;
	ssize_t sz;
	int i;

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
			perror("open");
			return -1;
	}

	do {
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		printf("select() ...\n");
		retval = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (retval == -1) {
				perror("select");
				break;
		}

		if (retval) {
				break;
		}
	} while (retval == 0);   /* timeout elapsed */

	if (FD_ISSET(fd, &rfds)) {
		printf("read() ...\n");
		sz = read(fd, &buf, 1);
		printf("read() %d\n", sz);
		printf("%02x ", buf);
		printf("\n");
	}

	close(fd);

	return 0;

}