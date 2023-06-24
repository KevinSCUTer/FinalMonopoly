#include "GameManager.h"

GameManager::GameManager()
{
	//��һ���֣�����ҵĳ�ʼ��
	//��Ҫ�ֳ��������
	//1. ��һ��ʹ�ã��ļ���û�д���
	ifstream ifsPlayer;
	ifsPlayer.open(PLAYERFILE, ios::in);

	if (!ifsPlayer.is_open()) //����ļ��޷��򿪣�˵���ļ�������û�д���
	{
		// ��ʼ����Ϸ��ҵ�����
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
		//2. �ļ����ڣ����������Ѿ����û������
		char character1;
		ifsPlayer >> character1;
		if (ifsPlayer.eof())
		{
			// ��ʼ����Ϸ��ҵ�����
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
		//3. �ļ����ڣ������Ѿ����������е�����
		else
		{
			initializePlayer(getPlayerNumber());
		}
	}
	
	//�ڶ����֣��Եص�ĳ�ʼ��
	//��Ҫ�ֳ��������
	ifstream ifsEstate;
	ifsEstate.open(HOUSEFILE, ios::in);
	if (!ifsEstate.is_open()) //1.����ļ��޷��򿪣�˵���ļ�������û�д���
	{
		// ��ʼ���ص������
		//�������� 10���ص� place0 ~ place9
		Place* place0 = new Bonus(50, 50); // 0�Ÿ���㣬�ӽ���
		placeArray.push_back(place0);
		Place* place1 = new Fates(150, 50); // 1�Ÿ�����
		placeArray.push_back(place1);
		Place* place2 = new Estate(250, 50, 300, 0, 0); //2�Ÿ�C���Ƥ
		placeArray.push_back(place2);				
		Place* place3 = new Estate(350, 50, 300, 0, 0); //3�Ÿ�C���Ƥ
		placeArray.push_back(place3);
		Place* place4 = new Estate(450, 50, 300, 0, 0);//4�Ÿ�C���Ƥ
		placeArray.push_back(place4);
		Place* place5 = new Estate(550, 50, 600, 0, 0); //5�Ÿ�B���Ƥ
		placeArray.push_back(place5);
		Place* place6 = new Estate(650, 50, 600, 0, 0); //6�Ÿ�B���Ƥ
		placeArray.push_back(place6);
		Place* place7 = new Estate(750, 50, 1000, 0, 0); //7�Ÿ�A���Ƥ
		placeArray.push_back(place7);
		Place* place8 = new Estate(850, 50, 300, 0, 0); //8�Ÿ�C���Ƥ
		placeArray.push_back(place8);
		Place* place9 = new Chances(950, 50); //9�Ÿ񣬻���
		placeArray.push_back(place9);

		//�������� 6���ص� place10 ~ place15
		Place* place10 = new Taxes(1050, 50); //10�Ÿ񣬽�˰
		placeArray.push_back(place10);
		Place* place11 = new Fates(1050, 150); //11�Ÿ�����
		placeArray.push_back(place11);
		Place* place12 = new Estate(1050, 250, 1000, 0, 0); //12�Ÿ�A���Ƥ
		placeArray.push_back(place12);
		Place* place13 = new Estate(1050, 350, 300, 0, 0); //13�Ÿ�C���Ƥ
		placeArray.push_back(place13);
		Place* place14 = new Estate(1050, 450, 600, 0, 0); //14�Ÿ�B���Ƥ
		placeArray.push_back(place14);
		Place* place15 = new Fates(1050, 550); //15�Ÿ�����
		placeArray.push_back(place15);

		//�ϲ����� 10���ص� place16 ~ place25
		Place* place16 = new Bonus(1050, 650); //16�Ÿ񣬽���
		placeArray.push_back(place16);
		Place* place17 = new Chances(950, 650); //17�Ÿ񣬻���
		placeArray.push_back(place17);
		Place* place18 = new Estate(850, 650, 300, 0, 0); //18�Ÿ�C���Ƥ
		placeArray.push_back(place18);
		Place* place19 = new Estate(750, 650, 600, 0, 0); //19�Ÿ�B���Ƥ
		placeArray.push_back(place19);
		Place* place20 = new Estate(650, 650, 300, 0, 0); //20�Ÿ�C���Ƥ
		placeArray.push_back(place20);
		Place* place21 = new Estate(550, 650, 300, 0, 0); //21�Ÿ�C���Ƥ
		placeArray.push_back(place21);
		Place* place22 = new Estate(450, 650, 1000, 0, 0); //22�Ÿ�A���Ƥ
		placeArray.push_back(place22);
		Place* place23 = new Estate(350, 650, 600, 0, 0); //23�Ÿ�B���Ƥ
		placeArray.push_back(place23);				  
		Place* place24 = new Estate(250, 650, 300, 0, 0); //24�Ÿ�C���Ƥ
		placeArray.push_back(place24);
		Place* place25 = new Chances(150, 650); //25�Ÿ񣬻���
		placeArray.push_back(place25);

		//�������� 6���ص� place26 ~ place31
		Place* place26 = new Taxes(50, 650); //26�Ÿ�˰��
		placeArray.push_back(place26);
		Place* place27 = new Chances(50, 550); //27�Ÿ񣬻���
		placeArray.push_back(place27);
		Place* place28 = new Estate(50, 450, 300, 0, 0); //28�Ÿ�C�෿��
		placeArray.push_back(place28);				 
		Place* place29 = new Estate(50, 350, 1000, 0, 0); //29�Ÿ�A�෿��
		placeArray.push_back(place29);				 
		Place* place30 = new Estate(50, 250, 300, 0, 0); //30�Ÿ�C�෿��
		placeArray.push_back(place30);
		Place* place31 = new Fates(50, 150); //31�Ÿ�����
		placeArray.push_back(place31);
	}
	else
	{
		//2. �ļ����ڣ����������Ѿ����û������
		char character2;
		ifsEstate >> character2;
		if (ifsEstate.eof())
		{
			// ��ʼ���ص������
			//�������� 10���ص� place0 ~ place9
			Place* place0 = new Bonus(50, 50); // 0�Ÿ���㣬�ӽ���
			placeArray.push_back(place0);
			Place* place1 = new Fates(150, 50); // 1�Ÿ�����
			placeArray.push_back(place1);
			Place* place2 = new Estate(250, 50, 300, 0, 0); //2�Ÿ�C���Ƥ
			placeArray.push_back(place2);
			Place* place3 = new Estate(350, 50, 300, 0, 0); //3�Ÿ�C���Ƥ
			placeArray.push_back(place3);
			Place* place4 = new Estate(450, 50, 300, 0, 0); //4�Ÿ�C���Ƥ
			placeArray.push_back(place4);
			Place* place5 = new Estate(550, 50, 600, 0, 0); //5�Ÿ�B���Ƥ
			placeArray.push_back(place5);
			Place* place6 = new Estate(650, 50, 600, 0, 0); //6�Ÿ�B���Ƥ
			placeArray.push_back(place6);
			Place* place7 = new Estate(750, 50, 1000, 0, 0); //7�Ÿ�A���Ƥ
			placeArray.push_back(place7);
			Place* place8 = new Estate(850, 50, 300, 0, 0); //8�Ÿ�C���Ƥ
			placeArray.push_back(place8);
			Place* place9 = new Chances(950, 50); //9�Ÿ񣬻���
			placeArray.push_back(place9);

			//�������� 6���ص� place10 ~ place15
			Place* place10 = new Taxes(1050, 50); //10�Ÿ񣬽�˰
			placeArray.push_back(place10);
			Place* place11 = new Fates(1050, 150); //11�Ÿ�����
			placeArray.push_back(place11);
			Place* place12 = new Estate(1050, 250, 1000, 0, 0); //12�Ÿ�A���Ƥ
			placeArray.push_back(place12);
			Place* place13 = new Estate(1050, 350, 300, 0, 0); //13�Ÿ�C���Ƥ
			placeArray.push_back(place13);
			Place* place14 = new Estate(1050, 450, 600, 0, 0); //14�Ÿ�B���Ƥ
			placeArray.push_back(place14);
			Place* place15 = new Fates(1050, 550); //15�Ÿ�����
			placeArray.push_back(place15);

			//�ϲ����� 10���ص� place16 ~ place25
			Place* place16 = new Bonus(1050, 650); //16�Ÿ񣬽���
			placeArray.push_back(place16);
			Place* place17 = new Chances(950, 650); //17�Ÿ񣬻���
			placeArray.push_back(place17);
			Place* place18 = new Estate(850, 650, 300, 0, 0); //18�Ÿ�C���Ƥ
			placeArray.push_back(place18);
			Place* place19 = new Estate(750, 650, 600, 0, 0); //19�Ÿ�B���Ƥ
			placeArray.push_back(place19);
			Place* place20 = new Estate(650, 650, 300, 0, 0); //20�Ÿ�C���Ƥ
			placeArray.push_back(place20);
			Place* place21 = new Estate(550, 650, 300, 0, 0); //21�Ÿ�C���Ƥ
			placeArray.push_back(place21);
			Place* place22 = new Estate(450, 650, 1000, 0, 0); //22�Ÿ�A���Ƥ
			placeArray.push_back(place22);
			Place* place23 = new Estate(350, 650, 600, 0, 0); //23�Ÿ�B���Ƥ
			placeArray.push_back(place23);
			Place* place24 = new Estate(250, 650, 300, 0, 0); //24�Ÿ�C���Ƥ
			placeArray.push_back(place24);
			Place* place25 = new Chances(150, 650); //25�Ÿ񣬻���
			placeArray.push_back(place25);

			//�������� 6���ص� place26 ~ place31
			Place* place26 = new Taxes(50, 650); //26�Ÿ�˰��
			placeArray.push_back(place26);
			Place* place27 = new Chances(50, 550); //27�Ÿ񣬻���
			placeArray.push_back(place27);
			Place* place28 = new Estate(50, 450, 300, 0, 0); //28�Ÿ�C�෿��
			placeArray.push_back(place28);
			Place* place29 = new Estate(50, 350, 1000, 0, 0); //29�Ÿ�A�෿��
			placeArray.push_back(place29);
			Place* place30 = new Estate(50, 250, 300, 0, 0); //30�Ÿ�C�෿��
			placeArray.push_back(place30);
			Place* place31 = new Fates(50, 150); //31�Ÿ�����
			placeArray.push_back(place31);

			this->PlacesFileIsEmpty = false;
			ifsPlayer.close();
		}
		//3. �ļ����ڣ������Ѿ����������е�����
		else
		{
			initializePlace();
		}
	}

	//�������֣��Եڼ������Ͷ���ӵĳ�ʼ��
	//��Ҫ�ֳ��������
	//1. ��һ��ʹ�ã��ļ���û�д���
	ifstream ifs;
	ifs.open(ROLLFILE, ios::in);

	if (!ifs.is_open()) //����ļ��޷��򿪣�˵���ļ�������û�д���
	{
		roller = 0;
	}
	else
	{
		//2. �ļ����ڣ����������Ѿ����û������
		int buff;
		ifs >> buff;
		if (ifs.eof())
		{
			roller = 0;
		}
		//3. �ļ����ڣ������Ѿ����������е�����
		else
		{
			roller = buff;
		}
	}

}

// �������ӵ�ͼƬ
void GameManager::loadDiceImages() {
	loadimage(&dice[0], "RollDice1.jpg");
	loadimage(&dice[1], "RollDice2.jpg");
	loadimage(&dice[2], "RollDice3.jpg");
	loadimage(&dice[3], "RollDice4.jpg");
	loadimage(&dice[4], "RollDice5.jpg");
	loadimage(&dice[5], "RollDice6.jpg");
}

// �������ӵ�ͼƬ
void GameManager::drawDice(int x, int y, int value) {
	putimage(x, y, &dice[value - 1]);
}

// ��������ӣ����ؽ��
int GameManager::rollDice() {
	srand(time(0));
	return rand() % 6 + 1;
}

// ��ʾ���ӵĺ���
void GameManager::showDice(int value) {
	// �������ӵ�ͼƬ
	loadDiceImages();
	
	// ��������ӣ�����ʾ���
	int x = 320 - 40 + 500;
	int y = 240 - 40 + 80;

	do
	{
		// ѭ����������¼���ֱ���û��رմ���
		// �ȴ��û�������
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				// ��������ӣ�����ʾ���
				drawDice(x, y, value);
				break;
			}
		}
	} while (true);
}

