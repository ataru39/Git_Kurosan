#pragma once

#include "SceneBase.h"

class Title :public SceneBase
{
private:

private:
	int background_image;      //�w�i�摜
	int menu_image;            //���j���[�摜
	int cursor_image;          //�J�[�\���摜
	int menu_cursor;           //���j���[�J�[�\���ԍ�

	int credit_time;           //�N���W�b�g����
	int credit_image;          //�N���W�b�g�摜
	bool end;                  //�N���W�b�g��ʔ��f
	int title_image;           //�薼�摜
	int title_car;             //�ԉ摜
	int BGM;				   //BGM

	int cursol_se;			   // �J�[�\��SE
	int kettei_se;			   // ����SE

public:
	Title();
	virtual ~Title();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

