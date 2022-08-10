//POWERS OF MATRIX P61833

#include <iostream>
#include <vector>

typedef std::vector<int> sqm_row;
typedef std::vector<sqm_row> square_matrix;

/*cout for 2x2 square matrix matrices*/
std::ostream& operator<<(std::ostream& _cout, const square_matrix& mat)
{
    _cout << mat[0][0] << ' ' << mat[0][1] << std::endl;
    _cout << mat[1][0] << ' ' << mat[1][1] << std::endl;

    return _cout;
}

/*compute product of of 2x2 square matrices*/
square_matrix product(const square_matrix& mat1, const square_matrix& mat2)
{
    square_matrix ret(2, sqm_row(2));
    ret[0][0] = mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];  /**/
    ret[0][1] = mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1];  /**/

    ret[1][0] = mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];  /**/
    ret[1][1] = mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1];  /**/

    return ret;
}

square_matrix operator%(const square_matrix& mat, int mod)
{
    square_matrix ret(2, sqm_row(2));
    ret[0][0] = mat[0][0]%mod;  /**/
    ret[0][1] = mat[0][1]%mod;  /**/

    ret[1][0] = mat[1][0]%mod;  /**/
    ret[1][1] = mat[1][1]%mod;  /**/

    return ret;
}

/*compute mat to the exp modulus mod*/
square_matrix power_of_matrix(const square_matrix& mat, int exp, int mod)
{
    square_matrix ret_mat(2, sqm_row(2));

    /*return matrix identity if exp is equal to 0*/
    if (exp == 0) {ret_mat[0][0] = ret_mat[1][1]=1; ret_mat[0][1] = ret_mat[1][0]=0; }
    else 
    {
        ret_mat = power_of_matrix(mat, exp/2, mod);
        if (exp % 2 == 0)   ret_mat = product(ret_mat, ret_mat)%mod;
        else                ret_mat = product(product(ret_mat,ret_mat)%mod, mat)%mod;
    }
    return ret_mat;
}

int main()
{   
    square_matrix matrix(2, sqm_row(2));
    int user_input;
    while (std::cin >> user_input)
    {
        /*Read matrix*/
        matrix[0][0] = user_input;
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> user_input;
            switch (i)
            {
                case 0: matrix[0][1] = user_input; break;
                case 1: matrix[1][0] = user_input; break;
                case 2: matrix[1][1] = user_input; break;
            }
        }
        /*Read exponent and modulus operands*/
        int exp, mod; std::cin >> exp >> mod;

        /*Compute and print results*/
        std::cout << power_of_matrix(matrix, exp, mod);
        std::cout << "----------" << std::endl;
    }


    return EXIT_SUCCESS;
}