// �ڵ�ͼ�ϲ�����Ϣ�������Ż����Ż������������õص��ʱ���õص��������Ϣ��
void GameManager::addInformation()
{
	//�ֶ������ض���һϵ�е������������Ϣ
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(18, 0, "����");

	// ��������ӷ����۸�ĺ���
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
	settextstyle(20, 0, "����");

	//������ʵʱ��ӷ�����Ϣ�ĺ���
	for (int i = 0; i < 32; ++i)
	{
		Place* currentPlacePtr = placeArray[i];
		Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
		if (estatePtr != nullptr) //����ص��ָ�벻�ǿ�ָ��Ļ�
		{
			if (estatePtr->getPositionOfPlace().y == 50)
			{
				string OWNER = "������";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(estatePtr->getPositionOfPlace().x, 180, OWNER.c_str());
				string LEVEL = "�ȼ���";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(estatePtr->getPositionOfPlace().x, 200, LEVEL.c_str());
			}
			// ����Ƕ�������
			else if (estatePtr->getPositionOfPlace().x == 1050)
			{
				string OWNER = "������";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(950, estatePtr->getPositionOfPlace().y + 30, OWNER.c_str());
				string LEVEL = "�ȼ���";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(950, estatePtr->getPositionOfPlace().y + 50, LEVEL.c_str());
			}
			// ������ϲ�����
			else if (estatePtr->getPositionOfPlace().y == 650)
			{
				string OWNER = "������";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(estatePtr->getPositionOfPlace().x, 580, OWNER.c_str());
				string LEVEL = "�ȼ���";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(estatePtr->getPositionOfPlace().x, 600, LEVEL.c_str());
			}
			// �������������
			else if (estatePtr->getPositionOfPlace().x == 50)
			{
				string OWNER = "������";
				OWNER += to_string(estatePtr->getInfoOfHouse().processor);
				outtextxy(150, estatePtr->getPositionOfPlace().y + 30, OWNER.c_str());
				string LEVEL = "�ȼ���";
				LEVEL += to_string(estatePtr->getInfoOfHouse().level);
				outtextxy(150, estatePtr->getPositionOfPlace().y + 50, LEVEL.c_str());
			}
		}
	}

	//����
	setbkcolor(WHITE);
	settextcolor(RED);
	settextstyle(80, 0, "Times New Romans");
	outtextxy(180, 60, "?");
	outtextxy(80, 160, "?");
	outtextxy(1080, 160, "?");
	outtextxy(1080, 560, "?");

	//����
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
	ofstream ofs; //�����ļ������
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
	ofstream ofs; //�����ļ������
	ofs.open(HOUSEFILE, ios::out);
	// Place(int _positionx, int _positiony)
	// Estate(int _positionx, int _positiony, int _price, int _level, int _processor, bool _isEmpty)
	for (int i = 0; i <= 31; i++)
	{
		Place* currentPlacePtr = placeArray[i];
		Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
		if (estatePtr != nullptr) //����ص��ָ�벻�ǿ�ָ��Ļ�
		{
			ofs << estatePtr->getInfoOfHouse().level << " "
				<< estatePtr->getInfoOfHouse().processor << " " << endl;
		}
	}
	this->PlacesFileIsEmpty = false;
}

