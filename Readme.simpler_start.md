Pentru a păstra relevanța cu subiectele de colocviu (dar la un nivel extrem de simplificat), ți-am pregătit **4 prompturi pe care le poți trimite direct lui Claude**. Ele folosesc contextul problemelor tale (Containere, Ecosistem, Transport), dar sunt formulate pentru a genera cerințe treptate, cu pași mici și hint-uri.

Le poți copia cu totul și trimite pe rând:

---

### Promptul 1: Recapitulare structura unei clase (Tema: Containere)
**Scop:** Învățarea sintaxei de bază a unei clase, constructor și o metodă simplă.

> **Prompt pentru Claude:**
> "Acționează ca un tutore de C++ empatic și răbdător. Un student are nevoie să își reamintească lucrul cu clase de la zero.
> Creează un exercițiu simplu bazat pe următoarea idee: O firmă lucrează cu containere de formă Cub. Pentru un cub, trebuie reținută latura, iar volumul este Latura la puterea a 3-a.
> 
> Te rog să scrii enunțul problemei și să îl împarți în 4 pași de rezolvare foarte mici.
> Pasul 1: Definirea clasei `Cub` și a atributului privat `latura`.
> Pasul 2: Crearea constructorului.
> Pasul 3: Crearea unei metode publice `calculeazaVolum()`.
> Pasul 4: Testarea în funcția `main()`.
> 
> Pentru fiecare pas, oferă 1-2 'Mini-hint-uri' (de exemplu, amintește-i de `;` la finalul clasei, explică diferența dintre public și private, arată-i cum se afișează ceva cu `std::cout`). Nu oferi codul complet rezolvat, ci doar structura și indicațiile pentru a-l ghida să scrie el codul."

### Promptul 2: Lucrul cu mai multe atribute și logica în metode (Tema: Animale)
**Scop:** Înțelegerea modului în care metodele modifică starea (atributele) unui obiect.

> **Prompt pentru Claude:**
> "Continuă lecția de C++ pentru studentul meu. Acum vom face o clasă puțin mai interactivă, inspirată dintr-o simulare a unui ecosistem.
> 
> Formula exercițiul astfel: Să se creeze o clasă `Erbivor` care are două atribute private: `nume` (de tip std::string) și `energie` (de tip double). Inițial, animalul primește o anumită energie prin constructor. Vom simula acțiunea de a mânca, care îi va crește energia.
> 
> Împarte cerința în pași mici:
> Pasul 1: Definirea clasei cu atributele și constructorul (recapitulare rapidă).
> Pasul 2: Crearea unei metode publice `mananca(double cantitate_mancare)`. În interiorul ei, animalul primește energie egală cu cantitatea de mâncare împărțită la 10. Metoda trebuie să modifice atributul `energie`.
> Pasul 3: Crearea unei metode `afiseazaStare()` care să printeze numele și energia curentă.
> Pasul 4: În `main()`, instanțierea unui Erbivor, apelarea metodei afiseazaStare(), apoi apelarea metodei mananca(), și din nou afiseazaStare() pentru a vedea cum s-a schimbat valoarea.
> 
> Oferă mini-hint-uri (ex: reamintește-i să includă `<string>`, explică-i scurt cuvintele cheie pentru tipurile de date). Nu îi da soluția directă, ci doar indicii clare."

### Promptul 3: Introducere în colecții (Tema: Firma de Transport)
**Scop:** Trecerea de la un singur obiect la lucrul cu `std::vector` (esențial pentru toate problemele de examen).

> **Prompt pentru Claude:**
> "Trecem la nivelul următor în C++. Acum studentul trebuie să își amintească cum se lucrează cu listele de obiecte folosind `std::vector`. Tema va fi o firmă de transport.
> 
> Generează următorul exercițiu: O firmă are mai multe curse de tip `Autobuz`. O cursă are ca atribute `distanta` și `pret_bilet`. Să se creeze clasa `Autobuz`, iar apoi în `main()` să se salveze 3 autobuze diferite într-o listă și să se afișeze prețul total al biletelor (suma lor).
> 
> Pași mici de rezolvare:
> Pasul 1: Clasa Autobuz cu atribute private, constructor și un getter pentru prețul biletului.
> Pasul 2: În `main()`, declararea unui `std::vector<Autobuz>`.
> Pasul 3: Adăugarea manuală a 3 autobuze în vector.
> Pasul 4: Parcurgerea vectorului cu un `for` și calcularea sumei.
> 
> Oferă mini-hint-uri foarte specifice aici: cum se include `<vector>`, sintaxa exactă pentru a declara un vector de obiecte, cum se folosește `.push_back()`, și cum arată un range-based for loop (`for (Autobuz a : autobuze)`) sau un for clasic. Nu scrie programul în locul lui."

### Promptul 4: Combinarea noțiunilor (Tema: Festival)
**Scop:** Testarea noțiunilor asimilate prin citirea de la tastatură a datelor și adăugarea lor în vector.

> **Prompt pentru Claude:**
> "Acesta este ultimul exercițiu introductiv înainte ca studentul să treacă la probleme mai complexe de colocviu. Tema este organizarea unui festival de muzică.
> 
> Creează un exercițiu unde se citește de la tastatură numărul `N` de persoane. Apoi se citesc `N` tranzacții: numele persoanei și numărul de bilete cumpărate.
> 
> Pași mici:
> Pasul 1: Crearea clasei `Tranzactie` (nume_persoana, nr_bilete) și a metodelor de acces (getters).
> Pasul 2: În `main()`, citirea numărului `N`. Declararea unui `std::vector<Tranzactie>`.
> Pasul 3: Un loop `for` care se repetă de `N` ori. În interior, se citesc variabilele de la tastatură, se creează un obiect `Tranzactie` și se adaugă în vector.
> Pasul 4: Parcurgerea vectorului și afișarea DOAR a persoanelor care au cumpărat strict mai mult de 5 bilete.
> 
> Mini-hint-uri: Amintește-i cum se citește cu `std::cin >>`, cum se folosește un `if` în interiorul unui `for` pentru a filtra rezultatele. Așa cum am stabilit, fără cod complet, doar îndrumări blânde."

---
**Cum să folosești aceste prompturi:**
*   Dă-i promptul 1. Așteaptă ca Claude să genereze lecția și dă-o studentului.
*   Când studentul termină și a reținut ce este un atribut privat și o metodă, treci la promptul 2, și tot așa.
*   Până ajunge la finalul celor 4 exerciții, îi vor reveni în reflex detaliile de sintaxă (`std::vector`, `class`, `public:`, `std::cin`, `push_back`) și va fi mult mai pregătit să încerce prima variantă de examen.