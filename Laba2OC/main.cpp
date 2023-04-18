#include <iostream>
#include <conio.h>
#include <clocale>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int num1;
	cout << "¬ведите мес€ц в формате 1 - январь, 2 - ‘евраль и т.д.: ";
	char dec1[12][20] = { "30","28","31","30","31","30","31","31","30","31","30","31"};
	
	cin >> num1;
	cout << " оличесвто дней: ";
	switch (num1)
	{
	case 1: cout << dec1[0]; break;
	case 2: cout << dec1[1]; break;
	case 3: cout << dec1[2]; break;
	case 4: cout << dec1[3]; break;
	case 5: cout << dec1[4]; break;
	case 6: cout << dec1[5]; break;
	case 7: cout << dec1[6]; break;
	case 8: cout << dec1[7]; break;
	case 9: cout << dec1[8]; break;
	case 10: cout << dec1[9]; break;
	case 11: cout << dec1[10]; break;
	case 12: cout << dec1[11]; break;
	}
	cout << "\n";

	//getch();
	return 0;
}