void GameManager::saveRoll(int value)
{
	ofstream ofs; //�����ļ������
	ofs.open(ROLLFILE, ios::out);
	ofs << value;
}

void GameManager::initializePlayer(int numPlayers)
{
	this->PlayerFileIsEmpty = false;
	ifstream ifsPlayer;
	ifsPlayer.open(PLAYERFILE, ios::in);
	
	//�ȶ�ȡ��һ����ҵ���Ϣ
	int currentnumber;
	int cash;
	int currentpositionx;
	int currentpositiony;
	int currentplace;
	ifsPlayer >> currentnumber >> cash >> currentpositionx >> currentpositiony >> currentplace;
	string filename = "player" + to_string(currentnumber) + ".jpg";
	Player player(currentnumber, cash, currentpositionx, currentpositiony, currentplace, filename.c_str());
	playerArray.push_back(player);

	// �������ȡ���������Ϣ����Ӳ������ƣ�ֱ���ļ�ĩβ���ȡnumPlayers�������Ϣ
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

	//����Ƿ����㹻������
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
		//�������� 10���ص� place0 ~ place9
		Place* place0 = new Bonus(50, 50); // 0�Ÿ���㣬�ӽ���
		placeArray.push_back(place0);

		Place* place1 = new Fates(150, 50); // 1�Ÿ�����
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

		Place* place9 = new Chances(950, 50); //9�Ÿ񣬻���
		placeArray.push_back(place9);

		//�������� 6���ص� place10 ~ place15
		Place* place10 = new Taxes(1050, 50); //10�Ÿ񣬽�˰
		placeArray.push_back(place10);

		Place* place11 = new Fates(1050, 150); //11�Ÿ�����
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

		Place* place15 = new Fates(1050, 550); //15�Ÿ�����
		placeArray.push_back(place15);

		//�ϲ����� 10���ص� place16 ~ place25
		Place* place16 = new Bonus(1050, 650); //16�Ÿ񣬽���
		placeArray.push_back(place16);

		Place* place17 = new Chances(950, 650); //17�Ÿ񣬻���
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

		Place* place25 = new Chances(150, 650); //25�Ÿ񣬻���
		placeArray.push_back(place25);

		//�������� 6���ص� place26 ~ place31
		Place* place26 = new Taxes(50, 650); //26�Ÿ�˰��
		placeArray.push_back(place26);

		Place* place27 = new Chances(50, 550); //27�Ÿ񣬻���
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

		Place* place31 = new Fates(50, 150); //31�Ÿ�����
		placeArray.push_back(place31);
	}

	ifsEstate.close();
}

