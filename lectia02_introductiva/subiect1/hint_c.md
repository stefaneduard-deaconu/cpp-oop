# Hint C — Sortarea alfabetică a formațiilor (Poster)

**Cerință rezumat:** Din $T$ formații, afișează numele în ordine alfabetică.

---

## Pas 1: Reutilizează clasa `Formatie`

Poți folosi aceeași clasă de la subpunctul b). Aici ai nevoie doar de nume.

```cpp
class Formatie {
private:
    string nume;
    int popularitate;
public:
    Formatie() : nume(""), popularitate(0) {}
    Formatie(string n, int p) : nume(n), popularitate(p) {}

    string getNume() { return nume; }
    int getPopularitate() { return popularitate; }
};
```

---

## Pas 2: Citirea formațiilor

```cpp
int T;
cin >> T;

Formatie formatii[100];
for (int i = 0; i < T; i++) {
    string nume;
    int pop;
    cin >> nume >> pop;
    formatii[i] = Formatie(nume, pop);
}
```

---

## Pas 3: Sortarea — Bubble Sort pe nume

Sortezi array-ul de formații după `getNume()` folosind un algoritm simplu.

```cpp
for (int i = 0; i < T - 1; i++) {
    for (int j = i + 1; j < T; j++) {
        if (formatii[i].getNume() > formatii[j].getNume()) {
            // interschimbă
            Formatie temp = formatii[i];
            formatii[i] = formatii[j];
            formatii[j] = temp;
        }
    }
}
```

> **De ce merge comparația cu `>`?** Operatorul `>` pe `string` compară lexicografic (alfabetic) în C++. Exact ce ne trebuie.

> **Alternativă STL:** Dacă folosești `vector<Formatie>`, poți apela `sort()` cu o funcție de comparare:
> ```cpp
> sort(formatii.begin(), formatii.end(), [](Formatie& a, Formatie& b) {
>     return a.getNume() < b.getNume();
> });
> ```

---

## Pas 4: Afișarea posterului

```cpp
cout << "=== POSTER FESTIVAL ===" << endl;
for (int i = 0; i < T; i++) {
    cout << formatii[i].getNume() << endl;
}
```

---

## Exemplu complet de rulare

**Input:**
```
c
5
Zebra 1
Metallica 2
ACDC 1
Beatles 3
Queen 2
```

**Output:**
```
=== POSTER FESTIVAL ===
ACDC
Beatles
Metallica
Queen
Zebra
```

Numele apar în ordine alfabetică, gata de pus pe poster.
