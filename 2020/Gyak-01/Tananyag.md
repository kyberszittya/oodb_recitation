# Gyakorlat 01 - Ismétlés

## Előzmények
A standard kimenet (STDOUT) és bemenet (STDIN) kezelésére a következő könyvtárat kell használni:
```C++
#include <iostream>
```
Kiíratás STDOUT-ra (vö.: konzolra):
```C++
...
std::cout << "Hello világ" << std::endl;
...
```
Beolvasás STDIN-ről egy értékhez (vö.: konzolról)
```C++
...
double a;
std::cin >> a;
...
```

## Struktúrák (C/C++)
Előző szemeszterből megismertük a _struktúrák_ fogalmát. Ezek a logikai építőelemek elsősorban arra voltak alkalmasak, hogy logikailag összetartozó nyelvi elemeket köthessünk össze. Ez előző félévben elsősorban változókra és más már definiált struktúrákra vonatkozott. Például, egy láncolt lista egy eleme, a következőképpen nézhetett ki:
```C++
struct LinkedListElem
{
    double elem;
    LinkedListElem*
};
```
## Osztályok (C/C++)
A C++ bevezeti az osztály fogalmát, a struktúrához hasonló logikai építőelemet. Az osztály az objektumorientált paradigma által megfoglamazott definíciókat teljesíti:
- Attribútumok (változók) és metódusok (függvények) használata, amelyek az osztály _tagjai_.
- Hozzáférés korlátozása (private/protected/public) attribútumokra és metódusokra egyaránt.
- Absztrakció definiálása, öröklődési láncolat bevezetésével.
- Polimorfizmus

Egy osztálynak a következő fontos függvényeit tartjuk számon:
- __Konstruktor:__ az osztály példányosítása során hívódik meg. Tipikus alkalmazása alapértékek beállítására. Bővebben a memóriakezelés során lesz tárgyalva.
- __Destruktor:__ az osztály életciklusának végén hívódik meg. Bővebben a memóriakezelés során lesz tárgyalva.
- __Getter függvény:__ az osztály egy attribútumával tér vissza a hívó szkópban. Alapvetően az attribútumhoz csak olvasási jogot szeretnénk biztosítani.
- __Setter függvény:__ az osztály egy attribútumát állítja be a függvény argumentumában megadott értékre.

A következő osztálydeklaráció például egy háromszöget valósít meg: a három oldal értékének tárolása mellett visszaadja kerületét és területét is:
```C++
#include <cmath>

class Triangle
{
private:
    double a;
    double b;
    double c;

    double heron_coeff()
    {
        double s = (a + b + c)/2.0;
        return s;
    }
public:
    // Konstruktor
    Triangle(double a, double b, double c): a(a), b(b), c(c)   { }

    // Háromszög egyenlőtlenség ellenőrzése
    bool check()
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Terület kiszámítása
    double area()
    {
        double s = heron_coeff();
        return std::sqrt(s*(s - a)*(s - b)*(s - c));
    }

    // Kerület kiszámítása
    double circumference()
    {
        return a + b + c;
    }
};
```
Egy osztály _példányosításáról_ (instantiation) beszélünk, ha egy szkópon belül a korábban deklarált osztály definiáljuk, például egy programfüggvényen (__main__) belül:
```C++
int main(int argc, char** argv)
{
    // a,b,c oldalak bekérése STDIN-ről
    double a,b,c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    // Triangle osztály példányosítása
    Triangle tri0(a,b,c);
    // Háromszög egyenlőtlenségek ellenőrzése
    if (tri0.check())
    {
        std::cout << "Kerület: " << tri0.circumference() << std::endl;
        std::cout << "Terület: " << tri0.area() << std::endl;
        return 0;
    }
    else
    {
        return -1;
    }
}
```
Egy osztály bármely más tagjára, a ```this``` foglalt szó használatával van lehetőségünk az osztály egy metódusán belül. Ez egy mutató az adott osztály aktuális példányára. Értelemszerűen ebben az esetben a hozzáférési korlátozások nem érvényesülnek. Pl. a Triangle osztály esetében, a következő ekvivalens felírás is állhat a Héron-képlet és a terület számításánál:
```C++
class Triangle
{
private:
    double a;
    double b;
    double c;

    double heron_coeff()
    {
        double s = (this->a + this->b + this->c)/2.0;
        return s;
    }
public:
    ...

    double area()
    {
        double s = this->heron_coeff();
        return std::sqrt(s*(s - this->a)*(s - this->b)*(s - this->c));
    }

    ...

}
```

