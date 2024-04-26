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

private:
	int time;
	int frame;
};