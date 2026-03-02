# Subiectul 1: Organizarea unui Festival — Ghid pas cu pas

Acest ghid te conduce treptat prin rezolvarea celor trei subpuncte.

Începe prin a citi cerința completă din [Readme-ul lecției](../Readme.md), apoi urmează hint-urile pe rând:

| Subpunct | Temă | Hint |
|----------|------|------|
| a) | Cumularea biletelor per persoană | [Hint A — Tranzacții](hint_a.md) |
| b) | Formarea seturilor de formații pe zile | [Hint B — Formații pe zile](hint_b.md) |
| c) | Sortarea alfabetică a formațiilor | [Hint C — Poster alfabetic](hint_c.md) |

---

## Structura generală a programului

Programul citește un caracter (`a`, `b` sau `c`) și execută ramura corespunzătoare. Scheletul de `main` arată așa:

```cpp
#include <iostream>
#include <string>
using namespace std;

// clasele Tranzactie, Formatie (definite mai jos)

int main() {
    char comanda;
    cin >> comanda;

    if (comanda == 'a') {
        // rezolvare subpunct a)
    } else if (comanda == 'b') {
        // rezolvare subpunct b)
    } else if (comanda == 'c') {
        // rezolvare subpunct c)
    }

    return 0;
}
```

Acum deschide hint-ul pentru subpunctul la care lucrezi.
