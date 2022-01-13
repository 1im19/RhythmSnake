#include "Level1.h"


//Constructors and Destructors
Level1::Level1()
{
	this->initVariables();
	this->initWindow();

	//Player
	this->initPlayer();

	//Diamonds
	this->initDiamond1();
	this->initDiamond2();

	//Finish Line
	this->initFinishLine();

	//collision
	this->collideWalls();
	this->collideDiamond1();
	this->collideDiamond2();
	this->collideFinishLine();

	//WAAALLLLSSS
	this->initWall1();
	this->initWall2();
	this->initWall3();
	this->initWall4();
	this->initWall5();
	this->initWall6();
	this->initWall7();
	this->initWall8();
	this->initWall9();
	this->initWall10();
	this->initWall11();
	this->initWall12();
	this->initWall13();
	this->initWall14();
	this->initWall15();
	this->initWall16();
	this->initWall17();
	this->initWall18();
	this->initWall19();
	this->initWall20();
	this->initWall21();
	this->initWall22();
	this->initWall23();
	this->initWall24();
	this->initWall25();
	this->initWall26();
	this->initWall27();
	this->initWall28();
	this->initWall29();
	this->initWall30();
	this->initWall31();
	this->initWall32();
	this->initWall33();
	this->initWall34();
    this->initWall35();
	this->initWall36();
	this->initWall37();
	this->initWall38();
	this->initWall39();
	this->initWall40();
	this->initWall41();
	this->initWall42();
	this->initWall43();
	this->initWall44();
	this->initWall45();
	this->initWall46();
	this->initWall47();
	this->initWall48();
	this->initWall49();
	this->initWall50();
	this->initWall51();
	this->initWall52();
	this->initWall53();
	this->initWall54();
	this->initWall55();
	this->initWall56();
	this->initWall57();
	this->initWall58();
	this->initWall59();
}

Level1::~Level1()
{
	delete this->window;
}

//Private Functions
void Level1::initVariables()
{
	this->window = nullptr;
	this->movementSpeed = 10.f;
	timer4 = 0;
	maxtimer = 2800;
	collecteddiamonds = 0;
	maxdiamonds = 2;
	progress = 0;

}

void Level1::initWindow()
{
	this->videoMode.width = 1920;
	this->videoMode.height = 1080;

	this->window = new RenderWindow(this->videoMode, "Rhythm Snake", Style::Titlebar | Style::Close);
	this->view = new View(FloatRect(0.f, 0.f, 800.f, 600.f));
	this->music1 = new Music();

	this->window->setFramerateLimit(60);
	this->music1->openFromFile("Music/SUNRAIN.ogg");
	this->music1->setVolume(70);


	if (!this->levelBackgroundTex.loadFromFile("Image/level1bg.png"))
	{
		cout << "Unable to load background" << endl;
	}
	this->levelBackground.setTexture(this->levelBackgroundTex);
	this->levelBackground.scale(0.6f, 0.6f);
 }

void Level1::initPlayer()
{
	this->player.setPosition(400, 300);
	this->player.setSize(Vector2f(100.f, 100.f));
	this->player.setScale(Vector2f(0.5f, 0.5f));
	this->player.setFillColor(Color::Magenta);
	this->player.setOutlineColor(Color::Black);
	this->player.setOutlineThickness(1.f);
	keycount = 0;
	timer1 = 0;
}

void Level1::pollEvents()
{
	//Event poling
	while (this->window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->window->close();
				this->music1->stop();
			}
			break;
		}
	}
}

//Public Functions
void Level1::Update()
{
	this->pollEvents();
	this->updateInput();

	if (collideWalls())
	{
		this->window->close();
		this->music1->stop();
		FinishLevel();
	}

	if (collideDiamond1() && timer2 == 0)
	{
		timer2++;
		collecteddiamonds++;
		this->diamond1.setFillColor(Color::Transparent);
		this->diamond1.setOutlineColor(Color::Transparent);
	}

	if (collideDiamond2() && timer3 == 0)
	{
		timer3++;
		collecteddiamonds++;
		this->diamond2.setFillColor(Color::Transparent);
		this->diamond2.setOutlineColor(Color::Transparent);
	}

	if (collideFinishLine())
	{
		timer4 = maxtimer;
		this->window->close();
		this->music1->stop();
		FinishLevel();
	}
}

