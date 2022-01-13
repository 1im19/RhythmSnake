#include <iostream> 

#include "Level1.h"
#include "Level2.h"

using namespace std;
using namespace sf;

void PlayLevel1()
{
	Level1 level1;
	while (level1.Running())
	{
		//Update
		level1.Update();

		//Render
		level1.Render();
	}
}

void PlayLevel2()
{
	Level2 level2;
	while (level2.Running())
	{
		//Update
		level2.Update();

		//Render
		level2.Render();
	}
}

void HowtoPlay()
{
	cout << "\t\t\tPress the up key to move the snake. Just tap to the rythm\t\t\t" << endl;
}

void Credits()
{
	cout << "\t\t\tGame Designer, Programmer\t\t\t" << endl;
	cout << "\t\t\tMuhammad Aiman Bin Mohd Nor Azman\t\t\t" << endl;
	cout << "\t\t\tB032010486\t\t\t" << endl;
	
	cout << endl;

	cout << "\t\t\tSupervisor\t\t\t" << endl;
	cout << "\t\t\tTs. Dr. Ibrahim Bin Ahmad\t\t\t" << endl;

	cout << endl;

	cout << "\t\t\tEvaluator\t\t\t" << endl;
	cout << "\t\t\tProfessor Ts. Dr. Sazilah Binti Salam" << endl;

	cout << endl;

	cout << "\t\t\tFaculty of Information and Communication Technology\t\t\t" << endl;
	cout << "\t\t\tUniversiti Teknikal Malaysia Melaka (UTEM) \t\t\t" << endl;

	cout << endl;
}

void LevelSelection()
{
	int levelselect;
	int savedcoins;
	int progress1;
	int progress2;
	int saveddiamonds1;
	int saveddiamonds2;
	int level2unlocked;

	ifstream isavefile1;
	ifstream isavefile2;
	ifstream iinventory1;

	ofstream osavefile1;
	ofstream oinventory1;

	do
	{
		iinventory1.open("Inventory.txt");
		if (iinventory1.is_open())
		{
			iinventory1 >> savedcoins;
			iinventory1.ignore(0, '\n');
		}
		else
		{
			cout << "Unable to locate level 1 save file" << endl;
		}
		iinventory1.close();

		isavefile1.open("SaveFile1.txt");
		if (isavefile1.is_open())
		{
			isavefile1 >> progress1;
			isavefile1.ignore(0, ' ');
			isavefile1 >> saveddiamonds1;
			isavefile1.ignore(0, '\n');
		}
		else
		{
			cout << "Unable to locate level 1 save file" << endl;
		}
		isavefile1.close();

		isavefile2.open("SaveFile2.txt");
		if (isavefile2.is_open())
		{
			isavefile2 >> progress2;
			isavefile2.ignore(0, ' ');
			isavefile2 >> saveddiamonds2;
			isavefile2.ignore(0, ' ');
			isavefile2 >> level2unlocked;
			isavefile2.ignore(0, '\n');
		}
		else
		{
			cout << "Unable to locate level 2 save file" << endl;
		}
		isavefile2.close();

		cout << "Coin: " << savedcoins << endl;

		cout << endl;

		cout << "\t\t\tLevel Selection\t\t\t" << endl;

		cout << endl;

		cout << "\t\t\t1 - Rolling Sky 2 - Sunrain\t\t\t" << endl;
		cout << "\t\t\t" << progress1 << "%\t\t\t" << endl;
		cout << "\t\t\tDiamonds: " << saveddiamonds1 << "/2\t\t\t" << endl;

		cout << endl;

		if (level2unlocked == 0)
		{
			cout << "\t\t\t2 - Thomas Bergersen - Empire of Angels\t\t\t" << endl;
			cout << "\t\t\t" << progress2 << "%\t\t\t" << endl;
			cout << "\t\t\tDiamonds: " << saveddiamonds2 << "/3\t\t\t" << endl;
			cout << "\t\t\t\tLevel Locked. Need 50 coins to unlock\t\t\t." << endl;
		}
		else
		{
			cout << "\t\t\t2 - Thomas Bergersen - Empire of Angels\t\t\t" << endl;
			cout << "\t\t\t" << progress2 << "%\t\t\t" << endl;
			cout << "\t\t\tDiamonds: " << saveddiamonds2 << "/3\t\t\t" << endl;
		}

		cout << endl;

		cout << "Select Level: ";
		cin >> levelselect;

		if (levelselect == 1)
		{
			system("CLS");
			PlayLevel1();
			system("Pause");
			system("CLS");
		}
		else if (levelselect == 2)
		{
			system("CLS");
			if (level2unlocked == 0)
			{
				if (savedcoins >= 50)
				{
					level2unlocked = 1;
					osavefile1.open("SaveFile2.txt");
					if (osavefile1.is_open())
					{
						osavefile1 << progress2 << endl;
						osavefile1 << saveddiamonds2 << endl;
						osavefile1 << level2unlocked << endl;
					}
					else
					{
						cout << "Unable to locate level 2 save file" << endl;
					}
					osavefile1.close();

					oinventory1.open("Inventory.txt");
					if (oinventory1.is_open())
					{
						oinventory1 << savedcoins - 50 << endl;
					}
					else
					{
						cout << "Unable to locate inventory file" << endl;
					}
					oinventory1.close();

					PlayLevel2();
					system("Pause");
					system("CLS");
				}
				else
				{
					cout << "You don't have enough coins to unlock this level" << endl;
					system("PAUSE");
					system("CLS");
				}
			}
			else
			{
				system("CLS");
				PlayLevel2();
				system("Pause");
				system("CLS");
			}
		}
	} while (levelselect == 1 || levelselect ==  2);
}

int main()
{
	//Init Game Engine

	//Level1 level1;
	/*Level2 level2;

	while (level2.Running())
	{
		//Update
		level2.Update();

		//Render
		level2.Render();
	}*/

	int mainmenuselect;

	do
	{
		cout << "\t\t\tRythm Snake\t\t\t" << endl << endl;
		cout << "\t\t\t1 - Play Game\t\t\t" << endl;
		cout << "\t\t\t2 - How to Play\t\t\t" << endl;
		cout << "\t\t\t3 - Credits\t\t\t" << endl;

		cout << endl;

		cout << "Select your input:	";
		cin >> mainmenuselect;

		if (mainmenuselect == 1)
		{
			system("CLS");
			LevelSelection();
			system("CLS");
		}
		else if (mainmenuselect == 2)
		{
			system("CLS");
			HowtoPlay();
			system("Pause");
			system("CLS");
		}
		else if (mainmenuselect == 3)
		{
			system("CLS");
			Credits();
			system("Pause");
			system("CLS");
		}
		
	} while (mainmenuselect >= 1 && mainmenuselect <= 3);
	
	
	//Ends the application
	return 0;
}