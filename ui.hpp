#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED
#include <SFML/Graphics.hpp>

#define MAX_NUM_OF_TEXT_ITEMS 3

class UI
{
	public:
		UI(sf::Vector2f viewSize);
		void SetText(std::string* menuText);
		void SetText(int element, std::string text);
		void CenterText();
		void Draw(sf::RenderWindow& window);

	private:
		void UpdateMenuElementsText();

	private:
		int selectItemIndex;
		sf::Font font;
		std::string menuText[MAX_NUM_OF_TEXT_ITEMS];
		sf::Text menuElements[MAX_NUM_OF_TEXT_ITEMS];
		sf::Vector2f viewSize;
};
#endif //UI_HPP_INCLUDED