void Level1::FinishLevel()
{
	progress = timer4 * 100 / maxtimer;
	cout << "\t\t\tRolling Sky 2 - SunRain\t\t\t" << endl;
	cout << "\t\t\t\t Progress: " << progress << "%" << "\t\t\t" << endl;
	cout << "\t\t\t\t" << collecteddiamonds << "/" << maxdiamonds << "Diamonds Collected \t\t\t" << endl;

	isavefile1.open("SaveFile1.txt");
	if (isavefile1.is_open())
	{
		while (!isavefile1.eof())
		{
			isavefile1 >> savedprogress;
			isavefile1.ignore(0, ' ');
			isavefile1 >> saveddiamonds;
			isavefile1.ignore(0, '\n');
		}

		if (progress >= savedprogress && collecteddiamonds >= saveddiamonds)
		{
			collectedcoins = (progress - savedprogress) + ((collecteddiamonds - saveddiamonds) * 50);
			osavefile1.open("SaveFile1.txt");
			if (osavefile1.is_open())
			{
				osavefile1 << progress << endl;
				osavefile1 << collecteddiamonds << endl;
			}
			else
			{
				cout << "Unable to locate save file" << endl;
			}
			osavefile1.close();
		}
		else if (progress >= savedprogress && collecteddiamonds < saveddiamonds)
		{
			collectedcoins = progress - savedprogress;
			osavefile1.open("SaveFile1.txt");
			if (osavefile1.is_open())
			{
				osavefile1 << progress << endl;
				osavefile1 << saveddiamonds << endl;
			}
			else
			{
				cout << "Unable to locate save file" << endl;
			}
			osavefile1.close();
		}
		else if (progress < savedprogress && collecteddiamonds >= saveddiamonds)
		{
			collectedcoins = (collecteddiamonds - saveddiamonds) * 50;
			osavefile1.open("SaveFile1.txt");
			if (osavefile1.is_open())
			{
				osavefile1 << savedprogress << endl;
				osavefile1 << collecteddiamonds << endl;
			}
			else
			{
				cout << "Unable to locate save file" << endl;
			}
			osavefile1.close();
		}
		
	}
	else
	{
		cout << "Unable to locate save file" << endl;
	}
	isavefile1.close();

	inventory1.open("Inventory.txt");
	if (inventory1.is_open())
	{
		inventory1 >> savedcoins;
		inventory1.ignore(0, '\n');

		inventory2.open("Inventory.txt");
		if (inventory2.is_open())
		{
			inventory2 << savedcoins + collectedcoins;
		}
		else
		{
			cout << "Unable to locate Inventory save file" << endl;
		}
		inventory2.close();
	}
	else
	{
		cout << "Unable to locate Inventory save file" << endl;
	}
	inventory1.close();
}

void Level1::updateInput()
{
	timer1++;
	//Key input

	if (Keyboard::isKeyPressed(Keyboard::Up) && keycount == 0 && timer1 != 0)
	{
		this->music1->play();
		keycount = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) && keycount == 1 && timer1 == 1)
	{
		keycount = 2;

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) && keycount == 2 && timer1 == 1)
	{
		keycount = 1;
	}
	else if (!Keyboard::isKeyPressed(Keyboard::Up))
	{
		timer1 = 0;
	}

	if (keycount == 1)
	{
		timer4++;
		this->player.move(this->movementSpeed, 0.f);
		this->view->move(this->movementSpeed, 0.f);
		this->levelBackground.move(this->movementSpeed, 0.f);
	}
	if (keycount == 2)
	{
		timer4++;
		this->player.move(0.f, -this->movementSpeed);
		this->view->move(0.f, -this->movementSpeed);
		this->levelBackground.move(0.f, -this->movementSpeed);
	}
}

