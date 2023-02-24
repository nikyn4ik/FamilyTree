#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Tree.h"
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Tree t = Tree();

	t.add_person(Person(L"Бабушка по маминой линии", L"20.11.1934"));
	t.add_person(Person(L"Дедушка по маминой линии", L"30.01.1935", L"26.12.1993"));
	t.add_person(Person(L"Бабушка по папиной линии", L"23.10.1944"));
	t.add_person(Person(L"Дедушка по папиной линии", L"22.11.1945", L"10.09.1996"));

	t.add_person(Person(L"Мама", L"28.11.1967"), Person(L"Бабушка по маминой линии", L"20.11.1934"), Person(L"Дедушка по маминой линии", L"30.01.1935", L"26.12.1993"));
	t.add_person(Person(L"Папа", L"01.12.1968", L"02.08.2019"), Person(L"Бабушка по папиной линии", L"23.10.1944"), Person(L"Дедушка по папиной линии", L"22.11.1945", L"10.09.1996"));

	t.add_person(Person(L"Я", L"01.03.2002"), Person(L"Мама", L"28.11.1967"), Person(L"Папа", L"01.12.1968", L"02.08.2019"));

	t.add_person(Person(L"Мой потомок из будущего", L"30.06.2934"), Person(L"Я", L"01.03.2002"));

	t.add_person(Person(L"Неизвестный родственник", L"00.00.0000"));

	t.print_description();

	t.show(1920, 1080);

	return 0;
}