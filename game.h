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
    
    double ResetLastTime;

    int state;

public:
    Game(int w, int h);
    ~Game();
    void Init();
    void Run();
    void Update();
    void Draw();

    void UpdatePong();
    void UpdateBattle();

    void DrawPong();
    void DrawBattle();

    void DrawLine();
    void DrawTime();

    void DrawScore();
};

