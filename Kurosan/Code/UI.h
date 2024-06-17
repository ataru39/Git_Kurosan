#pragma once
class UI
{
public:
	UI();
	~UI();

	void Draw()const;
	void Update();
	void Initialize();
	bool GetIsClear();

private:
	int sec;	// •b
	int minute;	// •ª
	int frame;
	int image;
	int font;
};