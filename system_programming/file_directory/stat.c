#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

struct stat {
dev_t st_dev; /* ID of device containing file */
ino_t st_ino; /* inode number */
mode_t st_mode; /* protection */
nlink_t st_nlink; /* number of hard links */
uid_t st_uid; /* user ID of owner */
gid_t st_gid; /* group ID of owner */
dev_t st_rdev; /* device ID (if special file) */
off_t st_size; /* total size, in bytes */
blksize_t st_blksize; /* blocksize for filesystem I/O */
blkcnt_t st_blocks; /* number of 512B blocks allocated */
struct timespec st_atim; /* time of last access */
struct timespec st_mtim; /* time of last modification */
struct timespec st_ctim; /* time of last status change */
};


int main(void) {
struct stat buf;
stat("stat.c", &buf);
printf("Inode = %d\n", (int)buf.st_ino);
printf("Mode = %o\n", (unsigned int)buf.st_mode);
printf("Nlink = %o\n", (unsigned int)buf.st_nlink);
printf("UID = %d\n", (int)buf.st_uid);
printf("GID = %d\n", (int)buf.st_gid);
printf("SIZE = %d\n", (int)buf.st_size);
printf("Atime = %d\n", (int)buf.st_atime);
printf("Mtime = %d\n", (int)buf.st_mtime);
printf("Ctime = %d\n", (int)buf.st_ctime);
printf("Blksize = %d\n", (int)buf.st_blksize);
printf("Blocks = %d\n", (int)buf.st_blocks);
return 0;
}