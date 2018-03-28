#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>  
#include <time.h> 
using namespace std;

void play();
string pickphrase();
string makeblanks(string phrase);
bool guessletter(string phrase, string& blanks, char guess);
bool guessphrase(string phrase, string& blanks, string guess);

void testguess(string phrase, string& blanks, string expected, char guess, bool should_be_correct){
	bool correct = guessletter(phrase, blanks, guess);
	cout << "guessing letter " << guess << endl;
	if (correct != should_be_correct)
		cout << "correct error\n";
	if (expected != blanks)
		cout << "Output error\n";
}

void test(){
	string input = "Hello World!";
	string expected = "_____ _____!";
	string output = makeblanks(input);
	if (input != "Hello World!")
		cout << "Input Error\n";
	if (expected != output)
		cout << "Output error\n";
	cout << output << endl;
	testguess(input, output, "H____ _____!", 'H', true);
	cout << output << endl;

	testguess(input, output, "H____ _____!", 'I', false);
	cout << output << endl;

	testguess(input, output, "H_ll_ ___l_!", 'L', true);
	cout << output << endl;
}

int main(){
	//test();
	string again = "yes";
	while (toupper(again.at(0)) == 'Y') {
		play();
		cout << "Do you want to play again? ";
		getline(cin, again);
	}
	return 0;
}

void play(){
	string phrase = pickphrase();
	string blanks = makeblanks(phrase);
	cout << blanks << endl;
	int wrong = 0;
	while (phrase != blanks && wrong < 6)
	{
		cout << "guess a letter or the entire phrase\n";
		string guess;
		bool correct;
		getline(cin,guess);
		if (guess.length() == 1){
			correct = guessletter(phrase, blanks, guess.at(0));
		}
		else if (guess.length() == phrase.length()){
			correct = guessphrase(phrase, blanks, guess);
			if (correct != true)
				wrong = 5;
		}
		else{
			cout << "Your response was the wrong length\n";
			correct = true;
		}
		if (correct != true)
		{
			wrong++; 
			cout << "You have " << 6 - wrong << " guesses left.\n";
		}
		/*if (wrong = 1);
		cout << "   _________\n";
		cout << "   |       |\n";
		cout << "   |        \n";
		cout << "   |        \n";
		cout << "   |        \n";
		cout << "   |        \n";
		cout << "___|________\n";
		*/
		cout << blanks << endl;
		/*if (wrong=2)
		cout << "   _________\n";
		cout << "   |       |\n";
		cout << "   |      ( ) \n";
		cout << "   |        \n";
		cout << "   |        \n";
		cout << "   |        \n";
		cout << "___|________\n";
		*/
	}
	if (phrase == blanks)
		cout << "You Win!!!\n";
	else
	{
		cout << "You Lose.\n";
	}
}

string pickphrase(){
	string phrases[12];
	phrases[0] = "Hello World";
	phrases[1] = "Baby youre a firework";
	phrases[2] = "Take on me";
	phrases[3] = "Never gonna give you up";
	phrases[4] = "Drop the bass";
	phrases[5] = "Just do it";
	phrases[6] = "A dream is a wish your heart makes";
	phrases[7] = "how much wood could a wood chuck chuck";
	phrases[8] = "Do you like pina coladas";
	phrases[9] = "Hey now youre an all star";
	phrases[10] = "Life is like a box of chocolates";
	phrases[11] = "To infinity and beyond";
	return phrases[11];
}

//take an answer and replace all letters with underscores, but leave everything else the same

string makeblanks(string phrase){
	for (unsigned int i = 0; i < phrase.length(); i++){
		if (isalpha(phrase.at(i))){
			phrase[i] = '_';
		}
	}
	return phrase;
}
//take an answer and the string with blanks, and replace the blanks if the guess is correct
//also return true if the guess is correct
bool guessletter(string phrase, string& blanks, char guess){
	bool correct = false;
	for (unsigned int i = 0; i < phrase.length(); i++){
		if (phrase.at(i) == toupper(guess) || phrase.at(i) == tolower(guess)){
			blanks[i] = phrase.at(i);
			correct = true;
		}
	}
	if (correct != true)
		cout << "invalid answer\n";
	return correct;
}
bool guessphrase(string phrase, string& blanks, string guess){
	bool correct = true;
	for (unsigned int i = 0; i < phrase.length(); i++){
		if (toupper(phrase.at(i)) != toupper(guess.at(i))){
			correct = false;
			break;
		}
	}
	if (correct == true)
		blanks = phrase;
	else
		cout << "invalid answer\n";
	return correct;
}
/*void image1(){

	cout << "  _________";
	cout << "  |       |";
	cout << "  |        ";
	cout << "  |        ";
	cout << "  |        ";
	cout << "  |        ";
	cout << "_______|____________";
		
}
*/
/* void image2()
       _________
       |       |
       |      ( ) 
       |      
	   |       
       |      
_______|____________
*/
/*void image3()
	   _________
       |       |
       |      ( )
       |       |
       |       
       |      
_______|____________
*/

/*void image4()
       _________
       |       |
       |      ( )
	   |      \|/
	   |       
       |      
_______|____________
*/
/* void image5()
       _________
       |       |
       |      ( )
       |      \|/
       |       |
       |      
_______|____________
*/
/* void image6()
       _________
       |       |
       |      ( )
       |      \|/
       |       |
       |      / \
_______|____________
*/