void GameManager::playGames(int numberOfPlayers)
{
	cleardevice();
	closegraph(); //���ԭ�е���Ļ
	initgraph(1200, 800, SHOWCONSOLE);

	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(WHITE);

	int startX = 50; // ��ͼ���Ͻ���ʼ������
	int startY = 50; // ��ͼ���Ͻ���ʼ������
	int width = 1100; // ��ͼ���
	int height = 700; // ��ͼ�߶�
	int colNum = 11; // ����
	int rowNum = 7; // ����

	int lineWidth = 2; // ��ͼ�������

	// ���Ʒ��ε�ͼ
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			int x = startX + j * (width / colNum);
			int y = startY + i * (height / rowNum);
			// �ж��Ƿ�������Ȧ
			if (i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) {
				// ����ǳɫ����
				setfillcolor(WHITE);
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// ���ư�ɫ���α߿�
				setlinestyle(PS_SOLID | PS_GEOMETRIC, lineWidth);
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
			//ÿһ�����ӵĺ��岻һ������ʾ������Ϣ�ĺ�����Ҫ�����ó���
			else {
				// ����ǳɫ����
				setfillcolor(RGB(160, 238, 225));
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// ����ǳɫ�߿�
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
			// ��ʾ��ǰ��ҵ���Ϣ�ͶԻ���
			for (int t = 0; t <= numberOfPlayers - 1; t++)
			{
				putimage(playerArray[t].getPosition().x, playerArray[t].getPosition().y, playerArray[t].playerImage->getwidth(), playerArray[t].playerImage->getheight(), playerArray[t].playerImage, 0, 0);
			}

			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(40, 0, "����");
			outtextxy(300, 300, "��ǰ���:");
			putimage(500, 300, playerArray[this->roller].playerImage->getwidth(), playerArray[this->roller].playerImage->getheight(), playerArray[this->roller].playerImage, 0, 0);
			outtextxy(300, 350, "���Ǯ��:");
			outtextxy(500, 350, "          ");
			char Money[20];
			sprintf_s(Money, "%d", playerArray[this->roller].getCash());
			outtextxy(500, 350, Money);
			settextstyle(40, 0, "����");
			outtextxy(300, 400, "�����Ͷ����");

			// ���ȣ����Ͷ����
			int diceNum = rollDice();
			showDice(diceNum);

			// Ȼ�󣬸������λ��
			playerArray[this->roller].clearPlayer();

			int alreadyWalked = playerArray[this->roller].getTotalPlace();
			playerArray[this->roller].setTotalPlace(alreadyWalked + diceNum);
			int newSubscriptOfPlace = playerArray[this->roller].getTotalPlace() % 32;

			// ��ͬ����Ҽ�ʹ��ͬһ���ص�Ҳ���в�ͬ��λ��
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

			//ִ�ж�Ӧ�ĵص㺯��
			placeArray[newSubscriptOfPlace]->PlaceFunction(playerArray[this->roller]);

			//�����������ҵ��˱��˵ĵ��̣���ô�Ǹ��ط��ķ����������ֽ�
			Place* currentPlacePtr = placeArray[newSubscriptOfPlace];
			Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
			if (estatePtr != nullptr) //����ص��ָ�벻�ǿ�ָ��Ļ�
			{
				if (estatePtr->getInfoOfHouse().processor > 0 && estatePtr->getInfoOfHouse().processor != playerArray[this->roller].getNumber())
				{
					int fee = estatePtr->getInfoOfHouse().price * (estatePtr->getInfoOfHouse().level + 1) / 5;
					playerArray[estatePtr->getInfoOfHouse().processor - 1].setCash(playerArray[estatePtr->getInfoOfHouse().processor - 1].getCash() + fee);
				}
			}

			//������ÿ��һ�β��������Զ�����һ���ļ�
			savePlayer();
			saveEstates();
			
			//���ִ������Ӧ�ĺ�������һ����ҵ�MoneyΪ0����Ϸ����
			if (playerArray[this->roller].getCash() < 0)
			{
				continueGame = false;
				break;
			}
			
			//���roller�����������������
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
	string ENDGAME = "��Ϸ��������ʤ������ǣ�";
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
	// �Ȼ�ȡ���ھ��
	HWND hnd = GetHWnd();
	// ������Ϣ���ڣ���ʾ�û�����
	int isOK = MessageBox(GetHWnd(), ENDGAME.c_str(), "��ʾ", MB_OK);
	if (isOK == IDOK)
	{
		//��Ϸ����ʱ�����д浵�����ݶ������ɾ��
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
	//������new�������ڴ�delete��
	for (auto iter = placeArray.begin(); iter != placeArray.end(); iter++)
	{
		delete* iter;
	}
}