void Level1::Render()
{
	this->window->clear();

	this->window->setView(*this->view);

	//Draw Background
	this->window->draw(this->levelBackground);

	//Draw Level1 objects
	this->window->draw(this->player);
	this->window->draw(this->diamond1);
	this->window->draw(this->diamond2);
	this->window->draw(this->finishline);
	this->window->draw(this->wall1);
	this->window->draw(this->wall2);
	this->window->draw(this->wall3);
	this->window->draw(this->wall4);
	this->window->draw(this->wall5);
	this->window->draw(this->wall6);
	this->window->draw(this->wall7);
	this->window->draw(this->wall8);
	this->window->draw(this->wall9);
	this->window->draw(this->wall10);
	this->window->draw(this->wall11);
	this->window->draw(this->wall12);
	this->window->draw(this->wall13);
	this->window->draw(this->wall14);
	this->window->draw(this->wall15);
	this->window->draw(this->wall16);
	this->window->draw(this->wall17);
	this->window->draw(this->wall18);
	this->window->draw(this->wall19);
	this->window->draw(this->wall20);
	this->window->draw(this->wall21);
	this->window->draw(this->wall22);
	this->window->draw(this->wall23);
	this->window->draw(this->wall24);
	this->window->draw(this->wall25);
	this->window->draw(this->wall26);
	this->window->draw(this->wall27);
	this->window->draw(this->wall28);
	this->window->draw(this->wall29);
	this->window->draw(this->wall30);
	this->window->draw(this->wall31);
	this->window->draw(this->wall32);
	this->window->draw(this->wall33);
	this->window->draw(this->wall34);
	this->window->draw(this->wall35);
	this->window->draw(this->wall36);
	this->window->draw(this->wall37);
	this->window->draw(this->wall38);
	this->window->draw(this->wall39);
	this->window->draw(this->wall40);
	this->window->draw(this->wall41);
	this->window->draw(this->wall42);
	this->window->draw(this->wall43);
	this->window->draw(this->wall44);
	this->window->draw(this->wall45);
	this->window->draw(this->wall46);
	this->window->draw(this->wall47);
	this->window->draw(this->wall48);
	this->window->draw(this->wall49);
	this->window->draw(this->wall50);
	this->window->draw(this->wall51);
	this->window->draw(this->wall52);
	this->window->draw(this->wall53);
	this->window->draw(this->wall54);
	this->window->draw(this->wall55);
	this->window->draw(this->wall56);
	this->window->draw(this->wall57);
	this->window->draw(this->wall58);
	this->window->draw(this->wall59);

	this->window->display();
}

//Accessors
const bool Level1::Running() const
{
	return this->window->isOpen();
}

//collision
bool Level1::collideDiamond1()
{
	return this->player.getGlobalBounds().intersects(this->diamond1.getGlobalBounds());
}

bool Level1::collideDiamond2()
{
	return this->player.getGlobalBounds().intersects(this->diamond2.getGlobalBounds());
}

bool Level1::collideFinishLine()
{
	return this->player.getGlobalBounds().intersects(this->finishline.getGlobalBounds());
}

bool Level1::collideWalls()
{
	return this->player.getGlobalBounds().intersects(this->wall1.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall2.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall3.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall4.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall5.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall6.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall7.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall8.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall9.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall10.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall11.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall12.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall13.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall14.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall15.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall16.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall17.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall18.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall19.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall20.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall21.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall22.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall23.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall24.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall25.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall26.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall27.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall28.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall29.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall30.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall31.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall32.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall33.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall34.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall35.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall36.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall37.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall38.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall39.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall40.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall41.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall42.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall43.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall44.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall45.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall46.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall47.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall48.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall49.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall50.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall51.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall52.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall53.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall54.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall55.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall56.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall57.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall58.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall59.getGlobalBounds());
}

void Level1::initDiamond1()
{
	this->diamond1.setPosition(9700, -3800);
	this->diamond1.setSize(Vector2f(100.f, 100.f));
	this->diamond1.setScale(Vector2f(0.5f, 0.5f));
	this->diamond1.setFillColor(Color::Blue);
	this->diamond1.setOutlineColor(Color::Black);
	this->diamond1.setOutlineThickness(1.f);
}

void Level1::initDiamond2()
{
	this->diamond2.setPosition(10900, -5800);
	this->diamond2.setSize(Vector2f(100.f, 100.f));
	this->diamond2.setScale(Vector2f(0.5f, 0.5f));
	this->diamond2.setFillColor(Color::Blue);
	this->diamond2.setOutlineColor(Color::Black);
	this->diamond2.setOutlineThickness(1.f);
}

void Level1::initFinishLine()
{
	this->finishline.setPosition(14300, -12700);
	this->finishline.setSize(Vector2f(400.f, 100.f));
	this->finishline.setScale(Vector2f(0.5f, 0.5f));
	this->finishline.setFillColor(Color::White);
	this->finishline.setOutlineColor(Color::Black);
	this->finishline.setOutlineThickness(1.f);
}

//WALLLLSSSSSSS
void Level1::initWall1()
{
	this->wall1.setPosition(400, 200);
	this->wall1.setSize(Vector2f(6400.f, 100.f));
	this->wall1.setScale(Vector2f(0.5f, 0.5f));
	this->wall1.setFillColor(Color::Green);
	this->wall1.setOutlineColor(Color::Black);
	this->wall1.setOutlineThickness(1.f);
}

