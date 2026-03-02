# C++ - Exerciții pentru Începători

Aici găsești 4 exerciții pentru a învăța C++ pas cu pas.

## Ce vor Exercițiile

Fiecare exercițiu te învață o idee nouă din C++.

### Exercițiul 1: Cuburi
**Ce faci:** Faci o clasă pentru un cub. Clasa calculează volumul.

**Cum:** Completezi `main.cpp` din folderul `exercitiu1_cuburi`

**De ce:** Să înveți ce este o clasă și cum funcționează.

---

### Exercițiul 2: Erbivor
**Ce faci:** Faci o clasă pentru un animal. Animalul poate mânca și energia se schimbă.

**Cum:** Completezi `main.cpp` din folderul `exercitiu2_erbivor`

**De ce:** Să înveți cum să schimbi datele dintr-o clasă.

---

### Exercițiul 3: Autobuz
**Ce faci:** Lucrezi cu mai multe autobuze. Calculezi suma biletelor.

**Cum:** Completezi `main.cpp` din folderul `exercitiu3_transport`

**De ce:** Să înveți cum să stochezi mai multe obiecte în o listă.

---

### Exercițiul 4: Festival
**Ce faci:** Citești niste oameni și biletele lor. Afișezi doar pe cei cu >5 bilete.

**Cum:** Completezi `main.cpp` din folderul `exercitiu4_festival`

**De ce:** Să înveți cum să citești date și să filtrezi ce vrei.

---

## Cum Se Lucrează

### Pasul 1: Mergi în folder
```
cd exercitiu1_cuburi
```

### Pasul 2: Deschizi README din folder
Citești ce trebuie să faci.

### Pasul 3: Deschizi main.cpp
Scrii **clasa și implementarea ei** în același fișier, deasupra funcției `main()`.

Apoi completezi logica din `main()`.

### Pasul 4: Compilezi
```
g++ -o test main.cpp
```

### Pasul 5: Rulezi
```
./test
```

---

## Structura unui Exercițiu

```
exercitiuX/
├── README.md       ← Enunț și instrucțiuni
└── main.cpp        ← TOT codul: clasa + main()
```

**Asta e tot!** Niciun `.h`, niciun fișier extra. Un singur fișier.

---

## Ce Este o Clasă?

O clasă este ca o "cutie" cu informații și acțiuni.

**Exemplu:**
```cpp
class Masina {
private:
    string culoare;

public:
    Masina() {
        culoare = "roșu";
    }

    void merge() {
        cout << "Masina merge!" << endl;
    }
};

int main() {
    Masina m;
    m.merge();
    return 0;
}
```

---

## Cuvinte Importante

- **class** = o grupare de date și acțiuni
- **private** = doar clasa știe
- **public** = oricine poate folosi
- **constructor** = inițializare (ce se întâmplă la început)
- **metoda** = o acțiune pe care o face clasa
- **vector** = o listă de obiecte

---

## De Ce Sunt 4 Exerciții?

Fiecare exercițiu este puțin mai greu decât cel dinainte.

1. **Cuburi** = doar clase ușoare
2. **Erbivor** = clase cu mai multe date
3. **Autobuz** = liste de obiecte (vector)
4. **Festival** = citire + liste + filtrare

Dacă faci toate 4, vei ști conceptele de bază! 🎓

---

## Dacă Nu Merge

### Eroare: "command not found: g++"
Instalează compilatorul. Pe Mac: `brew install gcc`

### Eroare: "undefined reference to"
Probabil ai încercat să compilezi 2 fișiere. Compilează doar `main.cpp`:
```
g++ -o test main.cpp
```

### Eroare: "expected ';' before"
Ai uitat `;` la final clasei sau o metodă. Verifică structura din README.

---

## Sfaturi

1. **Citește README de fiecare dată** - este acolo să te ajute
2. **Nu te uita la rezolvare imediat** - încearcă 10 minute
3. **Compilează des** - vezi dacă ai greșeli
4. **Testează cu date diferite** - nu doar cu exemplul din README

---

## Gata?

După ce termini toate 4 exerciții, ești gata pentru probleme mai grele!

Succes! 🚀
