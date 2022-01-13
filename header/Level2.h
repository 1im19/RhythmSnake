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

class Level2
{
private:
	//Variables

	int timer5;
	int maxtimer;
	int collecteddiamonds;
	int maxdiamonds;
	int progress;
	int collectedcoins;

	int savedprogress;
	int saveddiamonds;
	int savedcoins;
	int unlocked;

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
	RectangleShape diamond3;
	int timer2;
	int timer3;
	int timer4;

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
	RectangleShape wall61;
	RectangleShape wall62;
	RectangleShape wall63;
	RectangleShape wall64;
	RectangleShape wall65;
	RectangleShape wall66;
	RectangleShape wall67;
	RectangleShape wall68;
	RectangleShape wall69;
	RectangleShape wall70;
	RectangleShape wall71;
	RectangleShape wall72;
	RectangleShape wall73;
	RectangleShape wall74;
	RectangleShape wall75;
	RectangleShape wall76;
	RectangleShape wall77;
	RectangleShape wall78;
	RectangleShape wall79;
	RectangleShape wall80;
	RectangleShape wall81;
	RectangleShape wall82;
	RectangleShape wall83;
	RectangleShape wall84;
	RectangleShape wall85;
	RectangleShape wall86;
	RectangleShape wall87;
	RectangleShape wall88;
	RectangleShape wall89;
	RectangleShape wall90;
	RectangleShape wall91;
	RectangleShape wall92;
	RectangleShape wall93;
	RectangleShape wall94;
	RectangleShape wall95;
	RectangleShape wall96;
	RectangleShape wall97;
	RectangleShape wall98;
	RectangleShape wall99;
	RectangleShape wall100;
	RectangleShape wall101;
	RectangleShape wall102;
	RectangleShape wall103;
	RectangleShape wall104;
	RectangleShape wall105;
	RectangleShape wall106;
	RectangleShape wall107;
	RectangleShape wall108;
	RectangleShape wall109;
	RectangleShape wall110;

	//private functions
	void initVariables();
	void initWindow();
	//Collision
	bool collideWalls();
	bool collideDiamond1();
	bool collideDiamond2();
	bool collideDiamond3();
	bool collideFinishLine();
	//player
	void initPlayer();
	//Diamonds
	void initDiamond1();
	void initDiamond2();
	void initDiamond3();
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
	void initWall61();
	void initWall62();
	void initWall63();
	void initWall64();
	void initWall65();
	void initWall66();
	void initWall67();
	void initWall68();
	void initWall69();
	void initWall70();
	void initWall71();
	void initWall72();
	void initWall73();
	void initWall74();
	void initWall75();
	void initWall76();
	void initWall77();
	void initWall78();
	void initWall79();
	void initWall80();
	void initWall81();
	void initWall82();
	void initWall83();
	void initWall84();
	void initWall85();
	void initWall86();
	void initWall87();
	void initWall88();
	void initWall89();
	void initWall90();
	void initWall91();
	void initWall92();
	void initWall93();
	void initWall94();
	void initWall95();
	void initWall96();
	void initWall97();
	void initWall98();
	void initWall99();
	void initWall100();
	void initWall101();
	void initWall102();
	void initWall103();
	void initWall104();
	void initWall105();
	void initWall106();
	void initWall107();
	void initWall108();
	void initWall109();
	void initWall110();

public:
	//Constructor and Destructors
	Level2();
	virtual ~Level2();

	//Accessors
	const bool Running() const;

	//Functions
	void pollEvents();
	void Update();
	void Render();
	void updateInput();
};