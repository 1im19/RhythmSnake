#pragma once

//SFML headers

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

/*
Class that acts like a game engine.
Wrapper class
*/

class Level1
{
private:
	//Variables
	
	int timer4;
	int maxtimer;
	int collecteddiamonds;
	int maxdiamonds;
	int progress;
	int collectedcoins;

	int savedprogress;
	int saveddiamonds;
	int savedcoins;

	//File
	ifstream isavefile1;
	ofstream osavefile1;
	ifstream inventory1;
	ofstream inventory2;

	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	View* view;
	Music* music1;

	//Background
	Sprite levelBackground;
	Texture levelBackgroundTex;

	//Player
	float movementSpeed;
	int keycount;
	int timer1;

	//Game Objects
	//player
	RectangleShape player;

	//Diamonds
	RectangleShape diamond1;
	RectangleShape diamond2;
	int timer2;
	int timer3;

	//Finish Line
	RectangleShape finishline;

	//waaaallllllsssss
	RectangleShape wall1;
	RectangleShape wall2;
	RectangleShape wall3;
	RectangleShape wall4;
	RectangleShape wall5;
	RectangleShape wall6;
	RectangleShape wall7;
	RectangleShape wall8;
	RectangleShape wall9;
	RectangleShape wall10;
	RectangleShape wall11;
	RectangleShape wall12;
	RectangleShape wall13;
	RectangleShape wall14;
	RectangleShape wall15;
	RectangleShape wall16;
	RectangleShape wall17;
	RectangleShape wall18;
	RectangleShape wall19;
	RectangleShape wall20;
	RectangleShape wall21;
	RectangleShape wall22;
	RectangleShape wall23;
	RectangleShape wall24;
	RectangleShape wall25;
	RectangleShape wall26;
	RectangleShape wall27;
	RectangleShape wall28;
	RectangleShape wall29;
	RectangleShape wall30;
	RectangleShape wall31;
	RectangleShape wall32;
	RectangleShape wall33;
	RectangleShape wall34;
	RectangleShape wall35;
	RectangleShape wall36;
	RectangleShape wall37;
	RectangleShape wall38;
	RectangleShape wall39;
	RectangleShape wall40;
	RectangleShape wall41;
	RectangleShape wall42;
	RectangleShape wall43;
	RectangleShape wall44;
	RectangleShape wall45;
	RectangleShape wall46;
	RectangleShape wall47;
	RectangleShape wall48;
	RectangleShape wall49;
	RectangleShape wall50;
	RectangleShape wall51;
	RectangleShape wall52;
	RectangleShape wall53;
	RectangleShape wall54;
	RectangleShape wall55;
	RectangleShape wall56;
	RectangleShape wall57;
	RectangleShape wall58;
	RectangleShape wall59;
	RectangleShape wall60;

	//private functions
	void initVariables();
	void initWindow();
	//Collision
	bool collideWalls();
	bool collideDiamond1();
	bool collideDiamond2();
	bool collideFinishLine();
	//player
	void initPlayer();
	//Diamonds
	void initDiamond1();
	void initDiamond2();
	//FinishLine
	void initFinishLine();
	//Finish
	void FinishLevel();
	//waaalllssss
	void initWall1();
	void initWall2();
	void initWall3();
	void initWall4();
	void initWall5();
	void initWall6();
	void initWall7();
	void initWall8();
	void initWall9();
	void initWall10();
	void initWall11();
	void initWall12();
	void initWall13();
	void initWall14();
	void initWall15();
	void initWall16();
	void initWall17();
	void initWall18();
	void initWall19();
	void initWall20();
	void initWall21();
	void initWall22();
	void initWall23();
	void initWall24();
	void initWall25();
	void initWall26();
	void initWall27();
	void initWall28();
	void initWall29();
	void initWall30();
	void initWall31();
	void initWall32();
	void initWall33();
	void initWall34();
	void initWall35();
	void initWall36();
	void initWall37();
	void initWall38();
	void initWall39();
	void initWall40();
	void initWall41();
	void initWall42();
	void initWall43();
	void initWall44();
	void initWall45();
	void initWall46();
	void initWall47();
	void initWall48(); 
	void initWall49();
	void initWall50();
	void initWall51();
	void initWall52();
	void initWall53();
	void initWall54();
	void initWall55();
	void initWall56();
	void initWall57();
	void initWall58();
	void initWall59();
	void initWall60();

public:
	//Constructor and Destructors
	Level1();
	virtual ~Level1();

	//Accessors
	const bool Running() const;

	//Functions
	void pollEvents();
	void Update();
	void Render();
	void updateInput();
};