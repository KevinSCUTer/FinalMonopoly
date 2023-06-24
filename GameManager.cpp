#include "GameManager.h"

GameManager::GameManager()
{
	//第一部分：对玩家的初始化
	//主要分成三种情况
	//1. 第一次使用，文件并没有创建
	ifstream ifsPlayer;
	ifsPlayer.open(PLAYERFILE, ios::in);

	if (!ifsPlayer.is_open()) //如果文件无法打开，说明文件根本就没有创建
	{
		// 初始化游戏玩家的数组
		Player player1(1, 3000, 50, 50, 0, "player1.jpg");
		playerArray.push_back(player1);
		Player player2(2, 3000, 100, 50, 0, "player2.jpg");
		playerArray.push_back(player2);
		Player player3(3, 3000, 50, 100, 0, "player3.jpg");
		playerArray.push_back(player3);
		Player player4(4, 3000, 100, 100, 0, "player4.jpg");
		playerArray.push_back(player4);
		ifsPlayer.close();
	}
	else
	{
		//2. 文件存在，但是数据已经被用户清空了
		char character1;
		ifsPlayer >> character1;
		if (ifsPlayer.eof())
		{
			// 初始化游戏玩家的数组
			Player player1(1, 3000, 50, 50, 0, "player1.jpg");
			playerArray.push_back(player1);
			Player player2(2, 3000, 100, 50, 0, "player2.jpg");
			playerArray.push_back(player2);
			Player player3(3, 3000, 50, 100, 0, "player3.jpg");
			playerArray.push_back(player3);
			Player player4(4, 3000, 100, 100, 0, "player4.jpg");
			playerArray.push_back(player4);
			this->PlayerFileIsEmpty = false;
			ifsPlayer.close();
		}
		//3. 文件存在，并且已经保存了所有的数据
		else
		{
			initializePlayer(getPlayerNumber());
		}
	}
	
	//第二部分：对地点的初始化
	//主要分成三种情况
	ifstream ifsEstate;
	ifsEstate.open(HOUSEFILE, ios::in);
	if (!ifsEstate.is_open()) //1.如果文件无法打开，说明文件根本就没有创建
	{
		// 初始化地点的数组
		//北部地区 10个地点 place0 ~ place9
		Place* place0 = new Bonus(50, 50); // 0号格，起点，加奖金
		placeArray.push_back(place0);
		Place* place1 = new Fates(150, 50); // 1号格，命运
		placeArray.push_back(place1);
		Place* place2 = new Estate(250, 50, 300, 0, 0); //2号格，C类地皮
		placeArray.push_back(place2);				
		Place* place3 = new Estate(350, 50, 300, 0, 0); //3号格，C类地皮
		placeArray.push_back(place3);
		Place* place4 = new Estate(450, 50, 300, 0, 0);//4号格，C类地皮
		placeArray.push_back(place4);
		Place* place5 = new Estate(550, 50, 600, 0, 0); //5号格，B类地皮
		placeArray.push_back(place5);
		Place* place6 = new Estate(650, 50, 600, 0, 0); //6号格，B类地皮
		placeArray.push_back(place6);
		Place* place7 = new Estate(750, 50, 1000, 0, 0); //7号格，A类地皮
		placeArray.push_back(place7);
		Place* place8 = new Estate(850, 50, 300, 0, 0); //8号格，C类地皮
		placeArray.push_back(place8);
		Place* place9 = new Chances(950, 50); //9号格，机会
		placeArray.push_back(place9);

		//东部地区 6个地点 place10 ~ place15
		Place* place10 = new Taxes(1050, 50); //10号格，交税
		placeArray.push_back(place10);
		Place* place11 = new Fates(1050, 150); //11号格，命运
		placeArray.push_back(place11);
		Place* place12 = new Estate(1050, 250, 1000, 0, 0); //12号格，A类地皮
		placeArray.push_back(place12);
		Place* place13 = new Estate(1050, 350, 300, 0, 0); //13号格，C类地皮
		placeArray.push_back(place13);
		Place* place14 = new Estate(1050, 450, 600, 0, 0); //14号格，B类地皮
		placeArray.push_back(place14);
		Place* place15 = new Fates(1050, 550); //15号格，命运
		placeArray.push_back(place15);

		//南部地区 10个地点 place16 ~ place25
		Place* place16 = new Bonus(1050, 650); //16号格，奖金
		placeArray.push_back(place16);
		Place* place17 = new Chances(950, 650); //17号格，机会
		placeArray.push_back(place17);
		Place* place18 = new Estate(850, 650, 300, 0, 0); //18号格，C类地皮
		placeArray.push_back(place18);
		Place* place19 = new Estate(750, 650, 600, 0, 0); //19号格，B类地皮
		placeArray.push_back(place19);
		Place* place20 = new Estate(650, 650, 300, 0, 0); //20号格，C类地皮
		placeArray.push_back(place20);
		Place* place21 = new Estate(550, 650, 300, 0, 0); //21号格，C类地皮
		placeArray.push_back(place21);
		Place* place22 = new Estate(450, 650, 1000, 0, 0); //22号格，A类地皮
		placeArray.push_back(place22);
		Place* place23 = new Estate(350, 650, 600, 0, 0); //23号格，B类地皮
		placeArray.push_back(place23);				  
		Place* place24 = new Estate(250, 650, 300, 0, 0); //24号格，C类地皮
		placeArray.push_back(place24);
		Place* place25 = new Chances(150, 650); //25号格，机会
		placeArray.push_back(place25);

		//西部地区 6个地点 place26 ~ place31
		Place* place26 = new Taxes(50, 650); //26号格，税收
		placeArray.push_back(place26);
		Place* place27 = new Chances(50, 550); //27号格，机会
		placeArray.push_back(place27);
		Place* place28 = new Estate(50, 450, 300, 0, 0); //28号格，C类房产
		placeArray.push_back(place28);				 
		Place* place29 = new Estate(50, 350, 1000, 0, 0); //29号格，A类房产
		placeArray.push_back(place29);				 
		Place* place30 = new Estate(50, 250, 300, 0, 0); //30号格，C类房产
		placeArray.push_back(place30);
		Place* place31 = new Fates(50, 150); //31号格，命运
		placeArray.push_back(place31);
	}
	else
	{
		//2. 文件存在，但是数据已经被用户清空了
		char character2;
		ifsEstate >> character2;
		if (ifsEstate.eof())
		{
			// 初始化地点的数组
			//北部地区 10个地点 place0 ~ place9
			Place* place0 = new Bonus(50, 50); // 0号格，起点，加奖金
			placeArray.push_back(place0);
			Place* place1 = new Fates(150, 50); // 1号格，命运
			placeArray.push_back(place1);
			Place* place2 = new Estate(250, 50, 300, 0, 0); //2号格，C类地皮
			placeArray.push_back(place2);
			Place* place3 = new Estate(350, 50, 300, 0, 0); //3号格，C类地皮
			placeArray.push_back(place3);
			Place* place4 = new Estate(450, 50, 300, 0, 0); //4号格，C类地皮
			placeArray.push_back(place4);
			Place* place5 = new Estate(550, 50, 600, 0, 0); //5号格，B类地皮
			placeArray.push_back(place5);
			Place* place6 = new Estate(650, 50, 600, 0, 0); //6号格，B类地皮
			placeArray.push_back(place6);
			Place* place7 = new Estate(750, 50, 1000, 0, 0); //7号格，A类地皮
			placeArray.push_back(place7);
			Place* place8 = new Estate(850, 50, 300, 0, 0); //8号格，C类地皮
			placeArray.push_back(place8);
			Place* place9 = new Chances(950, 50); //9号格，机会
			placeArray.push_back(place9);

			//东部地区 6个地点 place10 ~ place15
			Place* place10 = new Taxes(1050, 50); //10号格，交税
			placeArray.push_back(place10);
			Place* place11 = new Fates(1050, 150); //11号格，命运
			placeArray.push_back(place11);
			Place* place12 = new Estate(1050, 250, 1000, 0, 0); //12号格，A类地皮
			placeArray.push_back(place12);
			Place* place13 = new Estate(1050, 350, 300, 0, 0); //13号格，C类地皮
			placeArray.push_back(place13);
			Place* place14 = new Estate(1050, 450, 600, 0, 0); //14号格，B类地皮
			placeArray.push_back(place14);
			Place* place15 = new Fates(1050, 550); //15号格，命运
			placeArray.push_back(place15);

			//南部地区 10个地点 place16 ~ place25
			Place* place16 = new Bonus(1050, 650); //16号格，奖金
			placeArray.push_back(place16);
			Place* place17 = new Chances(950, 650); //17号格，机会
			placeArray.push_back(place17);
			Place* place18 = new Estate(850, 650, 300, 0, 0); //18号格，C类地皮
			placeArray.push_back(place18);
			Place* place19 = new Estate(750, 650, 600, 0, 0); //19号格，B类地皮
			placeArray.push_back(place19);
			Place* place20 = new Estate(650, 650, 300, 0, 0); //20号格，C类地皮
			placeArray.push_back(place20);
			Place* place21 = new Estate(550, 650, 300, 0, 0); //21号格，C类地皮
			placeArray.push_back(place21);
			Place* place22 = new Estate(450, 650, 1000, 0, 0); //22号格，A类地皮
			placeArray.push_back(place22);
			Place* place23 = new Estate(350, 650, 600, 0, 0); //23号格，B类地皮
			placeArray.push_back(place23);
			Place* place24 = new Estate(250, 650, 300, 0, 0); //24号格，C类地皮
			placeArray.push_back(place24);
			Place* place25 = new Chances(150, 650); //25号格，机会
			placeArray.push_back(place25);

			//西部地区 6个地点 place26 ~ place31
			Place* place26 = new Taxes(50, 650); //26号格，税收
			placeArray.push_back(place26);
			Place* place27 = new Chances(50, 550); //27号格，机会
			placeArray.push_back(place27);
			Place* place28 = new Estate(50, 450, 300, 0, 0); //28号格，C类房产
			placeArray.push_back(place28);
			Place* place29 = new Estate(50, 350, 1000, 0, 0); //29号格，A类房产
			placeArray.push_back(place29);
			Place* place30 = new Estate(50, 250, 300, 0, 0); //30号格，C类房产
			placeArray.push_back(place30);
			Place* place31 = new Fates(50, 150); //31号格，命运
			placeArray.push_back(place31);

			this->PlacesFileIsEmpty = false;
			ifsPlayer.close();
		}
		//3. 文件存在，并且已经保存了所有的数据
		else
		{
			initializePlace();
		}
	}

	//第三部分：对第几名玩家投骰子的初始化
	//主要分成三种情况
	//1. 第一次使用，文件并没有创建
	ifstream ifs;
	ifs.open(ROLLFILE, ios::in);

	if (!ifs.is_open()) //如果文件无法打开，说明文件根本就没有创建
	{
		roller = 0;
	}
	else
	{
		//2. 文件存在，但是数据已经被用户清空了
		int buff;
		ifs >> buff;
		if (ifs.eof())
		{
			roller = 0;
		}
		//3. 文件存在，并且已经保存了所有的数据
		else
		{
			roller = buff;
		}
	}

}

