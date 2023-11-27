//
//  main.cpp
//

#include <iostream>

//  Question 1
//  Identify any potential issues with the implementation
//  of the function foo() below, and re-write foo() to fix those issues.

#define assert(a, m)    \
        if(!(a))        \
        {               \
            std::cerr << m << std::endl;    \
            return;     \
        }
#define assert_r(a, m)  \
        if(!(a))        \
        {               \
            std::cerr << m << std::endl;    \
            return -1;   \
        }

// Using this type of arrays gets tricky, some compilers may not complain if you
// pass a different size array, like passing A[3][5] will not complain but it
// will cause a stack overflow.
// so lets change the fucntion signature, and we can
// assert/fail if it doesnt fit the requirements for a matrix to vector product
void foo(float* A, size_t A_rows, size_t A_cols,
         float* b, size_t b_rows, float* c, size_t c_rows)
{
    // Error check inputs
    assert(A_cols == b_rows, "Matrix are not compatible A col != B row");
    assert(b_rows == c_rows, "result vector diff size");
    assert(A != nullptr,     "null ptr error"); // either assert of return err code
    assert(b != nullptr,     "null ptr error"); // either assert of return err code
    assert(c != nullptr,     "null ptr error"); // either assert of return err code
    
    // In the usage example, we can infer a requirement that
    // we need to do processing in palce so we cannot set this
    // to zero, we are going to be using that value later so we
    // will allocate a temp buffer, if performance needed we can
    // assert that c is different memory than b to force
    // user to use a different memory
    float* c_temp = new float[c_rows];  // could have been declared
                                        // as automatic to let it be free
                                        // when exiting, but we dont know
                                        // the max size, we dont want to
                                        // overflow the stack
    
    assert(c_temp != nullptr, "malloc error"); // check malloc
    
    int i, j;
    for (i = 0; i < A_rows; i++)
    {
        c_temp[i] = 0.0f;
        for (j = 0; j < A_cols; j++)
        {
            c_temp[i] += A[i*A_rows + j] * b[j];
        }
    }
    
    // Copy to result
    memcpy(c, c_temp, sizeof(float)*c_rows);
    
    // Free memory
    delete[] c_temp;
    c_temp = nullptr;
}

// Main function for context
int main()
{
    float F[6][6] =
    {
        { 69,    77,    71,    12,    75,    55  },
        { 32,    80,    75,    50,    26,    14 },
        { 95,    19,    28,    96,    51,    15 },
        {  3,    49,    68,    34,    70,    26 },
        { 44,    45,    66,    59,    89,    84 },
        { 38,    65,    16,    22,    96,    25 },
    };
    float x[6] = {1, 2, 3, 4, 5, 6};

    foo(&F[0][0], 6, 6, x, 6, x, 6);
    
    for(int i = 0; i < 6; i++)
    {
        std::cout << x[i] << ", " << std::endl;
    }
    
    float y[6] = {1189, 831, 946, 947, 1517, 934};
    
    // Compare results
    for(int i = 0; i < 6; i++)
    {
        assert_r(y[i] == x[i], "Result different from expected");
    }
    
    std::cout << "TEST PASSED" << std::endl;

    return 0;
}
