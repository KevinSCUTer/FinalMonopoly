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
	GameManager(); // ���캯��
	void loadDiceImages(); // չʾ����ͼƬ
	void drawDice(int x, int y, int value); // ��������ͼƬ
	int rollDice(); // ��������ӣ����ؽ��
	void showDice(int value); // չʾ����
	void addInformation(); // ������Ϣ
	void savePlayer(); //�����ı��ļ����������Ϣ
	void saveEstates(); //�����ı��ļ����淿����Ϣ
	void saveRoll(int value); //�����ı��ļ��������Ͷ����˳��
	int getPlayerNumber();
	int getEstateNumber();
	void initializePlayer(int numberOfPlayers); //��ʼ�����
	void initializePlace(); //��ʼ���ص�
	void playGames(int numberOfPlayers); // ������Ϸ
	void endGame(int numberOfPlayers); // ������Ϸ
	void cleanFileOfPlayer();//�����ҵ���Ϸ�浵
	void cleanFileOfEstates();//������������д浵
	void cleanFileOfRoller(); //����ڼ�������������Ϣ
	IMAGE dice[6];
	vector <Player> playerArray;
	vector <Place*> placeArray;
	bool PlayerFileIsEmpty;
	bool PlacesFileIsEmpty;
	int roller; //���ڱ��浱ǰʱ�ͼ������Ͷ����
	~GameManager(); // ��������
};

#endif