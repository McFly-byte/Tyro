#include <iostream>
using namespace std;

template<class T>
class TMatrix
{
	public:
		int row , col;
		T ** matrix;
		TMatrix() : row(0) , col(0) {};
		TMatrix( T** M, int r, int c ){
	        int i,j;
	        this->row = r , this->col = c;
	        matrix = new T*[row];
	        for( i = 0; i < row; i++ )
	            matrix[i] = new T[col];
	  
	        for( i = 0; i < row; i++ )
	          for( j = 0; j < col; j++ )
	            matrix[i][j] = M[i][j];
	    }
		~TMatrix(){
			for( int i = 0 ; i < this->row ; i++ )
				delete []matrix[i];
			delete []matrix;
		}
		bool operator==( const TMatrix & m  ){
			if( m.col != this->col || m.row != this->row ) return false;
			for( int i = 0 ; i < row ; i++ ){
				for( int j = 0 ; j < col ; j++ ){
					if( matrix[i][j] != m.matrix[i][j] ) return false;
				}
			}
			return true;
		} 
		bool operator!=( const TMatrix & m ){
			if( m == *this ) return false;
			return true;
		}
		bool canPom( const TMatrix & m ){//can plus or minus 
			if( row == m->row || col == m->col ) return true;
			return false; 
		}
		TMatrix & operator+( const TMatrix & m ){
			T M[row][col];
			for( int i = 0 ; i < row ; i++ ){
				for( int j = 0 ; j < col ; j++ ){
					M[i][j] = this->matrix[i][j] + m.matrix[i][j];
				} 
			} 
			TMatrix tmp( M , row , col );
			return tmp;
		}
		TMatrix & operator-( const TMatrix & m ){
			T M[row][col];
			for( int i = 0 ; i < row ; i++ ){
				for( int j = 0 ; j < col ; j++ ){
					M[i][j] = this->matrix[i][j] - m.matrix[i][j];
				} 
			} 
			TMatrix tmp( M , row , col );
			return tmp;
		}
		TMatrix & operator=( const TMatrix & m ){
			for( int i = 0 ; i < row ; i++ ){
				for( int j = 0 ; j < col ; j++ ){
					this->matrix[i][j] = m.matrix[i][j];
				} 
			} 
			return *this;
		}
		bool canM( const TMatrix & m ){//can multiple
			return ( col == m.row );
		}
		TMatrix & operator*( const TMatrix & m ){
			T M[row][m.col] = {0};
			for( int i = 0 ; i < row ; i++ ){
				for( int j = 0 ; j < m.col ; j++ ){
					for( int k = 0; k < col ; k++ ) 
						M[i][j] += this->matrix[i][k] * m.matrix[k][j];
				} 
			} 
			TMatrix tmp( M , row , m.col );
			return tmp;
		}
};

int main()
{
	
}
