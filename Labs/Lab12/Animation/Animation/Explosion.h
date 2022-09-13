#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* anim;                   // animação do personagem

public:

    Explosion();                             // construtor
    ~Explosion();                            // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Explosion::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif