// rps_game.c
// rock, paper and scissors game


/*
A simultaneous, zero-sum game, it has three possible outcomes: a draw, a win or a loss. 
A player who decides to play rock will beat another player who has chosen scissors 
("rock crushes scissors" or "breaks scissors" or sometimes "blunts scissors"[4]), but will
lose to one who has played paper ("paper covers rock"); a play of paper will lose to a 
play of scissors ("scissors cuts paper"). If both players choose the same shape, the game is 
tied and is usually immediately replayed to break the tie. 
*/


//preprocessor directives
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//function prototypes
void checkOptions(int userOption, int compOption);
void red(void); /* https://www.theurbanpenguin.com/4184-2/ */
void yellow(void);
void green(void);
void blue(void);
void reset(void);


//global variables
int userScore = 0, compScore = 0;


//function main
int main(void){

	//seed the random number generation function
 	srand(time(NULL));

	yellow();
	printf("\t\t\t==================*Welcome to Rock, Paper and Scissors Game*=================");
	reset();

	int userOption = 0; //declare and initialize user option

	while(userOption != -1){

		printf("\n[+] Please enter an option (scissors = 1, paper = 2, rock = 3, or -1 to quit): ");
		scanf("%d", &userOption);

		int compOption; //computer selected option

		compOption = (rand() % 3) + 1;

		checkOptions(userOption, compOption);

	}//end while


}//end function main	


void checkOptions(int userOption, int compOption){

	//1 = scissors, 2 = paper, 3 = rock
	if(userOption == compOption){

		blue();
		printf("%s\n", "--------------------------------");
		printf("%s\n", "[!] It's a tie");

		if(userOption == 1 && compOption == 1)
			printf("%s\n", "[!] You: scissors computer: scissors");

		if(userOption == 2 && compOption == 2)
			printf("%s\n", "[!] You: paper, computer: paper");

		if(userOption == 3 && compOption == 3)
			printf("%s\n", "[!] You: rock, computer: rock");

		printf("%s\n", "--------------------------------");
		reset();
	}
 
	else if(userOption == 1){

		if(compOption == 2){

			green();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[+] You won!");
			printf("%s\n", "[!] You: scissors, computer: paper");
			printf("%s\n", "[!] Reason: Scissors cuts paper.");
			printf("%s\n", "--------------------------------");
			reset();
			userScore++;
		
		}//end if

		else{

			red();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[-] You lose.");
			printf("%s\n", "[!] You: scissors, computer: rock");
			printf("%s\n", "[!] Reason: Rock crushes, breaks and blunts scissors.");
			printf("%s\n", "--------------------------------");
			reset();
			compScore++;

		}//end else

	}//end else if	

	else if(userOption == 2){
		
		if(compOption == 1){

			red();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[-] You lose!");
			printf("%s\n","[!] You: Paper, Computer: Scissors");
			printf("%s\n", "[!] Reason: Scissors cuts paper.");
			printf("%s\n", "--------------------------------");
			reset();
			userScore++;
		
		}//end if

		else{

			green();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[+] You won.");
			printf("%s\n", "[!] You: Paper, Computer: Rock");
			printf("%s\n", "[!] Reason: Paper covers rock.");
			printf("%s\n", "--------------------------------");
			reset();
			compScore++;

		} //end else

	}//end else if	

	else if(userOption == 3){

		if(compOption == 1){

			green();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[+] You won!");
			printf("%s\n", "[!] You: Rock, Computer: Scissors");
			printf("%s\n", "[!] Reason: Rock crushes, breaks and blunts scissors.");
			printf("%s\n", "--------------------------------");
			reset();
			userScore++;

		}//end if

		else{

			red();
			printf("%s\n", "--------------------------------");
			printf("%s\n", "[-] You lose.");
			printf("%s\n", "[!] You: Rock, Computer: Paper");
			printf("%s\n", "[!] Reason: Paper covers rock.");
			printf("%s\n", "--------------------------------");
			reset();
			compScore++;

		}//end else
	
	}//end else if	

	else if(userOption == -1){

		
		printf("%s\n", "--------------------------------");
		if(userScore > compScore){

			green();
			printf("%s\n", "[+] You won the game!");
			reset();

		}//end if	

		else if(userScore  < compScore){

			red();
			printf("%s\n", "[-] You lost the game!");
			reset();

		}//end else if

		else{

			yellow();
			printf("%s\n", "[!] No game played");
			reset();
		
		}//end else	

		yellow();
		printf("%s\n", "[+] Final score");
		printf("[+] You: %d\n", userScore);
		printf("[+] Computer: %d\n", compScore);
		printf("%s\n", "--------------------------------");
		reset();
		printf("\a");

	}//end else  if

	else{

		printf("\a");
		printf("\n[-] Invalid Option");

	}//end else	
		
}//end function checkOptions


void red(void){
  
  printf("\033[1;31m");

}//end function red


void yellow(void){
  
  printf("\033[1;33m");

}//end function yellow


void reset(void){
  
  printf("\033[0m");

}//end function reset


void green(void){

	printf("\033[0;32m");

}//end function green


void blue(void){

	printf("\033[0;34m");
}
