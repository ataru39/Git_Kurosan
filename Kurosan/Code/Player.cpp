#include "Player.h"
#include"../Utility/InputControl.h"
#include"Dxlib.h"

#define RUN				(0)
#define RUN1			(1)
#define RUN2			(2)
#define HIT				(3)
#define HIT1			(4)
#define HIT2			(5)
#define JUMP			(6)
#define JUMP1			(7)
#define JUMP2			(8)
#define JUMP3			(9)
#define SLIDING			(10)
#define CAR				(11)

#define RUN_SPAN		(105)
#define HIT_SPAN		(60)
#define JUMP_SPAN		(60)
#define SLIDING_SPAN	(60)
#define INVINCIBLETIME	(60)

Player::Player() :is_active(false), image(NULL), location(0.0f), box_size(0.0f), angle(0.0f),
speed(0.0f), hp(0.0f), fuel(0.0f), barrier_count(0), barrier(nullptr),
images{}, situation(0), hit(FALSE), red(FALSE), run_span(0), hit_span(0), jump_span(0), sliding_span(0), invincibletime(0)
{

}

Player::~Player()
{

}

//����������
void Player::Initialize()
{
	is_active = true;
	location = Vector2D(250.0f, 380.0f);
	box_size = Vector2D(19.0f, 30.0f);
	angle = 0.0f;
	speed = 3.0f;
	hp = 1000;
	fuel = 20000;
	barrier_count = 3;

	//�摜�̓ǂݍ���
	images[RUN1] = LoadGraph("Resource/images/player/run1.png");			//����摜1
	images[RUN2] = LoadGraph("Resource/images/player/run2.png");			//����摜2
	images[HIT1] = LoadGraph("Resource/images/player/hit1.png");			//�q�b�g�摜1
	images[HIT2] = LoadGraph("Resource/images/player/hit2.png");			//�q�b�g�摜2
	images[JUMP1] = LoadGraph("Resource/images/player/jump1.png");			//�W�����v�摜1
	images[JUMP2] = LoadGraph("Resource/images/player/jump2.png");			//�W�����v�摜2
	images[JUMP3] = LoadGraph("Resource/images/player/jump3.png");			//�W�����v�摜3
	images[SLIDING] = LoadGraph("Resource/images/player/sliding1.png");		//�X���C�f�B���O�摜
	images[CAR] = LoadGraph("Resource/images/player/car.png");				//�ԉ摜

	image = images[RUN1];
	situation = RUN;
	hit = FALSE;

	run_span = RUN_SPAN;
	hit_span = 0;
	jump_span = 0;
	sliding_span = 0;
	invincibletime = 0;

	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw("Resource/images/car1pol.bmp������܂���\n");
	}
}

//�X�V����
void Player::Update()
{
	//����s��Ԃł���΁A���M����]������
	if (!is_active)
	{
		if (situation == RUN)
		{
			hit = TRUE;
			hit_span = HIT_SPAN;
		}

		
		invincibletime = INVINCIBLETIME;
		is_active = true;
	}

	//�R���̏���
	fuel -= speed;

	//�ړ�����
	Movement();

	//����������
	Acceleration();

	//�t���[���̌v�Z
	if (run_span >= 0)
	{
		run_span -= speed;
	}
	if (hit_span >= 0)
	{
		hit_span -= 1;
	}
	if (jump_span >= 0)
	{
		jump_span -= 1;
	}
	if (sliding_span >= 0)
	{
		sliding_span -= 1;
	}
	//���G����
	if (invincibletime >= 0)
	{
		invincibletime -= 1;
	}

	//�v���C���[�̏�Ԃ̍X�V
	if (jump_span <= 0 && sliding_span <= 0)
	{
		situation = RUN;
	}
	if (jump_span == 1)
	{
		image = images[RUN1];
	}
	if (hit_span == 0)
	{
		hit = FALSE;
	}
	if(invincibletime==0)
	{
		image = images[RUN1];
	}
	
	//�����蔻��̕ω�
	if (situation == RUN)
	{
		box_size = Vector2D(19.0f, 30.0f);
	}
	if (IsCarMode())
	{
		box_size= Vector2D(30.0f, 70.0f);
	}


	//�W�����v����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		Jump();
	}

	//�X���C�f�B���O����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		Sliding();
	}

	//�e�X�g�p����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_Y))
	{
		//situation = CAR;
	}

	//�A�j���[�V����
	HitAnimation();
	RunAnimation();
	JumpAnimation();

	if (situation == CAR)
	{
		image = images[CAR];
	}
}

