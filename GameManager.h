#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Place.h"
#include "Bonus.h"
#include "Chances.h"
#include "Estate.h"
#include "Fates.h"
#include "Taxes.h"
#include "Position.h"
#include "House.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <easyx.h>
#include <graphics.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define PLAYERFILE "playerFile.txt"
#define HOUSEFILE "houseFile.txt" 
#define ROLLFILE "rollingFile.txt"

class GameManager
{
public:
	GameManager(); // 构造函数
	void loadDiceImages(); // 展示骰子图片
	void drawDice(int x, int y, int value); // 绘制骰子图片
	int rollDice(); // 随机掷骰子，返回结果
	void showDice(int value); // 展示骰子
	void addInformation(); // 补充信息
	void savePlayer(); //利用文本文件保存玩家信息
	void saveEstates(); //利用文本文件保存房产信息
	void saveRoll(int value); //利用文本文件保存玩家投骰子顺序
	int getPlayerNumber();
	int getEstateNumber();
	void initializePlayer(int numberOfPlayers); //初始化玩家
	void initializePlace(); //初始化地点
	void playGames(int numberOfPlayers); // 进入游戏
	void endGame(int numberOfPlayers); // 结束游戏
	void cleanFileOfPlayer();//清除玩家的游戏存档
	void cleanFileOfEstates();//清除房产的所有存档
	void cleanFileOfRoller(); //清除第几名玩家游玩的信息
	IMAGE dice[6];
	vector <Player> playerArray;
	vector <Place*> placeArray;
	bool PlayerFileIsEmpty;
	bool PlacesFileIsEmpty;
	int roller; //用于保存当前时低级名玩家投骰子
	~GameManager(); // 析构函数
};

#endif