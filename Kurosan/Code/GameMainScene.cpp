#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>
#include "../Utility/InputControl.h"

GameMainScene::GameMainScene()
{
	// �G�̐��������
	enemymax = 5;

	// �I�u�W�F�N�g�̐���
	wall = new Wall;
	player = new Player;
	ui = new UI;
	enemy = new Enemy * [enemymax];

	// �G�I�u�W�F�N�g�z��̏�����
	for (int i = 0; i < enemymax; i++) {
		enemy[i] = nullptr;
	}

	// �e�I�u�W�F�N�g
	bullet = new S_Bullet * [10];
	// ������
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = nullptr;
	}

	// ����I�u�W�F�N�g
	fist = new S_21Fist * [10];
	// ������
	for (int i = 0; i < 10; i++)
	{
		fist[i] = nullptr;
	}

	//�E��I�u�W�F�N�g
	fist2 = new S_21FistL * [10];
	//������
	for (int i = 0; i < 10; i++)
	{
		fist2[i] = nullptr;
	}


	// ���I�u�W�F�N�g
	frame = new S_Frame * [10];
	// ������
	for (int i = 0; i < 10; i++)
	{
		frame[i] = nullptr;
	}

	// �G�̃X�|�[���f�B���C������
	e_delay = 0;
	// �e�̃N�[���^�C��������
	b_cooltime = 0;
	// ����̃N�[���^�C��������
	f_cooltime = 0;
	// �E��̃N�[���^�C��������
	l_cooltime = 0;

}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
	delete enemy;
	delete ui;
	delete bullet;
	delete fist;
	delete fist2;
	delete frame;
}

