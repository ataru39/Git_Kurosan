#pragma once
class UI
{
public:
	UI();
	~UI();

	void Draw();
	void Update();

	void Initialize();

private:

	int time;
	int frame;
};