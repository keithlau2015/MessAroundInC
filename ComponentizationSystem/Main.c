#include "Main_H.h"
#include "Decode_H.h"
#include "Calculator_H.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	RunMainPageUI();
	scanf("%s", &OPTION);
	if(OPTION == '0'){
		exit(0);
	}
	else if(OPTION == '1'){
		CalculatorUI();
		scanf("%s", &OPTION);
		Calculator(OPTION);
	}
	else if(OPTION == '2'){
		DecodeUI();
		scanf("%s", &OPTION);
		Decoder(OPTION);
	}
	else{
		ErrorInputUI();
		main();
	}
}

//Delay function
void delay(int ms){
	for(int i = 0; i < ms; i++){
	}
}

//Windows support
#if defined(WIN32) || defined(WINDOWS)
#include <windows.h>

//Input Error UI
void ErrorInputUI(){
			system("color C");
			printf("                                    INPUT ERROR");
			delay(100000000);
}

//Message Box Error
void ExceptionErrorMsgBox(){
		MessageBox(0, "Unexpected Error", "Message", 1);
		main();
}

//Main Page UI
void RunMainPageUI(){
	system("color B");
	system("cls");
	printf("Welcom to Componentization system\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Press 1                                                          Calculator mode\n");
	printf("Press 2                                                              Decode mode\n");
	printf("Press 0                                                                     Quit\n");
}
#else
	
//Linux Support
#include <unistd.h>
#define RED "\x1B[31m"
#define BLUE "\x1B[34m"

// Main Page UI
void RunMainPageUI(){
	system("clear");
	printf(BLUE "Welcom to Componentization system\n");
	printf(BLUE "--------------------------------------------------------------------------------\n");
	printf(Blue "Press 1                                                          Calculator mode\n");
	printf(BLUE "Press 0                                                                     Quit\n");
}

//Input Error UI
void ErrorInputUI(){
		printf(RED "                                   INPUT ERROR");
		delay(100000000);
}

//Message Box Error
void ExceptionErrorMsgBox(){
	char cmd[1024];
	sprintf(cmd, "xmessage -center \"%s\"", "Unexpected Error");
    if(fork()==0){
        close(1); close(2);
        system(cmd);
        exit(0);
	}
	main();
}
#endif