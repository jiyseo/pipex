#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    int testVal = 5;
    int fdf, fd1[2], fd2[2];
    char fixed_str[] = " - test"; // char *fixed_str = " - test"; 와 같음
    char input_str[100], concat_str[256];

    fdf = open("aaa.txt", O_RDWR | O_CREAT, 0644);
    if (fdf == -1)
    {
        perror("Open Failed");
        return 1;
    }
    if (pipe(fd1) == -1) {
        perror("Pipe Failed");
        return 1;
    }
    if (pipe(fd2) == -1) {
        perror("Pipe Failed");
        return 1;
    }

    scanf("%s", input_str); // 문자열 입력(99바이트 초과하면 buffer overflow 발생)

    pid = fork();
    if (pid < 0) {
        perror("fork Failed");
        return 1;
    }

/*
※ fd1, fd2, fdf를 비롯한 모든 변수는 자식이 부모것을 복제한 것이기 때문에
   부모에서 close(fd1[1])을 한다고 하여 자식의 것도 close()되는 것은 아님.
   부모와 자식은 완전 별개의 공간에 각각의 변수와 file descriptor를 가지고 있음

※ concat_str은 부모와 자식이 공유할 수 있는 것이 아니고 완전 별개 공간임,
   프로세서간에 메모리 공유는 그냥은 할 수 없고 공유메모리(Shared Memory)라는
   개념을 이용하고 shmget()등의 함수를 이용해야 함
*/

    if (pid > 0) { // Parent process (요기는 부모)

        int status;
        char concat_str[100];

        testVal = 10; // 부모와 자식이 공유하는지 확인하고자 다른 값으로 변경해 봄

        // dprintf() 함수는 fd에 출력하는 printf() 함수
        dprintf(fdf, "parent process testVal=%d\n", testVal); // aaa.txt에 쓰기
        close(fdf);

        close(fd1[0]); // 사용하지 않는 첫 번째 pipe의 읽기 fd 닫기
        close(fd2[1]); // 사용하지 않는 두 번째 pipe의 쓰기 fd 닫기

        // 첫 번째 pipe에 입력 받은 문자열 input_str을 출력함
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]); // 첫 번째 pipe의 쓰기 fd 닫기

        // pid의 프로세서가 종료되길 대기함(=자식 프로세서 종료 대기)
        waitpid(pid, &status, 0); // wait(&status)는 waitpid(-1, &wstatus, 0)과 같음

        read(fd2[0], concat_str, 100 + sizeof(fixed_str)); // 자식이 보내온 것 읽기
        close(fd2[0]); // 두 번째 pipe의 읽기 fd 닫기

        printf("Concat string = %s\n", concat_str);

    } else { // child process (요기는 자식)

        char *src, *dest;

        dprintf(fdf, "clild process testVal=%d\n", testVal); // aaa.txt에 쓰기
        close(fdf);

        close(fd1[1]); // 사용하지 않는 첫 번째 pipe의 쓰기 fd 닫기
        close(fd2[0]); // 사용하지 않는 두 번째 pipe의 읽기 fd 닫기

        read(fd1[0], concat_str, 100); // 부모 프로세서가 pipe로 보내준 것 읽기
        close(fd1[0]); // 첫 번째 pipe의 읽기 fd 닫기

        src = fixed_str;
        dest = concat_str + strlen(concat_str); // concat_str에는 부모가 보내준 input_str의 값이 있음
        while (*src) *dest++ = *src++;
        *dest = '\0';
        
        write(fd2[1], concat_str, strlen(concat_str) + 1); // 부모에게 pipe로 보내줌
        close(fd2[1]); // 두 번째 pipe의 쓰기 fd 닫기

        exit(0); // 요거 실행되면 부모의 waitpid() 함수가 대기를 종료함

    }
}