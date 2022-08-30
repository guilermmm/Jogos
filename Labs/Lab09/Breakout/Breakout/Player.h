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

#ifndef _BREAKOUT_PLAYER_H_
#define _BREAKOUT_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"          // tipos específicos da engine
#include "Object.h"         // interface de Object
#include "Sprite.h"         // interface de Sprites
#include "Ball.h"

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite* sprite;           
    Ball* ball;
    float vel;                 
    bool keyCtrl;  
    float centerSprite;
    

public:
    Player();
    ~Player();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Player::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

#endif