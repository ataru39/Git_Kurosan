#pragma once

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw();          //�`�揈��
	void Finalize();      //�I��������

private:
	float hp;

	struct Rect{
		float x;
		float y;
		float width;
		float height;
	};struct Rect* rec_wall;

	struct Vec2 {
		float x;
		float y;
	};struct Vec2 center_wall;
};

