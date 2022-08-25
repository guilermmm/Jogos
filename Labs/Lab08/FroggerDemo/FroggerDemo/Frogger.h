/**********************************************************************************
// Frogger (Arquivo de Cabe�alho)
// 
// Cria��o:     19 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_FROGGER_H_
#define _FROGGER_FROGGER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"             // tipos espec�ficos da engine
#include "Object.h"            // interface de object
#include "Sprite.h"            // interface de sprites

// ---------------------------------------------------------------------------------

class Frogger : public Object
{
private:
    Sprite* spriteUp;
    Sprite* spriteDown;
    Sprite* spriteLeft;
    Sprite* spriteRight;
    bool ctrlUp;
    bool ctrlDown;
    bool ctrlLeft;
    bool ctrlRight;
    enum State {UP, DOWN, LEFT, RIGHT};
    State state;

public:
    Frogger();
    ~Frogger();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline



// ---------------------------------------------------------------------------------

#endif