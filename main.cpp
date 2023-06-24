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

void button(int x, int y, int w, int h, string information); // 按钮

void showMenu(); // 展示游戏目录
void showRules(); // 展示游戏规则
void saveNumberOfPlayers(); // 保存玩家人数
void cleanNumberOfPlayers(); // 清空文件
void chooseNumberOfPlayers(); // 选择游玩人数

int numberOfPlayers = 0;

int main()
{
	bool playgame = false;
	bool chooseNumber = false;

	showMenu();

	ExMessage msg;  //EasyX自带的鼠标操作，字符操作，键盘操作，窗口操作的结构体
	
	while (!chooseNumber)
	{
		if (peekmessage(&msg, EM_MOUSE)) // 如果有鼠标消息返回真，否则返回假
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
		if (peekmessage(&msg, EM_MOUSE)) // 如果有鼠标消息返回真，否则返回假
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
	setfillcolor(YELLOW); // 用红色填充
	fillroundrect(x, y, x + w, y + h, 10, 10); //绘制填充的圆角矩形

	settextstyle(50, 0, "黑体");

	int tx = x + (w - textwidth(information.c_str())) / 2;
	int ty = y + (h - textheight(information.c_str())) / 2;

	outtextxy(tx, ty, information.c_str());
}

void showMenu()
{
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //设置背景颜色为白色
	cleardevice(); //清屏

	//绘制文字
	//设置文字颜色
	settextcolor(RED);
	settextstyle(100, 0, "Arial Black");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	string WelcomeArray = "Welcome to Monopoly!";
	outtextxy(150, 50, WelcomeArray.c_str());

	button(330, 200, 500, 100, "游  戏  规  则");
	button(330, 350, 500, 100, "全  新  游  戏");
	button(330, 500, 500, 100, "继  续  游  戏");

	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	string ExitGame = "点击右上角X键可以退出游戏";
	outtextxy(800, 700, ExitGame.c_str());
	Sleep(10);

	IMAGE img; //定义一个与图片操作有关的对象
	loadimage(&img, "./Welcome.jpg", 300, 400);
	putimage(0, 400, &img);
}

void showRules()
{
	closegraph(); //清除原有的屏幕
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //设置背景颜色为白色
	cleardevice(); //清屏
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	button(330, 350, 500, 100, "全  新  游  戏");
	button(330, 500, 500, 100, "继  续  游  戏");
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色

	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	string ExitGame = "点击右上角X键可以退出游戏";
	outtextxy(800, 700, ExitGame.c_str());

	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(32, 32, 32)); //利用三原色设置文本的颜色
	outtextxy(0, 0, "1. 开始时每个玩家起始资金3000元。玩家依次掷骰子，移动棋子");
	outtextxy(0, 50, "2. 停留在空地可以选择购买，支付购买价");
	outtextxy(0, 100, "3. 停留在已购买地产需要支付过路费。过路费计算公式为：购买价 ×（等级 + 1）× 20%");
	outtextxy(0, 150, "4. 建造房屋或酒店需要支付建造费用。建造费计算公式为：购买价 × 房产等级对应权重");
	outtextxy(0, 200, "5. 当资金为0，无法支付过路费或建造费用时，将被判定破产。此时，资金最多的人获胜。");
	outtextxy(0, 250, "6. 游戏中还有一些特殊块，需要抽取对应的命运或机会卡片");
	outtextxy(0, 300, "7. 每回合最多只能建造一栋房屋或升级一块地产");
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
	closegraph(); //清除原有的屏幕
	initgraph(1200, 800, SHOWCONSOLE);
	setbkcolor(WHITE); //设置背景颜色为白色
	cleardevice(); //清屏
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	button(330, 200, 500, 100, "双  人  游  戏");
	button(330, 350, 500, 100, "三  人  游  戏");
	button(330, 500, 500, 100, "四  人  游  戏");
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色

	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0)); //利用三原色设置文本的颜色
	string ExitGame = "点击右上角X键可以退出游戏";
	outtextxy(800, 700, ExitGame.c_str());
}