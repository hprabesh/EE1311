#include <stdio.h>
/*
	Name:Prabesh Humagain
	Date:02/01/2020
	Assignmet: Homework 2
	Course: EE 1311
*/
	
void banner(int IdNo); //define a function name banner that takes idNo as a parameter
void ASCII(int start, int end, char var1[]); // define a function named ASCII that
// takes starting value and ending value and a string "Oct" or "Hex" as a parameter


int main(int argc, char *argv[]){
	if (argc>1){printf("Error Code: No command line argument allowed");return 0;}
	
	banner(4700); // call banner function passing an argument 4700 as an idNo
	ASCII(50,70, "Oct"); //call ASCII function passing an argument 50,70 and an octal 
	banner(4700);
	ASCII(90,110,"Hex");
	return 0; // return null value;
}

void banner(int IdNo){  // function name banner 
	printf("________Prabesh Humagain ID=%d________\n", IdNo);
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
void ASCII(int start, int end, char var1[]){ //function name ASCII
	int a;
	for (a=start; a<=end;a++){
		if (var1=="Oct"){ // the argument passed is "Oct" 
		printf ("ASCII= %d,\tChar= %c,\t Oct=%o,\tPoint=%p,\tPct=%d%%,\tslash=\\%o \n",a,a,a,a,a,a);
		}
		if (var1=="Hex"){
		printf ("ASCII= %d,\tChar= %c,\t Hex= %x,\tPoint= %p,\tPct= %d%%,\tslash= \\%x \n",a,a,a,a,a,a);	
		}
	}
}