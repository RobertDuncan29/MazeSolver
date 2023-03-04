#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	int x[5][5] = { {1, 1, 0, 1, 1},
					{1, 0, 0, 0, 1},
					{1, 0, 1, 1, 1},
					{1, 0, 0, 0, 1},
					{1, 1, 1, 0, 1} };

	// start if [2][0] (a = 0, b = 2), finish is [4][3] a = 3, b = 4

	Stack<int> y; // representing row value
	Stack<int> z; // representing column value
	int a = 0; // representing row start
	int b = 2; // representing column start
	for (int i = 0; i < 5; i++) { 
		for (int j = 0; j < 5; j++) { 
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "solved maze" << endl;
	cout << endl;
	bool solved = false;
	while (solved != true) {
		y.push(a);
		z.push(b);
		if (a == 4 && b == 3) {
			x[a][b] = 2;
			solved = true;
			for (int i = 0; i < 5; i++) { 
				for (int j = 0; j < 5; j++) { 
					cout << x[i][j] << " ";
				}
				cout << endl;
			}
		}
		else if (x[a][b + 1] == 0) { // checking one to the right/east
			x[a][b] = 2;
			b++;
		}
		else if (x[a][b - 1] == 0) { // checking one to the left/west
			x[a][b] = 2;
			b--;
		}
		else if (x[a + 1][b] == 0) { // checking one below/south
			x[a][b] = 2;
			a++;
		}
		else if (x[a - 1][b] == 0) { // checking one above/north
			x[a][b] = 2;
			a--;
		}
		else { // no open coordinates for maze to follow, must backtrack
			if (!y.isEmpty()) {
				x[a][b] = 3; // using three to denote where we have been
				// time to back track
				y.pop();
				z.pop();
				a = y.peek();
				b = z.peek();
			}
			else {
				solved = true;
				for (int i = 0; i < 5; i++) { 
					for (int j = 0; j < 5; j++) { 
						cout << x[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}