void Level1::initWall2()
{
	this->wall2.setPosition(400, 400);
	this->wall2.setSize(Vector2f(6900.f, 100.f));
	this->wall2.setScale(Vector2f(0.5f, 0.5f));
	this->wall2.setFillColor(Color::Green);
	this->wall2.setOutlineColor(Color::Black);
	this->wall2.setOutlineThickness(1.f);
}

void Level1::initWall3()
{
	this->wall3.setPosition(3600, -500);
	this->wall3.setSize(Vector2f(100.f, 1500.f));
	this->wall3.setScale(Vector2f(0.5f, 0.5f));
	this->wall3.setFillColor(Color::Green);
	this->wall3.setOutlineColor(Color::Black);
	this->wall3.setOutlineThickness(1.f);
}

void Level1::initWall4()
{
	this->wall4.setPosition(3800, -300);
	this->wall4.setSize(Vector2f(100.f, 1500.f));
	this->wall4.setScale(Vector2f(0.5f, 0.5f));
	this->wall4.setFillColor(Color::Green);
	this->wall4.setOutlineColor(Color::Black);
	this->wall4.setOutlineThickness(1.f);
}

void Level1::initWall5()
{
	this->wall5.setPosition(3600, -500);
	this->wall5.setSize(Vector2f(1300.f, 100.f));
	this->wall5.setScale(Vector2f(0.5f, 0.5f));
	this->wall5.setFillColor(Color::Green);
	this->wall5.setOutlineColor(Color::Black);
	this->wall5.setOutlineThickness(1.f);
}

void Level1::initWall6()
{
	this->wall6.setPosition(3800, -300);
	this->wall6.setSize(Vector2f(1300.f, 100.f));
	this->wall6.setScale(Vector2f(0.5f, 0.5f));
	this->wall6.setFillColor(Color::Green);
	this->wall6.setOutlineColor(Color::Black);
	this->wall6.setOutlineThickness(1.f);
}

void Level1::initWall7()
{
	this->wall7.setPosition(4200, -1200);
	this->wall7.setSize(Vector2f(100.f, 1400.f));
	this->wall7.setScale(Vector2f(0.5f, 0.5f));
	this->wall7.setFillColor(Color::Green);
	this->wall7.setOutlineColor(Color::Black);
	this->wall7.setOutlineThickness(1.f);
}


void Level1::initWall8()
{
	this->wall8.setPosition(4400, -1000);
	this->wall8.setSize(Vector2f(100.f, 1400.f));
	this->wall8.setScale(Vector2f(0.5f, 0.5f));
	this->wall8.setFillColor(Color::Green);
	this->wall8.setOutlineColor(Color::Black);
	this->wall8.setOutlineThickness(1.f);
}

void Level1::initWall9()
{
	this->wall9.setPosition(4200, -1200);
	this->wall9.setSize(Vector2f(1400.f, 100.f));
	this->wall9.setScale(Vector2f(0.5f, 0.5f));
	this->wall9.setFillColor(Color::Green);
	this->wall9.setOutlineColor(Color::Black);
	this->wall9.setOutlineThickness(1.f);
}

void Level1::initWall10()
{
	this->wall10.setPosition(4400, -1000);
	this->wall10.setSize(Vector2f(1400.f, 100.f));
	this->wall10.setScale(Vector2f(0.5f, 0.5f));
	this->wall10.setFillColor(Color::Green);
	this->wall10.setOutlineColor(Color::Black);
	this->wall10.setOutlineThickness(1.f);
}


void Level1::initWall11()
{
	this->wall11.setPosition(4900, -2400);
	this->wall11.setSize(Vector2f(100.f, 2500.f));
	this->wall11.setScale(Vector2f(0.5f, 0.5f));
	this->wall11.setFillColor(Color::Green);
	this->wall11.setOutlineColor(Color::Black);
	this->wall11.setOutlineThickness(1.f);
}

void Level1::initWall12()
{
	this->wall12.setPosition(5100, -2200);
	this->wall12.setSize(Vector2f(100.f, 2500.f));
	this->wall12.setScale(Vector2f(0.5f, 0.5f));
	this->wall12.setFillColor(Color::Green);
	this->wall12.setOutlineColor(Color::Black);
	this->wall12.setOutlineThickness(1.f);
}

void Level1::initWall13()
{
	this->wall13.setPosition(4900, -2400);
	this->wall13.setSize(Vector2f(1400.f, 100.f));
	this->wall13.setScale(Vector2f(0.5f, 0.5f));
	this->wall13.setFillColor(Color::Green);
	this->wall13.setOutlineColor(Color::Black);
	this->wall13.setOutlineThickness(1.f);
}

