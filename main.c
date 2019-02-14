#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
   
   //Open the file into a file stream
   FILE *file;
    if((file = fopen(argv[1], "r")) <= 0){
	int retcode = errno;
        perror("File error: ");
	exit(retcode);
    }else{
        printf("Successfuly opened file: %s \n", argv[1] );
    }


    //Obtain the file size to allocate appropriate buffer space
    fseek(file, 0, SEEK_END); 
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char buff[size];
    printf("Buffisze is: %d\n Reading %s into buffer...\n", size, argv[1]);
    size_t length;

    //Read file stream into buffer
    if((length = fread(buff, 1, size, file)) <= 0){
      perror("Buffer input error: ");
      int retcode = errno;
      exit(errno);
    }else{
      printf("Buffer read into Memory successfully!\n Amount of bytes read: %d", length);
    }

    //While loop for parsing buffer
    int cycle_count = 0;
    int i = 0;
    while(i != size){
	printf("0x%x: ", i);
	switch(buff[i]){

	//opcode mappings
	case 0x00:
		printf("NOP\n");
		i++;
		break;
	case 0x01:
		printf("LXI %x, %x\n", buff[i+1], buff[i+2]);
		i = i+3;
		break;

	case 0x02:
		printf("STAX B\n");
		i++;
		break;

	case 0x03:
		printf("INX B\n");
		i++;
		break;
	case 0x04:
		printf("INR B");
		i++;
		break;
	case 0x05:
		
		break;
	
	case 0xc3:
		printf("JMP $%x%x\n", buff[i+2], buff[i+1]);
		i = i+3;
		break;

	case EOF:
		printf("NULL TERMINATOR, ENDING DISASSEMBLY");
		break;
		



	//Catch all default for unknown cases
	default:
		printf("Unknown opcode detected: %x exiting\n", buff[i]);
		exit(0);
		break;



	}
    }

    return 0;
}