// ����������
void GameMainScene::Initialize()
{
	grace = LoadGraph("Resources/Images/background_grace.png");
	sound = LoadSoundMem("Resources/Images/Sounds/�t�@���^�W�[4-�i�W-.mp3");

	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

// �X�V����
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	ui->Update();

	// �G�̐���
	if (e_delay <= 0) {								//�Ԋu
		for (int i = 0; i < enemymax; i++) {		//�����
			if (enemy[i] == nullptr)				//�z��enemy�̒�����̎�
			{
				enemy[i] = new Enemy();				//��̔z��ɃG�l�~�[�����
				enemy[i]->Initialize();				//����������
				e_delay = 60;						//�G�����Ԋu
				break;								//for���[�v���甲����
			}
		}
	}

	// �G�̐����f�B���C����
	if (e_delay > 0)
	{
		e_delay--;
	}

	// �G�̍X�V
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
	}

	// �e����
	if (b_cooltime <= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i] == nullptr)
			{
				bullet[i] = new S_Bullet();
				bullet[i]->Initialize(player->GetLocation(), player->GetLevel());
				b_cooltime = 600;
				break;
			}
		}
	}

	// �e�N�[���^�C����������
	if (b_cooltime > 0)
	{
		b_cooltime--;
	}

	// ���萬����
	if (player->GetLevel() > 1) {
		if (f_cooltime <= 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (fist[i] == nullptr)
				{
					fist[i] = new S_21Fist();
					fist[i]->Initialize(player->GetLocation());
					f_cooltime = 300;
					break;
				}
			}
		}
	}

	// ����N�[���^�C����������
	if (f_cooltime > 0)
	{
		f_cooltime--;
	}

	//�E�萶������
	if (player->GetLevel() > 2) {
		if (l_cooltime <= 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (fist2[i] == nullptr)
				{
					fist2[i] = new S_21FistL();
					fist2[i]->Initialize(player->GetLocation());
					l_cooltime = 300;
					break;
				}
			}
		}
	}

	// �E��N�[���^�C����������
	if (l_cooltime > 0)
	{
		l_cooltime--;
	}

	// ����������
	if (player->GetLevel() > 4) {
		if (h_cooltime <= 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (frame[i] == nullptr)
				{
					frame[i] = new S_Frame();
					frame[i]->Initialize(player->GetLocation(), enemy[i]->GetLocation());
					h_cooltime = 60;
					break;
				}
			}
		}
	}

	// �N�[���^�C����������
	if (h_cooltime > 0)
	{
		h_cooltime--;
	}

	// �e�̍X�V����
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
		}
	}

	// ����̍X�V����
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			fist[i]->Update();
		}
	}

	// �E��̍X�V����
	for (int i = 0; i < 10; i++)
	{
		if (fist2[i] != nullptr)
		{
			fist2[i]->Update();
		}
	}

	// ���̍X�V����
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			frame[i]->Update();
		}
	}

	// �e�̏��������i���j
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			if (bullet[i]->GetLocation().x > 1300)
			{
				bullet[i] = nullptr;
			}
		}
	}

	//����̍폜����
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			f_location = fist[i]->GetLocation();
			if (fist[i]->FadeOut() <= 0) {
				fist[i] = nullptr;
			}
		}
	}

	//�E��̍폜����
	for (int i = 0; i < 10; i++)
	{
		if (fist2[i] != nullptr)
		{
			f_location = fist2[i]->GetLocation();
			if (fist2[i]->FadeOut() <= 0) {
				fist2[i] = nullptr;
			}
		}
	}

	// ���̏��������i���j
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			if (frame[i]->GetLocation().x > 1300)
			{
				frame[i] = nullptr;
			}
		}
	}

	//�G�ƒe�̓����蔻��
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			for (int j = 0; j < 10; j++)
			{
				if (bullet[j] != nullptr) {
					if (BhitCheck(enemy[i], bullet[j])) { // �G�ƒe���ڐG������
						enemy[i]->Damage(bullet[j]->GetDamage());// �G�Ƀ_���[�W��^����
						bullet[j] = nullptr;
						delete bullet[j];
						if (enemy[i]->GetHP() <= 0) // �G�����񂾂Ƃ�
						{
							player->RcvExp(enemy[i]->GetExp());	// �v���C���[��EXP��n��
							is_levelup = player->Levelup();
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}
				//����
				if (fist[j] != nullptr) {
					if (FhitCheck(enemy[i], fist[j])) {
						enemy[i]->Damage(fist[j]->GetDamage());
						if (enemy[i]->GetHP() <= 0)
						{
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}
				//�E��
				if (fist2[j] != nullptr) {
					if (FlhitCheck(enemy[i], fist2[j])) {
						enemy[i]->Damage(fist2[j]->GetDamage());
						if (enemy[i]->GetHP() <= 0)
						{
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}

				if (frame[j] != nullptr) {
					if (HhitCheck(enemy[i], frame[j])) {
						enemy[i]->Damage(frame[j]->GetDamage());
						frame[j] = nullptr;
						delete frame[j];
						if (enemy[i]->GetHP() <= 0)				// �G�����񂾂Ƃ�
						{
							player->RcvExp(enemy[i]->GetExp());	// �v���C���[��EXP��n��
							player->Levelup();
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}
			}
		}
	}

	//�G�ƕǂ̓����蔻��
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr && enemy[i]->GetAtkFlg() != true) {
			if (WhitCheck(enemy[i], wall)) {
				enemy[i]->ChengeAtkFlg(true);
				wall->Damage(enemy[i]->GetDamage());
			}
		}
	}

	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{
	//�w�i�摜
	for (int g = 0; g < 1281; g = g + 128) {
		for (int z = 0; z < 751; z = z + 71) {
			DrawRotaGraph(g, z, 2.0, 0, grace, FALSE);
		}
	}

	ui->Draw();
	wall->Draw();
	player->Draw();

	//�G�̕`��
	for (int i = 0; i < enemymax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		SkillDraw(i);
	}

	// ���x����EXP
	DrawFormatString(0, 0, 0x000000, "%d", player->GetExp());
	DrawFormatString(0, 15, 0x000000, "%d", player->GetLevel());
}

//�I��������
void GameMainScene::Finalize()
{

}

void GameMainScene::SkillDraw(int i)const
{
	//�e�̕`��
	for (i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	//����̕`��
	for ( i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			fist[i]->Draw();
		}
	}

	//�E��̕`��
	for (i = 0; i < 10; i++)
	{
		if (fist2[i] != nullptr)
		{
			fist2[i]->Draw();
		}
	}

	//���̕`��
	for ( i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			frame[i]->Draw();
		}
	}

}

bool GameMainScene::WhitCheck(Enemy* e, Wall* w)
{
	Vector2D diff_location = e->GetLocation() - w->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + w->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//�e
bool GameMainScene::BhitCheck(Enemy* e, S_Bullet* b)
{
	Vector2D diff_location = e->GetLocation() - b->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + b->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//����
bool GameMainScene::FhitCheck(Enemy* e, S_21Fist* f)
{
	Vector2D diff_location = e->GetLocation() - f->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + f->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//�E��
bool GameMainScene::FlhitCheck(Enemy* e, S_21FistL* l)
{
	Vector2D diff_location = e->GetLocation() - l->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + l->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//��
bool GameMainScene::HhitCheck(Enemy* e, S_Frame* h)
{
	Vector2D diff_location = e->GetLocation() - h->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + h->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}


