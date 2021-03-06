#ifndef ACTIONS_H
#define ACTIONS_H

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// list files in current directory
void listDir(char *directoryName){
    puts("Available files:\n");
    struct dirent *directoryEntry;
    DIR *directoryPtr = opendir(directoryName); 
    while ((directoryEntry = readdir(directoryPtr)) != NULL)
        if( directoryEntry->d_name[0] != '.' ) 
            printf("%s\n", directoryEntry->d_name); 
    
    closedir(directoryPtr); 
}

// create new file
void touch(char fileName[300]){
    FILE *newFile;
    newFile = fopen(fileName, "w");
    fclose(newFile);
}

// file existence checker
int checkFile(FILE *filePtr){
    return (filePtr == NULL)? 0 : 1;
}

// view an existing note
void viewNote(char noteName[300]){
    FILE *noteFile;
    noteFile = fopen(noteName, "r");
    if(!checkFile(noteFile)){
        puts("no such file found!");
        puts("creating new file with the provided name....");
        touch(noteName);
        return;
    }
    puts("current note contents:");
    while(!feof(noteFile)){
        printf("%c", fgetc(noteFile));
    }
    fclose(noteFile);
}

// a very retarted way to input a string with spaces but made adaptive with the current purpose of the program
void inputStringsWithSpaces(char str[]){
    // future alternate
    // scanf("%[^\n]", &lol);

    char string[300] = "";
    while(1){
        char temp[300];
        scanf("%s", temp);
        // quit checker
        if(temp[0] == 'q' && temp[1] == 'q')
            break;
        // if there's a return escape sequence do it :)
        if(temp[0] == '\\' && (temp[1] == 'n' || temp[1] == 'r') ){
            strcat(temp, "\n");
        }
        // add every other string
        else{    
            // append a space to the string for better formatting in the file
            strcat(temp, " ");
        }
        strcat(string, temp);
    }
    strcpy(str, string);
}

// append to an existing file
void appendToFile(char fileName[300]){
    FILE *noteFile;
    noteFile = fopen(fileName, "a");
    puts("\nenter your note type 'qq' when you are done(type '\\n' to jump a line)");
    char note[99];
    inputStringsWithSpaces(note);
    fputs(note, noteFile);
    fflush(noteFile);
    fclose(noteFile);
}

// delete the previous n lines from a file
void deletePreviousNChars(int numberOfLines, FILE *filePtr) {
    // to jump to the previous line
    fprintf(filePtr, "\b");
    // delete n lines 
    while(numberOfLines--){
        fprintf(filePtr, "\b");
        
    }
    
    printf("\n");

}
void deleteNChars(char fileName[300]) {
    FILE *noteFile;
    noteFile = fopen(fileName, "a");
    printf("\nenter number of lines you want to remove:");
    int numberOfRemovedChars;
    scanf("%d", &numberOfRemovedChars);
    deletePreviousNChars(numberOfRemovedChars, noteFile);
    fflush(noteFile);
    fclose(noteFile);
}

// add to existing note
void addToNote(char noteName[300]){
    viewNote(noteName);
    appendToFile(noteName);
}

// create new note
void addNote(char noteName[300]){
    touch(noteName);
    appendToFile(noteName);
}

// delete a note
void deleteNote(char noteName[300]){
    remove(noteName);
}

#endif // ACTION_H