// 加载骰子的图片
void GameManager::loadDiceImages() {
	loadimage(&dice[0], "RollDice1.jpg");
	loadimage(&dice[1], "RollDice2.jpg");
	loadimage(&dice[2], "RollDice3.jpg");
	loadimage(&dice[3], "RollDice4.jpg");
	loadimage(&dice[4], "RollDice5.jpg");
	loadimage(&dice[5], "RollDice6.jpg");
}

// 绘制骰子的图片
void GameManager::drawDice(int x, int y, int value) {
	putimage(x, y, &dice[value - 1]);
}

// 随机掷骰子，返回结果
int GameManager::rollDice() {
	srand(time(0));
	return rand() % 6 + 1;
}

// 显示骰子的函数
void GameManager::showDice(int value) {
	// 加载骰子的图片
	loadDiceImages();
	
	// 随机掷骰子，并显示结果
	int x = 320 - 40 + 500;
	int y = 240 - 40 + 80;

	do
	{
		// 循环处理鼠标事件，直到用户关闭窗口
		// 等待用户点击鼠标
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				// 随机掷骰子，并显示结果
				drawDice(x, y, value);
				break;
			}
		}
	} while (true);
}

// 在地图上补充信息，可以优化（优化方法：在设置地点的时候让地点来输出信息）
void GameManager::addInformation()
{
	//手动地在特定的一系列地区输出房产信息
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(18, 0, "宋体");

	// 以下是添加房产价格的函数
	outtextxy(250, 160, "300$");

	outtextxy(350, 160, "300$");
	
	outtextxy(450, 160, "300$");

	outtextxy(550, 160, "600$");

	outtextxy(650, 160, "600$");
	
	outtextxy(750, 160, "1000$");

	outtextxy(850, 160, "300$");

	outtextxy(950, 260, "1000$");
	
	outtextxy(950, 360, "300$");
	
	outtextxy(950, 460, "600$");
	
	outtextxy(850, 560, "300$");
	
	outtextxy(750, 560, "600$");
	
	outtextxy(650, 560, "300$");

	outtextxy(550, 560, "300$");
	
	outtextxy(450, 560, "1000$");

	outtextxy(350, 560, "600$");

	outtextxy(250, 560, "300$");

	outtextxy(150, 460, "300$");

	outtextxy(150, 360, "1000$");

	outtextxy(150, 260, "300$");
	
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");

	//以下是实时添加房产信息的函数
	for (int i = 0; i < 32; ++i)
	{
		Place* currentPlacePtr = placeArray[i];
		Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
		if (estatePtr != nullptr) //如果地点的指针不是空指针的话
		{
			if (estatePtr->getPositionOfPlace().y == 50)
			{
				string OWNER = "物主：";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(estatePtr->getPositionOfPlace().x, 180, OWNER.c_str());
				string LEVEL = "等级：";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(estatePtr->getPositionOfPlace().x, 200, LEVEL.c_str());
			}
			// 如果是东部地区
			else if (estatePtr->getPositionOfPlace().x == 1050)
			{
				string OWNER = "物主：";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(950, estatePtr->getPositionOfPlace().y + 30, OWNER.c_str());
				string LEVEL = "等级：";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(950, estatePtr->getPositionOfPlace().y + 50, LEVEL.c_str());
			}
			// 如果是南部地区
			else if (estatePtr->getPositionOfPlace().y == 650)
			{
				string OWNER = "物主：";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(estatePtr->getPositionOfPlace().x, 580, OWNER.c_str());
				string LEVEL = "等级：";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(estatePtr->getPositionOfPlace().x, 600, LEVEL.c_str());
			}
			// 如果是西部地区
			else if (estatePtr->getPositionOfPlace().x == 50)
			{
				string OWNER = "物主：";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(150, estatePtr->getPositionOfPlace().y + 30, OWNER.c_str());
				string LEVEL = "等级：";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(150, estatePtr->getPositionOfPlace().y + 50, LEVEL.c_str());
			}
		}
	}

	//命运
	setbkcolor(WHITE);
	settextcolor(RED);
	settextstyle(80, 0, "Times New Romans");
	outtextxy(180, 60, "?");
	outtextxy(80, 160, "?");
	outtextxy(1080, 160, "?");
	outtextxy(1080, 560, "?");

	//机会
	setbkcolor(WHITE);
	settextcolor(RGB(225, 180, 0));
	settextstyle(80, 0, "Times New Romans");
	outtextxy(180, 660, "!");
	outtextxy(980, 60, "!");
	outtextxy(980, 660, "!");
	outtextxy(80, 560, "!");

	setbkcolor(WHITE);
	settextcolor(RGB(225, 118, 128));
	settextstyle(55, 0, "Arial Black");
	outtextxy(1055, 75, "TAX");
	outtextxy(50, 675, "TAX");
}

