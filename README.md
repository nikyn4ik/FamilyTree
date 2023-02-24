# Проект семейное древо.

При добавлении нового элемента нужно давать родителей с полями, идентичными оригинальному элементу родителя. 
Возможно создать в самом начале несколько элементов Person и давать их в t.add_person(). 
Например:
Person mom = Person(L"Mom", L"BirthDateMom", L"DeathDateMom");
Person dad = Person(L"Dad", L"BirthDateDad", L"DeathDateDad");
Person me = Person(L"Me", L"BirthDateMe");

t.add_person(mom);
t.add_person(dad);
t.add_person(me, mom, dad);


Добавление элементов в дерево происходит так:
t.add_person(Person p, Person m, Person f), где p - новый элемент, m и f - мама и папа (порядок родителей не важен). 
Если добавить элемент без родителей, он отобразится в самом верху. Так же можно добавить элемент с одним родителем
