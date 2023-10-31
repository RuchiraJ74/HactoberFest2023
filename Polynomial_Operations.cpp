#include<iostream>
using namespace std;

const int maxsize = 100;

typedef struct
{
	float coef;
	int expo;
}polynomial_term;


class polynomial
{
	private:
	
	polynomial_term poly[maxsize];
	int total_terms;
	
	public:
	
	polynomial()
	{
		total_terms=0;
	}
	
	void read_poly();
	void display_poly();
	polynomial add_poly(polynomial B);
};

void polynomial :: read_poly()
{
	int i;
	cout << "Enter the number of polynomial : ";
	cin >> total_terms;
	
	for(i = 0; i <= total_terms; i++)
	{
		cout << "Enter exponent of " << i+1 << " term : ";
		cin >> poly[i].expo;
		
		cout << "Enter coefficient of "  <<  i+1 << " term : ";
		cin >> poly[i].coef;
	}
	
}

void polynomial :: display_poly()
{
	int i;
	for(i = 0; i <= total_terms; i++)
	{
		cout << poly[i].coef << "X^" << poly[i].expo << " + ";
	}
	cout << "\n\n";
}

polynomial polynomial :: add_poly(polynomial B)
{
	int i,j,k;
	i = j = k = 0;
	polynomial C;
	
	while(i <= total_terms && j <= B.total_terms)
	{
		if(poly[i].expo == B.poly[j].expo)
		{
			C.poly[k].coef = poly[i].coef + B.poly[j].coef;
			C.poly[k].expo = poly[i].expo;
			i++; j++; k++;
		}
		
		else if(poly[i].expo > B.poly[j].expo)
		{
			C.poly[k].coef = poly[i].coef;
			C.poly[k].expo = poly[i].expo;
			i++; k++;
		}
		
		else
		{
			C.poly[k].coef = B.poly[j].coef;
			C.poly[k].expo = B.poly[j].expo;
			j++; k++;
		}
	}
	
	while(i < total_terms)
	{
		C.poly[k].coef = poly[i].coef;
		C.poly[k].expo = poly[i].expo;
		i++; k++;
	}
	
	while(i < B.total_terms)
	{
		C.poly[k].coef = B.poly[j].coef;
		C.poly[k].expo = B.poly[j].expo;
		i++; k++;
	}
	
	C.total_terms = k - 1;
	return C;
}
int main()
{
	polynomial A,B,C1;
	A.read_poly();
	A.display_poly();
	B.read_poly();
	B.display_poly();
	C1 = A.add_poly(B);
	C1.display_poly();
	return 0;
}
