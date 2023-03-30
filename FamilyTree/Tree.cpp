#include "Tree.h"
#include <iostream>
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

Tree::Tree()
{

}

void Tree::add_person(Person p, Person father, Person mother)
{
    vector<pair<Person, pair<Person, Person>>> family;
    family.push_back(make_pair(p, make_pair(father, mother)));

    int last_node = tree.size() - 1;

    if (tree[last_node].size() >= 2)
    {
        tree.push_back(family);
    }
    else
    {
        tree[last_node].append_range(family);
    }
}

void Tree::add_person(Person p, Person parent)
{
    vector<pair<Person, pair<Person, Person>>> family;
    family.push_back(make_pair(p, make_pair(parent, Person("null", ""))));
    tree.push_back(family);
}

void Tree::add_person(Person p)
{
    vector<pair<Person, pair<Person, Person>>> family;
    family.push_back(make_pair(p, make_pair(Person("null", ""), Person("null", ""))));

    if (tree.empty())
    {
        tree.push_back(family);
    }
    else
    {
        int last_node = tree.size() - 1;
        tree[last_node].append_range(family);
    }
}

void Tree::print_description()
{
    for (int i = 0; i < tree.size(); i++)
    {
        vector<pair<Person, pair<Person, Person>>> family = tree[i];
        cout << "Generation " << i << ":" << endl;
        for (int j = 0; j < family.size(); j++)
        {
            Person p = family[j].first;
            pair<Person, Person> parents = family[j].second;

            if ((parents.first.get_name() == "null") && (parents.second.get_name() == "null")) {
                cout << "  t.add_person(Person(L\"" << p.get_name() << "\", L\"" << p.get_birth_date() << "\"));" << endl;
            }
            else {
                cout << "t.add_person(Person(L\"" << p.get_name() << "\", L\"" << p.get_birth_date() << "\"), " << endl;
                cout << "  Parents: " << endl;
                if (!parents.first.get_name().empty() || !parents.first.get_birth_date().empty()) {
                    cout << "    Person(L\"" << parents.first.get_name() << "\", L\"" << parents.first.get_birth_date() << "\")";
                }
                if (!parents.second.get_name().empty() || !parents.second.get_birth_date().empty()) {
                    cout << ", " << endl << "    Person(L\"" << parents.second.get_name() << "\", L\"" << parents.second.get_birth_date() << "\")";
                }
                cout << ");" << endl;
            }

            if (j != family.size() - 1)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
}


void Tree::show(int width, int height)
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width, height)), "Family Tree");
    window.clear(sf::Color::White);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font font;

    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
    {
        std::cout << "Error loading font\n";
        return;
    }

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        std::vector<std::vector<sf::RectangleShape>> shapes;

        for (int i = 0; i < tree.size(); i++)
        {
            std::vector<sf::RectangleShape> generation;
            std::vector<std::pair<Person, std::pair<Person, Person>>> family = tree[i];

            for (int j = 0; j < family.size(); j++)
            {
                Person p = family[j].first;
                sf::RectangleShape shape(sf::Vector2f(60, 2));
                shape.setPosition(sf::Vector2f((j + 1) * width / (family.size() + 1) - 1, (i + 1) * height / (tree.size() + 1) - 30));
                shape.setFillColor(sf::Color::Black);
                shape.setOutlineThickness(0);
                sf::Text text(p.get_name(), font, 16);
                text.setFillColor(sf::Color::Black);
                text.setPosition(sf::Vector2f(shape.getPosition().x + shape.getSize().x / 2 - text.getGlobalBounds().width / 2, shape.getPosition().y + shape.getSize().y));
                generation.push_back(shape);
                window.draw(shape);
                window.draw(text);
            }

            shapes.push_back(generation);
        }

        for (int i = 0; i < tree.size() - 1; i++)
        {
            std::vector<std::pair<Person, std::pair<Person, Person>>> generation1 = tree[i];
            std::vector<std::pair<Person, std::pair<Person, Person>>> generation2 = tree[i + 1];

            for (int j = 0; j < generation1.size(); j++)
            {
                sf::Vector2f p1 = shapes[i][j].getPosition() + sf::Vector2f(shapes[i][j].getSize().x / 2, shapes[i][j].getSize().y);
                sf::Vector2f p2 = shapes[i + 1][j / 2].getPosition() + sf::Vector2f(shapes[i + 1][j / 2].getSize().x / 2, 0);
                sf::Vertex line[] =
                {
                    sf::Vertex(p1, sf::Color::Black),
                    sf::Vertex(p2, sf::Color::Black)
                };
                window.draw(line, 2, sf::PrimitiveType::Lines);
            }
        }

        window.display();
    }
}