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

class studentas
{
private:
    string vardas_, pavarde_;
    vector <double> paz_;
    double egz_;
    double galutinis_vidurkis;
public:
    ~studentas() { paz_.clear(); }
    studentas() : vardas_(""), pavarde_(""), galutinis_vidurkis(0), egz_(0) { paz_.clear(); };

    inline std::string GetVardas() const { return vardas_; }    
    inline std::string GetPavarde() const { return pavarde_; }  
    inline double GetEgzamina() const { return egz_; }
    inline double GetGalutinisVidurkis() const { return galutinis_vidurkis; }

    void  setVardas(string vardas) { vardas_ = vardas; }
    void  setPavarde(string pavarde) { pavarde_ = pavarde; }
    void setEgz(double egz) { egz_ = egz; };

    void PazReserve(int ndKiek){ paz_.reserve(ndKiek);}
    void PazPut(double pazymys) {paz_.push_back(pazymys);}
    void PazClean() {paz_.clear();}
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
    float galutBalas(std::vector<int>);
};

int sugeneruojami_sakiciai();
void failoNuskaitymas(vector <studentas>& grupe1, int& v1);
void rusiavimas2(vector <studentas>& grupe_vector, vector <studentas>& vargsiukai_vector_2, vector <double>& time_vector, char& atsakymas);
void spausdinimas(int& v1, char& atsakymas, vector <double>& laikas, vector <studentas>& sarasas, string& pav);
void spausdinimas(char& atsakymas, vector <studentas>& grupe1);
void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, vector <double>& laikas, string& pav);


#endif


