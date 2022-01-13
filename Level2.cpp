#include "Level2.h"


//Constructors and Destructors
Level2::Level2()
{
	this->initVariables();
	this->initWindow();

	//Player
	this->initPlayer();

	//Diamonds
	this->initDiamond1();
	this->initDiamond2();
	this->initDiamond3();

	//Finish Line
	this->initFinishLine();

	//collision
	this->collideWalls();
	this->collideDiamond1();
	this->collideDiamond2();
	this->collideDiamond3();
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
	this->initWall60();
	this->initWall61();
	this->initWall62();
	this->initWall63();
	this->initWall64();
	this->initWall65();
	this->initWall66();
	this->initWall67();
	this->initWall68();
	this->initWall69();
	this->initWall70();
	this->initWall71();
	this->initWall72();
	this->initWall73();
	this->initWall74();
	this->initWall75();
	this->initWall76();
	this->initWall77();
	this->initWall78();
	this->initWall79();
	this->initWall80();
	this->initWall81();
	this->initWall82();
	this->initWall83();
	this->initWall84();
	this->initWall85();
	this->initWall86();
	this->initWall87();
	this->initWall88();
	this->initWall89();
	this->initWall90();
	this->initWall91();
	this->initWall92();
	this->initWall93();
	this->initWall94();
	this->initWall95();
	this->initWall96();
	this->initWall97();
	this->initWall98();
	this->initWall99();
	this->initWall100();
	this->initWall101();
	this->initWall102();
	this->initWall103();
	this->initWall104();
}

Level2::~Level2()
{	
	delete this->window;
}

//Private Functions
void Level2::initVariables()
{
	this->window = nullptr;
	this->movementSpeed = 10.f;
	timer5 = 0;
	maxtimer = 3000;
	collecteddiamonds = 0;
	maxdiamonds = 3;
	progress = 0;
}

void Level2::initWindow()
{
	this->videoMode.width = 1920;
	this->videoMode.height = 1080;
	
	this->window = new RenderWindow(this->videoMode, "Rhythm Snake", Style::Titlebar | Style::Close);
	this->view = new View(FloatRect(0.f, 0.f, 800.f, 600.f));
	this->music1 = new Music();

	this->window->setFramerateLimit(60);
	this->music1->openFromFile("Music/Thomas Bergersen - Empire of Angels (Sun).ogg");
	this->music1->setVolume(70);


	if (!this->levelBackgroundTex.loadFromFile("Image/level2bg.png"))
	{
		cout << "Unable to load background" << endl;
	}
	this->levelBackground.setTexture(this->levelBackgroundTex);
	this->levelBackground.scale(1.f, 1.f);
}

void Level2::initPlayer()
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

void Level2::pollEvents()
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
			}
			break;
		}
	}
}

//Public Functions
void Level2::Update()
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

	if (collideDiamond3() && timer4 == 0)
	{
		timer4++;
		collecteddiamonds++;
		this->diamond3.setFillColor(Color::Transparent);
		this->diamond3.setOutlineColor(Color::Transparent);
	}

	if (collideFinishLine())
	{
		timer5= maxtimer;
		this->window->close();
		this->music1->stop();
		FinishLevel();
	}
}

