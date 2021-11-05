// 0.5 darbas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <list>
using namespace std;
using std::left;
using std::cout;
using std::vector;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;

struct studentas {
	string vardas, pavarde;
	vector<float> paz = { 0 };
	int egz;
	float gal = 0;
};

studentas get(list<studentas> _list, int _i) {
	std::list<studentas>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}
int sugeneruojami_sakiciai()
{
	return rand() % 10 + 1;
}

vector<int> auto_marks(int how_many_marks)
{
	vector<int> skaiciai;
	for (int i = 0; i < how_many_marks; i++)
	{
		skaiciai.push_back(sugeneruojami_sakiciai());
	}
	return skaiciai;
}

float galutBalas(vector<int> skaiciai) {
	studentas grupe;
	grupe.gal = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * sugeneruojami_sakiciai();
	return grupe.gal;
}

int main()
{
	for (size_t i = 1000; i <= 10000000; i *= 10)
	{
		int NumberOfStudents = i;
		auto start = std::chrono::high_resolution_clock::now();
		std::string pav;
		pav = "Studentai" + std::to_string(i) + ".txt";
		std::ofstream out_data(pav);
		vector<int> skaiciai;
		studentas Eil;
		out_data << setw(20) << left << "Vardas"
			<< setw(20) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(vid.)" << endl;
		for (int s = 1; s < NumberOfStudents; s++) {
			skaiciai = auto_marks(5);
			out_data << setw(20) << "Vardas" + std::to_string(s) <<
				setw(20) << "Pavarde" + std::to_string(s) <<
				setw(20) << galutBalas(skaiciai) << endl;;
			skaiciai.clear();
		}
		auto End = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = End - start;
		cout << "Failo su " + std::to_string(i) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";


		int sum = 0;
		list <studentas> grupe1;
		studentas stud;
		ifstream fileRead;
		ifstream ReadFile("Studentai" + std::to_string(i) + ".txt");
		string buff;
		fileRead.open(pav);
		if (fileRead.is_open()) {
			auto start = std::chrono::high_resolution_clock::now();
			auto st = start;
			getline(fileRead >> std::ws, buff);
			while (sum < i)
			{
				grupe1.resize(grupe1.size() + 1);
				fileRead >> stud.vardas;
				fileRead >> stud.pavarde;
				fileRead >> stud.gal;
				sum++;
				grupe1.push_back(stud);
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> diff = end - start;
			cout << "Failo su " + std::to_string(i) + " studentu nuskaitymas uztruko: " << diff.count() << " s\n";


			list<studentas> protingi;
			list<studentas>vargsiukai;
			auto start2 = std::chrono::high_resolution_clock::now();
			auto StartSorting = std::chrono::high_resolution_clock::now();
			//sort(grupe1.begin(), grupe1.end(), ([](studentas a, studentas b)
				//{
					//return a.gal < b.gal;}));
			for (int i = 0; i < grupe1.size(); i++) {
				if (get(grupe1, i).gal < 5.00)
				{
					vargsiukai.push_back(get(grupe1, i));
				}
				else
					protingi.push_back(get(grupe1, i));
			}
			auto end2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> diff2 = end2 - start2;
			auto EndSorting = std::chrono::high_resolution_clock::now();
			cout << "Studentu rusiavimas " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << endl;

		
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
