#include "GameMainScene.h"
#include"RankingData.h"
#include"DxLib.h"
#include<math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL), barrier_image(NULL), mileage(0), nowscore(0), coin(0), item_get_se(0),getkey(0),
player(nullptr), obstacle(nullptr), item(nullptr), BGM(0)
{

	for (int i = 0; i < 3; i++)
	{
		obstacle_image[i] = NULL;
		obstacle_count[i] = NULL;
	}

	for (int i = 0; i < 2; i++)
	{
		item_image[i] = NULL;
	}
}

GameMainScene::~GameMainScene()
{

}

//����������
void GameMainScene::Initialize()
{
	//�����_�l��ǂݍ���
	ReadHighScore();

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/back.bmp");
	barrier_image = LoadGraph("Resource/images/barrier.png");
	int result = LoadDivGraph("Resource/images/obstacle.png", 3, 3, 1, 104, 72, obstacle_image);
	item_image[0] = LoadGraph("Resource/images/item/coin.png");
	item_image[1] = LoadGraph("Resource/images/item/key.png");

	//�T�E���h�̓ǂݍ���
	item_get_se = LoadSoundMem("Resource/Sounds/SE/se_coin_get.mp3");
	BGM = LoadSoundMem("Resource/Sounds/bgm/main/mp3");

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}
	if (result == -1)
	{
		throw("Resource/images/obstacle.bmp������܂���\n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}

	//�I�u�W�F�N�g�̐���
	player = new Player;
	obstacle = new Obstacle * [10];
	item = new Item * [10];

	//�I�u�W�F�N�g������
	player->Initialize();

	for (int i = 0; i < 10; i++)
	{

		obstacle[i] = nullptr;
	}

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr;
	}
}

//�X�V����
eSceneType GameMainScene::Update()
{
	StopSoundMem(BGM);

	//�v���C���[�̍X�V
	player->Update();

	//�ړ������̍X�V
	mileage += (int)player->GetSpeed() + 5;

	int count = 0;
	int nownumber = 0;

	//��Q����������
	if (mileage / 20 % 100 == 0)
	{

		for (int i = 0; i < 10; i++)
		{

			nownumber = i;

			if (obstacle[i] == nullptr)
			{

				int type = GetRand(3) % 3;
				if (type == 0)
				{

					while (count <= 2)
					{

						obstacle[nownumber] = new Obstacle(type, obstacle_image[type]);
						obstacle[nownumber]->Initialize(type, count);
						nownumber++;
						count++;
					}

					count = 0;

					break;
				}
				else
				{

					obstacle[i] = new Obstacle(type, obstacle_image[type]);
					obstacle[i]->Initialize(type, 0);
					break;
				}
			}
		}
	}

	//�A�C�e����������
	if (mileage / 20 % 100 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			int Prob = GetRand(10);
			if (Prob > 1) {
				int type = 0;
				item[i] = new Item(type, item_image[type]);
				item[i]->Initialize();
				break;
			}
			else{
				int type = 1;
				item[i] = new Item(type, item_image[type]);
				item[i]->Initialize();
				break;
			}
		}
	}

	//�G�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 10; i++)
	{
		if (obstacle[i] != nullptr)
		{
			obstacle[i]->Update(player->GetSpeed());

			//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
			if (obstacle[i]->GetLocation().y >= 640.0f)
			{
				obstacle_count[obstacle[i]->GetType()]++;
				//nowscore += (obstacle[i]->GetType() + 1) * 200;
				obstacle[i]->Finalize();
				delete obstacle[i];
				obstacle[i] = nullptr;
			}

			if (obstacle[i] != nullptr)
			{
				//�����蔻��̊m�F
				if (IsHitCheck(player, obstacle[i]))
				{
					if (player->IsCarMode())
					{
						obstacle[i]->Finalize();
						delete obstacle[i];
						obstacle[i] = nullptr;
					}
					else
					{
						player->SetActive(false);
						player->DecreaseHp(-100.0f);
						obstacle[i]->Finalize();
						delete obstacle[i];
						obstacle[i] = nullptr;
					}
				}
				/*else
				{
					nowscore += (obstacle[i]->GetType() + 1) * 200;
				}*/
			}
		}
	}
	//�A�C�e���̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 10; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Update(player->GetSpeed());

			//��ʊO�ɍs������A�A�C�e�����폜
			if (item[i]->GetLocation().y >= 640.0f)
			{
				item[i]->Finalize();
				delete item[i];
				item[i] = nullptr;

			}

			if (item[i] != nullptr)
			{
				//�����蔻��̊m�F
				if (IsItemHitCheck(player, item[i]))
				{
					

					if (item[i]->GetType() == 0)
					{
						coin += 1;
						nowscore += 500;
					}
					else
					{
						player->GetKey();
					}

					item[i]->Finalize();
					delete item[i];
					item[i] = nullptr;
					PlaySoundMem(item_get_se, DX_PLAYTYPE_BACK);
				}
			}
		}
	}

	//���݂̃X�R�A�̍X�V
	/*for (int i = 0; i < 3; i++)
	{
		nowscore += (i + 1) * 200 * obstacle_count[i];
	}
	nowscore += coin * 500;*/

	//�v���C���[�̔R�����̗͂�0�����Ȃ�A���U���g�ɑJ�ڂ���
	if (player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}

	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{
	//�w�i�摜�̕`��
	DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraph(0, mileage % 480, back_ground, TRUE);

	//��Q���̕`��
	for (int i = 0; i < 10; i++)
	{
		if (obstacle[i] != nullptr)
		{
			obstacle[i]->Draw();
		}
	}

	//�A�C�e���̕`��
	for (int i = 0; i < 10; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Draw();
		}
	}

	//�v���C���[�̕`��
	player->Draw();

	//UI�̕`��
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "�n�C�X�R�A");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	DrawFormatString(510, 80, GetColor(0, 0, 0), "��������");
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, obstacle_image[i], TRUE, FALSE);
		DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d", obstacle_count[i]);
	}

	DrawFormatString(510, 180, GetColor(0, 0, 0), "�l�������R�C��");
	DrawRotaGraph(533, 220, 1, 0, item_image[0], TRUE, FALSE);
	DrawFormatString(555, 212, GetColor(0, 0, 0), "�~");
	DrawFormatString(580, 212, GetColor(255, 255, 255), "%03d", coin);

	DrawFormatString(510, 250, GetColor(0, 0, 0), "�R�C���̃X�R�A");
	DrawFormatString(535, 270, GetColor(0, 0, 0), "%10d", nowscore);

	DrawFormatString(510, 300, GetColor(0, 0, 0), "���s����");
	DrawFormatString(555, 320, GetColor(0, 0, 0), "%08d", mileage / 10);
	DrawFormatString(510, 340, GetColor(0, 0, 0), "�X�s�[�h");
	DrawFormatString(555, 360, GetColor(0, 0, 0), "%08.1f", player->GetSpeed());

	float fx = 510.0f;
	float fy = 430.0f;
	DrawFormatStringF(fx, fy, GetColor(0, 0, 0), "PLAYER HP");
	DrawBoxAA(fx, fy + 20.0f, fx + (player->GetHp() * 100 / 1000), fy + 40.0f, GetColor(255, 0, 0), TRUE);
	DrawBoxAA(fx, fy + 20.0f, fx + 100.0f, fy + 40.0f, GetColor(0, 0, 0), FALSE);
}

