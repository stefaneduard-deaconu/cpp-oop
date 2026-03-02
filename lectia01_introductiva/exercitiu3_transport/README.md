# Exercițiul 3: Clasă Autobuz și Vector

## Ce Trebuie Să Faci

Faci o clasă `Autobuz` pentru o cursă.

Apoi creezi o listă cu 3 autobuze și calculezi suma prețurilor.

De exemplu:
- Autobuz 1: 25 RON
- Autobuz 2: 30 RON
- Autobuz 3: 35 RON
- **Suma: 90 RON**

---

## Pași

### Pasul 1: Definiția și implementarea clasei
Scrii în `main.cpp`, **deasupra** funcției `main()`:

```cpp
class Autobuz {
private:
    double distanta;
    double pret_bilet;
public:
    Autobuz(double d, double p) {
        // TODO: salvează d și p
    }

    double getPretBilet() {
        // TODO: returnează pret_bilet
    }
};
```

---

### Pasul 2: Folosirea clasei în `main()`

```cpp
int main() {
    // TODO: vector<Autobuz> autobuze;

    // TODO: autobuze.push_back(Autobuz(100, 25.0));
    //       autobuze.push_back(Autobuz(150, 30.0));
    //       autobuze.push_back(Autobuz(200, 35.0));

    // TODO: double suma = 0;

    // TODO: for (Autobuz a : autobuze) {
    //           suma += a.getPretBilet();
    //       }

    // TODO: cout << suma << endl;  // trebuie 90

    return 0;
}
```

---

### Pasul 3: Compilare
```
g++ -o test main.cpp
./test
```

Trebuie să afișeze: **90**

---

## 💡 Ghidare

- Constructor: `distanta = d; pret_bilet = p;`
- `vector<Autobuz>` = o listă care crește
- `push_back()` = adaugă element
- `for (Autobuz a : autobuze)` = repetă pentru fiecare
- `getPretBilet()` = returnează `pret_bilet`

---

## ✅ Checklist

- [ ] Am scris clasa Autobuz în main.cpp
- [ ] Constructor salvează parametrii
- [ ] getPretBilet() returnează prețul
- [ ] main() creează vectorul
- [ ] main() adaugă 3 autobuze
- [ ] main() calculează suma cu loop
- [ ] Compilează: `g++ -o test main.cpp`
- [ ] Afișează 90

Succes! 🚀