void Level2::FinishLevel()
{
	progress = timer5 * 100 / maxtimer;
	cout << "\t\t\tThomas Bergersen - Empire of Angels\t\t\t" << endl;
	cout << "\t\t\t\t Progress: " << progress << "%" << "\t\t\t" << endl;
	cout << "\t\t\t\t" << collecteddiamonds << "/" << maxdiamonds << "Diamonds Collected \t\t\t" << endl;

	isavefile1.open("SaveFile2.txt");
	if (isavefile1.is_open())
	{
		while (!isavefile1.eof())
		{
			isavefile1 >> savedprogress;
			isavefile1.ignore(0, ' ');
			isavefile1 >> saveddiamonds;
			isavefile1.ignore(0, ' ');
			isavefile1 >> unlocked;
			isavefile1.ignore(0, '\n');
		}

		if (progress >= savedprogress && collecteddiamonds >= saveddiamonds)
		{
			collectedcoins = (progress - savedprogress) + ((collecteddiamonds - saveddiamonds) * 50);
			osavefile1.open("SaveFile2.txt");
			if (osavefile1.is_open())
			{
				osavefile1 << progress << endl;
				osavefile1 << collecteddiamonds << endl;
				osavefile1 << unlocked << endl;
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
				osavefile1 << unlocked << endl;
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
				osavefile1 << unlocked << endl;
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

void Level2::updateInput()
{
	timer1++;
	//Key input
	
	if(Keyboard::isKeyPressed(Keyboard::Up) && keycount == 0 && timer1 != 0)
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
	else if(!Keyboard::isKeyPressed(Keyboard::Up))
	{
		timer1 = 0;
	}
	
	if (keycount == 1)
	{
		timer5++;
		this->player.move(this->movementSpeed, 0.f);
		this->view->move(this->movementSpeed, 0.f);
		this->levelBackground.move(this->movementSpeed, 0.f);
	}
	if (keycount == 2)
	{
		timer5++;
		this->player.move(0.f, -this->movementSpeed);
		this->view->move(0.f, -this->movementSpeed);
		this->levelBackground.move(0.f, -this->movementSpeed);
	}
}

void Level2::Render()
{
	this->window->clear();

	this->window->setView(*this->view);

	//Draw Background
	this->window->draw(this->levelBackground);

	//Draw Level2 objects
	this->window->draw(this->player);
	this->window->draw(this->diamond1);
	this->window->draw(this->diamond2);
	this->window->draw(this->diamond3);
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
	this->window->draw(this->wall60);
	this->window->draw(this->wall61);
	this->window->draw(this->wall62);
	this->window->draw(this->wall63);
	this->window->draw(this->wall64);
	this->window->draw(this->wall65);
	this->window->draw(this->wall66);
	this->window->draw(this->wall67);
	this->window->draw(this->wall68);
	this->window->draw(this->wall69);
	this->window->draw(this->wall70);
	this->window->draw(this->wall71);
	this->window->draw(this->wall72);
	this->window->draw(this->wall73);
	this->window->draw(this->wall74);
	this->window->draw(this->wall75);
	this->window->draw(this->wall76);
	this->window->draw(this->wall77);
	this->window->draw(this->wall78);
	this->window->draw(this->wall79);
	this->window->draw(this->wall80);
	this->window->draw(this->wall81);
	this->window->draw(this->wall82);
	this->window->draw(this->wall83);
	this->window->draw(this->wall84);
	this->window->draw(this->wall85);
	this->window->draw(this->wall86);
	this->window->draw(this->wall87);
	this->window->draw(this->wall88);
	this->window->draw(this->wall89);
	this->window->draw(this->wall90);
	this->window->draw(this->wall91);
	this->window->draw(this->wall92);
	this->window->draw(this->wall93);
	this->window->draw(this->wall94);
	this->window->draw(this->wall95);
	this->window->draw(this->wall96);
	this->window->draw(this->wall97);
	this->window->draw(this->wall98);
	this->window->draw(this->wall99);
	this->window->draw(this->wall100);
	this->window->draw(this->wall101);
	this->window->draw(this->wall102);
	this->window->draw(this->wall103);
	this->window->draw(this->wall104);

	this->window->display();
}

//Accessors
const bool Level2::Running() const
{
	return this->window->isOpen();
}

//collision

bool Level2::collideDiamond1()
{
	return this->player.getGlobalBounds().intersects(this->diamond1.getGlobalBounds());
}

bool Level2::collideDiamond2()
{
	return this->player.getGlobalBounds().intersects(this->diamond2.getGlobalBounds());
}

bool Level2::collideDiamond3()
{
	return this->player.getGlobalBounds().intersects(this->diamond3.getGlobalBounds());
}

bool Level2::collideFinishLine()
{
	return this->player.getGlobalBounds().intersects(this->finishline.getGlobalBounds());
}

bool Level2::collideWalls()
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
		this->player.getGlobalBounds().intersects(this->wall59.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall60.getGlobalBounds()) ||
		this->player.getGlobalBounds().intersects(this->wall61.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall62.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall63.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall64.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall65.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall66.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall67.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall68.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall69.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall70.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall71.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall72.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall73.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall74.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall75.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall76.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall77.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall78.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall79.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall80.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall81.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall82.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall83.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall84.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall85.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall86.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall87.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall88.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall89.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall90.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall91.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall92.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall93.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall94.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall95.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall96.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall97.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall98.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall99.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall100.getGlobalBounds())||
		this->player.getGlobalBounds().intersects(this->wall101.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall102.getGlobalBounds()) || 
		this->player.getGlobalBounds().intersects(this->wall103.getGlobalBounds()) || this->player.getGlobalBounds().intersects(this->wall104.getGlobalBounds());
}

//Diamonds

void Level2::initDiamond1()
{
	this->diamond1.setPosition(4700, -1700);
	this->diamond1.setSize(Vector2f(100.f, 100.f));
	this->diamond1.setScale(Vector2f(0.5f, 0.5f));
	this->diamond1.setFillColor(Color::Blue);
	this->diamond1.setOutlineColor(Color::Black);
	this->diamond1.setOutlineThickness(1.f);
}

void Level2::initDiamond2()
{
	this->diamond2.setPosition(7900, -4100);
	this->diamond2.setSize(Vector2f(100.f, 100.f));
	this->diamond2.setScale(Vector2f(0.5f, 0.5f));
	this->diamond2.setFillColor(Color::Blue);
	this->diamond2.setOutlineColor(Color::Black);
	this->diamond2.setOutlineThickness(1.f);
}

void Level2::initDiamond3()
{
	this->diamond3.setPosition(10700, -6300);
	this->diamond3.setSize(Vector2f(100.f, 100.f));
	this->diamond3.setScale(Vector2f(0.5f, 0.5f));
	this->diamond3.setFillColor(Color::Blue);
	this->diamond3.setOutlineColor(Color::Black);
	this->diamond3.setOutlineThickness(1.f);
}

//Finish Line

void Level2::initFinishLine()
{
	this->finishline.setPosition(20900, -8500);
	this->finishline.setSize(Vector2f(100.f, 500.f));
	this->finishline.setScale(Vector2f(0.5f, 0.5f));
	this->finishline.setFillColor(Color::White);
	this->finishline.setOutlineColor(Color::Black);
	this->finishline.setOutlineThickness(1.f);
}

//WALLLLSSSSSSS
void Level2::initWall1()
{
	this->wall1.setPosition(400, 200);
	this->wall1.setSize(Vector2f(6200.f, 100.f));
	this->wall1.setScale(Vector2f(0.5f, 0.5f));
	this->wall1.setFillColor(Color::Green);
	this->wall1.setOutlineColor(Color::Black);
	this->wall1.setOutlineThickness(1.f);
}

void Level2::initWall2()
{
	this->wall2.setPosition(400, 400);
	this->wall2.setSize(Vector2f(6600.f, 100.f));
	this->wall2.setScale(Vector2f(0.5f, 0.5f));
	this->wall2.setFillColor(Color::Green);
	this->wall2.setOutlineColor(Color::Black);
	this->wall2.setOutlineThickness(1.f);
}

void Level2::initWall3()
{
	this->wall3.setPosition(3500, 0);
	this->wall3.setSize(Vector2f(100.f, 500.f));
	this->wall3.setScale(Vector2f(0.5f, 0.5f));
	this->wall3.setFillColor(Color::Green);
	this->wall3.setOutlineColor(Color::Black);
	this->wall3.setOutlineThickness(1.f);
}

void Level2::initWall4()
{
	this->wall4.setPosition(3700, 200);
	this->wall4.setSize(Vector2f(100.f, 500.f));
	this->wall4.setScale(Vector2f(0.5f, 0.5f));
	this->wall4.setFillColor(Color::Green);
	this->wall4.setOutlineColor(Color::Black);
	this->wall4.setOutlineThickness(1.f);
}

void Level2::initWall5()
{
	this->wall5.setPosition(3500, 0);
	this->wall5.setSize(Vector2f(400.f, 100.f));
	this->wall5.setScale(Vector2f(0.5f, 0.5f));
	this->wall5.setFillColor(Color::Green);
	this->wall5.setOutlineColor(Color::Black);
	this->wall5.setOutlineThickness(1.f);
}

void Level2::initWall6()
{
	this->wall6.setPosition(3700, 200);
	this->wall6.setSize(Vector2f(400.f, 100.f));
	this->wall6.setScale(Vector2f(0.5f, 0.5f));
	this->wall6.setFillColor(Color::Green);
	this->wall6.setOutlineColor(Color::Black);
	this->wall6.setOutlineThickness(1.f);
}

void Level2::initWall7()
{
	this->wall7.setPosition(3700, -400);
	this->wall7.setSize(Vector2f(100.f, 900.f));
	this->wall7.setScale(Vector2f(0.5f, 0.5f));
	this->wall7.setFillColor(Color::Green);
	this->wall7.setOutlineColor(Color::Black);
	this->wall7.setOutlineThickness(1.f);
}


void Level2::initWall8()
{
	this->wall8.setPosition(3900, -200);
	this->wall8.setSize(Vector2f(100.f, 900.f));
	this->wall8.setScale(Vector2f(0.5f, 0.5f));
	this->wall8.setFillColor(Color::Green);
	this->wall8.setOutlineColor(Color::Black);
	this->wall8.setOutlineThickness(1.f);
}

void Level2::initWall9()
{
	this->wall9.setPosition(3700, -400);
	this->wall9.setSize(Vector2f(600.f, 100.f));
	this->wall9.setScale(Vector2f(0.5f, 0.5f));
	this->wall9.setFillColor(Color::Green);
	this->wall9.setOutlineColor(Color::Black);
	this->wall9.setOutlineThickness(1.f);
}

void Level2::initWall10()
{
	this->wall10.setPosition(3900, -200);
	this->wall10.setSize(Vector2f(600.f, 100.f));
	this->wall10.setScale(Vector2f(0.5f, 0.5f));
	this->wall10.setFillColor(Color::Green);
	this->wall10.setOutlineColor(Color::Black);
	this->wall10.setOutlineThickness(1.f);
}

void Level2::initWall11()
{
	this->wall11.setPosition(4000, -900);
	this->wall11.setSize(Vector2f(100.f, 1100.f));
	this->wall11.setScale(Vector2f(0.5f, 0.5f));
	this->wall11.setFillColor(Color::Green);
	this->wall11.setOutlineColor(Color::Black);
	this->wall11.setOutlineThickness(1.f);
}

void Level2::initWall12()
{
	this->wall12.setPosition(4200, -700);
	this->wall12.setSize(Vector2f(100.f, 1100.f));
	this->wall12.setScale(Vector2f(0.5f, 0.5f));
	this->wall12.setFillColor(Color::Green);
	this->wall12.setOutlineColor(Color::Black);
	this->wall12.setOutlineThickness(1.f);
}

void Level2::initWall13()
{
	this->wall13.setPosition(4000, -900);
	this->wall13.setSize(Vector2f(400.f, 100.f));
	this->wall13.setScale(Vector2f(0.5f, 0.5f));
	this->wall13.setFillColor(Color::Green);
	this->wall13.setOutlineColor(Color::Black);
	this->wall13.setOutlineThickness(1.f);
}

void Level2::initWall14()
{
	this->wall14.setPosition(4200, -700);
	this->wall14.setSize(Vector2f(400.f, 100.f));
	this->wall14.setScale(Vector2f(0.5f, 0.5f));
	this->wall14.setFillColor(Color::Green);
	this->wall14.setOutlineColor(Color::Black);
	this->wall14.setOutlineThickness(1.f);
} 

void Level2::initWall15()
{
	this->wall15.setPosition(4200, -2000);
	this->wall15.setSize(Vector2f(100.f, 2300.f));
	this->wall15.setScale(Vector2f(0.5f, 0.5f));
	this->wall15.setFillColor(Color::Green);
	this->wall15.setOutlineColor(Color::Black);
	this->wall15.setOutlineThickness(1.f);
}

void Level2::initWall16()
{
	this->wall16.setPosition(4400, -1400);
	this->wall16.setSize(Vector2f(100.f, 1500.f));
	this->wall16.setScale(Vector2f(0.5f, 0.5f));
	this->wall16.setFillColor(Color::Green);
	this->wall16.setOutlineColor(Color::Black);
	this->wall16.setOutlineThickness(1.f);
}

//1st upper rejoin wall
void Level2::initWall17()
{
	this->wall17.setPosition(4200, -2000);
	this->wall17.setSize(Vector2f(1600.f, 100.f));
	this->wall17.setScale(Vector2f(0.5f, 0.5f));
	this->wall17.setFillColor(Color::Green);
	this->wall17.setOutlineColor(Color::Black);
	this->wall17.setOutlineThickness(1.f);
}

//separation wall
void Level2::initWall18()
{
	this->wall18.setPosition(4400, -1800);
	this->wall18.setSize(Vector2f(100.f, 300.f));
	this->wall18.setScale(Vector2f(0.5f, 0.5f));
	this->wall18.setFillColor(Color::Green);
	this->wall18.setOutlineColor(Color::Black);
	this->wall18.setOutlineThickness(1.f);
}

void Level2::initWall19()
{
	this->wall19.setPosition(4400, -1800);
	this->wall19.setSize(Vector2f(400.f, 100.f));
	this->wall19.setScale(Vector2f(0.5f, 0.5f));
	this->wall19.setFillColor(Color::Green);
	this->wall19.setOutlineColor(Color::Black);
	this->wall19.setOutlineThickness(1.f);
}

//1st lower wall
void Level2::initWall20()
{
	this->wall20.setPosition(4400, -1400);
	this->wall20.setSize(Vector2f(400.f, 100.f));
	this->wall20.setScale(Vector2f(0.5f, 0.5f));
	this->wall20.setFillColor(Color::Green);
	this->wall20.setOutlineColor(Color::Black);
	this->wall20.setOutlineThickness(1.f);
}

void Level2::initWall21()
{
	this->wall21.setPosition(4600, -1600);
	this->wall21.setSize(Vector2f(100.f, 500.f));
	this->wall21.setScale(Vector2f(0.5f, 0.5f));
	this->wall21.setFillColor(Color::Green);
	this->wall21.setOutlineColor(Color::Black);
	this->wall21.setOutlineThickness(1.f);
}

void Level2::initWall22()
{
	this->wall22.setPosition(4600, -1600);
	this->wall22.setSize(Vector2f(400.f, 100.f));
	this->wall22.setScale(Vector2f(0.5f, 0.5f));
	this->wall22.setFillColor(Color::Green);
	this->wall22.setOutlineColor(Color::Black);
	this->wall22.setOutlineThickness(1.f);
}


void Level2::initWall23()
{
	this->wall23.setPosition(4800, -1800);
	this->wall23.setSize(Vector2f(100.f, 500.f));
	this->wall23.setScale(Vector2f(0.5f, 0.5f));
	this->wall23.setFillColor(Color::Green);
	this->wall23.setOutlineColor(Color::Black);
	this->wall23.setOutlineThickness(1.f);
}

//1st lower rejoin wall
void Level2::initWall24()
{
	this->wall24.setPosition(4800, -1800);
	this->wall24.setSize(Vector2f(800.f, 100.f));
	this->wall24.setScale(Vector2f(0.5f, 0.5f));
	this->wall24.setFillColor(Color::Green);
	this->wall24.setOutlineColor(Color::Black);
	this->wall24.setOutlineThickness(1.f);
}

void Level2::initWall25()
{
	this->wall25.setPosition(5000, -2200);
	this->wall25.setSize(Vector2f(100.f, 500.f));
	this->wall25.setScale(Vector2f(0.5f, 0.5f));
	this->wall25.setFillColor(Color::Green);
	this->wall25.setOutlineColor(Color::Black);
	this->wall25.setOutlineThickness(1.f);
}

void Level2::initWall26()
{
	this->wall26.setPosition(5200, -2000);
	this->wall26.setSize(Vector2f(100.f, 500.f));
	this->wall26.setScale(Vector2f(0.5f, 0.5f));
	this->wall26.setFillColor(Color::Green);
	this->wall26.setOutlineColor(Color::Black);
	this->wall26.setOutlineThickness(1.f);
}

void Level2::initWall27()
{
	this->wall27.setPosition(5000, -2200);
	this->wall27.setSize(Vector2f(3400.f, 100.f));
	this->wall27.setScale(Vector2f(0.5f, 0.5f));
	this->wall27.setFillColor(Color::Green);
	this->wall27.setOutlineColor(Color::Black);
	this->wall27.setOutlineThickness(1.f);
}

void Level2::initWall28()
{
	this->wall28.setPosition(5200, -2000);
	this->wall28.setSize(Vector2f(3400.f, 100.f));
	this->wall28.setScale(Vector2f(0.5f, 0.5f));
	this->wall28.setFillColor(Color::Green);
	this->wall28.setOutlineColor(Color::Black);
	this->wall28.setOutlineThickness(1.f);
}	

//1st copy paste

void Level2::initWall29()
{
	this->wall29.setPosition(6700, -2400);
	this->wall29.setSize(Vector2f(100.f, 500.f));
	this->wall29.setScale(Vector2f(0.5f, 0.5f));
	this->wall29.setFillColor(Color::Green);
	this->wall29.setOutlineColor(Color::Black);
	this->wall29.setOutlineThickness(1.f);
}

void Level2::initWall30()
{
	this->wall30.setPosition(6900, -2200);
	this->wall30.setSize(Vector2f(100.f, 500.f));
	this->wall30.setScale(Vector2f(0.5f, 0.5f));
	this->wall30.setFillColor(Color::Green);
	this->wall30.setOutlineColor(Color::Black);
	this->wall30.setOutlineThickness(1.f);
}

void Level2::initWall31()
{
	this->wall31.setPosition(6700, -2400);
	this->wall31.setSize(Vector2f(400.f, 100.f));
	this->wall31.setScale(Vector2f(0.5f, 0.5f));
	this->wall31.setFillColor(Color::Green);
	this->wall31.setOutlineColor(Color::Black);
	this->wall31.setOutlineThickness(1.f);
}

void Level2::initWall32()
{
	this->wall32.setPosition(6900, -2200);
	this->wall32.setSize(Vector2f(400.f, 100.f));
	this->wall32.setScale(Vector2f(0.5f, 0.5f));
	this->wall32.setFillColor(Color::Green);
	this->wall32.setOutlineColor(Color::Black);
	this->wall32.setOutlineThickness(1.f);
}

void Level2::initWall33()
{
	this->wall33.setPosition(6900, -2800);
	this->wall33.setSize(Vector2f(100.f, 900.f));
	this->wall33.setScale(Vector2f(0.5f, 0.5f));
	this->wall33.setFillColor(Color::Green);
	this->wall33.setOutlineColor(Color::Black);
	this->wall33.setOutlineThickness(1.f);
}


void Level2::initWall34()
{
	this->wall34.setPosition(7100, -2600);
	this->wall34.setSize(Vector2f(100.f, 900.f));
	this->wall34.setScale(Vector2f(0.5f, 0.5f));
	this->wall34.setFillColor(Color::Green);
	this->wall34.setOutlineColor(Color::Black);
	this->wall34.setOutlineThickness(1.f);
}

void Level2::initWall35()
{
	this->wall35.setPosition(6900, -2800);
	this->wall35.setSize(Vector2f(600.f, 100.f));
	this->wall35.setScale(Vector2f(0.5f, 0.5f));
	this->wall35.setFillColor(Color::Green);
	this->wall35.setOutlineColor(Color::Black);
	this->wall35.setOutlineThickness(1.f);
}

void Level2::initWall36()
{
	this->wall36.setPosition(7100, -2600);
	this->wall36.setSize(Vector2f(600.f, 100.f));
	this->wall36.setScale(Vector2f(0.5f, 0.5f));
	this->wall36.setFillColor(Color::Green);
	this->wall36.setOutlineColor(Color::Black);
	this->wall36.setOutlineThickness(1.f);
}

void Level2::initWall37()
{
	this->wall37.setPosition(7200, -3300);
	this->wall37.setSize(Vector2f(100.f, 1100.f));
	this->wall37.setScale(Vector2f(0.5f, 0.5f));
	this->wall37.setFillColor(Color::Green);
	this->wall37.setOutlineColor(Color::Black);
	this->wall37.setOutlineThickness(1.f);
}

void Level2::initWall38()
{
	this->wall38.setPosition(7400, -3100);
	this->wall38.setSize(Vector2f(100.f, 1100.f));
	this->wall38.setScale(Vector2f(0.5f, 0.5f));
	this->wall38.setFillColor(Color::Green);
	this->wall38.setOutlineColor(Color::Black);
	this->wall38.setOutlineThickness(1.f);
}


void Level2::initWall39()
{
	this->wall39.setPosition(7200, -3300);
	this->wall39.setSize(Vector2f(400.f, 100.f));
	this->wall39.setScale(Vector2f(0.5f, 0.5f));
	this->wall39.setFillColor(Color::Green);
	this->wall39.setOutlineColor(Color::Black);
	this->wall39.setOutlineThickness(1.f);
}

void Level2::initWall40()
{
	this->wall40.setPosition(7400, -3100);
	this->wall40.setSize(Vector2f(400.f, 100.f));
	this->wall40.setScale(Vector2f(0.5f, 0.5f));
	this->wall40.setFillColor(Color::Green);
	this->wall40.setOutlineColor(Color::Black);
	this->wall40.setOutlineThickness(1.f);
} 

void Level2::initWall41()
{
	this->wall41.setPosition(7400, -4400);
	this->wall41.setSize(Vector2f(100.f, 2300.f));
	this->wall41.setScale(Vector2f(0.5f, 0.5f));
	this->wall41.setFillColor(Color::Green);
	this->wall41.setOutlineColor(Color::Black);
	this->wall41.setOutlineThickness(1.f);
}

void Level2::initWall42()
{
	this->wall42.setPosition(7600, -3800);
	this->wall42.setSize(Vector2f(100.f, 1500.f));
	this->wall42.setScale(Vector2f(0.5f, 0.5f));
	this->wall42.setFillColor(Color::Green);
	this->wall42.setOutlineColor(Color::Black);
	this->wall42.setOutlineThickness(1.f);
}


//2nd upper rejoin wall
void Level2::initWall43()
{
	this->wall43.setPosition(7400, -4400);
	this->wall43.setSize(Vector2f(1600.f, 100.f));
	this->wall43.setScale(Vector2f(0.5f, 0.5f));
	this->wall43.setFillColor(Color::Green);
	this->wall43.setOutlineColor(Color::Black);
	this->wall43.setOutlineThickness(1.f);
}

//2nd separation wall
void Level2::initWall44()
{
	this->wall44.setPosition(7600, -4200);
	this->wall44.setSize(Vector2f(100.f, 300.f));
	this->wall44.setScale(Vector2f(0.5f, 0.5f));
	this->wall44.setFillColor(Color::Green);
	this->wall44.setOutlineColor(Color::Black);
	this->wall44.setOutlineThickness(1.f);
}

void Level2::initWall45()
{
	this->wall45.setPosition(7600, -4200);
	this->wall45.setSize(Vector2f(400.f, 100.f));
	this->wall45.setScale(Vector2f(0.5f, 0.5f));
	this->wall45.setFillColor(Color::Green);
	this->wall45.setOutlineColor(Color::Black);
	this->wall45.setOutlineThickness(1.f);
}

//2nd lower wall
void Level2::initWall46()
{
	this->wall46.setPosition(7600, -3800);
	this->wall46.setSize(Vector2f(400.f, 100.f));
	this->wall46.setScale(Vector2f(0.5f, 0.5f));
	this->wall46.setFillColor(Color::Green);
	this->wall46.setOutlineColor(Color::Black);
	this->wall46.setOutlineThickness(1.f);
}

void Level2::initWall47()
{
	this->wall47.setPosition(7800, -4000);
	this->wall47.setSize(Vector2f(100.f, 500.f));
	this->wall47.setScale(Vector2f(0.5f, 0.5f));
	this->wall47.setFillColor(Color::Green);
	this->wall47.setOutlineColor(Color::Black);
	this->wall47.setOutlineThickness(1.f);
}

void Level2::initWall48()
{
	this->wall48.setPosition(7800, -4000);
	this->wall48.setSize(Vector2f(400.f, 100.f));
	this->wall48.setScale(Vector2f(0.5f, 0.5f));
	this->wall48.setFillColor(Color::Green);
	this->wall48.setOutlineColor(Color::Black);
	this->wall48.setOutlineThickness(1.f);
}


void Level2::initWall49()
{
	this->wall49.setPosition(8000, -4200);
	this->wall49.setSize(Vector2f(100.f, 500.f));
	this->wall49.setScale(Vector2f(0.5f, 0.5f));
	this->wall49.setFillColor(Color::Green);
	this->wall49.setOutlineColor(Color::Black);
	this->wall49.setOutlineThickness(1.f);
}

//2nd lower rejoin wall
void Level2::initWall50()
{
	this->wall50.setPosition(8000, -4200);
	this->wall50.setSize(Vector2f(800.f, 100.f));
	this->wall50.setScale(Vector2f(0.5f, 0.5f));
	this->wall50.setFillColor(Color::Green);
	this->wall50.setOutlineColor(Color::Black);
	this->wall50.setOutlineThickness(1.f);
}

void Level2::initWall51()
{
	this->wall51.setPosition(8200, -4600);
	this->wall51.setSize(Vector2f(100.f, 500.f));
	this->wall51.setScale(Vector2f(0.5f, 0.5f));
	this->wall51.setFillColor(Color::Green);
	this->wall51.setOutlineColor(Color::Black);
	this->wall51.setOutlineThickness(1.f);
}

void Level2::initWall52()
{
	this->wall52.setPosition(8400, -4400);
	this->wall52.setSize(Vector2f(100.f, 500.f));
	this->wall52.setScale(Vector2f(0.5f, 0.5f));
	this->wall52.setFillColor(Color::Green);
	this->wall52.setOutlineColor(Color::Black);
	this->wall52.setOutlineThickness(1.f);
}

void Level2::initWall53()
{
	this->wall53.setPosition(8200, -4600);
	this->wall53.setSize(Vector2f(3000.f, 100.f));
	this->wall53.setScale(Vector2f(0.5f, 0.5f));
	this->wall53.setFillColor(Color::Green);
	this->wall53.setOutlineColor(Color::Black);
	this->wall53.setOutlineThickness(1.f);
}

void Level2::initWall54()
{
	this->wall54.setPosition(8400, -4400);
	this->wall54.setSize(Vector2f(3000.f, 100.f));
	this->wall54.setScale(Vector2f(0.5f, 0.5f));
	this->wall54.setFillColor(Color::Green);
	this->wall54.setOutlineColor(Color::Black);
	this->wall54.setOutlineThickness(1.f);
} 

//3rd copy paste

void Level2::initWall55()
{
	this->wall55.setPosition(9700, -5000);
	this->wall55.setSize(Vector2f(100.f, 900.f));
	this->wall55.setScale(Vector2f(0.5f, 0.5f));
	this->wall55.setFillColor(Color::Green);
	this->wall55 .setOutlineColor(Color::Black);
	this->wall55.setOutlineThickness(1.f);
}


void Level2::initWall56()
{
	this->wall56.setPosition(9900, -4800);
	this->wall56.setSize(Vector2f(100.f, 900.f));
	this->wall56.setScale(Vector2f(0.5f, 0.5f));
	this->wall56.setFillColor(Color::Green);
	this->wall56.setOutlineColor(Color::Black);
	this->wall56.setOutlineThickness(1.f);
}

void Level2::initWall57()
{
	this->wall57.setPosition(9700, -5000);
	this->wall57.setSize(Vector2f(600.f, 100.f));
	this->wall57.setScale(Vector2f(0.5f, 0.5f));
	this->wall57.setFillColor(Color::Green);
	this->wall57.setOutlineColor(Color::Black);
	this->wall57.setOutlineThickness(1.f);
}

void Level2::initWall58()
{
	this->wall58.setPosition(9900, -4800);
	this->wall58.setSize(Vector2f(600.f, 100.f));
	this->wall58.setScale(Vector2f(0.5f, 0.5f));
	this->wall58.setFillColor(Color::Green);
	this->wall58.setOutlineColor(Color::Black);
	this->wall58.setOutlineThickness(1.f);
}


void Level2::initWall59()
{
	this->wall59.setPosition(10000, -5500);
	this->wall59.setSize(Vector2f(100.f, 1100.f));
	this->wall59.setScale(Vector2f(0.5f, 0.5f));
	this->wall59.setFillColor(Color::Green);
	this->wall59.setOutlineColor(Color::Black);
	this->wall59.setOutlineThickness(1.f);
}

void Level2::initWall60()
{
	this->wall60.setPosition(10200, -5300);
	this->wall60.setSize(Vector2f(100.f, 1100.f));
	this->wall60.setScale(Vector2f(0.5f, 0.5f));
	this->wall60.setFillColor(Color::Green);
	this->wall60.setOutlineColor(Color::Black);
	this->wall60.setOutlineThickness(1.f);
}

void Level2::initWall61()
{
	this->wall61.setPosition(10000, -5500);
	this->wall61.setSize(Vector2f(400.f, 100.f));
	this->wall61.setScale(Vector2f(0.5f, 0.5f));
	this->wall61.setFillColor(Color::Green);
	this->wall61.setOutlineColor(Color::Black);
	this->wall61.setOutlineThickness(1.f);
}

void Level2::initWall62()
{
	this->wall62.setPosition(10200, -5300);
	this->wall62.setSize(Vector2f(400.f, 100.f));
	this->wall62.setScale(Vector2f(0.5f, 0.5f));
	this->wall62.setFillColor(Color::Green);
	this->wall62.setOutlineColor(Color::Black);
	this->wall62.setOutlineThickness(1.f);
}

void Level2::initWall63()
{
	this->wall63.setPosition(10200, -6600);
	this->wall63.setSize(Vector2f(100.f, 2300.f));
	this->wall63.setScale(Vector2f(0.5f, 0.5f));
	this->wall63.setFillColor(Color::Green);
	this->wall63.setOutlineColor(Color::Black);
	this->wall63.setOutlineThickness(1.f);
}

void Level2::initWall64()
{
	this->wall64.setPosition(10400, -6000);
	this->wall64.setSize(Vector2f(100.f, 1500.f));
	this->wall64.setScale(Vector2f(0.5f, 0.5f));
	this->wall64.setFillColor(Color::Green);
	this->wall64.setOutlineColor(Color::Black);
	this->wall64.setOutlineThickness(1.f);
}


//3rd upper rejoin wall
void Level2::initWall65()
{
	this->wall65.setPosition(10200, -6600);
	this->wall65.setSize(Vector2f(1600.f, 100.f));
	this->wall65.setScale(Vector2f(0.5f, 0.5f));
	this->wall65.setFillColor(Color::Green);
	this->wall65.setOutlineColor(Color::Black);
	this->wall65.setOutlineThickness(1.f);
}

//3rd separation wall
void Level2::initWall66()
{
	this->wall66.setPosition(10400, -6400);
	this->wall66.setSize(Vector2f(100.f, 300.f));
	this->wall66.setScale(Vector2f(0.5f, 0.5f));
	this->wall66.setFillColor(Color::Green);
	this->wall66.setOutlineColor(Color::Black);
	this->wall66.setOutlineThickness(1.f);
}

void Level2::initWall67()
{
	this->wall67.setPosition(10400, -6400);
	this->wall67.setSize(Vector2f(400.f, 100.f));
	this->wall67.setScale(Vector2f(0.5f, 0.5f));
	this->wall67.setFillColor(Color::Green);
	this->wall67.setOutlineColor(Color::Black);
	this->wall67.setOutlineThickness(1.f);
}

//3rd lower wall
void Level2::initWall68()
{
	this->wall68.setPosition(10400, -6000);
	this->wall68.setSize(Vector2f(400.f, 100.f));
	this->wall68.setScale(Vector2f(0.5f, 0.5f));
	this->wall68.setFillColor(Color::Green);
	this->wall68.setOutlineColor(Color::Black);
	this->wall68.setOutlineThickness(1.f);
}

void Level2::initWall69()
{
	this->wall69.setPosition(10600, -6200);
	this->wall69.setSize(Vector2f(100.f, 500.f));
	this->wall69.setScale(Vector2f(0.5f, 0.5f));
	this->wall69.setFillColor(Color::Green);
	this->wall69.setOutlineColor(Color::Black);
	this->wall69.setOutlineThickness(1.f);
}

void Level2::initWall70()
{
	this->wall70.setPosition(10600, -6200);
	this->wall70.setSize(Vector2f(400.f, 100.f));
	this->wall70.setScale(Vector2f(0.5f, 0.5f));
	this->wall70.setFillColor(Color::Green);
	this->wall70.setOutlineColor(Color::Black);
	this->wall70.setOutlineThickness(1.f);
}


void Level2::initWall71()
{
	this->wall71.setPosition(10800, -6400);
	this->wall71.setSize(Vector2f(100.f, 500.f));
	this->wall71.setScale(Vector2f(0.5f, 0.5f));
	this->wall71.setFillColor(Color::Green);
	this->wall71.setOutlineColor(Color::Black);
	this->wall71.setOutlineThickness(1.f);
}

//3rd lower rejoin wall
void Level2::initWall72()
{
	this->wall72.setPosition(10800, -6400);
	this->wall72.setSize(Vector2f(800.f, 100.f));
	this->wall72.setScale(Vector2f(0.5f, 0.5f));
	this->wall72.setFillColor(Color::Green);
	this->wall72.setOutlineColor(Color::Black);
	this->wall72.setOutlineThickness(1.f);
}

void Level2::initWall73()
{
	this->wall73.setPosition(11000, -6800);
	this->wall73.setSize(Vector2f(100.f, 500.f));
	this->wall73.setScale(Vector2f(0.5f, 0.5f));
	this->wall73.setFillColor(Color::Green);
	this->wall73.setOutlineColor(Color::Black);
	this->wall73.setOutlineThickness(1.f);
}

void Level2::initWall74()
{
	this->wall74.setPosition(11200, -6600);
	this->wall74.setSize(Vector2f(100.f, 500.f));
	this->wall74.setScale(Vector2f(0.5f, 0.5f));
	this->wall74.setFillColor(Color::Green);
	this->wall74.setOutlineColor(Color::Black);
	this->wall74.setOutlineThickness(1.f);
}

void Level2::initWall75()
{
	this->wall75.setPosition(11000, -6800);
	this->wall75.setSize(Vector2f(3400.f, 100.f));
	this->wall75.setScale(Vector2f(0.5f, 0.5f));
	this->wall75.setFillColor(Color::Green);
	this->wall75.setOutlineColor(Color::Black);
	this->wall75.setOutlineThickness(1.f);
}

void Level2::initWall76()
{
	this->wall76.setPosition(11200, -6600);
	this->wall76.setSize(Vector2f(3400.f, 100.f));
	this->wall76.setScale(Vector2f(0.5f, 0.5f));
	this->wall76.setFillColor(Color::Green);
	this->wall76.setOutlineColor(Color::Black);
	this->wall76.setOutlineThickness(1.f);
}

void Level2::initWall77()
{
	this->wall77.setPosition(12700, -7000);
	this->wall77.setSize(Vector2f(100.f, 500.f));
	this->wall77.setScale(Vector2f(0.5f, 0.5f));
	this->wall77.setFillColor(Color::Green);
	this->wall77.setOutlineColor(Color::Black);
	this->wall77.setOutlineThickness(1.f);
}

void Level2::initWall78()
{
	this->wall78.setPosition(12900, -6800);
	this->wall78.setSize(Vector2f(100.f, 500.f));
	this->wall78.setScale(Vector2f(0.5f, 0.5f));
	this->wall78.setFillColor(Color::Green);
	this->wall78.setOutlineColor(Color::Black);
	this->wall78.setOutlineThickness(1.f);
}

void Level2::initWall79()
{
	this->wall79.setPosition(12700, -7000);
	this->wall79.setSize(Vector2f(400.f, 100.f));
	this->wall79.setScale(Vector2f(0.5f, 0.5f));
	this->wall79.setFillColor(Color::Green);
	this->wall79.setOutlineColor(Color::Black);
	this->wall79.setOutlineThickness(1.f);
}

void Level2::initWall80()
{
	this->wall80.setPosition(12900, -6800);
	this->wall80.setSize(Vector2f(400.f, 100.f));
	this->wall80.setScale(Vector2f(0.5f, 0.5f));
	this->wall80.setFillColor(Color::Green);
	this->wall80.setOutlineColor(Color::Black);
	this->wall80.setOutlineThickness(1.f);
}

void Level2::initWall81()
{
	this->wall81.setPosition(12900, -7300);
	this->wall81.setSize(Vector2f(100.f, 700.f));
	this->wall81.setScale(Vector2f(0.5f, 0.5f));
	this->wall81.setFillColor(Color::Green);
	this->wall81.setOutlineColor(Color::Black);
	this->wall81.setOutlineThickness(1.f);
}

void Level2::initWall82()
{
	this->wall82.setPosition(13100, -7100);
	this->wall82.setSize(Vector2f(100.f, 700.f));
	this->wall82.setScale(Vector2f(0.5f, 0.5f));
	this->wall82.setFillColor(Color::Green);
	this->wall82.setOutlineColor(Color::Black);
	this->wall82.setOutlineThickness(1.f);
}

void Level2::initWall83()
{
	this->wall83.setPosition(12900, -7300);
	this->wall83.setSize(Vector2f(600.f, 100.f));
	this->wall83.setScale(Vector2f(0.5f, 0.5f));
	this->wall83.setFillColor(Color::Green);
	this->wall83.setOutlineColor(Color::Black);
	this->wall83.setOutlineThickness(1.f);
}

void Level2::initWall84()
{
	this->wall84.setPosition(13100, -7100);
	this->wall84.setSize(Vector2f(600.f, 100.f));
	this->wall84.setScale(Vector2f(0.5f, 0.5f));
	this->wall84.setFillColor(Color::Green);
	this->wall84.setOutlineColor(Color::Black);
	this->wall84.setOutlineThickness(1.f);
}

void Level2::initWall85()
{
	this->wall85.setPosition(13200, -7500);
	this->wall85.setSize(Vector2f(100.f, 500.f));
	this->wall85.setScale(Vector2f(0.5f, 0.5f));
	this->wall85.setFillColor(Color::Green);
	this->wall85.setOutlineColor(Color::Black);
	this->wall85.setOutlineThickness(1.f);
}

void Level2::initWall86()
{
	this->wall86.setPosition(13400, -7300);
	this->wall86.setSize(Vector2f(100.f, 500.f));
	this->wall86.setScale(Vector2f(0.5f, 0.5f));
	this->wall86.setFillColor(Color::Green);
	this->wall86.setOutlineColor(Color::Black);
	this->wall86.setOutlineThickness(1.f);
}

void Level2::initWall87()
{
	this->wall87.setPosition(13200, -7500);
	this->wall87.setSize(Vector2f(400.f, 100.f));
	this->wall87.setScale(Vector2f(0.5f, 0.5f));
	this->wall87.setFillColor(Color::Green);
	this->wall87.setOutlineColor(Color::Black);
	this->wall87.setOutlineThickness(1.f);
}

void Level2::initWall88()
{
	this->wall88.setPosition(13400, -7300);
	this->wall88.setSize(Vector2f(400.f, 100.f));
	this->wall88.setScale(Vector2f(0.5f, 0.5f));
	this->wall88.setFillColor(Color::Green);
	this->wall88.setOutlineColor(Color::Black);
	this->wall88.setOutlineThickness(1.f);
}

void Level2::initWall89()
{
	this->wall89.setPosition(13400, -7700);
	this->wall89.setSize(Vector2f(100.f, 500.f));
	this->wall89.setScale(Vector2f(0.5f, 0.5f));
	this->wall89.setFillColor(Color::Green);
	this->wall89.setOutlineColor(Color::Black);
	this->wall89.setOutlineThickness(1.f);
}

void Level2::initWall90()
{
	this->wall90.setPosition(13600, -7500);
	this->wall90.setSize(Vector2f(100.f, 500.f));
	this->wall90.setScale(Vector2f(0.5f, 0.5f));
	this->wall90.setFillColor(Color::Green);
	this->wall90.setOutlineColor(Color::Black);
	this->wall90.setOutlineThickness(1.f);
}

void Level2::initWall91()
{
	this->wall91.setPosition(13400, -7700);
	this->wall91.setSize(Vector2f(400.f, 100.f));
	this->wall91.setScale(Vector2f(0.5f, 0.5f));
	this->wall91.setFillColor(Color::Green);
	this->wall91.setOutlineColor(Color::Black);
	this->wall91.setOutlineThickness(1.f);
}

void Level2::initWall92()
{
	this->wall92.setPosition(13600, -7500);
	this->wall92.setSize(Vector2f(400.f, 100.f));
	this->wall92.setScale(Vector2f(0.5f, 0.5f));
	this->wall92.setFillColor(Color::Green);
	this->wall92.setOutlineColor(Color::Black);
	this->wall92.setOutlineThickness(1.f);
}

void Level2::initWall93()
{
	this->wall93.setPosition(13600, -8000);
	this->wall93.setSize(Vector2f(100.f, 700.f));
	this->wall93.setScale(Vector2f(0.5f, 0.5f));
	this->wall93.setFillColor(Color::Green);
	this->wall93.setOutlineColor(Color::Black);
	this->wall93.setOutlineThickness(1.f);
}

void Level2::initWall94()
{
	this->wall94.setPosition(13800, -7800);
	this->wall94.setSize(Vector2f(100.f, 700.f));
	this->wall94.setScale(Vector2f(0.5f, 0.5f));
	this->wall94.setFillColor(Color::Green);
	this->wall94.setOutlineColor(Color::Black);
	this->wall94.setOutlineThickness(1.f);
}

void Level2::initWall95()
{
	this->wall95.setPosition(13600, -8000);
	this->wall95.setSize(Vector2f(600.f, 100.f));
	this->wall95.setScale(Vector2f(0.5f, 0.5f));
	this->wall95.setFillColor(Color::Green);
	this->wall95.setOutlineColor(Color::Black);
	this->wall95.setOutlineThickness(1.f);
}

void Level2::initWall96()
{
	this->wall96.setPosition(13800, -7800);
	this->wall96.setSize(Vector2f(600.f, 100.f));
	this->wall96.setScale(Vector2f(0.5f, 0.5f));
	this->wall96.setFillColor(Color::Green);
	this->wall96.setOutlineColor(Color::Black);
	this->wall96.setOutlineThickness(1.f);
}

void Level2::initWall97()
{
	this->wall97.setPosition(13900, -8200);
	this->wall97.setSize(Vector2f(100.f, 500.f));
	this->wall97.setScale(Vector2f(0.5f, 0.5f));
	this->wall97.setFillColor(Color::Green);
	this->wall97.setOutlineColor(Color::Black);
	this->wall97.setOutlineThickness(1.f);
}

void Level2::initWall98()
{
	this->wall98.setPosition(14100, -8000);
	this->wall98.setSize(Vector2f(100.f, 500.f));
	this->wall98.setScale(Vector2f(0.5f, 0.5f));
	this->wall98.setFillColor(Color::Green);
	this->wall98.setOutlineColor(Color::Black);
	this->wall98.setOutlineThickness(1.f);
}

void Level2::initWall99()
{
	this->wall99.setPosition(13900, -8200);
	this->wall99.setSize(Vector2f(400.f, 100.f));
	this->wall99.setScale(Vector2f(0.5f, 0.5f));
	this->wall99.setFillColor(Color::Green);
	this->wall99.setOutlineColor(Color::Black);
	this->wall99.setOutlineThickness(1.f);
}

void Level2::initWall100()
{
	this->wall100.setPosition(14100, -8000);
	this->wall100.setSize(Vector2f(400.f, 100.f));
	this->wall100.setScale(Vector2f(0.5f, 0.5f));
	this->wall100.setFillColor(Color::Green);
	this->wall100.setOutlineColor(Color::Black);
	this->wall100.setOutlineThickness(1.f);
}

void Level2::initWall101()
{
	this->wall101.setPosition(14100, -8500);
	this->wall101.setSize(Vector2f(100.f, 700.f));
	this->wall101.setScale(Vector2f(0.5f, 0.5f));
	this->wall101.setFillColor(Color::Green);
	this->wall101.setOutlineColor(Color::Black);
	this->wall101.setOutlineThickness(1.f);
}

void Level2::initWall102()
{
	this->wall102.setPosition(14300, -8300);
	this->wall102.setSize(Vector2f(100.f, 700.f));
	this->wall102.setScale(Vector2f(0.5f, 0.5f));
	this->wall102.setFillColor(Color::Green);
	this->wall102.setOutlineColor(Color::Black);
	this->wall102.setOutlineThickness(1.f);
}

void Level2::initWall103()
{
	this->wall103.setPosition(14100, -8500);
	this->wall103.setSize(Vector2f(13600.f, 100.f));
	this->wall103.setScale(Vector2f(0.5f, 0.5f));
	this->wall103.setFillColor(Color::Green);
	this->wall103.setOutlineColor(Color::Black);
	this->wall103.setOutlineThickness(1.f);
}

void Level2::initWall104()
{
	this->wall104.setPosition(14300, -8300);
	this->wall104.setSize(Vector2f(13200.f, 100.f));
	this->wall104.setScale(Vector2f(0.5f, 0.5f));
	this->wall104.setFillColor(Color::Green);
	this->wall104.setOutlineColor(Color::Black);
	this->wall104.setOutlineThickness(1.f);
}