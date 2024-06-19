#pragma once

class UI
{
public:
	UI();
	~UI();

	void Draw()const;
	void Update();
	void Initialize();
	void Finalize();
	bool GetIsClear();
	int GetTime();

private:
	int sec;	// •b
	int minute;	// •ª
	int frame;
	int image;
	int font;
};