void GameManager::savePlayer()
{
	ofstream ofs; //定义文件输出流
	ofs.open(PLAYERFILE, ios::out);
	// Player(int _number, int _cash, int _positionx, int _positiony, int _place, const char* imagePath);
	for (int i = 0; i < 4; i++)
	{
		ofs << playerArray[i].getNumber() << " " << playerArray[i].getCash() << " "
			<< playerArray[i].getPosition().x << " " << playerArray[i].getPosition().y << " "
			<< playerArray[i].getTotalPlace() << endl;
	}
	this->PlacesFileIsEmpty = false;
}

void GameManager::saveEstates()
{
	ofstream ofs; //定义文件输出流
	ofs.open(HOUSEFILE, ios::out);
	// Place(int _positionx, int _positiony)
	// Estate(int _positionx, int _positiony, int _price, int _level, int _processor, bool _isEmpty)
	for (int i = 0; i <= 31; i++)
	{
		Place* currentPlacePtr = placeArray[i];
		Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
		if (estatePtr != nullptr) //如果地点的指针不是空指针的话
		{
			ofs << estatePtr->getInfoOfHouse().level << " "
				<< estatePtr->getInfoOfHouse().processor << " " << endl;
		}
	}
	this->PlacesFileIsEmpty = false;
}

void GameManager::saveRoll(int value)
{
	ofstream ofs; //定义文件输出流
	ofs.open(ROLLFILE, ios::out);
	ofs << value;
}

