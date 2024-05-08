#pragma once

#include"../Utility/Vector2D.h"

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw();          //�`�揈��
	void Finalize();      //�I��������

	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

private:
	float hp;
	int image;
	int image2;
	int imageblock;
	Vector2D location;
	Vector2D box_size;

};

