
/*
* File Name: lab5ExD.cpp
* Assignment: Lab 5 D
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/
//   matrix.cpp


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
for (int i=0;i<rowsM;i++){
    this->sum_rowsM[i]=0;
    for (int k = 0 ; k <colsM;k++)
    this->sum_rowsM[i] = this->sum_rowsM[i]+this->matrixM[i][k];

}
}

void Matrix::sum_of_cols()const
{
for (int i=0;i<colsM;i++){
    this->sum_colsM[i]=0;
    for (int k = 0 ; k <rowsM;k++)
    this->sum_colsM[i] = this->sum_colsM[i]+this->matrixM[k][i];

}
    
}

void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM;
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);

    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    for (int i =0; i<rowsM;i++){
        for (int k = 0;k<colsM;k++){
            matrixM[i][k]=source.matrixM[i][k];
        }
    }
    this->sum_of_cols();
    this->sum_of_rows();
}

    

void Matrix::destroy()
{
    delete[] this->sum_rowsM;
    delete[] this->sum_colsM;
    for (int i =0 ;i < rowsM;i++)
        delete[] this->matrixM[i];
    delete[] matrixM;
}

