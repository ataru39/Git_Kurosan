#pragma once
class UI
{
public:
	UI();
	~UI();

	void Draw();
	void Update();
	int Time();
	void Initialize();
	void Finalize();

private:
	int time;
	int frame;
	int whight;
	int image;
};