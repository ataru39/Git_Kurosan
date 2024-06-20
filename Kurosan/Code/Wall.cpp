#include "Wall.h"
#include "DxLib.h"

Wall::Wall()
{
	image = LoadGraph("Resources/Images/kabe4.png");
	o_image = LoadGraph("Resources/Images/tile_0.png");
	font = CreateFontToHandle(NULL, 40, 2);

}

Wall::~Wall()
{
	DeleteGraph(image);
	DeleteGraph(o_image);
}

void Wall::Initialize()
{
	hp = 1;
	location = Vector2D(0.0f, 100.0f);
	box_size = Vector2D(180.0f, 720.0f);
	cnt = 30;
}

void Wall::Update()
{
	flg = WallBreak();
	if (flg!=false && cnt > 0) 
	{
		cnt--;
	}
	if (cnt <= 0) 
	{
		cnt = 30;
	}
}

void Wall::Draw()const
{
	DrawFormatStringToHandle(300, 40, 0x00fff0, font, "@•Ç‚Ì‘Ï‹v’lF%d", hp);

	DrawGraph(0, 100, image, TRUE);
	DrawGraph(0, 300, image, TRUE);
	DrawGraph(0, 500, image, TRUE);
	DrawGraph(0, 700, image, TRUE);

	if (flg != false) {
		for (int i = 0; i < 800; i+=100) 
		{
			for (int j = 0; j < 1300; j+=100) 
			{
				if (cnt == 30) {
					DrawGraph(j, i, o_image, TRUE);
				}
			}
		}
	}
}

void Wall::Finalize()
{
	DeleteGraph(image);
	DeleteGraph(o_image);
}

Vector2D Wall::GetLocation() const
{
	return location;
}

Vector2D Wall::GetBoxSize() const
{
	return box_size;
}

int Wall::WallHp()
{
	return this->hp;
}

bool Wall::WallBreak()
{
	if (WallHp() > 0) {
		return false;
	}
	else {
		return true;
	}
}

void Wall::Damage(int damage)
{
	hp -= damage;
}




