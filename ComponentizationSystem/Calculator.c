#include "Calculator_H.h"
#include "Main_H.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Support Linux & Windows
#if defined(WIN32) || defined(WINDOWS)
#include <windows.h>
//UI Function
void CalculatorUI(){
	system("cls");
	system("color A");
	printf("Calculator mode\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Press 1                                                                      SUM\n");
	printf("Press 2                                                                 SUBTRACT\n");
	printf("Press 3                                                                 MULTIPLY\n");
	printf("Press 4                                                                   DIVIDE\n");
	printf("Press 0                                                                     HOME\n");

}
#else
#define BLUE "\x1B[34m"
//UI Function
void DecodeUI(){
	system("clear");
	printf(BLUE "Calculator mode\n");
	printf(BLUE "--------------------------------------------------------------------------------\n");
	printf(BLUE "Press 1                                                                      SUM\n");
	printf(BLUE "Press 2                                                                 SUBTRACT\n");
	printf(BLUE "Press 3                                                                 MULTIPLY\n");
	printf(BLUE "Press 0                                                                   DIVIDE\n");
	printf(BLUE "Press 0                                                                     HOME\n");
}
#endif
//Process
void Calculator(char Option){
	if(Option == '1'){
		system("cls");
		printf("Please input the first number\n");
		double input_1, input_2;
		if(1 != scanf("%lf", &input_1))
		{
			ErrorInputUI();
		}
		printf("Please input the second number\n");
		if(1 != scanf("%lf", &input_2))
		{
			ErrorInputUI();
		}
		delay(100000000);
		system("cls");
		printf("%lf\n", Sum(input_1, input_2));
		printf("Press 0                                                               Calculator\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			CalculatorUI();
			scanf("%s", &OPTION);
			Calculator(OPTION);
		}
		else ErrorInputUI();
	}
	else if(Option == '2'){
		system("cls");
		printf("Please input the first number\n");
		double input_1, input_2;
		scanf("%lf", &input_1);
		printf("Please input the second number\n");
		scanf("%lf", &input_2);
		delay(100000000);
		system("cls");
		printf("%lf\n", Subtract(input_1, input_2));
		printf("Press 0                                                               Calculator\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			CalculatorUI();
			scanf("%s", &OPTION);
			Calculator(OPTION);
		}
		else ErrorInputUI();
	}
	else if(Option == '3'){
		system("cls");
		printf("Please input the first number\n");
		double input_1, input_2;
		scanf("%lf", &input_1);
		printf("Please input the second number\n");
		scanf("%lf", &input_2);
		delay(100000000);
		system("cls");
		printf("%lf\n", Multiply(input_1, input_2));
		printf("Press 0                                                               Calculator\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			CalculatorUI();
			scanf("%s", &OPTION);
			Calculator(OPTION);
		}
		else ErrorInputUI();
	}
	else if(Option == '4'){
		system("cls");
		printf("Please input the first number\n");
		double input_1, input_2;
		scanf("%lf", &input_1);
		printf("Please input the second number\n");
		scanf("%lf", &input_2);
		delay(100000000);
		system("cls");
		printf("%lf\n", Divide(input_1, input_2));
		printf("Press 0                                                               Calculator\n");
		scanf("%s", &OPTION);
		if(OPTION == '0'){
			CalculatorUI();
			scanf("%s", &OPTION);
			Calculator(OPTION);
		}
		else{
			ErrorInputUI();
			CalculatorUI();
			scanf("%s", &OPTION);
			Calculator(OPTION);
		}
	}
	else if(Option == '0'){
		main();
	}
	else{
		ErrorInputUI();
		CalculatorUI();
		scanf("%s", &OPTION);
		Calculator(OPTION);
	}
}
//factorial
double Factorial(double input){
	return input * Factorial(input-1);
}

//Derivative
//void Derivative(int )

//Basic Math
//sum
double Sum(double input_1, double input_2){
	return input_1+input_2;
}

//subtract
double Subtract(double input_1, double input_2){
	return input_1-input_2;
}

//multiply
double Multiply(double input_1, double input_2){
	return input_1 * input_2;
}

//divide
double Divide(double input_1, double input_2){
	return input_1/input_2;
}
