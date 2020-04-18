#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//check if the input is more than 23 bit unsigned or not
int inputVerifier(int dataField, int maskField){
	
	int range= 8388607; //2^23-1
	if (dataField>range || maskField>range){
		return 1;
	} else 
	{
		return 0;
	}
}

//convert from Decimal to Binary
//pass data to convert from Decimal to Binary 
//pass range to get the desired number of bits of data you want to convert to binary
void decimalToBinary(int data, int range){
	printf ("0b");
	for (range;range>=0;range--){
		int bit=0;
		bit= data>>range;
		
		if (bit & 1){
			printf ("1");
		}
		else {
			printf ("0");
		}
	}
	printf ("\n");
}

// calculate the range of the function
int rangeCompute(int dataField, int maskField){
	int range=0;
	if (dataField<=255 && maskField<=255){
		range=7;
	}else if(dataField<=65535 && maskField<=65535){
		range=15;	
	}else {
		range=22;
	}
	return range;
}

int main(int argc, char* argv[]){
	if (argc!=3){
		printf ("Error!!! Please only enter two data in Command Line and rerun the program");
		return 0;
	}
	int dataField=atoi(argv[1]);
	int maskField=atoi(argv[2]);
	int a;
	while (1){
	if (inputVerifier(dataField,maskField)==1){
		printf ("Error!!! Please enter 23-bit unsigned integer and re-run the program");
		return 0;
	}
	printf ("Please enter the choices [1,2,3] from below \n \t 1. Set \n \t 2. Clear \n \t 3. Toggle\n");
	scanf(" \t%d",&a);
	if (a==1){ 
		system("clear");
		printf ("Please enter the choices [1,2,3] from below \n \t \t 1. SET \n \t 2. Clear \n \t 3. Toggle\n");
		printf ("\nmaskField = ");
		decimalToBinary(maskField,rangeCompute(dataField,maskField));	
		printf ("\nDataField = ");
		decimalToBinary(dataField,rangeCompute(dataField,maskField));
		
		printf ("\n____________________________________________");
		printf ("\n\nSET       = ");
		decimalToBinary(dataField|maskField, rangeCompute(dataField, maskField));

	} else if (a==2) {
		system("clear");
		printf ("Please enter the choices [1,2,3] from below \n \t 1. Set \n \t \t  2. CLEAR \n \t 3. Toggle\n");
		printf ("\nmaskField = ");
		decimalToBinary(maskField, rangeCompute(dataField, maskField));
		printf ("\nDataField = ");
		decimalToBinary(dataField, rangeCompute(dataField, maskField));
		printf ("\n____________________________________________");
		printf ("\n\nCLEAR     = ");
		decimalToBinary(dataField&(~maskField), rangeCompute(dataField, maskField));
	} else if (a==3){
		system("clear");
		printf ("Please enter the choices [1,2,3] from below \n \t 1. Set \n \t 2. Clear \n \t \t  3. TOGGLE\n");
		printf ("\nmaskField = ");
		decimalToBinary(maskField, rangeCompute(dataField, maskField));
		printf ("\nDataField = ");
		decimalToBinary(dataField, rangeCompute(dataField, maskField));
		printf ("\n____________________________________________");
		printf ("\n\nTOGGLE     = ");
		decimalToBinary(dataField^maskField, rangeCompute(dataField, maskField));
	} else {
		printf ("Please type correct value of 1,2 or 3 to select the option and rerun the program");
		return 0;
	}
	
	printf("\n\n\n Please Enter Data ");
	scanf ("%d",&dataField);
	printf("\n\n\n Please Enter Mask ");
	scanf ("%d",&maskField);
	
	}
	return 0;
}