void GameManager::initializePlayer(int numPlayers)
{
	this->PlayerFileIsEmpty = false;
	ifstream ifsPlayer;
	ifsPlayer.open(PLAYERFILE, ios::in);
	
	//先读取第一个玩家的信息
	int currentnumber;
	int cash;
	int currentpositionx;
	int currentpositiony;
	int currentplace;
	ifsPlayer >> currentnumber >> cash >> currentpositionx >> currentpositiony >> currentplace;
	string filename = "player" + to_string(currentnumber) + ".jpg";
	Player player(currentnumber, cash, currentpositionx, currentpositiony, currentplace, filename.c_str());
	playerArray.push_back(player);

	// 再逐个读取其他玩家信息，添加补偿机制，直到文件末尾或读取numPlayers个玩家信息
	for (int i = 1; i < numPlayers && !ifsPlayer.eof(); i++)
	{
		int currentnumber;
		int cash;
		int currentpositionx;
		int currentpositiony;
		int currentplace;
		ifsPlayer >> currentnumber >> cash >> currentpositionx >> currentpositiony >> currentplace;
		string filename = "player" + to_string(currentnumber) + ".jpg";
		Player player(currentnumber, cash + 300, currentpositionx, currentpositiony, currentplace, filename.c_str());
		playerArray.push_back(player);
	}

	ifsPlayer.close();
}

