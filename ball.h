#pragma once
#include<raylib.h>
#include<raymath.h>

class Player;

class Ball
{
private:
    float radius;
    float speed;
    Vector2 pos;
    Vector2 vel;

public:
    Vector2 dir;
    float distance;

    Ball();
    ~Ball();
    void Init();
    void Draw();
    void Update();
    void Reset();

    Vector2 GetPosition();
    Vector2 GetVel();

    float GetRadius();

    void SetSpeed(float increment);
    void PaddleCollide(Player *player);
};