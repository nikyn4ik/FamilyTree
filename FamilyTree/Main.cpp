#include <iostream>
#include <string>
#include "Person.h"
#include "Tree.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	//sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1920, 1080)), "Family Tree");

	Tree t = Tree();

	t.add_person(Person("Grandmother on mother's side", "20.11.1934")); //G0
	t.add_person(Person("Grandfather on mother's side", "30.01.1935", "26.12.1993"));//G0
	t.add_person(Person("Grandmother on father's side", "23.10.1944"));//G0
	t.add_person(Person("Grandfather on father's side", "22.11.1945", "10.09.1996"));//G0

	t.add_person(Person("Mother", "28.11.1967"), Person("Grandmother on mother's side", "20.11.1934"), Person("Grandfather on mother's side", "30.01.1935", "26.12.1993"));//G1
	t.add_person(Person("Father", "01.12.1968", "02.08.2019"), Person("Grandmother on father's side", "23.10.1944"), Person("Grandfather on father's side", "22.11.1945", "10.09.1996"));//G1

	t.add_person(Person("it's me", "01.03.2002"), Person("Mother", "28.11.1967"), Person("Father", "01.12.1968", "02.08.2019"));//G2

	t.add_person(Person("My descendant from the future", "30.06.2934"), Person("it's me", "01.03.2002"));//G3

	t.print_description();

	t.show(1920, 1080);

	return 0;
}