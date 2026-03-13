# README.skills.md - Skills pentru colocviu OOP

Acest ghid extrage abilitatile necesare pentru exercitiile din `private/colocvii`:
- `private/colocvii/colocviu.md` (Transport)
- `private/colocvii/alergatori.md` (Alergatori)
- `private/colocvii/animale.md` (Animale / Ecosistem)

## 1) Modelare OOP: incapsulare, clase, constructori
- Foloseste atribute non-publice (`private`) si metode publice clare.
- Pastreaza invarianti simpli (ex: energia nu devine negativa, stari valide de viata).
- Practica: `lectia01_introductiva/exercitiu1_cuburi/README.md`, `lectia01_introductiva/exercitiu2_erbivor/README.md`.

## 2) Mostenire corecta: baza + derivate
- Defineste o clasa baza (`Transport`, `Alergator`, `Animal`) si clase derivate specializate.
- Pune in baza comportamentul comun; in derivate formulele specifice.
- Practica: `lectia03_introductiva/exercitiu1_containere/README.md`, `lectia03_introductiva/exercitiu2_transport/README.md`.

## 3) Polimorfism real (virtual / override), fara `if(tip)` in logica
- Cerintele de colocviu cer metode virtuale si penalizeaza abordari cu `if(tip)` / `switch(tip)` in calcul.
- Tipul este folosit doar la construire; dupa aceea se lucreaza prin interfata bazei.
- Practica: `lectia03_introductiva/exercitiu2_transport/README.md`.

## 4) Clase abstracte si interfete (metode pur virtuale)
- Foloseste metode `virtual ... = 0` cand vrei un contract comun pentru toate derivatele.
- Exemple de contracte utile: `pret()`, `consumCombustibil()`, `amortizare()`, `pasTimp()`.
- Practica: `lectia03_introductiva/exercitiu2_transport/README.md`.

## 5) Simulare in timp discret (ordine de procesare)
- Modeleaza simularea pe pasi: fiecare entitate isi executa regulile in ordine.
- Respecta strict ordinea din enunt (important in Alergatori si Animale).
- Practica: `lectia03_introductiva/exercitiu3_alergatori/README.md`, `lectia03_introductiva/exercitiu4_ecosistem/README.md`.

## 6) Reguli conditionale de stare (regen, retragere, moarte)
- Implementeaza tranzitii de stare explicite: activ / retras / mort.
- Evita bug-uri de ordine (ex: verifici retragerea la inceputul pasului, nu la final).
- Practica: `lectia03_introductiva/exercitiu3_alergatori/README.md`, `lectia03_introductiva/exercitiu4_ecosistem/README.md`.

## 7) Colectii de obiecte si agregari globale
- Stocheaza obiecte intr-o colectie si calculeaza aggregate: maxim, suma incasari, profit, numar in viata.
- Pastreaza separata logica pe obiect de logica de raportare globala.
- Practica: `lectia01_introductiva/exercitiu3_transport/README.md`, `lectia01_introductiva/exercitiu4_festival/README.md`, `lectia03_introductiva/exercitiu2_transport/README.md`.

## 8) Matematica in C++ pentru formulele din enunt
- Lucreaza cu `double`, functii din `<cmath>` (`exp`, `sqrt`) si comparatii numerice robuste.
- Afiseaza cerintele numerice cu `fixed << setprecision(2)` unde este cerut.
- Practica: `lectia02_introductiva/Readme.md`, `lectia03_introductiva/exercitiu3_alergatori/README.md`, `lectia03_introductiva/exercitiu4_ecosistem/README.md`.

## 9) Input/output robust pentru subiecte de examen
- Parseaza corect intrari mixte (tip + string + valori numerice).
- Respecta exact formatul de output (ordine, etichete, zecimale).
- Practica: toate exercitiile din `lectia03_introductiva`.

## 10) Checklist minim pentru "nota mare" la colocviu
- Modelez cu baza + derivate, atribute private, metode virtuale.
- Nu folosesc reflexie sau `getTip()` pentru decizii de business.
- Respect ordinea exacta a simularii din enunt.
- Separ formulele pe clase, agregarea in fluxul principal.
- Verific corner cases: resurse insuficiente, energie sub prag, egalitati la maxim.
- Formatez output-ul exact ca in cerinta.

