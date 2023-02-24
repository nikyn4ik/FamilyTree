#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Tree.h"
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
	//setlocale(LC_ALL, "Russian");

	Tree t = Tree();

	t.add_person(Person(L"Grandmother on mother's side", L"20.11.1934")); //G0
	t.add_person(Person(L"Grandfather on mother's side", L"30.01.1935", L"26.12.1993"));//G0
	t.add_person(Person(L"Grandmother on father's side", L"23.10.1944"));//G0
	t.add_person(Person(L"Grandfather on father's side", L"22.11.1945", L"10.09.1996"));//G0

	t.add_person(Person(L"Mother", L"28.11.1967"), Person(L"Grandmother on mother's side", L"20.11.1934"), Person(L"Grandfather on mother's side", L"30.01.1935", L"26.12.1993"));//G1
	t.add_person(Person(L"Father", L"01.12.1968", L"02.08.2019"), Person(L"Grandmother on father's side", L"23.10.1944"), Person(L"Grandfather on father's side", L"22.11.1945", L"10.09.1996"));//G1

	t.add_person(Person(L"it's me", L"01.03.2002"), Person(L"Mother", L"28.11.1967"), Person(L"Father", L"01.12.1968", L"02.08.2019"));//G2

	t.add_person(Person(L"My descendant from the future", L"30.06.2934"), Person(L"it's me", L"01.03.2002"));//G3

	t.add_person(Person(L"Unknown relative", L"00.00.0000"));//G0

	t.print_description();

	t.show(1920, 1080);

	return 0;
}