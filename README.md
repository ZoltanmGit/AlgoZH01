#Task
Adott két rendezett, kétirányú, fejelemes ciklikus lista. Az egyik lista fejelemére FEJ1, a másik lista fejelemére FEJ2 mutat. FEJ1 lista hallgatók vizsgaeredményét tartalmazza, egy listaelemben a hallgató kódja, vizsgajegye, és egyéb adatok szerepelnek (dátum, pontszámok, stb.). FEJ2 lista hasonló szerkezetben a javító vizsga eredményeit rögzíti. A listák hallgatókód szerint szigorúan monoton növekedően rendezettek. Írjon algoritmust, mely FEJ1 listában előállítja a javító vizsga utáni állapotot: 
*	ha a hallgató javítót nem írt, akkor nem módosítjuk a rekordját; 
*	ha mindkét listában szerepel, a második jegye és annak egyéb adatai érvényesek: tehát töröljük az eredeti rekordot, és átfűzzük az új rekordot; 
*	ha az első vizsgán nem vett részt, de a javítón szerepel, akkor fűzzük át a hallgató rekordját FEJ2 listából FEJ1-be a rendezettség szerinti helyére. 
*	FEJ2 listát így az algoritmus menet közben lebontja, állítsuk üresre.  Műveletigény: O(n+m)
