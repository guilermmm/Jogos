
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion()
{
    tileset = new TileSet("Resources/sheet.png", 192, 192, 5, 16);
    anim = new Animation(tileset, 0.060f, true);

    
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Explosion::Update()
{
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------