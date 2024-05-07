//GAME_SCREEN_WIDTH���g������
#include"Common.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include <stdlib.h>
#include <DxLib.h>

void EnemyManager::Update()
{
	//����
	Spawn();
	for (int num = 0; num < enemynum; num++)
	{
		//NULL�łȂ��ꍇ
		if (enemy[num] != NULL)
		{
			enemy[num]->Update();
			//�e����ʊO�ɏo���ꍇ
			if (enemy[num]->GetFlag() == false)
			{
				//�폜���Ă���NULL������
				delete enemy[num];
				enemy[num] = NULL;
			}
		}
	}
}
void EnemyManager::Spawn()
{
	//���m���œG���o��
	if ((rand() % 100) == 0)
	{
		for (int num = 0; num < enemynum; num++)
		{
			//NULL�̏ꍇ
			if (enemy[num] == NULL)
			{
				//�G�𐶐�����X�������߂�
				int yPos = (rand() % (WINDOW_WIDTH));
				//�G����
				enemy[num] = new Enemy(&enemyGraphic, VGet(yPos, 0, 0));
				//��̐��������甲����悤�ɂ���
				break;
			}
		}
	}
}