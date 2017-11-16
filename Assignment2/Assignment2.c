// RhysHaydon_Assignment2.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char helpYN;
char operator1[2];
double answer, num2, memory;

void getNum2() {
	scanf_s("%lf", &num2);
}

void printAns() {
	printf("\nAns:\ >%.6lf\n", answer);
}

void addition() {
	getNum2();
	answer = answer + num2;
	printAns();
}

void subtraction() {
	getNum2();
	answer = answer - num2;
	printAns();
}

void multiplication() {
	getNum2();
	answer = answer * num2;
	printAns();
}

void division() {
	getNum2();
	answer = answer / num2;
	printAns();
}

void square() {
	answer = pow(answer, 2);
	printAns();
}

void squareRoot() {
	answer = sqrt(answer);
	printAns();
}

void help() {
	//Displays commands to the user on how to use the calculator
	printf("\nTO USE ANY OF THSE COMMANDS, INPUT AT OPERATOR STAGE\n"
		"E \t Exits this program.\n"
		"H \t Displays information about this program.\n"
		"M \t As part of a mathematical expression the term MEMORY\n"
		"\t is substituted by the value stored in memory. Otherwise, \n"
		"\t the value stored in memory is displayed on-screen\n"
		"R \t Erases stored memory and returns calculator to its\n"
		"\t initial 'start-up' mode.\n"
		"S \t saves current answer to memory.\n"

		"\nOPERATOR \t DESCRIPTION \t SYNTAX\n"
		"+ \t\t addition \t [+a]\n"
		"- \t\t subtraction \t [-a]\n"
		"* \t\t multiplication  [*a]\n"
		"/ \t\t division \t [/a]\n"
		"^ \t\t sqr(x) \t [^]\n"
		"# \t\t sqrt(x) \t [#]\n"
	);
}

void store() {
	memory = answer;
	printf("\nANSWER STORED in MEMORY\n");
}

void quitApp() {
	exit(0);
}

void clearScreen() {
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

void calculator() {

	//Asks the user to input the first number
	printf("\nEnter a Number\n");
	printf("Calc:\ >");
	scanf_s("%lf", &answer);

	//Asks the user to input an operator or command. The user can also input an operator and a number, or just a number and get the same result
	//The loop continues until the command 'e' has been entered
	do {
		printf("\nEnter an Operator and Number or Command\n");
		printf("Calc:\ >");

		getchar();
		fgets(operator1, 2, stdin);

		if (0 == strcmp(operator1, "+")) {
			addition();
		}
		else if (0 == strcmp(operator1, "-")) {
			subtraction();
		}
		else if (0 == strcmp(operator1, "*")) {
			multiplication();
		}
		else if (0 == strcmp(operator1, "/")) {
			division();
		}
		else if (0 == strcmp(operator1, "^")) {
			square();
		}
		else if (0 == strcmp(operator1, "#")) {
			squareRoot();
		}
		else if (0 == strcmp(operator1, "h")) {
			help();
		}
		else if (0 == strcmp(operator1, "m")) {
			answer = memory;
		}
		//Clears the screen and restarts the calculator
		else if (0 == strcmp(operator1, "r")) {
			clearScreen();
			memory = 0;
			calculator();
			break;
		}
		else if (0 == strcmp(operator1, "s")) {
			memory = answer;
			printf("\nANSWER STORED\n");
		}
		else if (0 == strcmp(operator1, "e")) {
			exit(1);
		}
		else {
			printf("\nIncorrect operator, try entering + | - | * | / | ^ | #\n");
		}
	} while (1);

}

int main() {

	//Asks the user for help, if yes it will bring up the help menu
	printf("Would you like help? Y/N\n");
	helpYN = getchar();
	if (helpYN == 'y') {
		help();
	}

	//Starts the calculator functions
	calculator();

	return 0;
}


