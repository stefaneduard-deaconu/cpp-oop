# 📚 C++ Exerciții Introductive - Ghid Complet

Aceste 4 exerciții sunt proiectate pentru **învățarea progresivă a conceptelor de bază ale C++** și **Programării Orientate pe Obiecte (POO)**.

---

## 🎯 Structura Exercițiilor

### **Exercițiul 1: Cuburi (Clase și Constructori)**
📁 Folder: `exercitiu1_cuburi/`

**Ce vei învăța:**
- Cum se declară o clasă
- Atribute private
- Constructor și inițializare
- Metode simple

**Dificultate:** ⭐ (Foarte ușor)

**Pași:**
```bash
cd exercitiu1_cuburi
# 1. Completează cub.h (definiția clasei)
# 2. Completează cub.cpp (implementarea)
# 3. Completează main.cpp (testare)
g++ -o test main.cpp cub.cpp
./test
```

---

### **Exercițiul 2: Erbivor (Modificare Stare)**
📁 Folder: `exercitiu2_erbivor/`

**Ce vei învăța:**
- Atribute multiple (string și double)
- Metode care modifică starea
- Metode void (fără return)
- std::string

**Dificultate:** ⭐⭐ (Ușor)

**Pași:**
```bash
cd exercitiu2_erbivor
# 1. Completează erbivor.h
# 2. Completează erbivor.cpp
# 3. Completează main.cpp
g++ -o test main.cpp erbivor.cpp
./test
```

---

### **Exercițiul 3: Autobuz (Vectori)**
📁 Folder: `exercitiu3_transport/`

**Ce vei învăța:**
- std::vector (liste dinamice)
- push_back() - adăugare în vector
- Getteri - metodă care returnează valori private
- Range-based for loop - iterare prin vector

**Dificultate:** ⭐⭐⭐ (Mediu)

**Pași:**
```bash
cd exercitiu3_transport
# 1. Completează autobuz.h
# 2. Completează autobuz.cpp
# 3. Completează main.cpp
g++ -o test main.cpp autobuz.cpp
./test
```

---

### **Exercițiul 4: Festival (Citire + Filtrare)**
📁 Folder: `exercitiu4_festival/`

**Ce vei învăța:**
- Citire de la tastatură (std::cin)
- Loop cu contor (for)
- Condiții (if)
- Parcurgere vector cu filtrare

**Dificultate:** ⭐⭐⭐⭐ (Mediu-Avansat)

**Pași:**
```bash
cd exercitiu4_festival
# 1. Completează tranzactie.h
# 2. Completează tranzactie.cpp
# 3. Completează main.cpp
g++ -o test main.cpp tranzactie.cpp
./test
```

---

## 📋 Structura unui Exercițiu

Fiecare exercițiu are:

```
exercitiu_X/
├── README.md          # Enunț, pași, hints și 20% rezolvare
├── clasa.h            # Header - să completezi
├── clasa.cpp          # Implementare - să completezi
└── main.cpp           # Program principal - să completezi
```

---

## 🚀 Cum să Lucrezi

### **Metoda Recomandată:**

1. **Citește README.md** din folder
   - Înțelege enunțul problemei
   - Citește Pașii de Rezolvare
   - Studiază Hint-urile

2. **Completează fișierele în ordinea:**
   - `clasa.h` - definiția clasei
   - `clasa.cpp` - implementarea metodelor
   - `main.cpp` - programul de testare

3. **Nu te uita la rezolvarea parțială dintr-o dată!**
   - Doar dacă ești blocat după 10 minute
   - Citește doar hint-ul necesar, nu tot codul

4. **Compilează și testează:**
   ```bash
   g++ -o test main.cpp clasa.cpp
   ./test
   ```

5. **Dacă nu merge:**
   - Verifică erorile compilatorului
   - Citește din nou README-ul
   - Compară structura cu rezolvarea parțială

---

## 💡 Sfaturi Importante

### **Atribute și Metode**
```cpp
class ExempluClasa {
private:                    // Doar clasa le vede
    int variabila;
    string nume;

public:                     // Oricine le folosește
    ExempluClasa(int v, string n) {  // Constructor
        variabila = v;
        nume = n;
    }

    int getVariabila() {    // Getter - returnează valoare privată
        return variabila;
    }

    void setVariabila(int v) {  // Setter - schimbă valoare privată
        variabila = v;
    }
};
```

### **Vector**
```cpp
#include <vector>
using namespace std;

vector<int> numere;           // Vector gol
numere.push_back(5);          // Adaugă 5
numere.push_back(10);         // Adaugă 10

// Iterare 1 - Range-based for
for (int n : numere) {
    cout << n << endl;
}

// Iterare 2 - For clasic
for (int i = 0; i < numere.size(); i++) {
    cout << numere[i] << endl;
}
```

### **Citire de la Tastatură**
```cpp
int numar;
string text;
double zecimal;

cin >> numar;       // Citire întreg
cin >> text;        // Citire string
cin >> zecimal;     // Citire zecimal
```

---

## ✅ Checklist de Progres

- [ ] Exercițiul 1 - Cuburi - COMPLETAT ✅
- [ ] Exercițiul 2 - Erbivor - COMPLETAT ✅
- [ ] Exercițiul 3 - Autobuz - COMPLETAT ✅
- [ ] Exercițiul 4 - Festival - COMPLETAT ✅

**După aceste exerciții, ești gata pentru probleme mai complexe!** 🎓

---

## 🔗 Resurse Utile

- [cppreference.com](https://en.cppreference.com/) - Documentație C++
- [cplusplus.com](http://www.cplusplus.com/) - Tutorial C++
- Compilator online: [repl.it](https://repl.it/) sau [ideone.com](https://ideone.com/)

---

## ❓ Întrebări Frecvente

**Q: Cum compilez?**
A: `g++ -o test main.cpp clasa.cpp` (sau `clang++`)

**Q: De ce nu merge compilarea?**
A: Verifică:
- Ai salvat fișierele?
- Ai inclus header-ele (`#include`)?
- Ai pus `;` la finalul clasei din header?
- Ai implementat toate metodele din .cpp?

**Q: Nu înțeleg hint-ul, ce fac?**
A: Citește din nou README, apoi privește rezolvarea parțială (doar structura, nu codul)

**Q: De ce nu trebuie să vad rezolvarea completă?**
A: Pentru a-ți dezvolta gândirea de programator și abilitatea de problem-solving!

---

**Mult succes! 🚀 Ești pe drumul bun!**
