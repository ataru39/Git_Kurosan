#pragma once
class EnemyManager
{
	Enemy* enemy[enemynum];
	//�G�̉摜
	int enemyGraphic;
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Render();
private:
	//�G�̐���
	void Spawn();
};