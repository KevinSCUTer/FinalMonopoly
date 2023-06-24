#include <iostream>
#include <cstdio>
#include <easyx.h>
#include <graphics.h>
#include <vector>
#include "GameManager.h"
#include "Position.h"
#include "Player.h"
using namespace std;

#define NUMBERFILE "numberOfPlayers.txt"

void button(int x, int y, int w, int h, string information); // ��ť

void showMenu(); // չʾ��ϷĿ¼
void showRules(); // չʾ��Ϸ����
void saveNumberOfPlayers(); // �����������
void cleanNumberOfPlayers(); // ����ļ�
void chooseNumberOfPlayers(); // ѡ����������

int numberOfPlayers = 0;

int main()
{
	bool playgame = false;
	bool chooseNumber = false;

	showMenu();

	ExMessage msg;  //EasyX�Դ������������ַ����������̲��������ڲ����Ľṹ��
	
	while (!chooseNumber)
	{
		if (peekmessage(&msg, EM_MOUSE)) // ����������Ϣ�����棬���򷵻ؼ�
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if (msg.x >= 330 && msg.x <= 830 && msg.y >= 200 && msg.y <= 300)
				{
					showRules();
				}
				else if (msg.x >= 330 && msg.x <= 830 && msg.y >= 350 && msg.y <= 450)
				{
					ofstream ofsPlayer(PLAYERFILE, ios::trunc);
					ofsPlayer.flush();
					ofsPlayer.close();
					ofstream ofsEstate(HOUSEFILE, ios::trunc);
					ofsEstate.flush();
					ofsEstate.close();
					ofstream ofsRoll(ROLLFILE, ios::trunc);
					ofsRoll.flush();
					ofsRoll.close();
					chooseNumberOfPlayers();
					chooseNumber = true;
				}
				else if (msg.x >= 330 && msg.x <= 830 && msg.y >= 500 && msg.y <= 650)
				{
					chooseNumberOfPlayers();
					chooseNumber = true;
				}
				break;
			}

			default:
				break;
			}
		}
	}
	
	while (chooseNumber && !playgame)
	{
		if (peekmessage(&msg, EM_MOUSE)) // ����������Ϣ�����棬���򷵻ؼ�
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if (msg.x >= 330 && msg.x <= 830 && msg.y >= 200 && msg.y <= 300)
				{
					numberOfPlayers = 2;
					playgame = true;
				}
				else if (msg.x >= 330 && msg.x <= 830 && msg.y >= 350 && msg.y <= 450)
				{
					numberOfPlayers = 3;
					playgame = true;
				}
				else if (msg.x >= 330 && msg.x <= 830 && msg.y >= 500 && msg.y <= 650)
				{
					numberOfPlayers = 4;
					playgame = true;
				}
				break;
			}

			default:
				break;
			}
		}
	}

	GameManager gamemanager;

	if (playgame)
	{
		gamemanager.playGames(numberOfPlayers);
	}
	
	closegraph();

	return 0;
}


void button(int x, int y, int w, int h, string information)
{
	setbkmode(TRANSPARENT);
	setfillcolor(YELLOW); // �ú�ɫ���
	fillroundrect(x, y, x + w, y + h, 10, 10); //��������Բ�Ǿ���

	settextstyle(50, 0, "����");

	int tx = x + (w - textwidth(information.c_str())) / 2;
	int ty = y + (h - textheight(information.c_str())) / 2;

	outtextxy(tx, ty, information.c_str());
}

void showMenu()
{
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //���ñ�����ɫΪ��ɫ
	cleardevice(); //����

	//��������
	//����������ɫ
	settextcolor(RED);
	settextstyle(100, 0, "Arial Black");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	string WelcomeArray = "Welcome to Monopoly!";
	outtextxy(150, 50, WelcomeArray.c_str());

	button(330, 200, 500, 100, "��  Ϸ  ��  ��");
	button(330, 350, 500, 100, "ȫ  ��  ��  Ϸ");
	button(330, 500, 500, 100, "��  ��  ��  Ϸ");

	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	string ExitGame = "������Ͻ�X�������˳���Ϸ";
	outtextxy(800, 700, ExitGame.c_str());
	Sleep(10);

	IMAGE img; //����һ����ͼƬ�����йصĶ���
	loadimage(&img, "./Welcome.jpg", 300, 400);
	putimage(0, 400, &img);
}

void showRules()
{
	closegraph(); //���ԭ�е���Ļ
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //���ñ�����ɫΪ��ɫ
	cleardevice(); //����
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	button(330, 350, 500, 100, "ȫ  ��  ��  Ϸ");
	button(330, 500, 500, 100, "��  ��  ��  Ϸ");
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ

	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	string ExitGame = "������Ͻ�X�������˳���Ϸ";
	outtextxy(800, 700, ExitGame.c_str());

	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(32, 32, 32)); //������ԭɫ�����ı�����ɫ
	outtextxy(0, 0, "1. ��ʼʱÿ�������ʼ�ʽ�3000Ԫ��������������ӣ��ƶ�����");
	outtextxy(0, 50, "2. ͣ���ڿյؿ���ѡ����֧�������");
	outtextxy(0, 100, "3. ͣ�����ѹ���ز���Ҫ֧����·�ѡ���·�Ѽ��㹫ʽΪ������� �����ȼ� + 1���� 20%");
	outtextxy(0, 150, "4. ���췿�ݻ�Ƶ���Ҫ֧��������á�����Ѽ��㹫ʽΪ������� �� �����ȼ���ӦȨ��");
	outtextxy(0, 200, "5. ���ʽ�Ϊ0���޷�֧����·�ѻ������ʱ�������ж��Ʋ�����ʱ���ʽ������˻�ʤ��");
	outtextxy(0, 250, "6. ��Ϸ�л���һЩ����飬��Ҫ��ȡ��Ӧ�����˻���ῨƬ");
	outtextxy(0, 300, "7. ÿ�غ����ֻ�ܽ���һ�����ݻ�����һ��ز�");
}

void saveNumberOfPlayers()
{
	ofstream ofsNumber;
	ofsNumber.open(PLAYERFILE, ios::in);
	ofsNumber << numberOfPlayers;
	
}

void cleanNumberOfPlayers()
{
	ofstream ofsNumbers(NUMBERFILE, ios::trunc);
	ofsNumbers.flush();
	ofsNumbers.close();
}

void chooseNumberOfPlayers()
{
	closegraph(); //���ԭ�е���Ļ
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //���ñ�����ɫΪ��ɫ
	cleardevice(); //����
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	button(330, 200, 500, 100, "˫  ��  ��  Ϸ");
	button(330, 350, 500, 100, "��  ��  ��  Ϸ");
	button(330, 500, 500, 100, "��  ��  ��  Ϸ");
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ

	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //������ԭɫ�����ı�����ɫ
	string ExitGame = "������Ͻ�X�������˳���Ϸ";
	outtextxy(800, 700, ExitGame.c_str());
}