#include "Fates.h"

Fates::Fates(int _positionx, int _positiony): Place(_positionx, _positiony)
{
	
}

void Fates::PlaceFunction(Player& player)
{
	// 先清除之前的信息
	setbkcolor(RGB(160, 238, 225));
	outtextxy(300, 400, "                             ");
	outtextxy(300, 450, "                             ");
	outtextxy(300, 500, "                               ");
	// 再输出新的信息
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(300, 450, "请勇敢面对命运！");
	outtextxy(300, 500, player.faceFate().c_str());
}
