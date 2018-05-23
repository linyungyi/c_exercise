#include <stdio.h>
#include <unistd.h>
int main() {
  pid_t pid;

  // 建立子行程
  pid = fork();

  if (pid == 0) {
    // 子行程
    printf("Child process!\n");
  } else if (pid > 0) {
    // 父行程
    printf("Parent process!\n");
  } else {
    // 錯誤
    printf("Error!\n");
  }

  return 0;
}