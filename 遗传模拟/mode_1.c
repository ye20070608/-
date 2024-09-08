#include"mode.h"

void mode_1(void) 
{
    int test = 0;
    int ratios[9] = { 0,0,0,0,0,0,0,0,0 };    //亲本比例存储
    int total = 0;    //亲本比例下分母
    int g_total = 0;
    int f1_total = 0;
    //每个基因型对应配子概率，分母为4[DT,Dt,dT,dt]
    int pg_ratios[9][4] = { {4,0,0,0},        //DDTT  1
                        {2,0,2,0},        //DdTT     2
                        {2,2,0,0},        //DDTt     3
                        {0,0,4,0},        //ddTT     4
                        {0,4,0,0},        //DDtt     5
                        {1,1,1,1},        //DdTt     6
                        {0,0,2,2},        //ddTt     7
                        {0,2,0,2},        //Ddtt     8
                        {0,0,0,4} };      //ddtt    9
    int g_ratios[4] = { 0,0,0,0 };   //配子概率[DT,Dt,dT,dt]
    int f1_ratios[9][2] = { {0,0},        //DDTT  1
                        {0,0},        //DdTT     2
                        {0,0},        //DDTt     3
                        {0,0},        //ddTT     4
                        {0,0},        //DDtt     5
                        {0,0},        //DdTt     6
                        {0,0},        //ddTt     7
                        {0,0},        //Ddtt     8
                        {0,0} };       //ddtt    9
    // 获取用户输入
    printf("请输入9个数字，用空格分隔，他们分别对应以下基因型间比例（不存在该基因型请输入0）：\r\n");
    printf("DDTT,DdTT,DDTt,ddTT,DDtt,DdTd,ddTt,Ddtt,ddtt\r\n");
    printf("帮你标记下数字位置\r\n");
    printf("1 2 3 4 5 6 7 8 9\r\n");
    while (test == 0)
    {
        for (int i = 0; i < 9; i++) 
        {
            test = scanf("%d", &ratios[i]);
            if (test == 0)
            {
                printf("输入数字，不要乱打啊喂\r\n");
                printf("哼，再给你次机会好了(～￣▽￣)～\r\n");
                printf("请输入9个数字，用空格分隔，他们分别对应以下基因型间比例（不存在该基因型请输入0）：\r\n");
                printf("DDTT,DdTT,DDTt,ddTT,DDtt,DdTd,ddTt,Ddtt,ddtt\r\n");
                printf("帮你标记下数字位置\r\n");
                printf("1 2 3 4 5 6 7 8 9\r\n");
                while (getchar() != '\n')
                    continue;
                total = 0;
                break;
            }
            else
                total += ratios[i];
        }
    }

    // 计算配子概率
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            g_ratios[i] += ratios[j] * pg_ratios[j][i];
        }
        g_total += g_ratios[i];//配子分母
    }

    printf("配子比例为 %d:%d:%d:%d\r\n", g_ratios[0], g_ratios[1], g_ratios[2], g_ratios[3]);

    f1_total = g_total * g_total;
    for (int i = 0; i < 9; i++)
        f1_ratios[i][1] = f1_total;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                    f1_ratios[0][0] += g_ratios[i] * g_ratios[j];
                else if (j == 1)
                    f1_ratios[2][0] += g_ratios[i] * g_ratios[j];
                else if (j == 2)
                    f1_ratios[1][0] += g_ratios[i] * g_ratios[j];
                else
                    f1_ratios[5][0] += g_ratios[i] * g_ratios[j];
            }
            else if (i == 1)
            {
                if (j == 0)
                    f1_ratios[2][0] += g_ratios[i] * g_ratios[j];
                else if (j == 1)
                    f1_ratios[4][0] += g_ratios[i] * g_ratios[j];
                else if (j == 2)
                    f1_ratios[5][0] += g_ratios[i] * g_ratios[j];
                else
                    f1_ratios[7][0] += g_ratios[i] * g_ratios[j];
            }
            else if (i == 2)
            {
                if (j == 0)
                    f1_ratios[1][0] += g_ratios[i] * g_ratios[j];
                else if (j == 1)
                    f1_ratios[5][0] += g_ratios[i] * g_ratios[j];
                else if (j == 2)
                    f1_ratios[3][0] += g_ratios[i] * g_ratios[j];
                else
                    f1_ratios[6][0] += g_ratios[i] * g_ratios[j];
            }
            else
            {
                if (j == 0)
                    f1_ratios[5][0] += g_ratios[i] * g_ratios[j];
                else if (j == 1)
                    f1_ratios[7][0] += g_ratios[i] * g_ratios[j];
                else if (j == 2)
                    f1_ratios[6][0] += g_ratios[i] * g_ratios[j];
                else
                    f1_ratios[8][0] += g_ratios[i] * g_ratios[j];
            }
        }
    }

    
    for (int i = 0; i < 9; i++) {
        simplify(&f1_ratios[i][0], &f1_ratios[i][1]);
    }

    // 输出结果
    printf("子代基因型比例为：\r\n");
    printf(" DDTT,DdTT,DDTt,ddTT,DDtt,DdTd,ddTt,Ddtt,ddtt\r\n");

    for (int i = 0; i < 9; i++) {
        printf("%2d/%d ", f1_ratios[i][0], f1_ratios[i][1]);
    }
    printf("\r\n\r\n");
}

// 最大公约数函数
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

// 约简分数函数
void simplify(int* numerator, int* denominator) {
    int common = gcd(*numerator, *denominator);
    if (common == 0)
        ;
    else
    {
        *numerator /= common;
        *denominator /= common;
    }
}