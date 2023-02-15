#ifndef ROPASCI_HPP_INCLUDED
#define ROPASCI_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <string>
#include "ui.hpp"

static const float WIN_WIDTH = 800.f;
static const float WIN_HEIGHT = 600.f;

class Game
{
    public:
    Game();
	//~Game();
    void run(void);
    void update(sf::RenderWindow&);
    void draw(sf::RenderWindow&);

    void initMenu(void);
    void drawMenu(sf::RenderWindow&);

    void initAbout(void);
    void drawAbout(sf:: RenderWindow&);

    void menuAnimation(sf::IntRect&);
    void cloudAnimation(sf::IntRect&);
    void splashLogo(sf::RenderWindow&);

    void initGameplay(void);
    void drawGameplay(sf::RenderWindow&);
    void battle(void);
    int botMove(void);

    private:
    bool isLoadAllFiles = true;
    const std::string title = "RoPaSci - Rock Paper Scissors Game";
    sf::Image icon;
    sf::Music bgm;
    sf::Event event;
    sf::Font pixleFont;
    sf::Font bubbleGun;
    sf::Texture arrow;
    sf::Sprite arrowSprite;
    int arrowNum;


    //menu UI
    sf::Text titleText;
    sf::Text menuText;
    sf::Text pyromagne;
    sf::Texture gameMenu;
    sf::Sprite gameMenuSprite;
    sf::Texture logoSmall;
    sf::Sprite logoSmallSprite;
    sf::Texture logoBig;
    sf::Sprite logoBigSprite;
    sf::Clock splashLogoClock;
    sf::Clock splashLogoAnimation;
    int splashAnimationTimer = 0;
    int splashAnimationTimer2 = 0;
    sf::Clock arrowClock;
    bool isMainMenu;

    //about UI
    bool isAbout;
    sf::Text inst;

    //game UI
    const short maxScore = 10;
    short userScore;
    short botScore;
    short tempBotMove;
    short tempUserMove;
    bool isGameplay;
    sf::Clock gameClock;

    sf::Texture cloud;
    sf::Sprite cloudSprite;
    sf::Clock cloudClock;
    bool cloudBack = false;



    sf::Texture gameplay;
    sf::Sprite gameplaySprite;
    sf::Texture sky;
    sf::Sprite skySprite;

    sf::Texture rock;
    sf::Sprite uRockSprite;
    sf::Sprite eRockSprite;

    sf::Texture paper;
    sf::Sprite uPaperSprite;
    sf::Sprite ePaperSprite;

    sf::Texture scissors;
    sf::Sprite uScissorsSprite;
    sf::Sprite eScissorsSprite;

    sf::Sprite lastUserMoveSprite;
    sf::Sprite lastBotMoveSprite;

    sf::Text userScoreText;
    sf::Text botScoreText;
    sf::Text userName;
    sf::Text botName;

    sf::Text winner;
    sf::Text loser;

    sf::FloatRect textRect;
};

#endif // ROPASCI_HPP_INCLUDED
