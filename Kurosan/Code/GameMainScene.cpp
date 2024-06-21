#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>
#include "../Utility/InputControl.h"

GameMainScene::GameMainScene()
{
	// �G�̐��������
	enemymax = 300;

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

	// ���I�u�W�F�N�g
	fist = new S_21Fist * [10];
	// ������
	for (int i = 0; i < 10; i++)
	{
		fist[i] = nullptr;
	}
	//����
	fistl = new S_21FistL * [10];
	// ������
	for (int i = 0; i < 10; i++)
	{
		fistl[i] = nullptr;
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

	// ���̃N�[���^�C��������
	f_cooltime = 0;
	l_cooltime = 200;

	// �J�E���g
	cnt = 0;
	levelcnt = 0;
}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
	delete enemy;
	delete ui;
	delete bullet;
	delete fist;
	delete fistl;
	delete frame;
	InitSoundMem();
}

// ����������
void GameMainScene::Initialize()
{
	// �摜�Ǎ�
	grace = LoadGraph("Resources/Images/background_grace.png");

	// �T�E���h�Ǎ�
	bgm_gm = LoadSoundMem("Resources/Sounds/GameMain_BGM.mp3");
	se_clear = LoadSoundMem("Resources/Sounds/GameClear.mp3");
	se_over = LoadSoundMem("Resources/Sounds/GameOver.mp3");
	se_bullet = LoadSoundMem("Resources/Sounds/Bullet_Act.mp3");
	se_fist = LoadSoundMem("Resources/Sounds/Fist_Act.mp3");
	se_fist_hit = LoadSoundMem("Resources/Sounds/Fist_Hit.mp3");
	se_flame = LoadSoundMem("Resources/Images/Sounds/Flame_Act.mp3.mp3");
	se_flame_hit = LoadSoundMem("Resources/Sounds/Flame_Hit.mp3");
	se_levelup = LoadSoundMem("Resources/Sounds/LevelUp.mp3");


	ChangeVolumeSoundMem(200, bgm_gm);
	ChangeVolumeSoundMem(170, se_bullet);
	ChangeVolumeSoundMem(150, se_levelup);

	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

// �X�V����
eSceneType GameMainScene::Update()
{
	if (wall->WallBreak() || is_clear)
	{
		//BGM���Đ�����Ă�����~�߂�
		if (CheckSoundMem(bgm_gm))
		{
			StopSoundMem(bgm_gm);
			DeleteSoundMem(bgm_gm);
		}

		// �Q�[���N���A�\��
		is_clear = ui->GetIsClear();
		if (is_clear)
		{
			cnt++;
			PlaySoundMem(se_clear, DX_PLAYTYPE_BACK);
			if (cnt > 180)
			{
				return eSceneType::E_TITLE;
			}
		}

		//�Q�[���I�[�o�[�\��
		is_over = wall->WallBreak();
		if (is_over)
		{
			cnt++;
			PlaySoundMem(se_over, DX_PLAYTYPE_BACK);
			if (cnt > 180)
			{
				return eSceneType::E_TITLE;
			}
		}

	}
	else {


		player->Update();
		wall->Update();
		ui->Update();

		if (is_levelup) {
			if (!CheckSoundMem(se_levelup))
			{
				PlaySoundMem(se_levelup, DX_PLAYTYPE_BACK);
			}
			levelcnt = 60;
		}

		if (levelcnt > 0) {
			levelcnt--;
		}
		else if (levelcnt <= 0)
		{
			is_levelup = false;
		}
		// BGM���Đ�����ĂȂ�����BGM�Đ�
		if (!CheckSoundMem(bgm_gm))
		{
			PlaySoundMem(bgm_gm, DX_PLAYTYPE_BACK);
		}

		// �G�̐���
		if (e_delay <= 0) {								//�Ԋu
			for (int i = 0; i < enemymax; i++) {		//�����
				if (enemy[i] == nullptr)				//�z��enemy�̒�����̎�
				{
					enemy[i] = new Enemy();				//��̔z��ɃG�l�~�[�����
					if (ui->GetTime() >= 2) {
						e_type = 0;
					}
					else if (ui->GetTime() >= 1) {
						//fun = 2;
						e_type = (rand() % 2);
					}
					else {
						//fun = 3;
						e_type = (rand() % 3);
					}
					enemy[i]->Initialize(e_type, player->GetLevel());				//����������
					e_delay = 90 - player->GetLevel() * 8;	//�G�����Ԋu
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
					b_cooltime = 50 - (player->GetLevel() * 3);
					PlaySoundMem(se_bullet, DX_PLAYTYPE_BACK);
					break;
				}
			}
		}

		// �e�N�[���^�C����������
		if (b_cooltime > 0)
		{
			b_cooltime--;
		}

		// ����������
		if (player->GetLevel() > 5) {
			if (f_cooltime <= 0)
			{
				for (int i = 0; i < 10; i++)
				{
					if (fist[i] == nullptr)
					{
						fist[i] = new S_21Fist();
						fist[i]->Initialize(player->GetLocation());
						f_cooltime = 300 - (player->GetLevel() * 25);
						PlaySoundMem(se_fist, DX_PLAYTYPE_BACK);
						break;
					}
				}
			}
		}
		// �N�[���^�C����������
		if (f_cooltime > 0)
		{
			f_cooltime--;
		}

		// ���萶������
		if (player->GetLevel() > 4) {
			if (l_cooltime <= 0)
			{
				for (int i = 0; i < 10; i++)
				{
					if (fistl[i] == nullptr)
					{
						fistl[i] = new S_21FistL();
						fistl[i]->Initialize(player->GetLocation());
						l_cooltime = 300 - (player->GetLevel() * 25);
						PlaySoundMem(se_fist, DX_PLAYTYPE_BACK);
						break;
					}
				}
			}
		}
		// �N�[���^�C����������
		if (l_cooltime > 0)
		{
			l_cooltime--;
		}

		// ����������
		if (player->GetLevel() > 2) {
			if (h_cooltime <= 0)
			{
				for (int i = 0; i < 10; i++)
				{
					if (frame[i] == nullptr && enemy[i] != nullptr)
					{
						frame[i] = new S_Frame();
						frame[i]->Initialize(player->GetLocation(), enemy[i]->GetLocation());
						h_cooltime = 300;
						PlaySoundMem(se_flame, DX_PLAYTYPE_BACK);
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

		// ���̍X�V����
		for (int i = 0; i < 10; i++)
		{
			if (fist[i] != nullptr)
			{
				fist[i]->Update();
			}
		}
		// ���̍X�V����
		for (int i = 0; i < 10; i++)
		{
			if (fistl[i] != nullptr)
			{
				fistl[i]->Update();
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

		//���̍폜����
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

		//����̍폜����
		for (int i = 0; i < 10; i++)
		{
			if (fistl[i] != nullptr)
			{
				l_location = fistl[i]->GetLocation();
				if (fistl[i]->FadeOut() <= 0) {
					fistl[i] = nullptr;
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

					if (fist[j] != nullptr) {
						//fist[i]->Level(player->GetLevel());
						if (FhitCheck(enemy[i], fist[j])) {
							enemy[i]->Damage(fist[j]->GetDamage());
							if (!CheckSoundMem(se_fist_hit))
							{
								PlaySoundMem(se_fist_hit, DX_PLAYTYPE_BACK);
							}
							if (enemy[i]->GetHP() <= 0)
							{
								player->RcvExp(enemy[i]->GetExp());	// �v���C���[��EXP��n��
								is_levelup = player->Levelup();
								enemy[i] = nullptr;
								delete enemy[i];
							}
							break;
						}
					}

					if (fistl[j] != nullptr) {
						//fist[i]->Level(player->GetLevel());
						if (FlhitCheck(enemy[i], fistl[j])) {
							if (!CheckSoundMem(se_fist_hit))
							{
								PlaySoundMem(se_fist_hit, DX_PLAYTYPE_BACK);
							}
							enemy[i]->Damage(fistl[j]->GetDamage());
							if (enemy[i]->GetHP() <= 0)
							{
								player->RcvExp(enemy[i]->GetExp());	// �v���C���[��EXP��n��
								is_levelup = player->Levelup();
								enemy[i] = nullptr;
								delete enemy[i];
							}
							break;
						}
					}

					if (frame[j] != nullptr) {
						if (HhitCheck(enemy[i], frame[j])) {
							if (!CheckSoundMem(se_flame_hit))
							{
								PlaySoundMem(se_flame_hit, DX_PLAYTYPE_BACK);
							}
							enemy[i]->Damage(frame[j]->GetDamage());
							frame[j] = nullptr;
							delete frame[j];
							if (enemy[i]->GetHP() <= 0)				// �G�����񂾂Ƃ�
							{
								player->RcvExp(enemy[i]->GetExp());	// �v���C���[��EXP��n��
								is_levelup = player->Levelup();
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

	//�G�̕`��
	for (int i = 0; i < enemymax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	ui->Draw();
	wall->Draw();
	player->Draw();

	if (levelcnt > 0) {
		DrawString(player->GetLocation().x - 40, player->GetLocation().y - 60, "LEVEL UP", 0xffff00);
	}

	//�e�̕`��
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	//���̕`��
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			fist[i]->Draw();
		}
	}

	//����̕`��
	for (int i = 0; i < 10; i++)
	{
		if (fistl[i] != nullptr)
		{
			fistl[i]->Draw();
		}
	}


	//���̕`��
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			frame[i]->Draw();
		}
	}

	// ���x����EXP
	SetFontSize(20);
	DrawString(30, 30, "�v���C���[���x��", 0xffffff);
	DrawFormatString(220, 30, 0xffffff, "%d", player->GetLevel());


	//�N���A�\��
	if (is_clear)
	{
		// �������ɂ��ă��j���[�w�i�̎l�p
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(150, 250, 1130, 530, GetColor(0, 0, 255));
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		// �s�����ɖ߂��Ĕ����g
		DrawLineBox(150, 250, 1130, 530, GetColor(255, 255, 255));

		SetFontSize(120);
		DrawString(200, 300, "�Q�[���N���A!!", GetColor(255, 255, 255));
	}

	//�Q�[���I�[�o�[�\��
	if (is_over)
	{
		// �������ɂ��ă��j���[�w�i�̎l�p
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(150, 250, 1130, 530, GetColor(0, 0, 255));
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		// �s�����ɖ߂��Ĕ����g
		DrawLineBox(150, 250, 1130, 530, GetColor(255, 255, 255));

		SetFontSize(120);
		DrawString(200, 300, "�Q�[���I�[�o�[", GetColor(255, 255, 255));
	}
}

//�I��������
void GameMainScene::Finalize()
{
	player->Finalize();
	ui->Finalize();
	wall->Finalize();
}

bool GameMainScene::WhitCheck(Enemy* e, Wall* w)
{
	Vector2D diff_location = e->GetLocation() - w->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + w->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::BhitCheck(Enemy* e, S_Bullet* b)
{
	Vector2D diff_location = e->GetLocation() - b->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + b->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::FhitCheck(Enemy* e, S_21Fist* f)
{
	Vector2D diff_location = e->GetLocation() - f->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + f->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::FlhitCheck(Enemy* e, S_21FistL* l)
{
	Vector2D diff_location = e->GetLocation() - l->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + l->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

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
