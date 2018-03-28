#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>  
#include <time.h> 
using namespace std;

string makeblanks(string phrase);
bool guessletter(string phrase, string& blanks, char guess);

void testguess(string phrase, string& blanks, string expected, char guess, bool should_be_correct){
	bool correct = guessletter(phrase, blanks, guess);
	cout << "guessing letter " << guess << endl;
	if (correct != should_be_correct)
		cout << "correct error\n";
	if (expected != blanks)
		cout << "Output error\n";
}
/*void wordlist(){
	word[1] = "Hello World";
	word[2] = "Baby your a firework";
	word[3] = "Take on me";
	word[4] = "Never gonna give you up";
	word[5] = "Drop the bass"

}
*/
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
	string phrase = "Hello World!";
	string blanks = makeblanks(phrase);
	int wrong = 0;
	while (phrase != blanks && wrong < 6)
	{
		cout << "guess a letter\n";
		string guess;
		getline(cin,guess);
		bool correct = guessletter(phrase, blanks, guess.at(0));
		if (correct != true)
		{wrong++; 
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
	system("pause");
	return 0;
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
bool guessphrase(string phrase, string& blanks, char guess){
	for (unsigned int i = phrase.length); {
		if (phrase == toupper(guess){
			blanks= phrase
		}
	}
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