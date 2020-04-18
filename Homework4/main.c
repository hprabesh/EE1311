/*
Name:Prabesh Humagain
ID: 1001734700
Homework ID: #4 MAIN FUNCTION
EE 1311-001
*/
#include <stdio.h>
#include "macro.h"

extern int val1; extern int val2;  int result;  //GLOBAL VARIABLES VAL1 and VAL2  

int main(int argc, char *argv[]){
	char a;char b;		
	if (argc>ONE){printf("Error Code: No command line argument allowed");return 0;}	//makes sure user don't pass anything from COMMAND LINE INTERFACE
	
	while (ONE){
		banner(IDNO); //displaying banner logo
		dataInput(); //for inputting the data in the variables
		if (val1==ZERO || val2==ZERO){return ZERO;} //from datainput when user enters invalid, gets updated with zero and finally ends the program
		printf ("\n\t\t  "); 
		decimalToBinary(val1,rangeCompute(val1,val2)); //displaying the decimal to binary and the decimal number 
		printf ("\n\t\t  ");
		decimalToBinary(val2,rangeCompute(val1,val2)); 
		horizontalLine(rangeCompute(egyMul(val1,val2),val2));// create a horizontal line for multiplication 
		printf ("\n\t\t ");
		result=rangeCompute(egyMul(val1,val2),val2); 	//GLOBAL VARIABLE FOR THE RESULT of the product
		decimalToBinary(egyMul(val1,val2),result); //display the result in both decimal and binary
		rerun: //indexing for rerunning the program
		printf ("\nDo you wish to continue? Please type the exit character 'Y/N'\n"); //option to check if user wants to exit or rerun the program
		scanf("%s", &b);
		if (b=='N'||b=='n'){
			printf ("\n\t Thank you for using our program!!!");
			return ZERO; //ends the program
			} else if (b=='y'||b=='Y'){
			printf ("\n\t Thank you for using it again \n\n");
			} else {
			printf ("Invalid selection \n");
			goto rerun; //verify the user's selection
		}
		
	}
	return ZERO;
}