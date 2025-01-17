#include"player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init(Vector2 pos, float w, float h, Color col)
{
    this->pos = pos;
    this->width = w;
    this->height = h;
    this->pos.y -= h/2;
    this->color = col;
    this->Paddle = Rectangle{this->pos.x,this->pos.y,this->width, this->height};
    this->Health = this->Paddle;
    this->Health.height = 0;
}

void Player::PongUpdate(KeyboardKey Up, KeyboardKey Down)
{
    if(IsKeyDown(Up))
    {
        this->Paddle.y -= 8;
        //std::cout<<"up";
    }

    if(IsKeyDown(Down))
    {
        this->Paddle.y += 8;
        //std::cout<<"down";
    }

    if(this->Paddle.y < 0) this->Paddle.y = 0;
    if(this->Paddle.y+this->Paddle.height > GetScreenHeight()) this->Paddle.y = GetScreenHeight() - this->Paddle.height;

}

void Player::PongDraw()
{
    DrawRectangleRec(this->Paddle,WHITE);
}

void Player::BattleUpdate()
{
    this->Health.y = this->Paddle.y + this->Paddle.height - this->Health.height;
    if(this->Health.height < 100){
        this->Health.height += 1;
    }
}

void Player::BattleDraw()
{
    DrawRectangleRec(this->Paddle,WHITE);
    DrawRectangleRec(this->Health,this->color);

}

bool Player::BallCollide(Ball *ball)
{
    return CheckCollisionCircleRec(ball->GetPosition(), ball->GetRadius(), this->Paddle);
}

void Player::Reset()
{
    if(this->Paddle.height < 100){

    this->Paddle.height += this->Increment / GetFPS() / 2;
    this->Paddle.y -= this->Increment / GetFPS() / 4;
    }

    if (this->Paddle.height > 100)
        this->Paddle.height = 100;

}

int Player::GetHeight()
{
    return this->height;
}

void Player::SetHeight(int a)
{
    if(this->Paddle.height > 20)
    {
        this->Paddle.height -= a;
    }
    
}

Rectangle Player::GetPaddle()
{
    return this->Paddle;
}
