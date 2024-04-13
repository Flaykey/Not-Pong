#pragma once
#include<raylib.h>
#include<iostream>
#include"ball.h"
class Player
{
private:
    float width;
    float height;
    Color color;
    Vector2 pos;
    Rectangle Paddle;
    Rectangle Health;

public:
    float Increment;

    Player();
    ~Player();
    void Init(Vector2 pos, float w, float h, Color col);
    void PongUpdate(KeyboardKey Up, KeyboardKey Down);
    void PongDraw();
    bool BallCollide(Ball *ball);
    void Reset();

    int GetHeight();
    void SetHeight(int a);
    Rectangle GetPaddle();
};

