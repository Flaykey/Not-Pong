#include "player.h"
#include"ball.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Init()
{
    float possibleDir[2] = {-1,1};
    this->pos = Vector2{(float) GetScreenWidth()/2 ,(float) GetScreenHeight()/2};
    this->vel = Vector2{ possibleDir[GetRandomValue(1,10) % 2 ], possibleDir[GetRandomValue(1,10) % 2]};
    this->radius = 10.0f;
    this->speed = 5.0f;
    
}

void Ball::Draw()
{
    DrawCircleV(this->pos, this->radius, WHITE);
}

void Ball::Update()
{
    this->vel = Vector2Normalize(this->vel);
    this->vel = Vector2Scale(this->vel , this->speed);
    this->pos = Vector2Add(this->pos, this->vel);

    // celling    
    if(this->pos.y - this->radius < 0 || this->pos.y + this->radius > GetScreenHeight())
    {
        this->vel.y *= -1;
        this->speed += 0.1;
    }

}

void Ball::Reset()
{
    
}

Vector2 Ball::GetPosition()
{
    return this->pos;
}

Vector2 Ball::GetVel()
{
    return this->vel;
}

float Ball::GetRadius()
{
    return this->radius;
}

void Ball::SetSpeed(float increment)
{
    this->speed += increment;
}

void Ball::PaddleCollide(Player *player)
{
    this->vel.x *= -1;
    this->vel.y = (this->pos.y - (player->GetPaddle().y + player->GetPaddle().height/2)) / 10;
    this->speed += 0.25;
}


