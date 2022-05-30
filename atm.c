//Project 2: Automated Teller Machine (ATM)
//atm.c


//preprocessor directive
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//function prototype
void change_terminal_color(void);
void check_pin(int pin, int enteredPin);
void transaction(void);
void withdrawl(void);
void deposit(void);
void balance_inquiry(void);


//global variables
float balance = 5000;


int main(void){

	change_terminal_color();

	int pin = 1234; //stored account pin

	time_t now;
	time(&now);
	printf("\n");
	printf("\t\t\t\t\t%s", ctime(&now));
	printf("\n\t\t\t%s\n\n", "=================*Welcome to Phoenyx Bank ATM*=================");

	printf("\n%s", "[+] Please enter your pin: ");
	int enteredPin;
	scanf("%d", &enteredPin);
	check_pin(pin, enteredPin);
	transaction();

	
}//end function main


void check_pin(int pin, int enteredPin){

	int invalid_pin_count = 0;

	while(pin != enteredPin){

		if(enteredPin != pin){

			printf("%s", "[-] Invalid pin");
			
		}//end if

		++invalid_pin_count;

		if(invalid_pin_count == 3 && enteredPin != pin){

			exit(0); //exit the program
		
		}//end if

		printf("\n%s", "[+] Please enter your pin: ");
		scanf("%d", &enteredPin);

	}//end while


}//end function check_pin


void transaction(void){

	int continueTransaction = 1;

	while(continueTransaction != 0){

		printf("\n\t\t\t%s", "=================*Available Transactions*=================");
		printf("\n\n%s", "1. Withdrawl");
		printf("\n%s", "2. Deposit");
		printf("\n%s", "3. Check Balance");
		printf("\n\n%s", "[+] Please select an option: ");
		int option;
		scanf("%d", &option);

		switch(option){

			case 1:
				
				withdrawl();
				break;
				
			case 2:

				deposit();
				break;

				
			case 3:

				balance_inquiry();
				break;

			default:
				printf("%s", "[-] Invalid option");	

		}//end switch

		printf("\n%s", "[!] Do wish to continue with another transaction? [Yes = 1], [No = 0]: ");
		scanf("%d", &continueTransaction);

	}//end while

}//end function transaction


void withdrawl(void){
	
	int amount;

	do{
					
		printf("\n%s", "[+] Please enter an amount: ");
		scanf("%d", &amount);

		if(amount % 500 != 0){

		printf("\n%s", "[!] The amount should be multiple of 500");

		}//end if

	}while(amount % 500 != 0); //end while

	
	if(balance < amount){

		printf("\n%s", "[-] Insufficient balance");
		
	}//end if

	else{

		balance -= amount;
		printf("[!] You have withdrawn N%d", amount);
		printf("\n[!] Your available balance is now N%.2f", balance);
		printf("\n\n\t\t\t%s", "=================*Thank you for banking with us*=================");
		
	}//end else	

}//end function withdrawl


void deposit(void){

	int amount;

	printf("%s", "[!] Please enter an amount: ");
	scanf("%d", &amount);

	balance += amount;
	printf("\n[!] You have deposited N%d", amount);
	printf("\n[!] Your available balance is now N%.2f", balance);
	printf("\n\n\t\t\t%s", "=================*Thank you for banking with us*=================");
		
}//end function deposit


void balance_inquiry(void){

	printf("\n[!] Your available balance is N%.2f", balance);
	printf("\n\n\t\t\t%s", "=================*Thank you for banking with us*=================");	

}//end function balance


void change_terminal_color(void){

	//yellow text on blue
	printf("\033[33;44m\n");
	//https://dev.to/tenry/terminal-colors-in-c-c-3dgc

}//end function change_terminal_color