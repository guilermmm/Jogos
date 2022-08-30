/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball()
{
    sprite = new Sprite("Resources/Ball.png");
    velX = 250.0f;
    velY = -250.0f;
    started = false;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    // movimenta��o da bola
    if (started)
    {
        Translate(velX * gameTime, velY * gameTime);
    }
    
    
    // bola dando bounce nos cantos da tela

    if (x > window->Width() - sprite->Width() || x < 0)
    {
        velX = -velX;
    }

    if (y > window->Height() - sprite->Height() || y < 0)
    {
        velY = -velY;
    }
}

void Ball::Start()
{
    started = true;
}


// ---------------------------------------------------------------------------------
