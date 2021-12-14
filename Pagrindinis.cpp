#include "Funkcijos.h"
#include "Studentas.h"
#include <sstream>

void failuKurimas(vector <int>& v1, int& ndKiek)
{
    string pav;
    double pazymys;
    std::stringstream out_data;
    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        pav = "Studentai " + to_string(v1.at(i)) + ".txt";
        std::ofstream isvedimas(pav);
        vector<int> skaiciai;
        studentas Eil;
        out_data << setw(20) << left << "Vardas"
            << setw(20) << left << "Pavarde";
        for (int i = 0; i < 5; i++)
            out_data << setw(20) << right << "ND" << i + 1;
        out_data << setw(20) << right << "Galutinis(vid.)" << endl;
        for (int s = 1; s < v1.at(i); s++) {
            out_data << left << setw(20) << "Vardas" + std::to_string(s) << left <<
                setw(20) << "Pavarde" + std::to_string(s);
            for (int i = 0; i < 5; i++)
                out_data << setw(20) << right << sugeneruojami_sakiciai();
            out_data << setw(20) << right << sugeneruojami_sakiciai() << endl;
            skaiciai.clear();
        }
        isvedimas << out_data.str();
        isvedimas.close();

        auto End = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = End - start;

        cout << v1.at(i) << " elementu kurimas uztruko: " << diff.count() << " s" << endl;
    }
}

void darbasSuFailu(vector <int>& v1, char& atsakymas)
{
    string failoPav;
    vector <double> time_vector;
    vector <studentas> protingi_vector;
    vector <studentas> vargsiukai_vector;
    vector <studentas> grupe_vector;
    string pavP = "Protingi";
    string pavV = "Vargsiukai";

    cout << setw(40) << left << " Atliktas darbas " << setw(23) << left << " Laikas su vektoriu "  << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        time_vector.reserve(3);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i));
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        time_vector.push_back(diff.count());


        int vieta = 40 - i;

        cout << "| " << v1.at(i) << setw(vieta) << " studentu nuskaitymas " << "| " << setw(23) << left << time_vector.at(0) << "| " << endl;
        cout << "------------------------------------------------------------------------" << endl;

        rusiavimas2(grupe_vector, vargsiukai_vector, time_vector, atsakymas);

        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 2 strategija " << "| " << setw(23) << left << time_vector.at(1) << "| " << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        //spausdinimas(v1.at(i), atsakymas, protingi, laikas, pavP);
        //spausdinimas(v1.at(i), atsakymas, vargsiukai, laikas, pavV);

        spausdinimas(v1.at(i), atsakymas, grupe_vector, time_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_vector, time_vector, pavV);

        grupe_vector.clear();
        vargsiukai_vector.clear();
        time_vector.clear();
    }
}