void GameManager::initializePlace()
{
	ifstream ifsEstate;
	ifsEstate.open(HOUSEFILE, ios::in);

	if (!ifsEstate.is_open())
	{
		return;
	}

	//检查是否有足够的数组
	int num_levels = 0;
	int num_processors = 0;

	for (int i = 0; i < getEstateNumber(); i++)
	{
		ifsEstate >> num_levels >> num_processors;
		if (ifsEstate.fail())
		{
			ifsEstate.close();
			return;
		}
	}

	// reset file stream and create the Place objects
	ifsEstate.clear();
	ifsEstate.seekg(0, ios::beg);

	if (!ifsEstate.eof())
	{
		//北部地区 10个地点 place0 ~ place9
		Place* place0 = new Bonus(50, 50); // 0号格，起点，加奖金
		placeArray.push_back(place0);

		Place* place1 = new Fates(150, 50); // 1号格，命运
		placeArray.push_back(place1);

		for (int i = 2; i <= 8; i++)
		{
			int level;
			int processor;
			
			ifsEstate >> level >> processor;
			
			if (ifsEstate.fail())
			{
				ifsEstate.close();
				return;
			}
			else
			{
				if ((i >= 2 && i <= 4) || i == 8)
				{
					Place* placeC = new Estate(50 + i * 100, 50, 300, level, processor);
					placeArray.push_back(placeC);
				}
				else if (i == 5 || i == 6)
				{
					Place* placeB = new Estate(50 + i * 100, 50, 600, level, processor);
					placeArray.push_back(placeB);
				}
				else
				{
					Place* placeA = new Estate(50 + i * 100, 50, 1000, level, processor);
					placeArray.push_back(placeA);
				}
			}
		}

		Place* place9 = new Chances(950, 50); //9号格，机会
		placeArray.push_back(place9);

		//东部地区 6个地点 place10 ~ place15
		Place* place10 = new Taxes(1050, 50); //10号格，交税
		placeArray.push_back(place10);

		Place* place11 = new Fates(1050, 150); //11号格，命运
		placeArray.push_back(place11);

		for (int i = 12; i <= 14; i++)
		{
			int level;
			int processor;
			
			ifsEstate >> level >> processor;

			if (ifsEstate.fail())
			{
				ifsEstate.close();
				return;
			}

			if (i == 12)
			{
				Place* place12 = new Estate(1050, 50 + (i - 10) * 100, 1000, level, processor);
				placeArray.push_back(place12);
			}
			else if (i == 13)
			{
				Place* place13 = new Estate(1050, 50 + (i - 10) * 100, 300, level, processor);
				placeArray.push_back(place13);
			}
			else if (i == 14)
			{
				Place* place14 = new Estate(1050, 50 + (i - 10) * 100, 600, level, processor);
				placeArray.push_back(place14);
			}

		}

		Place* place15 = new Fates(1050, 550); //15号格，命运
		placeArray.push_back(place15);

		//南部地区 10个地点 place16 ~ place25
		Place* place16 = new Bonus(1050, 650); //16号格，奖金
		placeArray.push_back(place16);

		Place* place17 = new Chances(950, 650); //17号格，机会
		placeArray.push_back(place17);

		for (int i = 18; i <= 24; i++)
		{
			int level;
			int processor;
			
			ifsEstate >> level >> processor;
			
			if (ifsEstate.fail())
			{
				ifsEstate.close();
				return;
			}
	
			else
			{
				if (i == 18 || i == 20 || i == 24)
				{
					Place* placeC = new Estate(1050 - (i - 16) * 100, 650, 300, level, processor);
					placeArray.push_back(placeC);
				}
				else if (i == 19 || i == 23)
				{
					Place* placeB = new Estate(1050 - (i - 16) * 100, 650, 600, level, processor);
					placeArray.push_back(placeB);
				}
				else
				{
					Place* placeA = new Estate(1050 - (i - 16) * 100, 650, 1000, level, processor);
					placeArray.push_back(placeA);
				}
			}
		}

		Place* place25 = new Chances(150, 650); //25号格，机会
		placeArray.push_back(place25);

		//西部地区 6个地点 place26 ~ place31
		Place* place26 = new Taxes(50, 650); //26号格，税收
		placeArray.push_back(place26);

		Place* place27 = new Chances(50, 550); //27号格，机会
		placeArray.push_back(place27);

		for (int i = 28; i <= 30; i++)
		{
			int level;
			int processor;
		
			ifsEstate >> level >> processor;
			
			if (ifsEstate.fail())
			{
				ifsEstate.close();
				return;
			}

			if (i == 28)
			{
				Place* place28 = new Estate(50, 450, 300, level, processor);
				placeArray.push_back(place28);
			}
			else if ( i == 29 )
			{
				Place* place29 = new Estate(50, 350, 1000, level, processor);
				placeArray.push_back(place29);
			}
			else
			{
				Place* place30 = new Estate(50, 250, 300, level, processor);
				placeArray.push_back(place30);
			}
		}

		Place* place31 = new Fates(50, 150); //31号格，命运
		placeArray.push_back(place31);
	}

	ifsEstate.close();
}

