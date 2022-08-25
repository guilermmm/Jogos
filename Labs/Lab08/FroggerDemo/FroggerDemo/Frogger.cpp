/**********************************************************************************
// Frogger (Código Fonte)
// 
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frogger.h"

// ---------------------------------------------------------------------------------

Frogger::Frogger()
{
    spriteUp = new Sprite("Resources/frog.png");
    spriteDown = new Sprite("Resources/frogDown.png");
    spriteLeft = new Sprite("Resources/frogLeft.png");
    spriteRight = new Sprite("Resources/frogRight.png");
    MoveTo(window->CenterX(), 560.0f, Layer::FRONT);
    ctrlUp = true;
    ctrlDown = true;
    ctrlLeft = true;
    ctrlRight = true;
    state = UP;
}

// ---------------------------------------------------------------------------------

Frogger::~Frogger()
{
    delete spriteUp;
    delete spriteDown;
    delete spriteLeft;
    delete spriteRight;
}

// ---------------------------------------------------------------------------------

void Frogger::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        Translate(0.0f, -40.0f);
        ctrlUp = false;
        state = UP;
    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }
    
    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        Translate(0.0f, 40.0f);
        ctrlDown = false;
        state = DOWN;
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }

    // desloca sapo para esquerda
    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        Translate(-40.0f, 0.0f);
        ctrlLeft = false;
        state = LEFT;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }

    // desloca sapo para direita
    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        Translate(40.0f, 0.0f);
        ctrlRight = false;
        state = RIGHT;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }
    
    // mantém sapo dentro da tela
    // eixo y
    if (y < 80)
        MoveTo(x, 80);

    if (y > 560)
        MoveTo(x, 560);


    // eixo x
    if (x < 20)
        MoveTo(20, y);
    if (x > 780)
        MoveTo(780, y);
}

// ---------------------------------------------------------------------------------

void Frogger::Draw() {

    Sprite* sprite = nullptr;
    

    switch (state)
    {
    case Frogger::UP:
        sprite = spriteUp;
        break;
    case Frogger::DOWN:
        sprite = spriteDown;
        break;
    case Frogger::LEFT:
        sprite = spriteLeft;
        break;
    case Frogger::RIGHT:
        sprite = spriteRight;
        break;
    default:
        break;
    }

    sprite->Draw(x - sprite->Width() / 2.0f, y - sprite->Height() / 2.0f, z);
}
