#include <iostream>
#include <string>
#include "Person.h"
#include "Person.cpp"
#include "Tree.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <fstream>

void performTask()
{
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

    std::string filename;
    std::cout << "Enter the filename to save to: ";
    std::cin >> filename;

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        file << line << std::endl;
    }

    file.close();

    std::cout << "File saved successfully to " << filename << std::endl;
}

void selectfile()//выбор
{
    std::ifstream file("file.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
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

int main() {
    //setlocale(LC_ALL, "Russian");

    char choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "a) Create a tree\n";
        std::cout << "b) Select a file with a tree\n";
        std::cout << "c) Compare two trees, select a txt file.\n";
        std::cout << "d) Exit\n"; //Выход
        std::cout << "Enter your choice (a, b, c or d ): "; //Выбор
        std::cin >> choice;
        switch (choice) {
        case 'a':
            performTask();
            break;
        case 'b':
            selectfile();
            break;
        case 'c':
            compare();
            break;
        case 'd':
            std::cout << "Exiting program." << std::endl; //Выход из программы
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl; //Неверный выбор (метод исключения).
            break;
        }
    } while (choice != 'd');
    return 0;
}