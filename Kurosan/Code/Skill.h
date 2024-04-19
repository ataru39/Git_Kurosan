#pragma once

#include"../Utility/Vector2D.h"

class Skill
{
private:
	int image;			// �摜
	Vector2D location;	// �ʒu���W
	Vector2D box_size;	// �����蔻��̑傫��
	Vector2D spawn_location;  // �X�|�[���ʒu

public:
	Skill();
	~Skill();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I��������

	Vector2D GetLocation() const;  //�ʒu���W�擾
	Vector2D GetBoxSize()const;    //�����蔻��̑傫���擾

};