_Korlátozott hozzáférés_: A háromszög osztály esetében az oldalakat tároló változókhoz nem férhetünk közvetlenül hozzá, mivel ezeket privát attribútumként definiáltuk! Vagyis a következő programkód nem fordulhat le:
```C++
...
Triangle tri(4,5,6);
std::cout << tri.a << std::endl; // Fordítási hiba! Nem férhetünk hozzá egyik oldalhoz sem mivel privát attribútumok
...
```
Ugyanígy a __heron_coeff__ metódus sem érhető el külső szkópból, mivel ezt privát metódusként definiáltuk:
```C++
...
Triangle tri(4,5,6);
std::cout << tri.heron_coeff() << std::endl; // Fordítási hiba! A metódus privát!
...
```

__Miért jó a hozzáférések korlátozása?__ Jelentős segítség nekünk egy nagyobb program fejlesztése esetében. Egy drasztikusabb esetet képzeljünk el: egy mobil-robot vezérlő szoftverét fejlesztjük. Ha azt választjuk, hogy az aktuális állapothoz hozzáférünk külsőleg, akkor egy hívó függvényből fogjuk ezt folyamatosan változtatni. Egyrészt, a helyes értékek ellenőrzését, vagy egy állapotdinamika hozzáadása ebből a függvényből kell történjen, holott logikailag a vezérlőszoftverhez tartozik. Ráadásul beláthatatlan következményei lehetnek a külső függvényből történő változtatásnak: a publikus értkeket bármelyik másik függvény felülírhatja, ami akár vezethet helytelen (akár katasztrófális) értékek megadásához. 

A hozzáférések korlátozása továbbá megköveteli a komponensorientált megközelítést, az osztály egyfajta építőelemként használható a szoftver többi része által. A szoftver többi része nyilvánvalóan a publikus metódusokhoz és attribútumokhoz fér csak hozzá. Ez egybevág a mérnöki megközelítéssel: más mérnöki területeken is alapvetően újrafelhasználható komponensek tervezése a cél (pl. elektronika, gépészet), amelyek belső működése el van fedve a rendszerbe integrálás során. 

Egy következő eset leírásával jól reprezentálható: például egy televízió vezérlőszoftverénél a működés egy részéhez szeretnénk hozzáférni (pl. ki/be kapcsolás, csatornaváltás), de ezek megvalósításának menetét szeretnénk elfedni. Az aktuális csatornát (amit egy attribútumként tárolunk) csak a megfelelő metódus hívásával szeretnénk változtatni, külsőleg nem engedélyezzük ennek változtatását. Ha ezt elektronikával oldanánk meg, hasonlóan járnánk el: a csatornaváltást egy vezérlőjel alkalmazásával érnénk el, a belső kapcsolást elfedjük a rendszer többi része elől.

### Konstans jelző
Osztályok és függvények során visszatérő a konstans értékek és változók kezelése. 

Attribútumok és változók esetében jelezzük a fordítónak, hogy az adott érték példányosítást (vagyis érték adaást követően) nem változtatható. Ugyanígy használható a függvény argumentumainak deifniálása esetében, ekkor jelezzük, hogy az argumentum értékét a függvényben nem változtatjuk. 

Konstans attribútum logikusan, például egy személyt leíró osztály esetében használható. Esetünkben a neve és a születési évnek egy embernek sem változik meg:
```C++
class Person
{
private:
    const std::string name;
    const unsigned int birth_year;
public:
    Person(const std::string name, const unsigned int birth_year): name(name), birth_year(birth_year){}
}
```
A konstans jelző használható függvények esetében is. Ezzel azt jelezzük, hogy a visszatérési érték lesz konstans, például a következő esetben a visszatért életkort a hívó szkópban nem változtatjuk meg:
```C++
class Person
{
    ...
public:
    ...
    const int getAge(const unsigned int current_year)
    {
        return current_year - birth_year;
    }
    ...
};
```
Ha a szignatúrát követően tesszük ki a konstans jelzőt, akkor azt jelezzük, hogy a függvény hívásával az osztály belső állapotát, változóit nem szeretnénk változtatni.


### Setter és getter függvények
A setter függvény esetében a következő függvényszignatúra követhető az osztály egy attribútumához:
```C++
void setAttributum(const attributum_tipus attributum)
{
    this->attributum = attributum;
}
```
Értelmeszerűen konstans adattag esetén a setter függvény nem működik. A getter függvény esetében a következő függvényszignatúra követhető:
```C++
attributum_tipus getAttributum() const
{
    return this->attributum;
}
```
A __const__ jelzi, hogy a függvény meghívásával az osztály állapotát nem változtatjuk meg.

