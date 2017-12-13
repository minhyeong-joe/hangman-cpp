#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
	vector<char> tried;
	char response;
	char guess;
	string wordpool[] = { "milkshake", "notepad", "pillowcase", "mirror", "airconditioner", "programming", "ironman", "environment",
		"apostrophe", "astronomer", "hangman", "camera", "flower", "typewriter", "pillar", "keyboard", "pencil", "president", "attorney",
		"vehicle", "toilet", "shampoo", "toothpaste", "garbage", "operator", "eraser", "finger", "intestine", "tongue", "candlestick",
		"theater", "chair", "bookshelf", "swimming", "refrigerator", "generator", "stove", "router", "cardboard", "award", "phenomenon",
		"chopsticks", "bride", "groom", "clutch", "luxury", "costume", "perfume", "window", "drawer", "spoon", "accelerator", "brake",
		"garage", "laundry", "airplane", "restaurant", "saloon", "firefighter", "police", "aligator", "daughter", "precedence", "descendant",
		"inheritance", "polymorph", "movie", "world", "insanity", "hospital", "tournament", "garment", "prison", "crime",
		"justice", "villain", "topographic", "office", "stereotype", "hypothetical", "hypocrite", "hypotenuse"};
	string answer;
	do
	{
	system("cls");
	tried.clear();
	int attempt = 8, match = 0;
	bool success = false;
	srand(time(0));
	int random = rand() % 82;
	answer = wordpool[random];
	string hide(answer.length(), '_');
	cout << "Welcome to the Hangman game.\n"
		<< "You have to guess the word.\n"
		<< "You may only type in one alphabet in each try.\n";
		do
		{
			cout << "You have " << attempt << " attempts left.\n";
			cout << "Your attempts: ";
			for (int j = 0; j < tried.size(); j++)
			{
				cout << tried.at(j) << " ";
			}
			cout << "\n\n";
			match = 0;
			cout << "The word is " << hide << endl;
			cout << "\nGuess a letter: ";
			cin >> guess;
			for (int i = 0; i < answer.length();i++)
			{
				if (tolower(guess) == answer[i])
				{
					hide[i] = tolower(guess);
					match++;
				}
			}
			system("cls");
			Beep(1000, 80);
			cout << "\n\n\n";
			if (match == 0)
			{
				tried.push_back(tolower(guess));
				attempt--;
			}
			if (hide == answer)
			{
				cout << "\n\n\nThe word is " << answer << "\nYou have successfully guessed the word!\n " << endl;
				success = true;
			}
		} while (attempt > 0 && !success);
		if (!success)
		{
			cout << "\n\n\nThe word was " << answer << "\nYou have failed..." << endl;
		}
		do {
			cout << "\n(R)etry or (Q)uit?\n";
			cin >> response;
		} while (toupper(response) != 'R' && toupper(response) != 'Q');
	} while (toupper(response) == 'R');
	cin.get();
	return 0;
}