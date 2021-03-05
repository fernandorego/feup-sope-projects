#include <stdio.h>
#include <sys/stat.h> //int chmod(const char *pathname, mode_t mode);
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include "permissions.h"

// MODE = '[ugoa](-+=)(rwx)+'

//xmod u+r

//chmod 777 file.txt

/*struct stat processStat(char* argv[]) {
    char users[4], permissions[3], operator;
    int j = 0;

    //muda buf
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] == 'u' || argv[1][i] == 'g' || argv[1][i] == 'o' || argv[1][i] == 'a')
            users[i] = argv[1][i];
        else if (argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '=') 
            operator = argv[1][i];
        else if (argv[1][i] == 'r' || argv[1][i] == 'w' || argv[1][i] == 'x') {
            permissions[j] = argv[1][i];             
            j++;
        }
        else {
            struct stat a; 
            a.st_mode = -1;
            return a;
        }
    }

    //armazena informação sobre file / dir
    struct stat stat_buf;
    //lstat -> ver symbolic links
    if (operator != '=')
        stat(argv[2], &stat_buf);


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            switch(permissions[i]){
                case 'r':
                    switch (users[j]) {
                        case 'a':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IRUSR | S_IRGRP | S_IROTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXUSR & ~S_IXGRP & ~S_IXOTH;
                            break;
                        case 'u':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IRUSR;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IRUSR;
                            break;
                        case 'g':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IRGRP;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IRGRP;
                            break;
                        case 'o':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IROTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IROTH;
                            break;
                        default: break;
                    }
                    break;
                case 'w':
                    switch (users[j]) {
                        case 'a':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IWUSR | S_IWGRP | S_IWOTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXUSR & ~S_IXGRP & ~S_IXOTH;
                            break;
                        case 'u':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IWUSR;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IWUSR;
                            break;
                        case 'g':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IWGRP;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IWGRP;
                            break;
                        case 'o':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IWOTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IWOTH;
                            break;
                        default: break;
                    }
                    break;
                case 'x':
                    switch (users[j]) {
                        case 'a':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IXUSR | S_IXGRP | S_IXOTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXUSR & ~S_IXGRP & ~S_IXOTH;
                            break;
                        case 'u':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IXUSR;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXUSR;
                            break;
                        case 'g':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IXGRP;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXGRP;
                            break;
                        case 'o':
                            if (operator == '+' || operator == '=') stat_buf.st_mode = stat_buf.st_mode | S_IXOTH;
                            if (operator == '-') stat_buf.st_mode = stat_buf.st_mode & ~S_IXOTH;
                            break;
                        default: 
                        break;
                    }
                    break;
                default: break;
            }
        }
    }
    return stat_buf;
}

bool changePermissions(char *dir, struct stat stat_buf) {
    return !(chmod(dir, stat_buf.st_mode) < 0);
}*/

int main(int argc, char* argv[], char* envp[]) {
    if (argc != 3) { //without OPTIONS
        printf("usage: xmod [OPTIONS] MODE FILE/DIR\n");
        return 0;
    }

    struct stat stat_buf = processStat(argv);

    if (changePermissions(argv[2],stat_buf)) 
        printf("Succeedd");
    else printf("Can't change Permissions!");

    return 0;
}

//#define S_IRWXU 0000700 // RWX mask for owner 
//#define S_IRUSR 0000400 // R for owner 
//#define S_IWUSR 0000200 // W for owner 
//#define S_IXUSR 0000100 // X for owner 

//#define S_IRWXG 0000070 // RWX mask for group 
//#define S_IRGRP 0000040 // R for group 
//#define S_IWGRP 0000020 // W for group 
//#define S_IXGRP 0000010 // X for group 

//#define S_IRWXO 0000007 // RWX mask for other 
//#define S_IROTH 0000004 // R for other 
//#define S_IWOTH 0000002 // W for other 
//#define S_IXOTH 0000001 // X for other 

//#define S_ISUID 0004000 // set user id on execution 
//#define S_ISGID 0002000 // set group id on execution 
//#define S_ISVTX 0001000 // save swapped text even after use 
