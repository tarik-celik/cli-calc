/*
	18.12.2023
aesh.c by Tarık Çelik

This software is relased under bsd-3 clause
license.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


void copyFile(const char *source, const char *destination) {
    FILE *sourceFile = fopen(source, "rb");
    FILE *destFile = fopen(destination, "wb");

    if (sourceFile == NULL || destFile == NULL) {
        printf("Error: Unable to open files for copying.\n");
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
}

int main() {

bool exit = false;
char command[100];
char dir[100];
char file[100];
char exc[100];

printf("\nAetherShell 0.2 by Tarık Çelik \n");
printf("Write 'help' for help \n");

while (exit == false) {

	printf("* ");
	scanf("%s", command);

	if (strcmp(command, "clear") == 0) {
	printf("\e[1;1H\e[2J");
		}

	if (strcmp(command, "exit") == 0) {
	exit = true;
		}

	if (strcmp(command, "cd") == 0) {
	scanf("%s", dir);
	chdir(dir);
	}

	if (strcmp(command, "ls") == 0) {
	 DIR *dir;
	 struct dirent *entry;
	 dir = opendir(".");
	 while ((entry = readdir(dir)) != NULL) {
         printf("%s\n", entry->d_name);
	}
	 closedir(dir);
	}

	if (strcmp(command, "mkdir") == 0) {
	scanf("%s",dir);
	mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	if (strcmp(command, "rmdir") == 0) {
		scanf("%s", dir);
		rmdir(dir);
	}

	if (strcmp(command, "touch") == 0) {
		scanf("%s", file);
		FILE* File = fopen(file, "w");
		fclose(File);
	}

	if (strcmp(command, "rm") == 0) {
                scanf("%s", file);
                remove(file);
	}

	if (strcmp(command, "exec") == 0) {
		fgets(exc, sizeof(exc), stdin);
		system(exc);
	}

	if (strcmp(command, "mv") == 0) {
		scanf("%s", file);
		scanf("%s", dir);
		rename(file, dir);
	}

	if (strcmp(command, "cp") == 0) {
         	 char sourcefile[100], destinationfile[100];
      		 scanf("%s %s", sourcefile, destinationfile);
       		 copyFile(sourcefile, destinationfile);
       }
	if (strcmp(command, "calc") == 0) {
		float num1, num2, num3;
		char op;
     		scanf("%f %c %f", &num1, &op, &num2);
		if (op == *"+") {
		num3 = num1 + num2;
		printf("%.3f",num3);
			}
		if (op == *"-") {
		num3 = num1 - num2;
		printf("%.3f", num3);
			}
		if (op == *"/") {
		num3 = num1 / num2;
		printf("%.3f", num3);
			}
		if (op == *"x") {
		num3 = num1 * num2;
		printf("%.3f", num3);
		}
		printf("\n");
	}
	if (strcmp(command, "help") == 0) {

		printf("\nAetherShell 0.2 by Tarık Çelik");
		printf("\n * help for that menu");
		printf("\n * clear for clearing the screen");
		printf("\n * exit for exiting");
		printf("\n * cd <path>for entering to a directory");
		printf("\n * ls for listing contents of current directory");
		printf("\n * mkdir <dirname> for creating a directory");
		printf("\n * rmdir <dirname> for removing a directory");
		printf("\n * touch <filename> for creating files");
		printf("\n * rm <filename> for removing a file");
		printf("\n * exec <command> for executing a command");
		printf("\n * mv <filename> <location > for moving a file");
		printf("\n * cp <filename> <newfile> for moving a file");
                printf("\n \n"); // we need that line for proper output
		}
	}
}
