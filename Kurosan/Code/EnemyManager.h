#pragma once
class EnemyManager
{
	Enemy* enemy[enemynum];
	//“G‚Ì‰æ‘œ
	int enemyGraphic;
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Render();
private:
	//“G‚Ì¶¬
	void Spawn();
};