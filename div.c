//
//  div.c
//  Systems
//
//  Created by Theodore Fahey on 11/3/21.
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
int main(int argu, char * argv[]){
    char file[100];
    DIR * direct;
    if (argu == 1){
        printf("Please Enter a valid Directory: \n");
        read(STDIN_FILENO, file, 100);
        file[strlen(file)-1] = '\0';
        direct = opendir(file);
    }
    else{
        direct = opendir(argv[1]);
    }
    if (errno > 0){
        printf("error number %d: \nerror string: %s\n",errno,strerror(errno));
    }
    struct dirent *entry;
    int i = 0;
    
    while ((entry = readdir(direct)) != NULL ){
        struct stat size;
        stat(entry->d_name, &size);
        i += size.st_size;
    }
    printf("Statistics for Directory: \n");
    printf("Size of Directory: %d bytes\n", i);
    rewinddir(direct);
    printf("Directories: \n");
    while ((entry = readdir(direct)) != NULL ){
        if (entry->d_type == 4){
            printf("%s\n", entry->d_name);
        }
    }
    rewinddir(direct);
    printf("Regular Files: \n");
    while ((entry = readdir(direct)) != NULL ){
        if (entry->d_type == 8){
            printf("%s\n", entry->d_name);
        }
    }
    return 0;
}

