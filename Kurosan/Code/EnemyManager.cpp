////GAME_SCREEN_WIDTHを使うため
//#include"Common.h"
//#include "EnemyManager.h"
//#include "Enemy.h"
//#include <stdlib.h>
//#include <DxLib.h>
//
//void EnemyManager::Update()
//{
//	//生成
//	Spawn();
//	for (int num = 0; num < enemynum; num++)
//	{
//		//NULLでない場合
//		if (enemy[num] != NULL)
//		{
//			enemy[num]->Update();
//			//弾が画面外に出た場合
//			if (enemy[num]->GetFlag() == false)
//			{
//				//削除してからNULLを入れる
//				delete enemy[num];
//				enemy[num] = NULL;
//			}
//		}
//	}
//}
//void EnemyManager::Spawn()
//{
//	//一定確立で敵が出現
//	if ((rand() % 100) == 0)
//	{
//		for (int num = 0; num < enemynum; num++)
//		{
//			//NULLの場合
//			if (enemy[num] == NULL)
//			{
//				//敵を生成するX軸を決める
//				int yPos = (rand() % (WINDOW_WIDTH));
//				//敵生成
//				enemy[num] = new Enemy(&enemyGraphic, VGet(yPos, 0, 0));
//				//一体生成したら抜けるようにする
//				break;
//			}
//		}
//	}
//}