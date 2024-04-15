#include <iostream>
#include <string>
#include "Person.h"
#include "Tree.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <fstream>

using namespace std;

void selectfile() // выбор
{
    std::string filename;
    std::cout << "Enter file name or file path: ";
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
    }
    else {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}

void compare() //сравнение
{
    std::string filename1;
    std::cout << "Enter the name of the first file: ";
    std::cin >> filename1;
    std::ifstream file1(filename1);

    if (!file1.is_open()) {
        std::cerr << "Failed to open file " << filename1 << std::endl;
    }

    std::string filename2;
    std::cout << "Enter the name of the second file: ";
    std::cin >> filename2;
    std::ifstream file2(filename2);

    if (!file2.is_open()) {
        std::cerr << "Failed to open file " << filename2 << std::endl;
    }

    int num_generations1 = 0, num_generations2 = 0;
    std::string line;
    while (std::getline(file1, line)) {
        if (line.find("Generation") != std::string::npos) {
            num_generations1++;
        }
    }
    while (std::getline(file2, line)) {
        if (line.find("Generation") != std::string::npos) {
            num_generations2++;
        }
    }

    if (num_generations1 > num_generations2) {
        std::cout << filename1 << " has more generations (" << num_generations1 << " vs " << num_generations2 << ")" << std::endl;
    }
    else if (num_generations2 > num_generations1) {
        std::cout << filename2 << " has more generations (" << num_generations2 << " vs " << num_generations1 << ")" << std::endl;
    }
    else {
        std::cout << "The two files have the same number of generations (" << num_generations1 << ")" << std::endl;
    }
    file1.close();
    file2.close();
}

void files(Tree t) //работа с файлом
{
    t.print_description();
    t.show(1920, 1080);
    std::string filename;
    std::cout << "Enter the filename to save to: ";
    std::cin >> filename;

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    std::streambuf* orig_cout = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());
    t.print_description();
    std::cout.rdbuf(orig_cout);

    file.close();

    std::cout << "File saved successfully to " << filename << std::endl;
}

int main() {

    Tree t = Tree();

    t.add_person(Person("Grandmother on mother's side", "10.10.1944")); //G0
    t.add_person(Person("Grandfather on mother's side", "10.01.1945", "20.12.1980"));//G0
    t.add_person(Person("Grandmother on father's side", "23.10.1944"));//G0
    t.add_person(Person("Grandfather on father's side", "22.11.1945", "10.09.1996"));//G0
    //удаление последних двух строк
    t.add_person(Person("Mother", "20.10.1960"), Person("Grandmother on mother's side", "10.10.1944"), Person("Grandfather on mother's side", "10.01.1945", "20.12.1980"));//G1
    t.add_person(Person("Father", "01.01.1980", "01.01.2010"), Person("Grandmother on father's side", "23.10.1944"), Person("Grandfather on father's side", "22.11.1945", "10.09.1996"));//G1

    t.add_person(Person("it's me", "01.01.2000"), Person("Mother", "20.10.1960"), Person("Father", "01.01.1980", "01.01.2010"));//G2

    t.add_person(Person("My descendant from the future", "30.06.2934"), Person("it's me", "01.01.2000"));//G3

    int choice;
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1) Create a tree\n";
        std::cout << "2) Select a file with a tree\n";
        std::cout << "3) Compare two trees, select a txt file.\n";
        std::cout << "4) Exit\n"; //Выход
        std::cout << "Enter your choice (1, 2, 3 or 4): "; //Выбор
        cin >> choice;

        if (cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        switch (choice) {
        case 1:
            files(t);
            break;
        case 2:
            selectfile();
            break;
        case 3:
            compare();
            break;
        case 4:
            std::cout << "Exiting program." << std::endl; //Выход из программы
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl; //Неверный выбор (метод исключения).
            break;
        }
    }
    return 0;
}