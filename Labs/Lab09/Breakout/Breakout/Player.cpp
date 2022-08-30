/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    sprite = new Sprite("Resources/Player.png");
    centerSprite = sprite->Width() / 2.0f;
    ball = new Ball();
    Breakout::scene->Add(ball);

    MoveTo(window->CenterX() - centerSprite, window->Height() - 50.0f, Layer::FRONT);
    vel = 160;
    keyCtrl = true;
    
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // dispara um míssil com a barra de espaço
    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        ball->Start();
        keyCtrl = false;
    }
    if (keyCtrl)
    {
        ball->MoveTo(x + centerSprite - 5.0f, y - 20.0f);
    }

    

    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mantém jogador dentro da janela
    if (x < 0)
        MoveTo(0, y);
    if (x + sprite->Width() > window->Width())
        MoveTo(float(window->Width() - sprite->Width()), y);
}

// ---------------------------------------------------------------------------------
