#pragma once
class UI
{
public:
	UI();
	~UI();

	void Draw()const;
	void Update();
	int Time();
	void Initialize();
	void Finalize();

private:
	int time;
	int frame;
	int barimage[13];
	int y_i;
	int image;
};