//�`�揈��
void Player::Draw()
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y-20, 1.0, angle, image, TRUE);

	//�����蔻��`��
	//DrawBox(location.x + box_size.x, location.y + box_size.y, location.x - box_size.x, location.y - box_size.y, GetColor(0, 0, 255), FALSE);

	//�o���A����������Ă�����A�`����s��
	if (barrier != nullptr)
	{
		barrier->Draw(this->location);
	}
}

//�I��������
void Player::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(image);

	//�o���A����������Ă�����A�폜����
	if (barrier != nullptr)
	{
		delete barrier;
	}
}

//��Ԑݒ菈��
void Player::SetActive(bool flg)
{
	this->is_active = flg;
}

//�̗͌�������
void Player::DecreaseHp(float value)
{
	this->hp += value;
}

//���擾
void Player::GetKey()
{
	situation = CAR;
	invincibletime = INVINCIBLETIME * 5;
	image = images[CAR];

}

//�ʒu���擾����
Vector2D Player::GetLocation()const
{
	return this->location;
}

//�����蔻��̑傫���擾����
Vector2D Player::GetBoxSize()const
{
	return this->box_size;
}

//�����擾����
float Player::GetSpeed()const
{
	return this->speed;
}

//�R���擾����
float Player::GetFuel()const
{
	return this->fuel;
}

//�̗͎擾����
float Player::GetHp()const
{
	return this->hp;
}

//�o���A�����擾����
int Player::GetBarriarCount()const
{
	return this->barrier_count;
}

//�o���A�L����?���擾
bool Player::IsBarrier()const
{
	return(barrier != nullptr);
}

//�W�����v�̐^�U���擾
bool Player::IsJump()const
{
	if (situation == JUMP)
	{
		return TRUE;
	}
	return FALSE;
}

//�X���C�f�B���O�̐^�U���擾
bool Player::IsSliding()const
{
	if (situation == SLIDING)
	{
		return TRUE;
	}
	return FALSE;
}

//�ԃ��[�h�̐^�U���擾
bool Player::IsCarMode()
{
	if (image == images[CAR])
	{
		return TRUE;
	}
	return FALSE;
}

//���G��Ԃ̐^�U���擾
bool Player::IsInvincible()
{
	if (invincibletime > 0)
	{
		return TRUE;
	}
	return FALSE;
}

//�ړ�����
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);
	angle = 0.0f;

	//�\���ړ�����
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		move += Vector2D(-3.0f, 0.0f);
		angle = -DX_PI_F / 18;
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		move += Vector2D(3.0f, 0.0f);
		angle = DX_PI_F / 18;
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_UP))
	{
		//move += Vector2D(0.0f, -1.0f);
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		//move += Vector2D(0.0f, 1.0f);
	}

	//�X�e�B�b�N�ړ�����
	if (InputControl::GetLeftStick().x < -0.2)
	{
		move += Vector2D(-3.0f, 0.0f);
		angle = -DX_PI_F / 18;
	}
	if (InputControl::GetLeftStick().x > 0.2)
	{
		move += Vector2D(3.0f, 0.0f);
		angle = DX_PI_F / 18;
	}
	if (InputControl::GetLeftStick().y < -0.2)
	{
		//move += Vector2D(0.0f, -1.0f);
	}
	if (InputControl::GetLeftStick().y > 0.2)
	{
		//move += Vector2D(0.0f, 1.0f);
	}

	location += move;

	//��ʊO�ɍs���Ȃ��悤�ɐ�������
	if ((location.x < box_size.x) || (location.x >= 640.0f - 180.0f) || (location.y < box_size.y) || (location.y >= 480.0f - box_size.y))
	{
		location -= move;
	}
}

