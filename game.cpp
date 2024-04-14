#include"game.h"

Game::Game(int w, int h)
{
    this->ScreenWidth = w;
    this->ScreenHeight = h;
}

Game::~Game()
{
    CloseWindow();
    std::cout<<"exited";
}

void Game::Init()
{
    InitWindow(this->ScreenWidth,this->ScreenHeight,"Not Pong");
    SetTargetFPS(60);

    this->PaddleA.Init(Vector2 {10,(float)GetScreenHeight()/2},15,100,BLUE);
    this->PaddleB.Init(Vector2 {(float)GetScreenWidth()-25,(float)GetScreenHeight()/2},15,100,RED);
    this->ball.Init();

    this->ScoreA = 0;
    this->ScoreB = 0;
    this->Timer = -1;
    this->ResetLastTime = 0;

    this->state = 1;


}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        BeginDrawing();
        ClearBackground(BLACK);
        Draw();
        EndDrawing();

    }
    
}

void Game::Update()
{
    switch (this->state)
    {
    case 1:
        this->UpdatePong();
        break;
    case 2:
        this->UpdateBattle();
        break;
    default:
        break;
    }
    

}

void Game::Draw()
{   
    this->DrawScore();

    switch (this->state)
    {
    case 1:
        this->DrawPong();
        break;
    case 2:
        this->DrawBattle();
        break;
    default:
        break;
    }

}

void Game::UpdatePong()
{
    this->PaddleA.PongUpdate(KEY_W,KEY_S);
    this->PaddleB.PongUpdate(KEY_UP,KEY_DOWN);

    if(Timer <= 0){
    this->ball.Update();
    }
    else {
        this->PaddleA.Reset();
        this->PaddleB.Reset();
        if(Timer <= 2){
            this->ball.Reset();
        }
    }
    

    if (this->PaddleA.BallCollide(&this->ball) && this->ball.GetVel().x < 0)
    {    
    this->ball.PaddleCollide(&this->PaddleA);
    this->PaddleA.SetHeight(2);
    }
    
    if (this->PaddleB.BallCollide(&this->ball) && this->ball.GetVel().x > 0)
    {
    this->ball.PaddleCollide(&this->PaddleB);
    this->PaddleB.SetHeight(2);
    }

    if((this->ball.GetPosition().x - this->ball.GetRadius() < 0 || this->ball.GetPosition().x + this->ball.GetRadius() > GetScreenWidth()) && (this->Timer == -1))
    {
        this->PaddleA.Increment = this->PaddleA.GetHeight() - this->PaddleA.GetPaddle().height;
        this->PaddleB.Increment = this->PaddleB.GetHeight() - this->PaddleB.GetPaddle().height;
        this->ball.dir = Vector2Subtract(Vector2{(float)GetScreenWidth()/2,(float) GetScreenHeight()/2} , this->ball.GetPosition());
        this->ball.distance = Vector2Length(this->ball.dir);
        this->ball.dir = Vector2Normalize(this->ball.dir);
        this->Timer = 3;
        this->ResetLastTime = GetTime();
        if(this->ball.GetPosition().x < GetScreenWidth()/2){
            ScoreB++;
        }
        else{
            ScoreA++;
        }
    }
}

void Game::DrawPong()
{
    this->DrawLine();
    this->DrawTime();
    this->ball.Draw();
    this->PaddleA.PongDraw();
    this->PaddleB.PongDraw();
}

void Game::UpdateBattle()
{
    this->PaddleA.BattleUpdate();
    this->PaddleB.BattleUpdate();
}

void Game::DrawBattle()
{
    this->PaddleA.BattleDraw();
    this->PaddleB.BattleDraw();
}

void Game::DrawLine()
{
    int width = 5;
    int height = 10;
    for(int i = 0 ; i<GetScreenHeight() / height * 2; i++){
        if(i%2 != 0) continue;
        DrawRectangle(GetScreenWidth()/2 - width/2 , i * height + 4, width, height, LIGHTGRAY);
    }
}

void Game::DrawTime()
{
    if(Timer > 0){
        if(Timer > 1)
            DrawText(TextFormat("%d",this->Timer) , GetScreenWidth() / 2 - 25, 40, 100, WHITE);
        if (Timer == 1)
            DrawText(TextFormat("%d",this->Timer) , GetScreenWidth() / 2 - 15, 40, 100, WHITE);
        if(GetTime() - ResetLastTime >= 1){
            ResetLastTime = GetTime();
            Timer--;
        }
    }
    else if(Timer == 0){
        //this->state++;
        // DrawText("GO!", GetScreenWidth() / 2 - 65, 40, 100, WHITE);
        
        // if(GetTime() - ResetLastTime >= 1){
        //     LastTime = GetTime();
        //     Timer--;
        // }
    }
}

void Game::DrawScore()
{
    DrawText(TextFormat("%d",this->ScoreA) , GetScreenWidth() / 4 - 25, 30, 50, WHITE);
    DrawText(TextFormat("%d",this->ScoreB) , GetScreenWidth() / 2 + GetScreenWidth() / 4 - 25, 30, 50, WHITE);
}
