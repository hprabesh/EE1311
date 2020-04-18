/*
Name:Prabesh Humagain
ID: 1001734700
Homework ID: #4 Function Repository
EE 1311-001
*/

#include <stdio.h>
#include "macro.h"
int val1; int val2;

int egyMul(int a, int b){		//multiplication function
	int prod=ZERO;
	while (a!=ZERO){
		if (a%TWO==ONE){
			prod=prod+b;
		}
		a=a>>ONE;
		b=b<<ONE;
	}
	return prod;
}
void banner(int IdNo){  // function name banner 
	printf("_____Prabesh Humagain ID=%d_____\n", IdNo);
	printf("****************************************\n");
	printf("****************************************\n");
	printf("*************######  #     #************\n");
	printf("*************#     # #     #************\n");
	printf("*************#     # #     #************\n");
	printf("*************######  #######************\n"); 
	printf("*************#       #     #************\n"); 
	printf("*************#       #     #************\n"); 
	printf("*************#       #     #************\n"); 
	printf("****************************************\n");
	printf("****************************************\n");
}
void decimalToBinary(int data, int range){ //convert decimal to binary and display decimal
	printf ("\t0b");
	for (range;range>=ZERO;range--){
		int bit=ZERO;
		bit= data>>range;
		
		if (bit & ONE){
			printf ("1");
		}
		else {
			printf ("0");
		}
	}
	printf ("\t(DecimalNumber:%d)\n",data);
}
int rangeCompute(int data1, int data2){ //find the appropriatee range of the function
	int range;
	if (data1<=EIGHTBIT && data2<=EIGHTBIT ){
		range=EIGHTRANGE;
	}else if(data1<=SIXTEENBIT && data2<=SIXTEENBIT){
		range=SIXTEENRANGE;	
	}else if(data2<=THIRTYTWOBIT && data2<=THIRTYTWOBIT) {
		range=THIRTYTWORANGE;
	} else {
		range=SIXTYFOURRANGE;
	}
	return range;
}
void horizontalLine(){ //create a horizontal line
	printf ("\n\t\tX______________________\n");
}
void dataInput(){ //for entering the data
	int option=0;
	reenter:
	printf ("\n Please select the layout for entering the number\n\n");
	printf ("\t\t1.Input the number individually\n");
	printf ("\t\t2.Input the number at the same time\n");
	scanf ("%d",&option);
	if (option==ONE){
	printf ("\n\n Please enter two numbers between 0 and 5000\t");
	scanf("%d %d",&val1,&val2);
	} else if (option==TWO){
		printf ("\n\n Please enter a number between 0 and 5000\t");
		scanf("%d", &val1);
		printf ("\n\n Please enter another number between 0 and 5000\t");
		scanf("%d", &val2);
	} else if (option!=ONE || option!=TWO) {
		printf ("Invalid Selection\nPlease rerun the program");
		return;
	}
	if (val1>MAXVAL || val2>MAXVAL|| val1<MINVAL || val2<MINVAL){
		printf ("Invalid range of data. \nPlease enter number from 0 to 5000 only.\n");
		goto reenter;
	}
}