//����������
void Player::Acceleration()
{
	//LB�{�^���������ꂽ��A��������
	if (InputControl::GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) && speed > 1.0f)
	{
		speed -= 1.0f;
	}

	//RB�{�^���������ꂽ��A��������
	if (IsCarMode())
	{
		if (InputControl::GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) && speed < 20.0f)
		{
			speed += 1.0f;
		}
	}
	else
	{
		if (InputControl::GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) && speed < 10.0f)
		{
			speed += 1.0f;
		}
	}

	if (IsCarMode())
	{
		speed = 20.0f;
	}

	if (!IsCarMode() && speed >= 20.0f)
	{
		speed = 10.0f;
	}
}

//�W�����v����
void Player::Jump()
{
	//�v���C���[�������Ă���Ȃ�W�����v����
	if (situation == RUN)
	{
		situation = JUMP;

		//�W�����v�L�����Ԃ�ݒ肷��
		jump_span = JUMP_SPAN;
	}	
}

//�X���C�f�B���O����
void Player::Sliding()
{
	//�v���C���[�������Ă���Ȃ�X���C�f�B���O����
	if (situation == RUN)
	{
		situation = SLIDING;

		//�摜���X���C�f�B���O�ɂ���
		image = images[SLIDING];

		//�X���C�f�B���O�L�����Ԃ�ݒ肷��
		sliding_span = SLIDING_SPAN;
	}	
}

//����A�j���[�V����
void Player::RunAnimation()
{
	if (situation == RUN)
	{
		if (run_span <= 0)
		{
			if (image == images[RUN1] || image == images[HIT1])
			{
				image = images[RUN2];

			}
			else if (image == images[RUN2] || image == images[HIT2] || image == images[JUMP3] || image == images[SLIDING])
			{
				image = images[RUN1];

			}	
			run_span = RUN_SPAN;
		}

		if (red == TRUE)
		{
			if (image == images[RUN1])
			{
				image = images[HIT1];
			}
			else if (image == images[RUN2])
			{
				image = images[HIT2];
			}
		}
		else
		{
			if (image == images[RUN1])
			{
				image = images[RUN1];
			}
			else if (image == images[RUN2])
			{
				image = images[RUN2];
			}
		}
	}	
}

//�q�b�g�A�j���[�V����
void Player::HitAnimation()
{
	if (hit == TRUE)
	{
		if (hit_span > 0)
		{
			if (hit_span <= HIT_SPAN && hit_span > HIT_SPAN - (HIT_SPAN / 8))
			{
				red = TRUE;
			}
			else if (hit_span <= HIT_SPAN - (HIT_SPAN / 8) && hit_span > HIT_SPAN - ((HIT_SPAN / 8) * 2))
			{
				red = FALSE;
			}
			else if (hit_span <= HIT_SPAN - ((HIT_SPAN / 8) * 2) && hit_span > HIT_SPAN - ((HIT_SPAN / 8) * 3))
			{
				red = TRUE;
			}
			else if (hit_span <= HIT_SPAN - ((HIT_SPAN / 8) * 4) && hit_span > HIT_SPAN - ((HIT_SPAN / 8) * 5))
			{
				red = FALSE;
			}
			else if (hit_span <= HIT_SPAN - ((HIT_SPAN / 8) * 5) && hit_span > HIT_SPAN - ((HIT_SPAN / 8) * 6))
			{
				red = TRUE;
			}
			else if (hit_span <= HIT_SPAN - ((HIT_SPAN / 8) * 6) && hit_span > HIT_SPAN - ((HIT_SPAN / 8) * 7))
			{
				red = FALSE;
			}
			else if ( hit_span > 0)
			{
				red = TRUE;
			}
		}
	}
	if (hit_span < 0)
	{
		red = FALSE;
		//hit = FALSE;
	}
}

//�W�����v�A�j���[�V����
void Player::JumpAnimation()
{
	if (situation == JUMP)
	{
		if (jump_span <= JUMP_SPAN && jump_span > JUMP_SPAN - (JUMP_SPAN / 3))
		{
			image = images[JUMP1];
		}
		if (jump_span <= JUMP_SPAN - (JUMP_SPAN / 3) && jump_span > (JUMP_SPAN / 3))
		{
			image = images[JUMP2];
		}
		if (jump_span <= (JUMP_SPAN / 3) && jump_span > 0)
		{
			image = images[JUMP3];
		}
		if (jump_span == 0)
		{
			image = images[RUN2];
		}
	}
}