void Level1::initWall14()
{
	this->wall14.setPosition(5100, -2200);
	this->wall14.setSize(Vector2f(1400.f, 100.f));
	this->wall14.setScale(Vector2f(0.5f, 0.5f));
	this->wall14.setFillColor(Color::Green);
	this->wall14.setOutlineColor(Color::Black);
	this->wall14.setOutlineThickness(1.f);
}

void Level1::initWall15()
{
	this->wall15.setPosition(5600, -3000);
	this->wall15.setSize(Vector2f(100.f, 1300.f));
	this->wall15.setScale(Vector2f(0.5f, 0.5f));
	this->wall15.setFillColor(Color::Green);
	this->wall15.setOutlineColor(Color::Black);
	this->wall15.setOutlineThickness(1.f);
}

void Level1::initWall16()
{
	this->wall16.setPosition(5800, -2800);
	this->wall16.setSize(Vector2f(100.f, 1300.f));
	this->wall16.setScale(Vector2f(0.5f, 0.5f));
	this->wall16.setFillColor(Color::Green);
	this->wall16.setOutlineColor(Color::Black);
	this->wall16.setOutlineThickness(1.f);
}

void Level1::initWall17()
{
	this->wall17.setPosition(5600, -3000);
	this->wall17.setSize(Vector2f(4000.f, 100.f));
	this->wall17.setScale(Vector2f(0.5f, 0.5f));
	this->wall17.setFillColor(Color::Green);
	this->wall17.setOutlineColor(Color::Black);
	this->wall17.setOutlineThickness(1.f);
}

void Level1::initWall18()
{
	this->wall18.setPosition(5800, -2800);
	this->wall18.setSize(Vector2f(4000.f, 100.f));
	this->wall18.setScale(Vector2f(0.5f, 0.5f));
	this->wall18.setFillColor(Color::Green);
	this->wall18.setOutlineColor(Color::Black);
	this->wall18.setOutlineThickness(1.f);
}

void Level1::initWall19()
{
	this->wall19.setPosition(7600, -3700);
	this->wall19.setSize(Vector2f(100.f, 1500.f));
	this->wall19.setScale(Vector2f(0.5f, 0.5f));
	this->wall19.setFillColor(Color::Green);
	this->wall19.setOutlineColor(Color::Black);
	this->wall19.setOutlineThickness(1.f);
}


void Level1::initWall20()
{
	this->wall20.setPosition(7800, -3500);
	this->wall20.setSize(Vector2f(100.f, 1500.f));
	this->wall20.setScale(Vector2f(0.5f, 0.5f));
	this->wall20.setFillColor(Color::Green);
	this->wall20.setOutlineColor(Color::Black);
	this->wall20.setOutlineThickness(1.f);
}

void Level1::initWall21()
{
	this->wall21.setPosition(7600, -3700);
	this->wall21.setSize(Vector2f(4100.f, 100.f));
	this->wall21.setScale(Vector2f(0.5f, 0.5f));
	this->wall21.setFillColor(Color::Green);
	this->wall21.setOutlineColor(Color::Black);
	this->wall21.setOutlineThickness(1.f);
}

void Level1::initWall22()
{
	this->wall22.setPosition(7800, -3500);
	this->wall22.setSize(Vector2f(4500.f, 100.f));
	this->wall22.setScale(Vector2f(0.5f, 0.5f));
	this->wall22.setFillColor(Color::Green);
	this->wall22.setOutlineColor(Color::Black);
	this->wall22.setOutlineThickness(1.f);
}


//1st upper wall
void Level1::initWall23()
{
	this->wall23.setPosition(9600, -4000);
	this->wall23.setSize(Vector2f(100.f, 600.f));
	this->wall23.setScale(Vector2f(0.5f, 0.5f));
	this->wall23.setFillColor(Color::Green);
	this->wall23.setOutlineColor(Color::Black);
	this->wall23.setOutlineThickness(1.f);
}

void Level1::initWall24()
{
	this->wall24.setPosition(9600, -4000);
	this->wall24.setSize(Vector2f(500.f, 100.f));
	this->wall24.setScale(Vector2f(0.5f, 0.5f));
	this->wall24.setFillColor(Color::Green);
	this->wall24.setOutlineColor(Color::Black);
	this->wall24.setOutlineThickness(1.f);
}

