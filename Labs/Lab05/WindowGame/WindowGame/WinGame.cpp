/**********************************************************************************
// WinGame 
// 
// Criação:     19 Mai 2007
// Atualização: 04 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init, 
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

int speedX = 3;
int speedY = 3;

LPPOINT lp;

struct Point
{
	int x;
	int y;
};

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	stringstream textSize;
	stringstream textMode;
	stringstream textMouse;

	Point p1 = { 0,0 };
	Point p2 = { 0,0 };
	Point speed1 = { 5,7 };
	Point speed2 = { 12,14 };

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{
	textSize << "Tamanho: " << window->Width() << " x " << window->Height();
	textMode << "Formato: " << (window->Mode() == WINDOWED ? "Em Janela" : "Tela Cheia"); 
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (p1.x < 0 || p1.x > window->Width()) {
		speed1.x = -speed1.x;
	}
	if (p1.y < 0 || p1.y > window->Height()) {
		speed1.y = -speed1.y;
	}

	if (p2.x < 0 || p2.x > window->Width()) {
		speed2.x = -speed2.x;
	}
	if (p2.y < 0 || p2.y > window->Height()) {
		speed2.y = -speed2.y;
	}

	p1.x += speed1.x;
	p1.y += speed1.y;
	p2.x += speed2.x;
	p2.y += speed2.y;
} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{	
	window->Print("Window Game Demo", 10, 10, RGB(0,0,0));
	window->Print(textSize.str(), 10, 50, RGB(0,0,0)); 
	window->Print(textMode.str(), 10, 70, RGB(0,0,0)); 
	window->Print(textMouse.str(), 10, 90, RGB(0, 0, 0));

	HDC hdc = GetDC(window->Id());

	MoveToEx(
		hdc, // contexto do dispositivo
		p1.x, // posição no eixo x
		p1.y, // posição no eixo y
		lp // guarda última coordenada em um POINT
	);

	LineTo(hdc, p2.x,p2.y);

	ReleaseDC(window->Id(), hdc);
} 

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
}	


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------

