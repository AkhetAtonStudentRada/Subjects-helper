#include <iostream>
#include <vector>

using namespace std;

class Point
{
	friend istream& operator >> (istream& in, Point& a)
	{
		in >> a.x >> a.y;
		return in;
	}
	friend ostream& operator << (ostream& out, Point& a)
	{
		out << "(" << a.x << "; " << a.y << ")";
		return out;
	}
public:
	int x;
	int y;
};

const double EPS = 1E-9;

inline int det(int a, int b, int c, int d) {
	return a * d - b * c;
}

inline bool between(int a, int b, double c) {
	return min(a, b) <= c + EPS && c <= max(a, b) + EPS;
}

inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(Point a, Point b, Point c, Point d) {
	if (b.x == c.x && b.y == c.y)
		return false;
	int A1 = a.y - b.y, B1 = b.x - a.x, C1 = -A1 * a.x - B1 * a.y;
	int A2 = c.y - d.y, B2 = d.x - c.x, C2 = -A2 * c.x - B2 * c.y;
	int zn = det(A1, B1, A2, B2);
	if (zn != 0) {
		double x = -det(C1, B1, C2, B2) * 1.0 / zn;
		double y = -det(A1, C1, A2, C2) * 1.0 / zn;
		return between(a.x, b.x, x) && between(a.y, b.y, y)&& between(c.x, d.x, x) && between(c.y, d.y, y);
	}
	else
		return det(A1, C1, A2, C2) == 0 && det(B1, C1, B2, C2) == 0 && intersect_1(a.x, b.x, c.x, d.x) && intersect_1(a.y, b.y, c.y, d.y);
}

class cut
{
	friend ostream& operator << (ostream& out, cut& a)
	{
		out << a.start<<" "<< a.end;
		return out;
	}
public:
	Point start;
	Point end;
	cut(Point start, Point end)
	{
		this->start = start;
		this->end = end;
	}
};

bool intersectionCuts(cut* a, cut* b)
{
	return intersect(a->start, a->end, b->start, b->end);
}

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	int N;
	cout << "”ведiть кiлькiсть пар N: ";
	cin >> N;
	vector <Point> points;
	vector<cut> cuts;
	points.resize(N);
	for (int i = 0; i < N; i++)
	{
		cout << "”ведiть "<< i+1<<" пару(x, y): ";
		cin >> points[i];
		if (i > 0)
		{
			cuts.push_back(cut(points[i - 1], points[i]));
			if (cuts.size() > 2)
			{
				int k = cuts.size();
				for (int j = 0; j < k-1; j++)
				{
					if(intersectionCuts(&cuts[j],&cuts[k-1]))
						cout << "\nѕеретин!\n" << cuts[k-1] <<"       "<< cuts[j]<<endl<<endl;
				}
			}
		}
	}
	
	return 0;
}