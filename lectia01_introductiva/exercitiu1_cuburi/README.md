# Exercițiul 1: Clasă Cub

## Ce Trebuie Să Faci

Faci o clasă `Cub` care calculează volumul.

Un cub are o latură. Volumul = latura × latura × latura.

De exemplu: cub cu latura 5 → volumul 125.

---

## Pași

### Pasul 1: Definiția și implementarea clasei
Scrii în `main.cpp`, **deasupra** funcției `main()`:

```cpp
class Cub {
private:
    double latura;
public:
    Cub(double l) {
        // TODO: salvează l în latura
    }

    double calculeazaVolum() {
        // TODO: returnează latura * latura * latura
    }
};
```

---

### Pasul 2: Folosirea clasei în `main()`

```cpp
int main() {
    // TODO: Creează un cub: Cub c(5.0);

    // TODO: Calculează și afișează volumul
    // Trebuie să afișeze: 125

    return 0;
}
```

---

### Pasul 3: Compilare
```
g++ -o test main.cpp
./test
```

Trebuie să afișeze: **125**

---

## 💡 Ghidare

- Constructor primește latura și o salvează: `latura = l;`
- Metodă calculează: `latura * latura * latura`
- În main afișezi cu: `cout << c.calculeazaVolum() << endl;`

---

## ✅ Checklist

- [ ] Am scris clasa Cub în main.cpp
- [ ] Constructorul salvează latura
- [ ] Metoda returnează volum
- [ ] main() creează un cub și afișează volumul
- [ ] Compilează: `g++ -o test main.cpp`
- [ ] Afișează 125

Succes! 🚀
