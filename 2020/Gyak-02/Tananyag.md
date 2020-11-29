# 2. Gyakorlat tananyag

## Fájlkezelés
C++-ban a fájlkezelés _folyamok (stream)_ segítségével megoldott. Emlékezzünk vissza az ```std::cout``` és az ```std::cin```  folyamokra standard be/kimenet használatánál! A szükséges könyvtár az __fstream__. A fájlfolyamok ezekhez analóg módon használhatók:
- std::ifstream: fájl beolvasása (bemenet). Példa inializálásra: ```std::ifstream f("Names.txt");```
- std::ofstream: fájl kilvasása (kimenet). Példa inicializálásra: ```std::ofstream f("Names.txt");```

Egy szöveges fájlból a soronkénti kiolvasás az ```std::getline``` segítségével történhet meg, a függvény mindig előrelép. Amennyiben a fájl végére ért, a függvény egy 0 értékkel tér vissza. Így például egy ```while``` ciklusban használható a sorok kiolvasására:
```C++
while (std::getline(f, line))
{
    ...
}
```

### Kidolgozott példa: fájlkezelés
Olvassunk be személyeket a (Names.txt)[./FileHandling/Names.txt] fájlból és rendezzük is őket név szerint. Egy sorban a családnevet, keresztnevet, életkort  :
```
Gipsz Jakab 20 185 84
```
Ehhez először hozzunk létre egy osztályt, ami tárolja a személyeket:
```C++
class Person
{
private:
	const std::string first_name;
	const std::string last_name;
	unsigned int age;
	double height;
	double weight;
public:
	Person(const std::string fist_name, const std::string last_name, 
		unsigned int age, double height, double weight) :
		first_name(first_name), last_name(last_name), age(age),
		height(height), weight(weight)
	{}

	Person(const Person& p) : first_name(p.first_name), last_name(p.last_name),
		age(p.age), height(p.height), weight(p.weight) {}

	

	double getHeight() const
	{
		return height;
	}

	double getWeight() const
	{
		return weight;
	}
};
```
Ezután soronként olvassuk be a személyeket a főprogramban:
```C++

std::ifstream f("Names.txt");
if (!f.is_open())
{
    std::cerr << "Could not open file" << std::endl;
    return -1;
}
std::string line;
std::list<Person> persons;
while (std::getline(f, line))
{
    std::istringstream ss(line);
    std::string first_name;
    std::string last_name;
    unsigned int age;
    double height;
    double weight;
    ss >> last_name; 
    ss >> first_name;		
    ss >> age;
    ss >> height;
    ss >> weight;
    std::cout << first_name << " " << last_name << " " << age << std::endl;
    Person p(first_name, last_name, age, height, weight);
    persons.push_back(p);
}
```
A rendezést az egszerűség kedvéért beszúrásos rendezéssel hajtsuk végre:
```C++
std::vector<Person> sorted_persons(persons);
for (unsigned int i = 0; i < sorted_persons.size(); i++)
{
    for (unsigned int j = i; j < sorted_persons.size(); j++)
    {
        if (sorted_persons[i].getHeight() < sorted_persons[j].getHeight())
        {
            // Swap
            std::swap(sorted_persons[i], sorted_persons[j]);
        }
    }
}
```
Ezután írjuk ki a rendezett sorozat tartalmát:
```C++
for (unsigned int i = 0; i < sorted_persons.size(); i++)
{
    std::cout << sorted_persons[i].getHeight() << std::endl;
}
```

A feladat teljes megoldása elérhető a (következő mappából)[./FileHandling].

## TODO