# Exercițiul 2: Clasă Erbivor

## Ce Trebuie Să Faci

Faci o clasă `Erbivor` pentru un animal.

Animalul are:
- Nume (text)
- Energie (număr)

Când mănâncă, energia crește. (mâncare / 10)

De exemplu: Bambi cu 50 energie. Mănâncă 100 → energia devine 60.

---

## Pași

### Pasul 1: Definiția și implementarea clasei
Scrii în `main.cpp`, **deasupra** funcției `main()`:

```cpp
class Erbivor {
private:
    string nume;
    double energie;
public:
    Erbivor(string n, double e) {
        // TODO: salvează n în nume, e în energie
    }

    void mananca(double cat) {
        // TODO: energie = energie + cat / 10
    }

    void afiseazaStare() {
        // TODO: afișează "Erbivor-ul [NUME] are energie [ENERGIE]"
    }
};
```

---

### Pasul 2: Folosirea clasei în `main()`

```cpp
int main() {
    // TODO: Creează Erbivor animal("Bambi", 50.0);

    // TODO: animal.afiseazaStare();  // afișează 50

    // TODO: animal.mananca(100.0);   // +10 energie

    // TODO: animal.afiseazaStare();  // afișează 60

    return 0;
}
```

---

### Pasul 3: Compilare
```
g++ -o test main.cpp
./test
```

Trebuie să afișeze:
```
Erbivor-ul Bambi are energie 50
Erbivor-ul Bambi are energie 60
```

---

## 💡 Ghidare

- Constructor: `nume = n; energie = e;`
- `mananca(100)` → `energie = energie + 100/10` → +10
- `afiseazaStare()` → `cout << "Erbivor-ul " << nume << " are energie " << energie << endl;`

---

## ✅ Checklist

- [ ] Am scris clasa Erbivor în main.cpp
- [ ] Constructorul salvează parametrii
- [ ] mananca() crește energia
- [ ] afiseazaStare() afișează corect
- [ ] Compilează: `g++ -o test main.cpp`
- [ ] Afișează 50, apoi 60

Succes! 🚀
