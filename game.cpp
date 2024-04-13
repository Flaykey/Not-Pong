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
    this->PaddleA.PongUpdate(KEY_W,KEY_S);
    this->PaddleB.PongUpdate(KEY_UP,KEY_DOWN);
    this->ball.Update();
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

    if(this->ball.GetPosition().x - this->ball.GetRadius() < 0 || this->ball.GetPosition().x + this->ball.GetRadius() > GetScreenWidth())
    {
        this->ball.Init();
        this->PaddleA.Init(Vector2 {10,(float)GetScreenHeight()/2},15,100,BLUE);
        this->PaddleB.Init(Vector2 {(float)GetScreenWidth()-25,(float)GetScreenHeight()/2},15,100,RED);
    }

}

void Game::Draw()
{
    this->DrawLine();
    this->ball.Draw();
    this->PaddleA.PongDraw();
    this->PaddleB.PongDraw();
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
