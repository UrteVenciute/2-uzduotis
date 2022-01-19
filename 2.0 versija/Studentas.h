#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>    
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <list>
#include <iterator>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;
using std::vector;
using std::ifstream;
using std::cerr;
using std::getline;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::list;
using std::advance;

/// Informacija apie Zmogus class
///
/// Zmogus duomenys: vardas, pavarde
class Zmogus
{
protected:
    string vardas_;
    string pavarde_;
public:
    /// Konstruktorius
    /// 
    /// 
    Zmogus() : vardas_(""), pavarde_("") {};
    ///Destruktorius
    ///
    ///
    ~Zmogus() {};
    virtual string GetVardas() const = 0;
    virtual string GetPavarde() const = 0;
};
/// Informacija apie Studentas class
/// 
/// Studento duomenys: pazymiai, egzamino pazymys ir galutiniai ivertinimai
class studentas : public Zmogus
{
private:
    vector <double> paz_;
    double egz_;
    double galutinis_vidurkis;
public:
    /// Destruktorius
    ///
    /// 
    ~studentas() { paz_.clear(); } 
    /// Default konstruktorius
    /// 
    /// </summary>
    studentas() : egz_(0), galutinis_vidurkis(0) {}; 
    /// Kopijavimo konstruktorius
    /// 
    /// </summary>
    /// @param s studentas
    studentas(const studentas& s) 
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        paz_ = s.paz_;
        galutinis_vidurkis = s.galutinis_vidurkis;
    }
    /// Priskyrimo operatorius
    /// 
    /// </summary>
    /// @param s Studentas
    studentas& operator=(const studentas& s) 
    {
        if (&s == this) return *this;

        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        paz_ = s.paz_;
        galutinis_vidurkis = s.galutinis_vidurkis;

        return *this;
    }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    /// @return studento varda
    inline std::string GetVardas() const { return vardas_; }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    /// @return studento pavarde
    inline std::string GetPavarde() const { return pavarde_; }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    /// @return studento egzamino pazymi
    inline double GetEgzamina() const { return egz_; }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    /// @return kiek studentas turi pazymiu 
    inline int GetNdDydi() const { return paz_.size(); }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    /// @param i namu darbu numeris
    /// @return namu darbu pazymi
    inline double GetNdElementa(int i) const { return paz_.at(i); }
    /// Papildo studento duomenis
    /// 
    /// Priskiria varda 
    void  setVardas(string vardas) { vardas_ = vardas; }
    /// Papildo studento duomenis
    /// 
    /// Priskiria pavarde 
    void  setPavarde(string pavarde) { pavarde_ = pavarde; }
    /// Papildo studento duomenis
    /// 
    /// Priskiria egzamina
    void setEgz(double egz) { egz_ = egz; };
    /// Papildo studento duomenis
    /// 
    /// Nustato, kiek bus pazymiu is nd
    /// @param ndKiek namu darbu skaicius
    void PazReserve(int pazKiek) { paz_.reserve(pazKiek); }
    /// Papildo studento duomenis
    /// 
    /// Iraso namu darbu pazymi
    /// @param pazymys uz namu darbu
    void PazPut(double pazymys) { paz_.push_back(pazymys); }
    /// Istrina namu darbu pazymius
    /// 
    /// </summary>
    void PazClean() { paz_.clear(); }
    /// Papildo studento duomenis
    /// 
    /// Apskaiciuoja galutini pazymi 
    void SetGalutinis_vidurkis() {
        double sum = 0.;
        double kiekis = 0.;
        double vid = 0.;
        for (int i = 0; i < paz_.size(); i++)
        {
            sum += paz_.at(i);
            kiekis++;
        }
        vid = sum / kiekis;
        galutinis_vidurkis = 0.4 * vid + 0.6 * egz_;
    }
    /// Info gauti apie studenta
    /// 
    /// </summary>
    ///  @return grazina galutini pazymi
    inline double GetGalutinisVidurkis() const { return galutinis_vidurkis; }
    /// Papildo studento duomenis
    /// 
    /// Apskaiciuoja galutini pazymi su vidurkiu
    float galutBalas(std::vector<int>);

};

int sugeneruojami_sakiciai();
void failoNuskaitymas(vector <studentas>& grupe1, int& v1);
void rusiavimas2(vector <studentas>& grupe_vector, vector <studentas>& vargsiukai_vector_2, vector <double>& time_vector, char& atsakymas);
void spausdinimas(int& v1, char& atsakymas, vector <double>& laikas, vector <studentas>& sarasas, string& pav);
void spausdinimas(char& atsakymas, vector <studentas>& grupe1);
void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, vector <double>& laikas, string& pav);


#endif
