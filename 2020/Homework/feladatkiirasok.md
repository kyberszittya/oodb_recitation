# Házi feladatok (gyakorló)

Az alábbi feladatokból tetszőleges számú megoldható! A kész megoldást érdemes Git-re feltölteni. A megoldásokat Visual Studio vagy CMake segítségével szervezze.

Memóriaszivárgást Valgrind vagy Visual Studio segítségével ellenőrizheti:
- Valgrind tutorial: http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
- Visual Studio Memóriaszivárgás ellenőrzése (CRT könyvtár segítségével): https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

## Kezdő feladatok

### Feladat 1.1
Készítsen programot, ami a mellékelt [CSV fájlból](Kezdo/Feladat1/heroes.csv) beolvassa a harcoló hősök listáját! Vizsgálja meg a CSV fájl tartalmát: a tárolt adatok (és a feladatkiírás) alapján készítsen egy osztályt! Nézzen utána az esetleg még nem tanult, ismeretlen dolgoknak!

A program egy játékot szimuláljon:
1.	Listázza ki, a hősöket és tulajdonságaikat.
1.	A felhasználó válasszon ki az elején két hőst.
1.	A szimuláció körökre osztott. Minden körben sebezzék meg egymást a hősök, az alábbi összefüggés alapján: precision * uniform_random(min_DPS, max_DPS)
1.	Minden játékoshoz tartozik egy speciális képesség. Minden hős egy körben 5%-os valószínűséggel használja képességét. A képességhez tartozik egy speciális sebzés, ami teljes értékben sebzi az ellenfelet.
1.	A szimuláció mindaddig folytatódjon, ameddig az egyik hős életereje nem lesz 0 egy kör végén.


### Feladat 1.2
Készítsen programot, ami a mellékelt [CSV fájlból](Kezdo/Feladat2/stars.csv) beolvassa csillagok listáját! Ezeket tárolja egy láncolt listában (a láncolt lista implementációja legyen saját)! Listázza ki az összes csillagot! Írassa ki ezután a: 
-	legtávolabbi, 
-	legközelebbi, 
-	legfényesebb,
-	leghalványabb 
-	legmasszívabb
-	és legkisebb csillagot!

Implementálás ajánlott menete:
1.	Először tárolja a csillagokat struktúrában.
1.	Ezután egy másik programban írja meg az objektumorientált verziót is!

Készítsen egy űrhajó osztályt! Az űrhajónak legyen egy sebesség attribútuma (m/s). A felhasználótól kérjen inputot, amivel kiválassza a célcsillagot, és adja vissza mennyi évig tart eljutni az adott csillaghoz. Figyeljen, hogy az csillagok távolsága fényévben van megadva!

### Feladat 1.3
Készítsen programot, ami beolvas egy [CSV fájlból](Kezdo/Feladat3/monsters.csv) szörnyeket. A program indításakor listázza ki az elérhető szörnyeket! A játékos egy csapatot állít össze: kiválaszthat szörnyeket, amennyi a játékoshoz adott pontszámból előállhat (minden szörnyhöz tartozik egy szint). A játékoshoz tartozó pontszám legyen 25 első körben.
A számítógép ezután kiválasztja saját maga is a szörnyeket, hogy beleférjen a meghatározott pontszámba (25 pontba férjen bele).
-	Először oldja meg, hogy egy 5-ös szintű szörnyet választ ki. Ezután válasszon ki kettő 4-es szintű szörnyet és három darab 2-es szintű szörnyet (ezt megteheti véletlenszerűen). A maradékot 1-es szintű szörnyekből válassza ki!
-	Opcionális: oldja meg, hogy életerőre legoptimálisabb összeállítást válassza ki (hátizsák probléma)!
A játék körökre osztott legyen. 

Minden kör elején írja ki mindkét félnek mennyi szörnye maradt, mekkora életerővel (a szörnyek legyenek sorszámozottak)! Minden körben a leggyorsabb szörny támad először, játékostól függetlenül (ugyanakkora sebességnél a játék véletlenszerűen döntsön). A játékos megadhatja, melyik sorszámú szörnyet szeretné megtámadni! A számítógép ezt véletlenszerűen tegye meg! A támadás során a megtámadott szörnyet egy véletlenszerű érték alapján sebezze meg: uniform_random(min_dps, max_dps).

A játék akkor ér véget, ha valamelyik csapat szörnyei elfogynak. A játék végén írja ki egy fájlba:
-	A játékos kezdő csapatát
-	A játékos végére maradt csapata (ha vesztes, akkor ne írjon semmit!)

### Feladat 1.4
Készítsen egy labirintus programot! A labirintust egy szöveges fájlból olvassa be! A labirintus szöveges formája nem kötött, de minden labirintus legyen egy téglalap alaprajzú, amiben a következők adottak:
-	falak
-	akadályokkal
-	csapdák
-	szörnyek
-	a játékos kezdőpozíciója
-	célpont

A játék az egyszerűség kedvéért legyen körökre osztott! Minden kör elején írja ki konzolra a labirintus állapotát. Minden kör elején a szörnyek véletlenszerű szomszédos pontra mozdulnak. Bárki, aki a csapdába lép, az meghal (szörny/játékos egyaránt).

A játékos a W,A,S,D gombokkal irányítható (fel, balra, le, jobbra)! A játékos nem tud támadni: ha szörnnyel találkozik akkor meghal. A játékos halála esetén a program kilép. Ha a játékos a célpontra ért, győzelem! Kapjon 100 pontot és az eredményt frissítse egy highscores.txt fájlban (ekkor kérje be a játékos nevét)!
Opcionális: készítsen „okos” szörnyeket, akik a játékost igyekeznek becserkészni, vagyis a játékoshoz vezető legközelebbi útvonalon igyekeznek utolérni. A szörnyek kerüljék ki a csapdákat is! Milyen algoritmust használna erre a problémára?

## Haladó feladatok

### Feladat 2.1
Valósítsa meg az életjátékot (Conway https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) C++ program segítségével! Ez egy klasszikus probléma a programozási feladatok esetében. Hozzon létre egy a program kezdetekor állítható rácsot, amiben sejtek tárolhatók. A sejtek működését azok szomszédjainak száma határozza meg:
-	Minden élő sejt, aminek egy vagy annál kevesebb sejtszomszédja van, elpusztul a következő ciklusban, vagyis szabaddá válik a cella.
-	Minden élő sejt, aminek kettő vagy három szomszédja van, túléli a következő ciklust.
-	Minden élő sejt, aminek háromnál több szomszédja van, elpusztul.
-	Minden cella, ahol pontosan három szomszédos cellában található sejt, új élő sejt keletkezik.

A cellákat véletlenszerűen töltse fel a program indításakor. A ciklus előrehaladása automatikus legyen, ne legyen szükség a felhasználó beavatkozására (időzítés). Ha ez elkészült, a következőket valósítsa meg:
-	Állítson be a cellának programozott halált. Vagyis egy előre definiált ciklusszám után minden sejt pusztuljon el.
-	Szimulálja a rákos sejteket: legyen sejteknek egy csoportja, amire nem érvényes a programozott halál. Mit tapasztal?
