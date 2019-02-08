#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
    char* buff[16];
   int file;
    if((file = open(argv[1], O_CREAT)) <= 0){
        printf("Error!");
    }else{
        printf("success!");
    }

    read(file, buff, 16);
    printf("done!");

    for(int i = 0; i < 100; i++){
        printf("%x", buff[i]);
    }

    return 0;
}