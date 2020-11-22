# Ismétlő, Osztályok fogalma

## Előző kurzusanyag ismétlése
Korábbi kurzusban egy bevezetőt kaphattunk C/C++ alapú programozásból.

Amit C++-ról tudni kell: a C++ egy imperatív, objektum-orientált nyelv. Előző félévben az objektum-orientáltság nem került előtérbe.

### Fájlstruktúra
A C++-nak kötött fájlstruktúrája van. Egyrészt vannak forrásfájlok (__.cpp, .cc, .c__ kiterjesztéssel), másrészt más forrásfájlok számára is olvasható fejléc (header) fájlok (*.h, *.hpp).

A header fájlok definíciókat és függvényszignatúrákat tartalmaznak. A forrásfájlok


### Struktúra
A struktúra alkalmas volt arra, hogy az absztrakt módon összekapcsolható változókat csoportosíthassuk. Például egy pont struktúrát definiáló struktúra:
```C++
struct Point
{
    double x;
    double y;
    double z;
};
```
A definiált struktúra példányosítható a programon belül egy függvény hatáskörén belül. Például:
```C++
int main(int argc, char** argv)
{
    Point p0({0.0, 0.1, 1.2});
    return 0;
}
```

# Fontos nyelvi elemek
A C++ a következő alap nyelvi elemeket definiálja:
- &var