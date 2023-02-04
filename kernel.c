#include <stdio.h>
#include <stdint.h>
#include "limits.h"
#include <stdint.h>

void run_test();
void k_printstr(char *string, int row, int col);
void print_border(int start_row, int start_col, int width, int height);
void k_clearscr(int start_row, int start_col, int width, int height);

int main() {
	k_clearscr(0, 0, 80, 25); //call the function to clear the screen      // written by you in C
	print_border(0, 0, 80, 25); //call the function to print the border      // written by you in C
	run_test(); //call run_test()                            // written by the professor


	//loop that spins for approximately INT_MAX (found in limits.h) iterations
	for (int i = 0; i < INT_MAX; i++) { //loop INT_MAX times
	}
	k_clearscr(0, 0, 80, 25); //call the function to clear the screen

	//add another loop that fills the screen with stars.
	//print a row of 80 stars('*') at line i, row 0
	for (int i = 0; i < 25; i++) { //loop i from 0 to 24
		for(int j = 0; j < 80; j++){
			k_printstr("*", i, j); //void k_printstr(char *s, int row, int col);
		}
	}


	//end loop
	while (1) {

	}//loop forever      // Its done, but the OS has nowhere which to return!

}


// but they must call k_printstr() to get their work done
void print_border(int start_row, int start_col, int width, int height) {
	k_printstr("\xC9", start_row, start_col);
	k_printstr("\xBB", start_row, start_col+width-1);
	k_printstr("\xC8", start_row+height-1, start_col);
	k_printstr("\xBC", start_row + height-1, start_col+width-1);

	for (int i = start_col + 1; i < start_col + width - 1; i++) {
		k_printstr("\xCD", start_row, i);
		k_printstr("\xCD", start_row + height -1, i);
	}

	for (int i = start_row + 1; i < start_row + height - 1; i++) {
		k_printstr("\xBA", i, start_col);
		k_printstr("\xBA", i, start_col + width - 1);
	}
}

// Note that k_clearscr() can also clear a portion of the screen
void k_clearscr(int start_row, int start_col, int width, int height) {
	for (int i = start_row; i < height+start_row; i++) {
		for (int j = start_col; j < start_col+width; j++) {
			k_printstr(" ", i, j);
		}
	}
} 
// calls k_printstr() twenty five times passing it a string of the required number of spaces