void GameManager::playGames(int numberOfPlayers)
{
	cleardevice();
	closegraph(); //清除原有的屏幕
	initgraph(1200, 800, SHOWCONSOLE);

	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(WHITE);

	int startX = 50; // 地图左上角起始横坐标
	int startY = 50; // 地图左上角起始纵坐标
	int width = 1100; // 地图宽度
	int height = 700; // 地图高度
	int colNum = 11; // 列数
	int rowNum = 7; // 行数

	int lineWidth = 2; // 地图线条宽度

	// 绘制方形地图
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			int x = startX + j * (width / colNum);
			int y = startY + i * (height / rowNum);
			// 判断是否在最外圈
			if (i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) {
				// 绘制浅色矩形
				setfillcolor(WHITE);
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// 绘制白色矩形边框
				setlinestyle(PS_SOLID | PS_GEOMETRIC, lineWidth);
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
			//每一个格子的含义不一样，显示房产信息的函数需要单独拿出来
			else {
				// 绘制浅色矩形
				setfillcolor(RGB(160, 238, 225));
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// 绘制浅色边框
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
		}
	}

	addInformation();

	bool continueGame = true;

	while (continueGame) 
	{
		for (; this->roller <= numberOfPlayers - 1; ++this->roller)
		{
			// 显示当前玩家的信息和对话框。
			for (int t = 0; t <= numberOfPlayers - 1; t++)
			{
				putimage(playerArray[t].getPosition().x, playerArray[t].getPosition().y, playerArray[t].playerImage->getwidth(), playerArray[t].playerImage->getheight(), playerArray[t].playerImage, 0, 0);
			}

			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(40, 0, "楷体");
			outtextxy(300, 300, "当前玩家:");
			putimage(500, 300, playerArray[this->roller].playerImage->getwidth(), playerArray[this->roller].playerImage->getheight(), playerArray[this->roller].playerImage, 0, 0);
			outtextxy(300, 350, "玩家钱数:");
			outtextxy(500, 350, "          ");
			char Money[20];
			sprintf_s(Money, "%d", playerArray[this->roller].getCash());
			outtextxy(500, 350, Money);
			settextstyle(40, 0, "楷体");
			outtextxy(300, 400, "请玩家投骰子");

			// 首先，玩家投骰子
			int diceNum = rollDice();
			showDice(diceNum);

			// 然后，更新玩家位置
			playerArray[this->roller].clearPlayer();

			int alreadyWalked = playerArray[this->roller].getTotalPlace();
			playerArray[this->roller].setTotalPlace(alreadyWalked + diceNum);
			int newSubscriptOfPlace = playerArray[this->roller].getTotalPlace() % 32;

			// 不同的玩家即使在同一个地点也会有不同的位置
			int newX, newY;
			switch (playerArray[this->roller].getNumber())
			{
			case 1:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y;
				playerArray[this->roller].setPosition(newX, newY);
				putimage(newX, newY, playerArray[this->roller].playerImage);
				break;
			case 2:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x + 50;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y;
				playerArray[this->roller].setPosition(newX, newY);
				putimage(newX, newY, playerArray[this->roller].playerImage);
				break;
			case 3:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y + 50;
				playerArray[this->roller].setPosition(newX, newY);
				putimage(newX, newY, playerArray[this->roller].playerImage);
				break;
			case 4:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x + 50;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y + 50;
				playerArray[this->roller].setPosition(newX, newY);
				putimage(newX, newY, playerArray[this->roller].playerImage);
				break;
			default:
				break;
			}

			//执行对应的地点函数
			placeArray[newSubscriptOfPlace]->PlaceFunction(playerArray[this->roller]);

			//新增，如果玩家到了别人的地盘，那么那个地方的房主将会获得现金
			Place* currentPlacePtr = placeArray[newSubscriptOfPlace];
			Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
			if (estatePtr != nullptr) //如果地点的指针不是空指针的话
			{
				if (estatePtr->getInfoOfHouse().processor > 0 && estatePtr->getInfoOfHouse().processor != playerArray[this->roller].getNumber())
				{
					int fee = estatePtr->getInfoOfHouse().price * (estatePtr->getInfoOfHouse().level + 1) / 5;
					playerArray[estatePtr->getInfoOfHouse().processor - 1].setCash(playerArray[estatePtr->getInfoOfHouse().processor - 1].getCash() + fee);
				}
			}

			//新增，每做一次操作，就自动保存一次文件
			savePlayer();
			saveEstates();
			
			//如果执行完相应的函数后，有一个玩家的Money为0，游戏结束
			if (playerArray[this->roller].getCash() < 0)
			{
				continueGame = false;
				break;
			}
			
			//如果roller等于玩家人数的上限
			if (this->roller == numberOfPlayers - 1)
			{
				this->roller = -1;
			}
			
			saveRoll(this->roller);
			Sleep(3000);

		}
	}

	endGame(numberOfPlayers);

	getchar();
}

