#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	int image;				//�`�悷��摜�f�[�^
	Vector2D location;		//�ʒu���W
	Vector2D box_size;		//�����蔻��̑傫��

public:
	Player();
	~Player();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw();          //�`�揈��
	void Finalize();      //�I��������

public:
	Vector2D GetLocation() const;  //�ʒu���W�擾
	Vector2D GetBoxSize()const;    //�����蔻��̑傫���擾
	void Movement();
};

