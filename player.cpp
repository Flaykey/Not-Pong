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

bool Player::BallCollide(Ball *ball)
{
    return CheckCollisionCircleRec(ball->GetPosition(), ball->GetRadius(), this->Paddle);
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
