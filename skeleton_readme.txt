A tervhez képest történt néhány változás a fejlesztés során. Kigyűjtöttem ide azokat a dolgokat, amit én észrevettem, hogy eltér a "megígértektől".

std::string char* helyett | Arra jutottam, hogy az std::stringeket kényelmesebb kezelni a c-stringek helyett. Ha esetleg ez tiltott lenne a NHF-ben akkor kérlek jelezzétek és kijavítom.

Getter, setter, RW függvények | Kihagytam egy csomó fontos getter, setter és RW függvényt az UML diagramról. Ezek bekerültek a classekbe.

navigal() fölösleges | Rájöttem, hogy a menüben a navigal fgv teljesen felesleges, szóval ezt kihagyom teljesen.

List fgv-k | Az Osszetevo és Recept osztályokhoz deklaráltam listázó függvényeket amik majd kiírják szépen formattálva az adott listát.