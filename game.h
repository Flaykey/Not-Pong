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

    int ScoreA;
    int ScoreB;
    int Timer;
    
    double LastTime;

public:
    Game(int w, int h);
    ~Game();
    void Init();
    void Run();
    void Update();
    void Draw();
    void DrawLine();
    void DrawTime();
};

