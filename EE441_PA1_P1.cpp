
#include <iostream>
using namespace std;

template <int N>
class Matrix
{
private:
	double data[N][N];
public:
	int const SIZE = N;
	Matrix();
	void SetMatrix(int i, int j, int k);
	int GetMatrix(int i, int j);

};
// Constructor
template <int N>
Matrix<N>::Matrix() {
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N;j++) {
			if (i == j)
				data[i][j] = 1;
			else
				data[i][j] = 0;
		}
	}
}

template <int N>
int Matrix<N>::GetMatrix(int i, int j) {
	int a;
	if (i > N || j > N) //checking the indices are valid.
		cerr << "ERROR";
	else
		a = data[i][j];
	return a;
}
template <int N>
void Matrix<N>::SetMatrix(int i, int j, int k) {
	if (i > N || j > N)  //checking the indices are valid.
		cerr << "ERROR";
	else
		data[i][j] = k;
}
template <int N>
Matrix<N>* AddMatrix(Matrix<N>& M1, Matrix<N>& M2) {
	Matrix<N>* M3 = new Matrix<N>();
	if ((M1.SIZE != M2.SIZE)) {
		cerr << "ERROR";
		return M3;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				M3->SetMatrix(i, j, M1.GetMatrix(i, j) + M2.GetMatrix(i, j));
		}
		return  M3;
	}
}
template <int N>
Matrix<N>* SubMatrix(Matrix<N>& M1, Matrix<N>& M2) {
	Matrix<N>* M3 = new Matrix<N>();
	if ((M1.SIZE != M2.SIZE)) {
		cerr << "ERROR";
		return M3;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				M3->SetMatrix(i, j, M1.GetMatrix(i, j) - M2.GetMatrix(i, j));
		}
		return  M3;
	}
}
template <int N>
Matrix<N>* MultMatrix(Matrix<N>& M1, Matrix<N>& M2) {
	Matrix<N>* M3 = new Matrix<N>();
	if ((M1.SIZE != M2.SIZE)) {
		cerr << "ERROR";
		return M3;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				M3->SetMatrix(i, j, M1.GetMatrix(i, j) * M2.GetMatrix(i, j));
		}
		return  M3;
	}
}
/*
template <int N>
int determinantOfMatrix(Matrix<N>& M1)
{
	int D = 0; // Initialize result

	//  Base case : if matrix contains single element
	if (N == 1)
		return M1[0][0];

	Matrix<N>* M5 = new Matrix<N>(); // To store cofactors

	int sign = 1; // To store sign multiplier

	// Iterate for each element of first row
	for (int f = 0; f < N; f++)
	{
		// Getting Cofactor of mat[0][f]
		getCofactor(M1, M5, 0, f, N);
		D += sign * M1[0][f];
			N -= N;
			* determinantOfMatrix(M5);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}
template <int N>
void getCofactor(int mat[N][N], int temp[N][N], int p,
	int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those
			//  element which are not in given row and
			//  column
			if (row != p && col != q)
			{
				temp[i][j++] = mat[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
*/
int main() {
	Matrix<2> M2;
	Matrix<2> M1;
	for (int i = 0;i < 2;i++)
		for (int j = 0; j < 2;j++)
			M1.SetMatrix(i, j, 7);
	for (int k = 0;k < 2;k++)
		for (int l = 0; l < 2;l++)
			M2.SetMatrix(k, l, 5);
	Matrix<2> M3 = *SubMatrix(M1, M2);
	M3.GetMatrix(1, 1);

}
