#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MYPORT 9090

int main() { 

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("Socket error");
    return 1;
  }

  struct sockaddr_in my_addr = {0};

  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int bind_res = bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);

  if (bind_res < 0) {
    perror("Bind error");
    return 1;
  }

  printf("Todo bien\n");

  return 0;

}