//1st left rejoin wall
void Level1::initWall25()
{
	this->wall25.setPosition(9800, -6500);
	this->wall25.setSize(Vector2f(100.f, 5000.f));
	this->wall25.setScale(Vector2f(0.5f, 0.5f));
	this->wall25.setFillColor(Color::Green);
	this->wall25.setOutlineColor(Color::Black);
	this->wall25.setOutlineThickness(1.f);
}

//1st right rejoin wall
void Level1::initWall26()
{
	this->wall26.setPosition(10000, -5000);
	this->wall26.setSize(Vector2f(100.f, 3000.f));
	this->wall26.setScale(Vector2f(0.5f, 0.5f));
	this->wall26.setFillColor(Color::Green);
	this->wall26.setOutlineColor(Color::Black);
	this->wall26.setOutlineThickness(1.f);
}

//1st separation wall
void Level1::initWall27()
{
	this->wall27.setPosition(9800, -3700);
	this->wall27.setSize(Vector2f(100.f, 100.f));
	this->wall27.setScale(Vector2f(0.5f, 0.5f));
	this->wall27.setFillColor(Color::Green);
	this->wall27.setOutlineColor(Color::Black);
	this->wall27.setOutlineThickness(1.f);
}

//2nd upper rejoin wall
void Level1::initWall28()
{
	this->wall28.setPosition(9800, -6500);
	this->wall28.setSize(Vector2f(4000.f, 100.f));
	this->wall28.setScale(Vector2f(0.5f, 0.5f));
	this->wall28.setFillColor(Color::Green);
	this->wall28.setOutlineColor(Color::Black);
	this->wall28.setOutlineThickness(1.f);
}


//2.1st lower wall
void Level1::initWall29()
{
	this->wall29.setPosition(10000, -5000);
	this->wall29.setSize(Vector2f(600.f, 100.f));
	this->wall29.setScale(Vector2f(0.5f, 0.5f));
	this->wall29.setFillColor(Color::Green);
	this->wall29.setOutlineColor(Color::Black);
	this->wall29.setOutlineThickness(1.f);
}

void Level1::initWall30()
{
	this->wall30.setPosition(10300, -5300);
	this->wall30.setSize(Vector2f(100.f, 700.f));
	this->wall30.setScale(Vector2f(0.5f, 0.5f));
	this->wall30.setFillColor(Color::Green);
	this->wall30.setOutlineColor(Color::Black);
	this->wall30.setOutlineThickness(1.f);
}

void Level1::initWall31()
{
	this->wall31.setPosition(10300, -5300);
	this->wall31.setSize(Vector2f(600.f, 100.f));
	this->wall31.setScale(Vector2f(0.5f, 0.5f));
	this->wall31.setFillColor(Color::Green);
	this->wall31.setOutlineColor(Color::Black);
	this->wall31.setOutlineThickness(1.f);
}

void Level1::initWall32()
{
	this->wall32.setPosition(10600, -5600);
	this->wall32.setSize(Vector2f(100.f, 700.f));
	this->wall32.setScale(Vector2f(0.5f, 0.5f));
	this->wall32.setFillColor(Color::Green);
	this->wall32.setOutlineColor(Color::Black);
	this->wall32.setOutlineThickness(1.f);
}

void Level1::initWall33()
{
	this->wall33.setPosition(10600, -5600);
	this->wall33.setSize(Vector2f(800.f, 100.f));
	this->wall33.setScale(Vector2f(0.5f, 0.5f));
	this->wall33.setFillColor(Color::Green);
	this->wall33.setOutlineColor(Color::Black);
	this->wall33.setOutlineThickness(1.f);
}

void Level1::initWall34()
{
	this->wall34.setPosition(11000, -6300);
	this->wall34.setSize(Vector2f(100.f, 1500.f));
	this->wall34.setScale(Vector2f(0.5f, 0.5f));
	this->wall34.setFillColor(Color::Green);
	this->wall34.setOutlineColor(Color::Black);
	this->wall34.setOutlineThickness(1.f);
}

//2nd lower rejoin wall
void Level1::initWall35()
{
	this->wall35.setPosition(11000, -6300);
	this->wall35.setSize(Vector2f(2000.f, 100.f));
	this->wall35.setScale(Vector2f(0.5f, 0.5f));
	this->wall35.setFillColor(Color::Green);
	this->wall35.setOutlineColor(Color::Black);
	this->wall35.setOutlineThickness(1.f);
}

//2nd separation wall
void Level1::initWall36()
{
	this->wall36.setPosition(10000, -6300);
	this->wall36.setSize(Vector2f(100.f, 2200.f));
	this->wall36.setScale(Vector2f(0.5f, 0.5f));
	this->wall36.setFillColor(Color::Green);
	this->wall36.setOutlineColor(Color::Black);
	this->wall36.setOutlineThickness(1.f);
}

