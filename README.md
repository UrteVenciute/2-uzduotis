# Pirmas-projektas
* Vietoj studentas strūktūros modifikuojam ją į klasę.
* Palyginsiu realizacijos spartą 1.0 versijos kodo ir 1.1 versijos kodą, naudojant vektoriaus fiksuotą konteinerį, pačia greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus.
* Gauti rezultatai:

| laikas naudojant   | klasės        | struct       |
| -------------      | ------------- |--------------|
| nuskaitymas 100000 |               | 11.2294      |
| rusiavimas 100000  | 1.30096       | 0.135774     |
| nuskaitymas 1000000|               | 72.9566      |
| rusiavimas 1000000 |               | 1.7959       |

* Atliksiu eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3. Rezultatai:
