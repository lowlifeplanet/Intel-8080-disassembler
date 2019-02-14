#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
int main(int argc, char* argv[]) {
   
   FILE *file;
    if((file = fopen(argv[1], "r")) <= 0){
	int retcode = errno;
        perror("File error: ");
	exit(retcode);
    }else{
        printf("Successfuly opened file: %s \n", argv[1] );
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char buff[size];
    printf("Buffisze is: %d\n Reading %s into buffer...\n", size, argv[1]);
    size_t length;
    if((length = fread(buff, 1, size, file)) <= 0){
      perror("Buffer input error: ");
      int retcode = errno;
      exit(errno);
    }else{
      printf("Buffer read into Memory successfully!\n Amount of bytes read: %d", length);
    }
    int exit = 0;
    while(exit == 0){
	
    }

    return 0;
}
