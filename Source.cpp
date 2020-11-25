#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int MAX_WORDS = 5;

string Words[MAX_WORDS] = {
	"tequila",
	"concatenation",
	"locomotive",
	"overwatch",
	"appartement"
};
string Hints[MAX_WORDS] = {
	"Ca se boit avec des citrons et du sel",
	"C'est un synonyme de combiner",
	"C'est un moyen de transport",
	"C'est un jeu connu de la licence Blizzard",
	"C'est un lieu où l'ont vit"
};

int main(int argc, char** argv[])
{
	string word, hint;
	double points = 0;
	bool correct = false, rejouer = true;

	cout << "Bienvenue dans le Word Jumble, un jeu ou il faut deviner le mot melange.\n";
	cout << "Comme explique plus haut l'objectif du jeu et de trouver le bon mot.\n";
	cout << "Ecris 'hint' si tu as besoin d'aide pour trouver le mot ou 'quit' pour fermer le jeu a tout moment.\n\n";

	while (rejouer)
	{
		correct = false;
		int guess = 0;
		srand(static_cast<unsigned int>(time(0)));
		int num = rand() % MAX_WORDS + 1;
		word = Words[num];
		hint = Hints[num];
		string jumble = word;
		int length = jumble.size();

		for (int i = 0; i < length * 2; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		cout << "Le mot est: " << jumble << endl;
		double tempPoints = 0;

		while (!correct)
		{
			string theGuess;
			cout << "Devine le mot: ";
			cin >> theGuess;
			guess++;

			while (!cin)
			{
				cin.sync();
				cin.clear();
				cout << "Mauvaise réponse, reessayez: ";
				cin >> theGuess;
			}
			if (theGuess == word)
			{
				cout << "Bravo ! Tu as devine le bon mot en " << guess << " essaie !\n";
				tempPoints += jumble.size() * 1.5;
				tempPoints -= (guess - 1) / 4.0;
				points += tempPoints;
				cout << "Tu as gagne " << tempPoints << " points, tu as donc " << points << " au total !\n";
				correct = true;
				cout << "Rejouer ? ( o / n ): ";
				char tempON;
				cin >> tempON;

				while (!cin || tempON != 'o' && tempON != 'n')
				{
					cin.sync();
					cin.clear();
					cout << "Saisie invalide, rejouer ? ( o / n ): ";
					cin >> tempON;
				}
				if (tempON == 'o')
				{
					rejouer = true;
				}
				else
				{
					rejouer = false;
				}
			}
			else if (theGuess == "hint")
			{
				cout << "Indice: " << hint << endl;
				correct = false;
				rejouer = true;
			}
			else if (theGuess == "quit")
			{
				correct = true;
				rejouer = false;
			}
		};
	};

	cout << "Merci d'avoir joue a bientot !";
}