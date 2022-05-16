#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int Lives = 6;
int Checker(char, string, string &);
void drawingHangman(int &wrong_guesses)
{
    cout << endl
         << "Whoops! That letter isn't in there!" << endl;
    wrong_guesses++;
    if (wrong_guesses == 0)
    {
        cout << " ___________" << endl;
        cout << " |        }" << endl;
        cout << " |         " << endl;
        cout << " |         " << endl;
        cout << " |         " << endl;
        cout << "_|______________" << endl;
    }
    else if (wrong_guesses == 1)
    {
        cout << " ___________" << endl;
        cout << " |        }" << endl;
        cout << " |        0 " << endl;
        cout << " |         " << endl;
        cout << " |         " << endl;
        cout << "_|______________" << endl;
    }
    else if (wrong_guesses == 2)
    {
        cout << " ___________" << endl;
        cout << " |         }" << endl;
        cout << " |       \\ 0 " << endl;
        cout << " |         " << endl;
        cout << " |         " << endl;
        cout << "_|______________" << endl;
    }
    else if (wrong_guesses == 3)
    {
        cout << " ___________" << endl;
        cout << " |         }" << endl;
        cout << " |       \\ 0 /" << endl;
        cout << " |         " << endl;
        cout << " |         " << endl;
        cout << "_|______________" << endl;
    }
    else if (wrong_guesses == 4)
    {
        cout << " ___________" << endl;
        cout << " |        }" << endl;
        cout << " |      \\ 0 /" << endl;
        cout << " |        |" << endl;
        cout << " |         " << endl;
        cout << "_|______________" << endl;
    }
    else if (wrong_guesses == 5)
    {
        cout << " ___________" << endl;
        cout << " |         }" << endl;
        cout << " |       \\ 0 /" << endl;
        cout << " |         | " << endl;
        cout << " |        /  " << endl;
        cout << "_|______________" << endl;
    }
    else
    {
        cout << " ___________" << endl;
        cout << " |         }" << endl;
        cout << " |       \\ 0 /" << endl;
        cout << " |         | " << endl;
        cout << " |        / \\ " << endl;
        cout << "_|______________" << endl;
    }
}
void free() {
   
    cout << " ___________" << endl;
    cout << " |        }" << "       __ 0 __" << endl;
    cout << " |         " << "          | " << endl;
    cout << " |         " << "         / \\ " << endl;
    cout << " |         " << endl;
    cout << "_|_____________________________" << endl;
    cout << "You are a free man now.\n";
    
}
int main()
{

    string correct_word;
    char hint[100];
    char letter;
    int wrong_guesses = 0;

    /* Player 1 enters the word to be guessed as a challenge by other player */
    cout << "Please challenger enter the word secretively, he may see and you might loose :p \n ";
    cin >> correct_word;
    cin.ignore();
    cout << "Please enter a hint to make it a fair game \n";
    //cin >> hint;
    cin.get(hint, 100);
    cin.ignore();

    system("CLS");

    string Unidentified(correct_word.length(), '-');

    // welcome Challenger!!!
    cout << "\n\nWelcome to hangman... Hope you guess the word correctly. \n";
    cout << " ___________" << endl;
    cout << " |         }" << endl;
    cout << " |       \\ 0 /" << endl;
    cout << " |         | " << endl;
    cout << " |        / \\ " << endl;
    cout << "_|______________" << endl;
    cout << "\n The hint provided by your challenger is\n'";
    for (int i = 0; i < strlen(hint); i++)
        cout << hint[i];
    cout << "'\n";
    cout << "\n\nEach letter is represented by a blank.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << Lives << " tries to try and guess the word, as that is the number required to hang a person. \n";
    cout << "\n\t------------Let the Game Begin--------------\n";

    // Loop until the guesses are used up
    while (wrong_guesses < Lives)
    {
        cout << "\n\n"
             << Unidentified;
        cout << "\n\nGuess a letter: \n";
        cin >> letter;
        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (Checker(letter, correct_word, Unidentified) == 0)
        {
            drawingHangman(wrong_guesses);
        }
        else
        {
            cout << endl
                 << "One down another to go" << endl;
        }
        // Tell user how many guesses has left.
        cout << "\nYou have " << Lives - wrong_guesses;
        cout << " guesses left." << endl;
        // Check if user guessed the word.
        if (correct_word == Unidentified)
        {
            cout << correct_word << endl;
            cout << "Yeah! You got it!";
            free();
            break;
        }
    }
    if (wrong_guesses == Lives)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        cout << "The word was : " << correct_word << endl;
    }

    return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int Checker(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i])
            return 0;
        // Is the guess in the secret word?
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

