//GAME_SCREEN_WIDTH‚ğg‚¤‚½‚ß
#include"Common.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include <stdlib.h>
#include <DxLib.h>

void EnemyManager::Update()
{
	//¶¬
	Spawn();
	for (int num = 0; num < enemynum; num++)
	{
		//NULL‚Å‚È‚¢ê‡
		if (enemy[num] != NULL)
		{
			enemy[num]->Update();
			//’e‚ª‰æ–ÊŠO‚Éo‚½ê‡
			if (enemy[num]->GetFlag() == false)
			{
				//íœ‚µ‚Ä‚©‚çNULL‚ğ“ü‚ê‚é
				delete enemy[num];
				enemy[num] = NULL;
			}
		}
	}
}
void EnemyManager::Spawn()
{
	//ˆê’èŠm—§‚Å“G‚ªoŒ»
	if ((rand() % 100) == 0)
	{
		for (int num = 0; num < enemynum; num++)
		{
			//NULL‚Ìê‡
			if (enemy[num] == NULL)
			{
				//“G‚ğ¶¬‚·‚éX²‚ğŒˆ‚ß‚é
				int yPos = (rand() % (WINDOW_WIDTH));
				//“G¶¬
				enemy[num] = new Enemy(&enemyGraphic, VGet(yPos, 0, 0));
				//ˆê‘Ì¶¬‚µ‚½‚ç”²‚¯‚é‚æ‚¤‚É‚·‚é
				break;
			}
		}
	}
}