void GameManager::endGame(int numberOfPlayers)
{
	string ENDGAME = "游戏结束，获胜的玩家是：";
	int max = -9999;
	int winner = 0;

	for (int i = 0; i <= numberOfPlayers - 1; i++)
	{
		if (playerArray[i].getCash() > max)
		{
			max = playerArray[i].getCash();
			winner = playerArray[i].getNumber();
		}
	}

	ENDGAME += to_string(winner);
	// 先获取窗口句柄
	HWND hnd = GetHWnd();
	// 弹出消息窗口，提示用户操作
	int isOK = MessageBox(GetHWnd(), ENDGAME.c_str(), "提示", MB_OK);
	if (isOK == IDOK)
	{
		//游戏结束时，所有存档的数据都必须得删除
		cleanFileOfPlayer(); 
		cleanFileOfEstates();
		exit(0);
	}
}

void GameManager::cleanFileOfPlayer()
{
	ofstream ofsPlayer(PLAYERFILE, ios::trunc);
	ofsPlayer.flush();
	ofsPlayer.close();
}

void GameManager::cleanFileOfEstates()
{
	ofstream ofsEstate(HOUSEFILE, ios::trunc);
	ofsEstate.flush();
	ofsEstate.close();
}

void GameManager::cleanFileOfRoller()
{
	ofstream ofs(ROLLFILE, ios::trunc);
	ofs.flush();
	ofs.close();
}

int GameManager::getPlayerNumber()
{
	ifstream ifsPlayer;
	ifsPlayer.open(PLAYERFILE, ios::in);
	// Player(int _number, int _cash, int _positionx, int _positiony, int _place, const char* imagePath);
	int currentnumber;
	int cash;
	int currentpositionx;
	int currentpositiony;
	int currentplace;
	int number = 0;
	while (ifsPlayer >> currentnumber && ifsPlayer >> cash
		&& ifsPlayer >> currentpositionx && ifsPlayer >> currentpositiony
		&& ifsPlayer >> currentplace)
	{
		number++;
	}
	return number;
}

int GameManager::getEstateNumber()
{
	ifstream ifsEstate;
	ifsEstate.open(HOUSEFILE, ios::in);
	int currentlevel;
	int currentprocessor;
	
	int number = 0;
	while (ifsEstate >> currentlevel
		&& ifsEstate >> currentprocessor)
	{
		number++;
	}
	return number;
	return 0;
}

GameManager::~GameManager()
{
	//将所有new出来的内存delete掉
	for (auto iter = placeArray.begin(); iter != placeArray.end(); iter++)
	{
		delete* iter;
	}
}