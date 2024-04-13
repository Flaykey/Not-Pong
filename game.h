#pragma once
#include<iostream>
#include<raylib.h>

#include "ball.h"
#include "player.h"


class Game
{
private:
    int ScreenWidth;
    int ScreenHeight;
    Player PaddleA;
    Player PaddleB;
    Ball ball;
    

public:
    Game(int w, int h);
    ~Game();
    void Init();
    void Run();
    void Update();
    void Draw();
    void DrawLine();
};