void Level1::initWall37()
{
	this->wall37.setPosition(10000, -6300);
	this->wall37.setSize(Vector2f(1600.f, 100.f));
	this->wall37.setScale(Vector2f(0.5f, 0.5f));
	this->wall37.setFillColor(Color::Green);
	this->wall37.setOutlineColor(Color::Black);
	this->wall37.setOutlineThickness(1.f);
}

void Level1::initWall38()
{
	this->wall38.setPosition(11800, -6700);
	this->wall38.setSize(Vector2f(100.f, 500.f));
	this->wall38.setScale(Vector2f(0.5f, 0.5f));
	this->wall38.setFillColor(Color::Green);
	this->wall38.setOutlineColor(Color::Black);
	this->wall38.setOutlineThickness(1.f);
}

void Level1::initWall39()
{
	this->wall39.setPosition(12000, -6500);
	this->wall39.setSize(Vector2f(100.f, 500.f));
	this->wall39.setScale(Vector2f(0.5f, 0.5f));
	this->wall39.setFillColor(Color::Green);
	this->wall39.setOutlineColor(Color::Black);
	this->wall39.setOutlineThickness(1.f);
}

void Level1::initWall40()
{
	this->wall40.setPosition(11800, -6700);
	this->wall40.setSize(Vector2f(600.f, 100.f));
	this->wall40.setScale(Vector2f(0.5f, 0.5f));
	this->wall40.setFillColor(Color::Green);
	this->wall40.setOutlineColor(Color::Black);
	this->wall40.setOutlineThickness(1.f);
}

void Level1::initWall41()
{
	this->wall41.setPosition(12000, -6500);
	this->wall41.setSize(Vector2f(600.f, 100.f));
	this->wall41.setScale(Vector2f(0.5f, 0.5f));
	this->wall41.setFillColor(Color::Green);
	this->wall41.setOutlineColor(Color::Black);
	this->wall41.setOutlineThickness(1.f);
}

void Level1::initWall42()
{
	this->wall42.setPosition(12100, -7000);
	this->wall42.setSize(Vector2f(100.f, 700.f));
	this->wall42.setScale(Vector2f(0.5f, 0.5f));
	this->wall42.setFillColor(Color::Green);
	this->wall42.setOutlineColor(Color::Black);
	this->wall42.setOutlineThickness(1.f);
}

void Level1::initWall43()
{
	this->wall43.setPosition(12300, -6800);
	this->wall43.setSize(Vector2f(100.f, 700.f));
	this->wall43.setScale(Vector2f(0.5f, 0.5f));
	this->wall43.setFillColor(Color::Green);
	this->wall43.setOutlineColor(Color::Black);
	this->wall43.setOutlineThickness(1.f);
}

void Level1::initWall44()
{
	this->wall44.setPosition(12100, -7000);
	this->wall44.setSize(Vector2f(1400.f, 100.f));
	this->wall44.setScale(Vector2f(0.5f, 0.5f));
	this->wall44.setFillColor(Color::Green);
	this->wall44.setOutlineColor(Color::Black);
	this->wall44.setOutlineThickness(1.f);
}

void Level1::initWall45()
{
	this->wall45.setPosition(12300, -6800);
	this->wall45.setSize(Vector2f(1400.f, 100.f));
	this->wall45.setScale(Vector2f(0.5f, 0.5f));
	this->wall45.setFillColor(Color::Green);
	this->wall45.setOutlineColor(Color::Black);
	this->wall45.setOutlineThickness(1.f);
}

void Level1::initWall46()
{
	this->wall46.setPosition(12800, -8600);
	this->wall46.setSize(Vector2f(100.f, 3300.f));
	this->wall46.setScale(Vector2f(0.5f, 0.5f));
	this->wall46.setFillColor(Color::Green);
	this->wall46.setOutlineColor(Color::Black);
	this->wall46.setOutlineThickness(1.f);
}

void Level1::initWall47()
{
	this->wall47.setPosition(13000, -8400);
	this->wall47.setSize(Vector2f(100.f, 3300.f));
	this->wall47.setScale(Vector2f(0.5f, 0.5f));
	this->wall47.setFillColor(Color::Green);
	this->wall47.setOutlineColor(Color::Black);
	this->wall47.setOutlineThickness(1.f);
}

