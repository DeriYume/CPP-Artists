#include "iostream"
#include "string"

using namespace std;

class artist {
	string name, country;
	int songs, age;

	public:
		artist();
		void print();
		int get_songs() { return songs; }
		string get_country() { return country; }
		int get_age() { return age; }
};

artist::artist() {

	cout << "Name: ";
	getline(cin, name);

	cout << "Country: ";
	getline(cin, country);

	cout << "Age: ";
	cin >> age;

	cout << "# of songs: ";
	cin >> songs;

	cin.ignore();
}

void artist::print() {
	cout << name << " " << age << " " << country << " " << songs << endl;
}

void youngBulgarianArtists(int size, artist arrtist[]) {
	for (int i = 1 ; i < size ; i++) {
		if (arrtist[i].get_country() == "Bulgaria" && arrtist[i].get_age() < 20)
			arrtist[i].print();
	}
}

double averageFrenchArtistAge(int size, artist arrtist[]) {
	double sum = 0;
	int count = 0;

	for (int c = 0 ; c < size ; c++) {
		if (arrtist[c].get_country() == "France") {
			sum = arrtist[c].get_age() + sum;
			count++;
		};
	};

	return sum / count;
};

void sort(int size, artist arrtist[])
{
	for (int i = 1 ; i < size ; i++)
		for (int j = 0 ; j <= size - i - 1 ; j++)
			if (arrtist[j].get_songs() < arrtist[j + 1].get_songs())
			{
				artist temp = arrtist[j];
				arrtist[j] = arrtist[j + 1];
				arrtist[j + 1] = temp;
			}

	for (int i = 0 ; i < size ; i++) {
		arrtist[i].print();
	}
}

int main()
{
	cout << "Input data about an artist: " << endl;
	artist firstArtist;
	firstArtist.print();

	cout << "Input data about another artist: " << endl;
	artist secondArtist;

	cout << "The artist with more songs is: ";
	if (firstArtist.get_songs() > secondArtist.get_songs()) firstArtist.print();
	else secondArtist.print();

	int input;

	do {
		cout << "Input desired amount of artists: ";
		cin >> input;
	} while (input < 2 || input > 50);
	cin.ignore();

	artist* artistPointer = new artist[input];

	cout << "The average French artist age is " << averageFrenchArtistAge(input, artistPointer) << endl;

	cout << endl;
	cout << "List of artists from Bulgaria who are younger than 20: " << endl;
	youngBulgarianArtists(input, artistPointer);

	cout << endl;
	cout << "Sorting the artists by number of songs: " << endl;
	sort(input, artistPointer);

	return 0;
}
