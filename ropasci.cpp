#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "ropasci.hpp"


//GAME CLASS
    Game::Game()
    {
        std::cout<<"constructor created"<<std::endl;

        icon.loadFromFile("assets/art/icon.png");

        if (!bgm.openFromFile("assets/bgm/Max_Manie_Sunday_KlangTherapeuten _Looking_For_Summer_ Remix.ogg"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Music: success loading file"<<std::endl;
        }

        if (!pixleFont.loadFromFile("assets/font/Pixle_Font.ttf"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Font: success loading file"<<std::endl;
        }

        if (!bubbleGun.loadFromFile("assets/font/bubblegun.ttf"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Font: success loading file"<<std::endl;
        }

        if (!gameMenu.loadFromFile("assets/texture/background/menu.png"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!gameplay.loadFromFile("assets/texture/background/arena.png"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!sky.loadFromFile("assets/texture/background/sky.png"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!cloud.loadFromFile("assets/texture/background/cloud_map.png"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!rock.loadFromFile("assets/texture/hand/rock.png"))
        {
            std::cout<<"Error loading file"<<std::endl;

            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }


        if (!paper.loadFromFile("assets/texture/hand/paper.png"))
        {
            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }


        if (!scissors.loadFromFile("assets/texture/hand/scissors.png"))
        {
            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!arrow.loadFromFile("assets/texture/arrow.png"))
        {
            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!logoSmall.loadFromFile("assets/sfml-icon-small.png"))
        {
            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }

        if (!logoBig.loadFromFile("assets/sfml-logo-big.png"))
        {
            isLoadAllFiles = false;
        }
        else
        {
            std::cout<<"Image: success loading file"<<std::endl;
        }



        rock.setSmooth(true);
        paper.setSmooth(true);
        scissors.setSmooth(true);

        gameMenuSprite.setTexture(gameMenu);
        gameplaySprite.setTexture(gameplay);
        logoSmallSprite.setTexture(logoSmall);
        logoBigSprite.setTexture(logoBig);
        skySprite.setTexture(sky);

        uRockSprite.setTexture(rock);
        eRockSprite.setTexture(rock);
        uPaperSprite.setTexture(paper);
        ePaperSprite.setTexture(paper);
        uScissorsSprite.setTexture(scissors);
        eScissorsSprite.setTexture(scissors);

        arrowNum = 0;

        arrowSprite.setPosition(15.f, 300.f);

        userScore = 0;
        botScore = 0;
        tempUserMove = 0;
        tempBotMove = 0;

        isMainMenu = true;
        isGameplay = false;
    }

    void Game::run(void)
    {
        // Create the main window
        sf::RenderWindow mainWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), title, sf::Style::Close);
        mainWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        mainWindow.setMouseCursorVisible(false);
        mainWindow.setFramerateLimit(60);
        mainWindow.setKeyRepeatEnabled(false);

        if (!isLoadAllFiles) mainWindow.close();

        bgm.setLoop(true);
        bgm.setVolume(80);
        bgm.play();

        initMenu();
        initAbout();
        initGameplay();

        sf::IntRect arrowRect(0,0,49,49);
        sf::IntRect cloudRect(0,0,1600,1200);
        cloudSprite.setScale(0.5f, 0.5f);

        logoBigSprite.setOrigin(250.f, 76.f);
        logoBigSprite.setPosition(400.f, 300.f);

        //while(splashLogoClock.getElapsedTime().asMilliseconds() != 4500.f);

        // Start the game loop
        while (mainWindow.isOpen())
        {

            while (mainWindow.pollEvent(event))
            {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                {
                    mainWindow.close();
                }

                update(mainWindow);
            }

            if (isMainMenu)
            {
                menuAnimation(arrowRect);
            }


            if(isGameplay)
            {
                cloudAnimation(cloudRect);
            }

            if(splashAnimationTimer2 != 500)
            {
                std::cout<<splashAnimationTimer2<<std::endl;
                splashLogo(mainWindow);
                logoBigSprite.setColor(sf::Color(255,255,255,splashAnimationTimer));
            }

            mainWindow.clear(sf::Color::Black);
            draw(mainWindow);
            mainWindow.display();

        }
    }

    void Game::update(sf::RenderWindow& mainWindow)
    {
        if(isMainMenu)
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (arrowNum != 2)
                    {
                        arrowNum = arrowNum + 1;
                    }
                    std::cout<<"Down\n";
                    std::cout<<arrowNum;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    if (arrowNum != 0)
                    {
                        arrowNum = arrowNum - 1;
                    }
                    std::cout<<"Up\n";
                    std::cout<<arrowNum;
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    if (arrowNum == 0)
                    {
                        isMainMenu = false;
                        isAbout = false;
                        isGameplay = true;
                    }
                    else if (arrowNum == 1)
                    {
                        isMainMenu = false;
                        isAbout = true;
                        isGameplay = false;
                    }
                    else if (arrowNum == 2)
                    {
                        mainWindow.close();
                    }


                }
                    if (arrowNum == 0)
                    {
                        arrowSprite.setPosition(15.f, 300.f);
                    }
                    else if (arrowNum == 1)
                    {
                        arrowSprite.setPosition(15.f, 350.f);
                    }
                    else if (arrowNum == 2)
                    {
                        arrowSprite.setPosition(15.f, 400.f);
                    }

            }
        }

        if(isGameplay)
        {
            userScoreText.setString("Score: " + std::to_string(userScore));
            botScoreText.setString("Score: " + std::to_string(botScore));


            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    {
                        isMainMenu = true;
                        isAbout = false;
                        isGameplay= false;
                    }
            }
            if (userScore == maxScore || botScore == maxScore)
            {
                gameClock.restart();
                while (gameClock.getElapsedTime().asSeconds() < 2.5f)
                isMainMenu = true;
                isGameplay = false;
                userScore = 0;
                botScore = 0;
            }

            battle();

        }
        if (isAbout)
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    {
                        isMainMenu = true;
                        isAbout = false;
                        isGameplay= false;
                    }
            }
        }
        



    }

    void Game::draw(sf::RenderWindow& mainWindow)
    {
        if (isMainMenu)
        {
            drawMenu(mainWindow);
        }

        if (isGameplay)
        {
            drawGameplay(mainWindow);
        }
        if(isAbout)
        {
            drawAbout(mainWindow);
        }

        if(splashAnimationTimer2 < 496)
        {
            mainWindow.clear(sf::Color::Black);
            mainWindow.draw(logoBigSprite);
        }

    }

    void Game::initMenu(void)
    {
        gameMenuSprite.setScale(0.5f, 0.5f);

        titleText.setFont(bubbleGun);               titleText.setString("RoPaSci");
        titleText.setCharacterSize(100);             titleText.setPosition(40.f, 20.f);
        titleText.setFillColor(sf::Color::Black);

        menuText.setFont(bubbleGun);                menuText.setString("Play\nAbout\nExit");
        menuText.setCharacterSize(40);              menuText.setPosition(70.f, 300.f);
        menuText.setFillColor(sf::Color::Black);

        logoSmallSprite.setPosition(725.f, 525.f);

        pyromagne.setFont(pixleFont);
        pyromagne.setString("Pyromagne");
        pyromagne.setCharacterSize(40);
        pyromagne.setPosition(525.f, 540.f);
    }

    void Game::drawMenu(sf::RenderWindow& mainWindow)
    {
        mainWindow.draw(gameMenuSprite);
        mainWindow.draw(titleText);
        mainWindow.draw(menuText);
        mainWindow.draw(arrowSprite);
        mainWindow.draw(logoSmallSprite);
        mainWindow.draw(pyromagne);
    }

    void Game::initAbout(void)
    {
        inst.setFont(bubbleGun);               inst.setPosition(40.f, 20.f);
        inst.setCharacterSize(25);
        inst.setFillColor(sf::Color::Black);

        inst.setString
(R"(A Rock Paper Scissors game made by Pyromagne
using SFML (Simple and Fast Media Library).

Instruction:
Rock wins over scissors (rock smashes scissors)
Scissors wins over paper (scissors cut paper)
Paper wins over rock (paper covers rock)

R - rock
P - paper
S - Scissors

Music:
Max Manie - Sunday (KlangTherapeuten Remix)
Font:
Simon Thomaschke - Bubblegun
Carlos Flores - Pixle Font

)");


    }

    void Game::drawAbout(sf::RenderWindow& mainWindow)
    {
        mainWindow.draw(gameMenuSprite);
        mainWindow.draw(inst);

        mainWindow.draw(logoSmallSprite);
        mainWindow.draw(pyromagne);
    }

    void Game::menuAnimation(sf::IntRect& arrowRect)
    {

        if (arrowClock.getElapsedTime().asMilliseconds() > 50.f)
        {
            if (arrowRect.left == 343)
            {
                arrowRect.left = 0;
            }
            else arrowRect.left += 49;

            arrowSprite.setTextureRect(arrowRect);
            arrowSprite.setTexture(arrow);
            arrowClock.restart();
        }
    }

    void Game::cloudAnimation(sf::IntRect& cloudRect)
    {

        if (cloudClock.getElapsedTime().asMilliseconds() > 10.f)
        {
            if (cloudBack == false)
            {
                if (cloudRect.left == 3200)
                {
                    cloudRect.left = 0;
                    cloudBack = true;
                }
                else cloudRect.left += 1;
            }
            else if (cloudBack == true)
            {
                if (cloudRect.left == 0)
                {
                    cloudRect.left = 3200;
                }
                else cloudRect.left -= 1;
            }





            cloudSprite.setTextureRect(cloudRect);
            cloudSprite.setTexture(cloud);
            cloudClock.restart();
        }
    }

    void Game::splashLogo(sf::RenderWindow& mainWindow)
    {
        if (splashLogoAnimation.getElapsedTime().asMilliseconds() > 10.f)
        {
            if (splashAnimationTimer != 254)
            {
                splashAnimationTimer = splashAnimationTimer + 2;
            }
            splashAnimationTimer2 = splashAnimationTimer2 + 2;

        }
        splashLogoAnimation.restart();
    }

    void Game::initGameplay(void)
    {
        gameplaySprite.setScale(0.5f, 0.5f);
        skySprite.setScale(0.5f, 0.5f);

        lastUserMoveSprite.setScale(0.5f, 0.5f);    lastUserMoveSprite.setPosition(10.f, 225.f);
        lastBotMoveSprite.setScale(-0.5f, 0.5f);     lastBotMoveSprite.setPosition(790.f, 225.f);

        uRockSprite.setScale(0.5f, 0.5f);       uRockSprite.setPosition(10.f, 225.f);
        eRockSprite.setScale(-0.5f, 0.5f);      eRockSprite.setPosition(790.f, 225.f);

        uPaperSprite.setScale(0.5f, 0.5f);      uPaperSprite.setPosition(10.f, 225.f);
        ePaperSprite.setScale(-0.5f, 0.5f);     ePaperSprite.setPosition(790.f, 225.f);

        uScissorsSprite.setScale(0.5f, 0.5f);   uScissorsSprite.setPosition(10.f, 225.f);
        eScissorsSprite.setScale(-0.5f, 0.5f);  eScissorsSprite.setPosition(790.f, 225.f);

        userName.setFont(bubbleGun);                userName.setString("Player 1");
        userName.setCharacterSize(35);              userName.setPosition(40.f, 75.f);
        userName.setFillColor(sf::Color::Black);

        botName.setFont(bubbleGun);                 botName.setString("Player 2 (Bot)");
        botName.setCharacterSize(35);               botName.setPosition(760.f, 75.f);
        botName.setFillColor(sf::Color::Black);     botName.setOrigin(205.f, 0.f);

        userScoreText.setFont(bubbleGun);                userScoreText.setString("Score: " + std::to_string(userScore));
        userScoreText.setCharacterSize(30);              userScoreText.setPosition(40.f, 125.f);
        userScoreText.setFillColor(sf::Color::Black);

        botScoreText.setFont(bubbleGun);                botScoreText.setString("Score: " + std::to_string(botScore));
        botScoreText.setCharacterSize(30);              botScoreText.setOrigin(102.f, 0.f);
        botScoreText.setFillColor(sf::Color::Black);    botScoreText.setPosition(760.f, 125.f);

        winner.setFont(bubbleGun);                  winner.setString("You Win!");
        winner.setCharacterSize(100);               winner.setPosition(40.f, 100.f);
        winner.setFillColor(sf::Color::Green);      winner.setOutlineColor(sf::Color::Black);
        winner.setOutlineThickness(5);              winner.setLetterSpacing(2);
        winner.setOrigin(230.5f,46.5f);             winner.setPosition(400.f,300.f);

        loser.setFont(bubbleGun);                   loser.setString("You Lose!");
        loser.setCharacterSize(100);                loser.setPosition(40.f, 100.f);
        loser.setFillColor(sf::Color::Red);         loser.setOutlineColor(sf::Color::Black);
        loser.setOutlineThickness(5);               loser.setLetterSpacing(2);
        loser.setOrigin(251.f,46.f);                loser.setPosition(400.f,300.f);

        textRect = loser.getLocalBounds();
        std::cout<<textRect.width<<std::endl;
        std::cout<<textRect.height<<std::endl;

    }

    void Game::drawGameplay(sf::RenderWindow& mainWindow)
    {
        if (userScore == 0 && botScore == 0)
        {
            lastUserMoveSprite.setTexture(rock);
            lastBotMoveSprite.setTexture(rock);
        }
        
        mainWindow.draw(skySprite);
        mainWindow.draw(cloudSprite);
        mainWindow.draw(gameplaySprite);
        mainWindow.draw(userName);
        mainWindow.draw(botName);
        mainWindow.draw(userScoreText);
        mainWindow.draw(botScoreText);
        mainWindow.draw(lastUserMoveSprite);
        mainWindow.draw(lastBotMoveSprite);

        switch (tempUserMove)
        {
        case 1:
            if (tempBotMove == 1)
            {
                mainWindow.draw(uRockSprite);
                lastUserMoveSprite.setTexture(rock);
                lastBotMoveSprite.setTexture(rock);
                mainWindow.draw(eRockSprite);
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 2)
            {
                mainWindow.draw(uRockSprite);
                mainWindow.draw(ePaperSprite);
                lastUserMoveSprite.setTexture(rock);
                lastBotMoveSprite.setTexture(paper);
                botScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 3)
            {
                mainWindow.draw(uRockSprite);
                mainWindow.draw(eScissorsSprite);
                lastUserMoveSprite.setTexture(rock);
                lastBotMoveSprite.setTexture(scissors);
                userScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
        break;
        case 2:
            if (tempBotMove == 2)
            {
                mainWindow.draw(uPaperSprite);
                mainWindow.draw(ePaperSprite);
                lastUserMoveSprite.setTexture(paper);
                lastBotMoveSprite.setTexture(paper);
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 1)
            {
                mainWindow.draw(uPaperSprite);
                mainWindow.draw(eRockSprite);
                lastUserMoveSprite.setTexture(paper);
                lastBotMoveSprite.setTexture(rock);
                userScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 3)
            {
                mainWindow.draw(uPaperSprite);
                mainWindow.draw(eScissorsSprite);
                lastUserMoveSprite.setTexture(paper);
                lastBotMoveSprite.setTexture(scissors);
                botScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
        break;
        case 3:
            if (tempBotMove == 3)
            {
                mainWindow.draw(uScissorsSprite);
                mainWindow.draw(eScissorsSprite);
                lastUserMoveSprite.setTexture(scissors);
                lastBotMoveSprite.setTexture(scissors);
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 1)
            {
                mainWindow.draw(uScissorsSprite);
                mainWindow.draw(eRockSprite);
                lastUserMoveSprite.setTexture(scissors);
                lastBotMoveSprite.setTexture(rock);
                botScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
            else if (tempBotMove == 2)
            {
                mainWindow.draw(uScissorsSprite);
                mainWindow.draw(ePaperSprite);
                lastUserMoveSprite.setTexture(scissors);
                lastBotMoveSprite.setTexture(paper);
                userScore++;
                tempUserMove = 0;
                tempBotMove = 0;
                std::cout<<userScore<<" "<<botScore<<std::endl;
            }
        break;

        }

        if (userScore == maxScore || botScore == maxScore)
        {
            mainWindow.clear();
            mainWindow.draw(skySprite);
            mainWindow.draw(cloudSprite);
            mainWindow.draw(gameplaySprite);

            if(userScore == maxScore)
            {
                mainWindow.draw(winner);
            }
            else if(botScore == maxScore)
            {
                mainWindow.draw(loser);
            }
        }
    }

    void Game::battle(void)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::R || event.key.code == sf::Keyboard::Z)
            {
                tempUserMove = 1;
                tempBotMove = botMove();
                std::cout<<"User: "<<tempUserMove<<"\n";
                std::cout<<"Bot: "<<tempBotMove<<"\n";
            }
            else if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::X)
            {
                tempUserMove = 2;
                tempBotMove = botMove();
                std::cout<<"User: "<<tempUserMove<<"\n";
                std::cout<<"Bot: "<<tempBotMove<<"\n";
            }
            else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::C)
            {
                tempUserMove = 3;
                tempBotMove = botMove();
                std::cout<<"User: "<<tempUserMove<<"\n";
                std::cout<<"Bot: "<<tempBotMove<<"\n";
            }

        }
    }

    int Game::botMove(void)
    {
        int move = (rand() % (3 - 1 + 1)) + 1;
        return move;
    }
//END OF GAME CLASS
