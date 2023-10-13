#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>

using namespace std;

struct Interval {
	int leviDel;
	int desniDel;
};
int counterDebug = 0;
bool intervalCompare(const Interval& a, const Interval& b) {
	if (a.leviDel != b.leviDel) { //orderamo po prvem ascending
		return a.leviDel < b.leviDel;
	}
	else {//ce imata isti start point orderamo keri ma vecji doseg
		return a.desniDel > b.desniDel;
	}
}

int main(int argc, char** argv) {

	if (argc < 2) {
		cout << "premalo argumentov" << endl;
		return 1;
	}

	ifstream input_file(argv[1]);
	if (!input_file) {
		cout << "Unable to open input file" << endl;
		return 1;
	}

	int celotnaDolzina, stPostaj;
	input_file >> celotnaDolzina >> stPostaj;

	vector<Interval> intervals(stPostaj);
	for (int i = 0; i < stPostaj; i++) {
		int inLokacija, inputRadij;
		input_file >> inLokacija >> inputRadij;
		intervals[i].leviDel = max(0, inLokacija - inputRadij); //pogledamo najbolj levo tocko (zacetek - radius)
		intervals[i].desniDel = min(celotnaDolzina, inLokacija + inputRadij);
	}

	//interval compare vrne 0 ko sta v pravilnem vrstnem redu, in 1 ko treba zamenjat
	//sort tudi ob swapu pogleda naprej ce bi se moral element se pomaknit
	sort(intervals.begin(), intervals.end(), intervalCompare);
	//mogoce bo to prepocasi

	vector<Interval> acceptedIntervals;
	acceptedIntervals.push_back(intervals[0]);


	int trenutniAccepted = 0;
	bool prviKandidat = false;

	Interval kandidat;
	int najdlje_desno = intervals[0].desniDel;

	for (int i = 1; i < stPostaj; i++) {
		if (acceptedIntervals[trenutniAccepted].desniDel > celotnaDolzina) {
			cout << "-1";
			return 0;
		}
		//preverimo če se prekrivata
		if (acceptedIntervals[trenutniAccepted].desniDel >= intervals[i].leviDel) {
			//preverimo če je ta interval daljsi od trenutnega kandidata
			if (intervals[i].desniDel > najdlje_desno) {
				//ta interval je novi kandidat, najdlje desno je še dlje
				najdlje_desno = intervals[i].desniDel;
				kandidat = intervals[i];
				prviKandidat = true;
			}
		}
		else {
			//interval pa trenutni interrval se ne prekrivata, v rešitev dodamo kandidata
			if (!prviKandidat) {
				cout << "-1";
				return 0;
			}
			acceptedIntervals.push_back(kandidat);
			trenutniAccepted++;
			i--;
			prviKandidat = false;
		}
	}


	//preverimo če zadnji interval štima
	if (!(acceptedIntervals[trenutniAccepted].desniDel >= celotnaDolzina)) {
		acceptedIntervals.push_back(kandidat);
		trenutniAccepted++;
	}
	//ce je dolzina premajhna
	if (acceptedIntervals[trenutniAccepted].desniDel < celotnaDolzina) { cout << "-1"; }

	//če je šlo vse po maslu
	else cout << stPostaj - acceptedIntervals.size();

	return 0;
}