//�I��������
void GameMainScene::Finalize()
{
	StopSoundMem(BGM);

	int score = 0;

	//�X�R�A���v�Z����
	score += (mileage / 10);
	
	for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 200 * obstacle_count[i];
	}

	score += coin * 500;

	//���U���g�f�[�^�̏�������
	FILE* fp = nullptr;
	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���J���܂���\n");
	}

	//�X�R�A��ۑ�
	fprintf(fp, "%d,\n", score);

	//���������Ɠ��_��ۑ�
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d,\n", obstacle_count[i]);
	}

	//�l�������R�C���̖�����ۑ�
	fprintf(fp, "%d,\n", coin);

	//�t�@�C���N���[�Y
	fclose(fp);

	//���I�m�ۂ����I�u�W�F�N�g���폜
	player->Finalize();
	delete player;

	for (int i = 0; i < 10; i++)
	{
		if (obstacle[i] != nullptr)
		{
			obstacle[i]->Finalize();
			delete obstacle[i];
			obstacle[i] = nullptr;
		}
	}

	delete[]obstacle;

	for (int i = 0; i < 10; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Finalize();
			delete item[i];
			item[i] = nullptr;
		}
	}

	delete[]item;
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}

//�n�C�X�R�A�̓ǂݍ���
void GameMainScene::ReadHighScore()
{
	RankingData data;
	data.Initialize();

	high_score = data.GetScore(0);

	data.Finalize();
}

//�����蔻�菈��(�v���C���[�ƓG)
bool GameMainScene::IsHitCheck(Player* p, Obstacle* e)
{
	switch (e->GetType())
	{
	case 0:
		break;
	case 1:		//�W�����v����`�F�b�N
		if (p->IsJump())
		{
			return false;
		}
		else
		{
			break;
		}
	case 2:		//�X���C�f�B���O����`�F�b�N
		if (p->IsSliding())
		{
			return false;
		}
		else
		{
			break;
		}
	default:
		break;
	}

	//�v���C���[�����G��ԂȂ�A�����蔻��𖳎�����
	if (p->IsInvincible())
	{
		return false;
	}

	//�G��񂪖�����΁A�����蔻��𖳎�����
	if (e == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//�����蔻�菈��(�v���C���[�ƃA�C�e��)
bool GameMainScene::IsItemHitCheck(Player* p, Item* i)
{
	//�G��񂪖�����΁A�����蔻��𖳎�����
	if (i == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - i->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