void Level1::initWall48()
{
	this->wall48.setPosition(12800, -8600);
	this->wall48.setSize(Vector2f(600.f, 100.f));
	this->wall48.setScale(Vector2f(0.5f, 0.5f));
	this->wall48.setFillColor(Color::Green);
	this->wall48.setOutlineColor(Color::Black);
	this->wall48.setOutlineThickness(1.f);
}

void Level1::initWall49()
{
	this->wall49.setPosition(13000, -8400);
	this->wall49.setSize(Vector2f(600.f, 100.f));
	this->wall49.setScale(Vector2f(0.5f, 0.5f));
	this->wall49.setFillColor(Color::Green);
	this->wall49.setOutlineColor(Color::Black);
	this->wall49.setOutlineThickness(1.f);
}

void Level1::initWall50()
{
	this->wall50.setPosition(13100, -9400);
	this->wall50.setSize(Vector2f(100.f, 1700.f));
	this->wall50.setScale(Vector2f(0.5f, 0.5f));
	this->wall50.setFillColor(Color::Green);
	this->wall50.setOutlineColor(Color::Black);
	this->wall50.setOutlineThickness(1.f);
}

void Level1::initWall51()
{
	this->wall51.setPosition(13300, -9200);
	this->wall51.setSize(Vector2f(100.f, 1700.f));
	this->wall51.setScale(Vector2f(0.5f, 0.5f));
	this->wall51.setFillColor(Color::Green);
	this->wall51.setOutlineColor(Color::Black);
	this->wall51.setOutlineThickness(1.f);
}

void Level1::initWall52()
{
	this->wall52.setPosition(13100, -9400);
	this->wall52.setSize(Vector2f(1400.f, 100.f));
	this->wall52.setScale(Vector2f(0.5f, 0.5f));
	this->wall52.setFillColor(Color::Green);
	this->wall52.setOutlineColor(Color::Black);
	this->wall52.setOutlineThickness(1.f);
}

void Level1::initWall53()
{
	this->wall53.setPosition(13300, -9200);
	this->wall53.setSize(Vector2f(1400.f, 100.f));
	this->wall53.setScale(Vector2f(0.5f, 0.5f));
	this->wall53.setFillColor(Color::Green);
	this->wall53.setOutlineColor(Color::Black);
	this->wall53.setOutlineThickness(1.f);
}

void Level1::initWall54()
{
	this->wall54.setPosition(13800, -10000);
	this->wall54.setSize(Vector2f(100.f, 1300.f));
	this->wall54.setScale(Vector2f(0.5f, 0.5f));
	this->wall54.setFillColor(Color::Green);
	this->wall54.setOutlineColor(Color::Black);
	this->wall54.setOutlineThickness(1.f);
}

void Level1::initWall55()
{
	this->wall55.setPosition(14000, -9800);
	this->wall55.setSize(Vector2f(100.f, 1300.f));
	this->wall55.setScale(Vector2f(0.5f, 0.5f));
	this->wall55.setFillColor(Color::Green);
	this->wall55.setOutlineColor(Color::Black);
	this->wall55.setOutlineThickness(1.f);
}

void Level1::initWall56()
{
	this->wall56.setPosition(13800, -10000);
	this->wall56.setSize(Vector2f(1000.f, 100.f));
	this->wall56.setScale(Vector2f(0.5f, 0.5f));
	this->wall56.setFillColor(Color::Green);
	this->wall56.setOutlineColor(Color::Black);
	this->wall56.setOutlineThickness(1.f);
}

void Level1::initWall57()
{
	this->wall57.setPosition(14000, -9800);
	this->wall57.setSize(Vector2f(1000.f, 100.f));
	this->wall57.setScale(Vector2f(0.5f, 0.5f));
	this->wall57.setFillColor(Color::Green);
	this->wall57.setOutlineColor(Color::Black);
	this->wall57.setOutlineThickness(1.f);
}

void Level1::initWall58()
{
	this->wall58.setPosition(14300, -12700);
	this->wall58.setSize(Vector2f(100.f, 5500.f));
	this->wall58.setScale(Vector2f(0.5f, 0.5f));
	this->wall58.setFillColor(Color::Green);
	this->wall58.setOutlineColor(Color::Black);
	this->wall58.setOutlineThickness(1.f);
}

void Level1::initWall59()
{
	this->wall59.setPosition(14500, -12700);
	this->wall59.setSize(Vector2f(100.f, 5900.f));
	this->wall59.setScale(Vector2f(0.5f, 0.5f));
	this->wall59.setFillColor(Color::Green);
	this->wall59.setOutlineColor(Color::Black);
	this->wall59.setOutlineThickness(1.f);
}