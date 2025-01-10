#include <stdio.h>
#include <stdlib.h>

void rotateby90(int row, int col, int mat[row][col])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col / 2; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[i][col - j - 1];
            mat[i][col - j - 1] = temp;
        }
    }
}

void leftshift(int row, int col, int mat[row][col])
{
    int res[row][col];
    int no_of_shifts;
    printf("Enter the number of shifts");
    scanf("%d", &no_of_shifts);

    if (no_of_shifts > col)
    {
        no_of_shifts = no_of_shifts % col;
    }

    for (int k = 0; k < no_of_shifts; k++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j > 0)
                {
                    res[i][j - 1] = mat[i][j];
                }
                else
                {
                    res[i][col - 1] = mat[i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = res[i][j];
            }
        }
    }
}

void rightshift(int row, int col, int mat[row][col])
{
    int no_of_shifts;
    printf("Enter the number of shifts");
    scanf("%d", &no_of_shifts);

    int res[row][col];
    if (no_of_shifts > col)
    {
        no_of_shifts = no_of_shifts % col;
    }
    for (int k = 0; k < no_of_shifts; k++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j < col - 1)
                {
                    res[i][j + 1] = mat[i][j];
                }
                else
                {
                    res[i][0] = mat[i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = res[i][j];
            }
        }
    }
}

void downshift(int row, int col, int mat[row][col])
{
    int no_of_shifts;
    printf("Enter the number of shifts");
    scanf("%d", &no_of_shifts);
    int res[row][col];
    if (no_of_shifts > row)
    {
        no_of_shifts = no_of_shifts % col;
    }
    for (int k = 0; k < no_of_shifts; k++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i < row - 1)
                {
                    res[i + 1][j] = mat[i][j];
                }
                else
                {
                    res[0][j] = mat[i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = res[i][j];
            }
        }
    }
}

void upshift(int row, int col, int mat[row][col])
{
    int no_of_shifts;
    printf("Enter the number of shifts");
    scanf("%d", &no_of_shifts);
    int res[row][col];
    if (no_of_shifts > row)
    {
        no_of_shifts = no_of_shifts % col;
    }
    for (int k = 0; k < no_of_shifts; k++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i > 0)
                {
                    res[i - 1][j] = mat[i][j];
                }
                else
                {
                    res[row - 1][j] = mat[i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = res[i][j];
            }
        }
    }
}

int main()
{

    int row, col;

    printf("Enter the number of rows");
    scanf("%d", &row);
    printf("Enter the number of columns");
    scanf("%d", &col);

    int input[row][col];

    printf("Enter the elements of the matrix\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }
    printf("Original matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("Enter the operation you want to perform\n");
        printf("1. Rotate by 90 degrees\n");
        printf("2. Left shift\n");
        printf("3. Right shift\n");
        printf("4. up shift\n");
        printf("5. Down shift\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            rotateby90(row, col, input);
            break;
        case 2:
            leftshift(row, col, input);
            break;
        case 3:
            rightshift(row, col, input);
            break;
        case 4:
            upshift(row, col, input);
            break;
        case 5:
            downshift(row, col, input);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }

        printf("Matrix after operation:\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d ", input[i][j]);
            }
            printf("\n");
        }

    } while (1);

    return 0;
}
