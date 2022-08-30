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

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"            // tipos espec�ficos da engine
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
// Fun��es Membro Inline
inline void Ball::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

#endif