A Háromszög számító program Triangle osztálya kibőívthető getter és setter függvényekkel. Ezzel azt szeretnénk biztosítani, hogy az értékek kiolvashatók vagy változtathatók legyenek a program futása során, bármely szkópból.
```C++
class Triangle
{
private:
    double a;
    double b;
    double c;

    double heron_coeff()
    {
        double s = (a + b + c)/2.0;
        return s;
    }
public:
    ...

    // Getter függvények
    const double getA() const
    {
        return a;
    }

    const double getB() const
    {
        return b;
    }

    const double getC() const
    {
        return c;
    }

    // Setter függvények
    void setA(const double a)
    {
        this->a = a;
    }

    void setB(const double b)
    {
        this->b = b;
    }

    void setC(const double c)
    {
        this->c = c;
    }
};
```


## Kidolgozott feladat: Téglalap számítása
__Feladat:__ Készítsen egy programot, ami kiszámítja egy téglalap kerületét és területét! Az értékeket (a téglalap két oldala) kérje be standard inputról és írassa ki a kerület/terület számítás eredményét standard outputra! Használjunk setter/getter függvényeket. A téglalap oldalait ne változtathassuk meg példányosítást követően.

__Megoldás:__ Készítsünk egy osztályt, ami a téglalapot deifniálja!
```C++
class Rectangle
{
private:
    const double a; // Az oldalak példányosítást követően nem változtahatók meg
    const double b;
public:
    Rectangle(const double a, const double b): a(a), b(b) {} // Konstans adattagok esetén adunk értéket az attribútumoknak

    // Kerület számítása
    const double circumference() const
    {
        return 2*(a + b);
    }

    // Terület számítása
    const double area() const
    {
        return a*b;
    }

    // Setter függvényeknek esetünkben (a két konstans attribútumra) nincs lehetősége
    
    // Getter függvények
    const double getA() const { return a; }
    const double getB() const { return b; }
};
```
A főprogram ezek tükrében:
```C++
int main(int argc, char** argv)
{
    // Értékek bekérése
    double a,b;
    std::cout << "Adjon meg egy téglalapot" << std::endl;
    std::cout << "A oldal: ";
    std::cin >> a;
    std::cout << "B oldal: ";
    std::cin >> b;
    // Téglalap példányosítása
    Rectangle rect(a, b);
    // Téglalap kiírása
    std::cout << "Téglalap: " << std::endl;
    std::cout << "A: " << rect.getA() << " B: " << rect.getB() << std::endl;
    // Kerület/terület kiírása
    std::cout << "Kerület: " << rect.circumference() << std::endl;
    std::cout << "Terület: " << rect.area() << std::endl;
    return 0;
}
```
A feladat megoldása (Visual Studio projektént) elérhető a [Rectangle mappában](./Rec1/Rectangle).

## Kiegészítés: Struktúrák vs. Osztályok
Formálisan a C++ a sturktúrák és osztályok között az alapértelmezett hozzáférés tekintetében tesz különbséget:
- Az osztály esetében az alapértelmezett hozzáférés privát.
- A struktúra esetében az alapértelmezett hozzáférés publikus.

Ezt a következő kódrészlet jól reprezentálja. Ha struktúraként 
```C++
struct VehicleState
{
    double linear_velocity;
    double angular_velocity;
};

class Person
{
    std::string name;
};
...

VehicleState vehiclestate;
vehiclestate.linear_velocity = 6.0; // OK! A linear_velocity attribútum publikus
Person p0;
p0.name = "Gipsz Jakab"; // Fordítási hiba! A name attirbútum privát
```

__Miért szükséges struktúra definiálása C++-ban?__ Ennek elsősorban kompatibilitási okai vannak, szeretnénk a C-vel a lehető leginkább kompatibilissá tenni. A C-ben megírt programok (pl. meghajtószoftverek) sok esetben egy az egyben felhasználhatóak egy C++ programban. Ugyanakkor lehetővé tesz egy hasznos struktúrálási lehetőséget is: egy osztályon belüli részek sturktúrálására lehet alkalmas. Például egy vezérlőszoftver esetében sok változót definiáltunk, amelyek valamilyen logikai szinten összetartoznak. A következő lehetséges:
```C++
struct VehicleState
{
    double linear_velocity;
    double angular_velocity;
};

class VehicleController
{
private:
    VehicleState state;
public:
    VehicleController(){}

    void update_state(double lin_acc, double ang_acc)
    {
                
    }
};
```