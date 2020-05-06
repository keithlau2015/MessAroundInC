#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Main_H.h"
#include "Decode_H.h"

char file_name[50];

char MorseCode2English(char temp[4]){
	if(strcmp(temp, ".-") == 0)return 'A';
	if(strcmp(temp, "-...") == 0)return 'B';
	if(strcmp(temp, "-.-.") == 0)return 'C';
	if(strcmp(temp, "-..") == 0)return 'D';
	if(strcmp(temp, ".") == 0)return 'E';
	if(strcmp(temp, "..-.") == 0)return 'F';
	if(strcmp(temp, "--.") == 0)return 'G';
	if(strcmp(temp, "....") == 0)return 'H';
	if(strcmp(temp, "..") == 0)return 'I';
	if(strcmp(temp, ".---") == 0)return 'J';
	if(strcmp(temp, "-.-") == 0)return 'K';
	if(strcmp(temp, ".-..") == 0)return 'L';
	if(strcmp(temp, "--") == 0)return 'M';
	if(strcmp(temp, "-.") == 0)return 'N';
	if(strcmp(temp, "---") == 0)return 'O';
	if(strcmp(temp, ".--.") == 0)return 'P';
	if(strcmp(temp, "--.-") == 0)return 'Q';
	if(strcmp(temp, ".-.") == 0)return 'R';
	if(strcmp(temp, "...") == 0)return 'S';
	if(strcmp(temp, "-") == 0)return 'T';
	if(strcmp(temp, "..-") == 0)return 'U';
	if(strcmp(temp, "...-") == 0)return 'V';
	if(strcmp(temp, ".--") == 0)return 'W';
	if(strcmp(temp, "-..-") == 0)return 'X';
	if(strcmp(temp, "-.--") == 0)return 'Y';
	if(strcmp(temp, "--..") == 0)return 'Z';
}

void English2MorseCode(char temp){
	if(temp == 'a'){
		printf(".-");
	}
	if(temp == 'b'){
		printf("-...");
	} 
	if(temp == 'c'){
		printf("-.-.");
	} 
	if(temp == 'd'){
		printf("-..");
	} 
	if(temp == 'e'){
		printf(".");
	} 
	if(temp == 'f'){
		printf("..-.");
	} 
	if(temp == 'g'){
		printf("--.");
	} 
	if(temp == 'h'){
		printf("....");
	} 
	if(temp == 'i'){
		printf("..");
	} 
	if(temp == 'j'){
		printf(".---");
	} 
	if(temp == 'k'){
		printf("-.-");
	} 
	if(temp == 'l'){
		printf(".-..");
	} 
	if(temp == 'm'){
		printf("--");
	} 
	if(temp == 'n'){
		printf("-.");
	} 
	if(temp == 'o'){
		printf("---");
	} 
	if(temp == 'p'){
		printf(".--.");
	} 
	if(temp == 'q'){
		printf("--.-");
	} 
	if(temp == 'r'){
		printf(".-.");
	} 
	if(temp == 's'){
		printf("...");
	} 
	if(temp == 't'){
		printf("-");
	}
	if(temp == 'u'){
		printf("..-");
	} 
	if(temp == 'v'){
		printf("...-");
	} 
	if(temp == 'w'){
		printf(".--");
	} 
	if(temp == 'x'){
		printf("-..-");
	} 
	if(temp == 'y'){
		printf("-.--");
	} 
	if(temp == 'z'){
		printf("--..");
	}
	if(temp == '\n'){
		printf("\n");
	}
	else{
		printf(" ");
	}
}

void InputFile(char file_name[50], int boolean){
	FILE *fp;
	char temp;
	fp = fopen(file_name, "r");
	if(fp == NULL){
		perror("Error");
		//exit(EXIT_FAILURE);
	}
	else if(boolean == 0){
		printf("Text inside the file:\n");
		while((temp = fgetc(fp))!=EOF){
			printf("%c", temp);
		}
	} 
	else if(boolean == 1){
		printf("Text inside the file:\n");
		while((temp = fgetc(fp))!=EOF){
				printf("%c", temp-7);
		}
	}else if(boolean == 2){
		char fileString[1024];
		char tempChar[] = " |\n";
		while(fgets(fileString, sizeof(fileString), fp)){
			char *ptr = strtok(fileString, tempChar);
			while(ptr != NULL){
				printf("%c", MorseCode2English(ptr));
				ptr = strtok(NULL, tempChar);
			}
			if(ptr == NULL){
				printf("\n");
			}
		}		
	}
	else if(boolean == 3){
		while((temp = fgetc(fp))!=EOF){
			English2MorseCode(tolower(temp));
		}
	}
	fclose(fp);
}

//Support Linux & Windows
#if defined(WIN32) || defined(WINDOWS)
#include <windows.h>
//UI Function
void DecodeUI(){
	system("cls");
	system("color 9");
	printf("Decode mode\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Press 1                                                   MorseCode ---> English\n");
	printf("Press 2                                                   English ---> MorseCode\n");
	printf("Press 3                                                   Basic decode(char - 7)\n");
	printf("Press 0                                                                     HOME\n");

}
#else
#define RED "\x1B[31m"
//UI Function
void DecodeUI(){
	system("clear");
	printf(RED "Decode mode\n");
	printf(RED "--------------------------------------------------------------------------------\n");
	printf(RED "Press 1                                                   MorseCode ---> English\n");
	printf(RED "Press 2                                                   English ---> MorseCode\n");
	printf(RED "Press 3                                                   Basic decode(char - 7)\n");
	printf(RED "Press 0                                                                     HOME\n");
}
#endif

//Process
void Decoder(char option){
	if(option == '1'){
		system("cls");
		char input[1024];
		printf("Please input file location for decoding\n");
		scanf("%s", &input);
		InputFile(input, 2);
		printf("\nPress 0                                                                 Decoding\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			DecodeUI();
			scanf("%s", &OPTION);
			Decoder(OPTION);
		}
		else ErrorInputUI();
	}
	else if(option == '2'){
		system("cls");
		char input[1024];
		printf("Please input file location for decoding\n");
		scanf("%s", &input);
		InputFile(input, 3);
		printf("\nPress 0                                                                 Decoding\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			DecodeUI();
			scanf("%s", &OPTION);
			Decoder(OPTION);
		}
		else ErrorInputUI();
	}
	else if(option == '3'){
		system("cls");
		char input[1024];
		printf("Please input file location for decoding\n");
		scanf("%s", &input);
		InputFile(input, 1);
		printf("\nPress 0                                                                 Decoding\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			DecodeUI();
			scanf("%s", &OPTION);
			Decoder(OPTION);
		}
		else ErrorInputUI();
	}
	else if(option == '0'){
		main();
	}	
	else{
			ErrorInputUI();
			DecodeUI();
			scanf("%s", &OPTION);
			Decoder(OPTION);
		}

}