# Pirmas-projektas
* Vietoj studentas strūktūros modifikuojam ją į klasę.
* Palyginsiu realizacijos spartą 1.0 versijos kodo ir 1.1 versijos kodą, naudojant vektoriaus fiksuotą konteinerį, pačia greičiausią dalijimo strategiją ir 1000000 ir 10000000 dydžio failus.
* Gauti rezultatai:

| laikas naudojant    | struct        | class        |
| -------------       | ------------- |--------------|
| nuskaitymas 1000000 | 5.0839        | 4.697321     |
| rusiavimas 1000000  | 0.549153      | 0.848525     |
| nuskaitymas 10000000| 55.2592       | 79.0615      |
| rusiavimas 10000000 | 6.986948      | 10.7959      |

![2021-12-16 (7)](https://user-images.githubusercontent.com/90273563/146445333-f048bbbf-db54-48f0-80b5-ec9c30b1f9a1.png)

* Atliksiu eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3. Rezultatai:

| FLAG  | 1000       | 10000    | 100000   | 1000000  |10000000|   
| O1    | 0,275056   | 0.228769 | 1.85613  | 8.47258  | 59.2835|
| O2    | 0.029916   | 0.164836 | 0.685419 | 5.63854  |        |
