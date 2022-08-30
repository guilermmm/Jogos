/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"            // tipos específicos da engine
#include "Object.h"            // interface de Object
#include "Sprite.h"            // interface de Sprites

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite* sprite;
    float velX, velY;
    bool started;

public:
    Ball();
    ~Ball();

    void Update();
    void Draw();
    void Start();
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline
inline void Ball::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

#endif