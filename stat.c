#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
        struct stat finfo;
        int i;

        if (argc == 1) {
                fprintf(stderr, "wrong number of arguments!..\n");
                exit(EXIT_FAILURE);
        }

        for (i = 1; i < argc; ++i) {
                if (stat(argv[i], &finfo) == -1) {
                        fprintf(stderr, "stat: %s\n", strerror(errno));
                        continue;
                }

                printf("----------------------------\n");
                printf("%s\n\n", argv[i]);
                printf("%-20s%lld\n", "Size", (long long)finfo.st_size);
                printf("%-20s%llu\n", "I-Node", (unsigned long long)finfo.st_ino);
                printf("%-20s%lld\n", "User id", (long long)finfo.st_uid);
                printf("%-20s%lld\n", "Group id", (long long)finfo.st_gid);
                printf("%-20s%s", "Last Update", ctime(&finfo.st_mtime));
                printf("%-20s%s", "Last Read", ctime(&finfo.st_atime));
                printf("%-20s%s", "Last I-Node Update", ctime(&finfo.st_ctime));
        }

        return 0;
}
