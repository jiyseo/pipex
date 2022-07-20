#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        fprintf(stderr, "pipe error: %s\n", strerror(errno));
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork error : %s\n", strerror(errno));
        return 1;
    }
    if (pid == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        int ste = execlp(argv[2], argv[2], argv[3], NULL);
        if (ste == -1) {
            fprintf(stderr, "run error: %s\n", strerror(errno));
            return 1;
        }
    }
    dup2(fd[0], 0);
    close(fd[1]);
    char line[255];
    while (fgets(line, sizeof(line), stdin) != 0) {
        printf("%s", line);
    }
    return 0;
}
