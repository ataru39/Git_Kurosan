#pragma once

#include"../Utility/Vector2D.h"

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw()const;          //�`�揈��
	void Finalize();      //�I��������
	void Damage(int damage);
	int WallHp();

	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

private:
	int hp;
	int image;
	int font;
	Vector2D location;
	Vector2D box_size;

};

