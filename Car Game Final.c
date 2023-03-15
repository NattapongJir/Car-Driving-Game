#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define ROW 20
#define COL 18

void get_menu();    // menu
void goto_game();   // รันเกมส์
void move_carR();   // ขยับรถขวา
void move_carL();   // ขยับรถซ๊าย
void print_track(); // พิมพ์สนาม(อาเรย์)
void remove_o();    //ลบ O

void move_race0(); // พิมพ์รถอุปสรรคเลน0ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_race1(); // พิมพ์รถอุปสรรคเลน1ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_race2(); // พิมพ์รถอุปสรรคเลน2ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_race3(); // พิมพ์รถอุปสรรคเลน3ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_race4(); // พิมพ์รถอุปสรรคเลน4ในอาเรย์(ขยับลงมาทีล่ะ+1)

void move_coin0(); // พิมพ์เหรียญ0ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_coin1(); // พิมพ์เหรียญ0ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_coin2(); // พิมพ์เหรียญ0ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_coin3(); // พิมพ์เหรียญ0ในอาเรย์(ขยับลงมาทีล่ะ+1)
void move_coin4(); // พิมพ์เหรียญ0ในอาเรย์(ขยับลงมาทีล่ะ+1)

void car_crash();             // เช็ครถชน
void set_track();             // เซ็ทสนามก่อนเริ่มใหม่
int or (int c, int s);        // ถามเล่นต่อไหม
int oil_zero(int c, int s);   // กรณีรถไม่ชนแต่เกมส์หยุดเพราะน้ำมันหมด
int conclusion(int c, int s); // show score

int r, c, pass, pass_coin;
int row, row_coin;
int pick_side = 0, position = 2, count = 50, S = 0;
bool collision;
int coin_side = 1;
int coin = 5;

char track[ROW][COL] = {
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|               |",
    "|      O O      |",
    "|               |",
    "|      O O      |",
    "|               |",
};

int main()
{
    get_menu();
}

void get_menu()
{
    int selection = 0;
    printf("	      ###               ######                  ######           ####          ####               ###\n");
    printf("            #######             ######                  ######           ####          ####             #######\n");
    printf("          ##       ##           ######                  ##      ##       ####          ####           ##       ##\n");
    printf("         ##         ##          ######                  ##        ##     ####          ####          ##         ##\n");
    printf("        ##           ##         ######                  ##          ##   ####          ####         ##           ##\n");
    printf("       ##             ##        ######                  ##        ##     ##################        ##             ##\n");
    printf("      ##  ### ### ###  ##       ######                  ##      ##       ##################       ##  ### ### ###  ##\n");
    printf("     ##                 ##      ######                  ######           ####          ####      ##                 ##\n");
    printf("    ##                   ##     ######                  ######           ####          ####     ##                   ##\n");
    printf("   ##                     ##    ###############         ######           ####          ####    ##                     ##\n");
    printf("  ##                       ##   ###############         ######           ####          ####   ##                       ##\n");
    printf("\n\n");
    printf("\t\t   ####      ######           ##########   ##########    ####\n");
    printf("\t\t   ####      ######           ##########   ##########    #### ##\n");
    printf("\t\t ##          ##      ##       ####         ####          ##     ##\n");
    printf("\t\t##           ##        ##     ####         ####          ##      ##\n");
    printf("\t\t ##          ##          ##   ##########   ##########    ##       ##\n");
    printf("\t\t   ####      ##        ##     ##########   ##########    ##       ##\n");
    printf("\t\t       ##    ##      ##       ####         ####          ##       ##\n");
    printf("\t\t        ##   ######           ####         ####          ##      ##\n");
    printf("\t\t       ##    ######           ####         ####          ##     ##\n");
    printf("\t\t   ####      ######           ##########   ##########    #### ##\n");
    printf("\t\t   ####      ######           ##########   ##########    #####\n");
    printf("\n\n");
    printf("How to play : ");
    printf("\n\t1) Avoid the crash.");
    printf("\n\t2) Pick up a coin to refill fuel or buy life.");
    printf("\n\t3) Are you Ready for Challenge?\n\n");
    printf("Control :\n\t  1. A : Move left\n\t  2. D : Move right\n\t  3. R : Buy fuel (50 coin) \n\n");
    do
    {
        printf("=================================================");
        printf("\n\tWHAT WOULD YOU LIKE TO DO?");
        printf("\n=================================================\n\n");
        printf("\t1.  START \n\n");
        printf("\t2.  EXIT\n\n");
        printf("ENTER YOUR CHOICE (Press 1 or 2 and press ENTER)\n\n");
        printf("------->> ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            printf("\nGAME START! \n");
            goto_game();
            break;
        case 2:
            printf("\nTHANK YOU FOR PLAYING\n");
            break;
        default:
            printf("\nError\n\n");
            printf("\n**Please re-enter your selection.**\n\n");
        }
    } while (selection != 1 && selection != 2);
}

void goto_game()
{

    char ch;
    pass = 0;
    pass_coin = 1;
    collision = false;

    system("cls");
    Sleep(250);
    print_track();

    while (count > 8)
    {
        if (collision == true)
            break;

        remove_o(); // ลบ O * ที่ผ่านรถไป

        if (pass == 0) // สุมเลขให้รถอุปสรรค
        {
            srand(time(NULL));
            pick_side = rand() % 5;
            row = 0;
        }
        if (pass_coin == 0) // สุ่มเลขให้เหรียญ
        {
            srand(time(NULL));
            coin_side = rand() % 5;
            row_coin = 0;
        }
        // ถ้าล้อหน้ารถไม่เป็นช่องว่างให้ไปเช็คฟังก์ชันชน
        if (track[ROW - 6][1] != ' ' && track[ROW - 6][3] != ' ')
            car_crash();
        else if (track[ROW - 6][4] != ' ' && track[ROW - 6][6] != ' ')
            car_crash();
        else if (track[ROW - 6][7] != ' ' && track[ROW - 6][9] != ' ')
            car_crash();
        else if (track[ROW - 6][10] != ' ' && track[ROW - 6][12] != ' ')
            car_crash();
        else if (track[ROW - 6][13] != ' ' && track[ROW - 6][15] != ' ')
            car_crash();
        // ถ้าสุ่มเลขอุปสรรคได้ตรงไหนให้ใช้ฟังกันพิมพ์อุปสรรคตรงนั้น
        if (pick_side == 0)
        {
            move_race0();
        }
        else if (pick_side == 1)
        {
            move_race1();
        }
        else if (pick_side == 2)
        {
            move_race2();
        }
        else if (pick_side == 3)
        {
            move_race3();
        }
        else if (pick_side == 4)
        {
            move_race4();
        }
        // ถ้าสุ่มเลขให้เหรียญอยู่ตรงไหนให้พิมพ์เหรียญตรงนั้น
        if (coin_side == 0 && coin_side != pick_side)
        {
            move_coin0();
        }
        else if (coin_side == 1 && coin_side != pick_side)
        {
            move_coin1();
        }
        else if (coin_side == 2 && coin_side != pick_side)
        {
            move_coin2();
        }
        else if (coin_side == 3 && coin_side != pick_side)
        {
            move_coin3();
        }
        else if (coin_side == 4 && coin_side != pick_side)
        {
            move_coin4();
        }
        // ถ้าระหว่างล้อกลางเจอ*ให้+ค่าcoin(ชนแน่ๆเพราะ*จะมูฟลงมาเสมอ)
        if (track[15][2] == '*' && track[ROW - 5][1] == 'O' && track[ROW - 5][3] == 'O')
            coin++;
        else if (track[15][5] == '*' && track[ROW - 5][4] == 'O' && track[ROW - 5][6] == 'O')
            coin++;
        else if (track[15][8] == '*' && track[ROW - 5][7] == 'O' && track[ROW - 5][9] == 'O')
            coin++;
        else if (track[15][11] == '*' && track[ROW - 5][10] == 'O' && track[ROW - 5][12] == 'O')
            coin++;
        else if (track[15][14] == '*' && track[ROW - 5][13] == 'O' && track[ROW - 5][15] == 'O')
            coin++;

        // ถ้าในตำแหน่งนั้นๆ ตัวรถที่เราคุมหายไปให้การชนเป็นจริง(เพราะถ้าชนจากด้านข้างตำแหน่งตัวรถที่เราคุมจะเปลี่ยน)
        if (position == 0 && (track[15][1] != 'O' || track[15][3] != 'O' || track[17][1] != 'O' || track[17][3] != 'O'))
            collision = true;
        else if (position == 1 && (track[15][4] != 'O' || track[15][4] != 'O' || track[17][6] != 'O' || track[17][6] != 'O'))
            collision = true;
        else if (position == 2 && (track[15][7] != 'O' || track[15][7] != 'O' || track[17][9] != 'O' || track[17][9] != 'O'))
            collision = true;
        else if (position == 3 && (track[15][10] != 'O' || track[15][10] != 'O' || track[17][12] != 'O' || track[17][12] != 'O'))
            collision = true;
        else if (position == 4 && (track[15][13] != 'O' || track[15][13] != 'O' || track[17][15] != 'O' || track[17][15] != 'O'))
            collision = true;

        // ถ้ามีการกดแป้น
        if (kbhit())
        {
            switch (ch = getch())
            {
            case 'd': // ขยับขวา
            {
                if (position == 0)
                {
                    move_carR();

                    position = 1;
                    break;
                }
                else if (position == 1)
                {
                    move_carR();

                    position = 2;
                    break;
                }
                else if (position == 2)
                {
                    move_carR();

                    position = 3;
                    break;
                }
                else if (position == 3)
                {
                    move_carR();

                    position = 4;
                    break;
                }
                else
                    break;
            }
            case 'D': // ขยับขวา
            {
                if (position == 0)
                {
                    move_carR();

                    position = 1;
                    break;
                }
                else if (position == 1)
                {
                    move_carR();

                    position = 2;
                    break;
                }
                else if (position == 2)
                {
                    move_carR();

                    position = 3;
                    break;
                }
                else if (position == 3)
                {
                    move_carR();

                    position = 4;
                    break;
                }
                else
                    break;
            }
            case 'a': // ขยับซ๊าย
            {
                if (position == 4)
                {
                    move_carL();

                    position = 3;
                    break;
                }
                else if (position == 3)
                {
                    move_carL();

                    position = 2;
                    break;
                }
                else if (position == 2)
                {
                    move_carL();

                    position = 1;
                    break;
                }
                else if (position == 1)
                {
                    move_carL();

                    position = 0;
                    break;
                }
                else
                    break;
            }
            case 'A': // ขยับซ๊าย
            {
                if (position == 4)
                {
                    move_carL();

                    position = 3;
                    break;
                }
                else if (position == 3)
                {
                    move_carL();

                    position = 2;
                    break;
                }
                else if (position == 2)
                {
                    move_carL();

                    position = 1;
                    break;
                }
                else if (position == 1)
                {
                    move_carL();

                    position = 0;
                    break;
                }
                else
                    break;
            }
            case 'R':
            {
                if (coin >= 5)
                {
                    coin = coin - 5;
                    count = count + 50;
                    break;
                }
                else
                    break;
            }
            case 'r':
            {
                if (coin >= 5)
                {
                    coin = coin - 5;
                    count = count + 50;
                    break;
                }
                else
                    break;
            }

            default:;
            }
        }
        system("cls"); // เคลียก่อนพิมพ์อาเรย์ใหม่ที่บวกค่าแล้ว
        print_track();
        S++;     // เพิ่มระยะทาง
        count--; // ลด%น้ำมัน(น้ำมันคือcount/10)
    }
    Sleep(500);
    system("cls");
    if (count == 8)
        oil_zero(coin * 10, S);
    else
        or (coin * 10, S);
}
void print_track()
{
    for (r = 0; r < ROW; r++)
    {
        printf(" %s\n", track[r]);
    }
    // printf("\nPass = %d pickside = %d\nPass coin = %d coinside = %d Count = %d ",pass,pick_side,pass_coin,coin_side,count);
    printf("\nFuel = %d%% Distance = %d m.\nMy Coin = %d\n", count / 10, S, coin * 20);
}

void move_carR()
{

    for (r = 17; r > 14; r--)
    {
        for (c = 15; c > 0; c--)
        {
            if (track[r][c] == 'O')
            {
                track[r][c + 3] = 'O';
                track[r][c] = ' ';
            }
        }
    }
}

void move_carL()
{
    for (r = 15; r < 18; r++)
    {
        for (c = 1; c < 16; c++)
        {
            if (track[r][c] == 'O')
            {
                track[r][c - 3] = 'O';
                track[r][c] = ' ';
            }
        }
    }
}

void move_race0()
{

    track[row + 1][1] = ' ';
    track[row + 1][3] = ' ';

    track[row + 2][2] = ' ';

    track[row + 3][1] = ' ';
    track[row + 3][3] = ' ';

    row++;

    track[row + 1][1] = 'o';
    track[row + 1][3] = 'o';

    track[row + 2][2] = 'o';

    track[row + 3][1] = 'o';
    track[row + 3][3] = 'o';

    pass++;
    if (pass == 18)
    {
        pass = 0;
    }
    Sleep(200);
}
void move_race1()
{

    track[row + 1][4] = ' ';
    track[row + 1][6] = ' ';

    track[row + 2][5] = ' ';

    track[row + 3][4] = ' ';
    track[row + 3][6] = ' ';

    row++;

    track[row + 1][4] = 'o';
    track[row + 1][6] = 'o';

    track[row + 2][5] = 'o';

    track[row + 3][4] = 'o';
    track[row + 3][6] = 'o';

    pass++;
    if (pass == 18)
    {
        pass = 0;
    }
    Sleep(200);
}

void move_race2()
{

    track[row + 1][7] = ' ';
    track[row + 1][9] = ' ';

    track[row + 2][8] = ' ';

    track[row + 3][7] = ' ';
    track[row + 3][9] = ' ';

    row++;

    track[row + 1][7] = 'o';
    track[row + 1][9] = 'o';

    track[row + 2][8] = 'o';

    track[row + 3][7] = 'o';
    track[row + 3][9] = 'o';

    pass++;
    if (pass == 18)
    {
        pass = 0;
    }
    Sleep(200);
}
void move_race3()
{

    track[row + 1][10] = ' ';
    track[row + 1][12] = ' ';

    track[row + 2][11] = ' ';

    track[row + 3][10] = ' ';
    track[row + 3][12] = ' ';

    row++;

    track[row + 1][10] = 'o';
    track[row + 1][12] = 'o';

    track[row + 2][11] = 'o';

    track[row + 3][10] = 'o';
    track[row + 3][12] = 'o';

    pass++;
    if (pass == 18)
    {
        pass = 0;
    }
    Sleep(200);
}
void move_race4()
{

    track[row + 1][13] = ' ';
    track[row + 1][15] = ' ';

    track[row + 2][14] = ' ';

    track[row + 3][13] = ' ';
    track[row + 3][15] = ' ';

    row++;

    track[row + 1][13] = 'o';
    track[row + 1][15] = 'o';

    track[row + 2][14] = 'o';

    track[row + 3][13] = 'o';
    track[row + 3][15] = 'o';

    pass++;
    if (pass == 18)
    {
        pass = 0;
    }
    Sleep(200);
}

void remove_o()
{
    track[ROW - 2][1] = ' ';
    track[ROW - 2][2] = ' ';
    track[ROW - 2][3] = ' ';
    track[ROW - 2][4] = ' ';
    track[ROW - 2][5] = ' ';
    track[ROW - 2][6] = ' ';
    track[ROW - 2][7] = ' ';
    track[ROW - 2][8] = ' ';
    track[ROW - 2][9] = ' ';
    track[ROW - 2][10] = ' ';
    track[ROW - 2][11] = ' ';
    track[ROW - 2][12] = ' ';
    track[ROW - 2][13] = ' ';
    track[ROW - 2][14] = ' ';
    track[ROW - 2][15] = ' ';
}

void car_crash()
{

    if (track[ROW - 6][1] == 'o' && track[ROW - 6][3] == 'o')
    {
        if (track[ROW - 5][1] == 'O' & track[ROW - 5][3] == 'O')
            collision = true;
    }

    if (track[ROW - 6][4] == 'o' && track[ROW - 6][6] == 'o')
    {
        if (track[ROW - 5][4] == 'O' && track[ROW - 5][6] == 'O')
            collision = true;
    }
    if (track[ROW - 6][7] == 'o' && track[ROW - 6][9] == 'o')
    {
        if (track[ROW - 5][7] == 'O' && track[ROW - 5][9] == 'O')
            collision = true;
    }

    if (track[ROW - 6][10] == 'o' && track[ROW - 6][12] == 'o')
    {
        if (track[ROW - 5][10] == 'O' && track[ROW - 5][12] == 'O')
            collision = true;
    }

    if (track[ROW - 6][13] == 'o' && track[ROW - 6][15] == 'o')
    {
        if (track[ROW - 5][13] == 'O' && track[ROW - 5][15] == 'O')
            collision = true;
    }
}

void move_coin0()
{

    track[row_coin + 2][2] = ' ';
    row_coin++;
    track[row_coin + 2][2] = '*';

    pass_coin++;
    if (pass_coin == 18)
    {
        pass_coin = 0;
    }
}

void move_coin1()
{

    track[row_coin + 2][5] = ' ';
    row_coin++;
    track[row_coin + 2][5] = '*';

    pass_coin++;
    if (pass_coin == 18)
    {
        pass_coin = 0;
    }
}

void move_coin2()
{

    track[row_coin + 2][8] = ' ';
    row_coin++;
    track[row_coin + 2][8] = '*';

    pass_coin++;
    if (pass_coin == 18)
    {
        pass_coin = 0;
    }
}

void move_coin3()
{

    track[row_coin + 2][11] = ' ';
    row_coin++;
    track[row_coin + 2][11] = '*';

    pass_coin++;
    if (pass_coin == 18)
    {
        pass_coin = 0;
    }
}

void move_coin4()
{

    track[row_coin + 2][14] = ' ';
    row_coin++;
    track[row_coin + 2][14] = '*';

    pass_coin++;
    if (pass_coin == 18)
    {
        pass_coin = 0;
    }
}
int or (int c, int s)
{
    char re;
    printf("*                                                                            *\n*                                                                            *\n*                               .                                            *\n");
    printf("*           //=========\\\\        ..  .   //==========\\\\                      *\n");
    printf("*          //        x  \\\\        . .   //         o  \\\\                     *\n");
    printf("*      /--***-------------***----|../--***--------------***-------\\          *\n");
    printf("*     |--*****-----------*****--|..|--*****------------*****-------\\         *\n");
    printf("*       --***-------------***----|.. --***--------------***--------          *\n");
    printf("*----------------------------------------------------------------------------*\n*                                                                            *\n");
    printf("*                             CAR CRASHED !!!                                *\n*                                                                            *\n");
    printf("*                             Distance : %-5d m.                            *\n*                                                                            *\n", s);
    printf("*                  Coins : %-4d              Use 50 coins to Revive          *\n*                                                                            *\n", c);

    if (c >= 50)
    {
        do
        {
            printf("                      Do you want to revive? (y/n) : ");
            scanf("%s", &re);
        } while (re != 'y' && re != 'Y' && re != 'n' && re != 'N');
        if (re == 'y' || re == 'Y')
        {
            coin = coin - 5;
            set_track();
            goto_game();
        }
        else if (re == 'n' || re == 'N')
            conclusion(c, s);
    }

    else
    {
        do
        {
            printf("                  Do not have enough coins (Input "
                   "k"
                   ") : ");
            scanf("%s", &re);
        } while (re != 'k' && re != 'K');
        if (re == 'k' || re == 'K')
            conclusion(c, s);
    }
}

int oil_zero(int c, int s)
{
    char re;
    printf("*                                                                            *\n*                                                                            *\n*                               .                                            *\n");
    printf("*           //=========\\\\        ..  .   //==========\\\\                      *\n");
    printf("*          //        x  \\\\        . .   //         o  \\\\                     *\n");
    printf("*      /--***-------------***----|../--***--------------***-------\\          *\n");
    printf("*     |--*****-----------*****--|..|--*****------------*****-------\\         *\n");
    printf("*       --***-------------***----|.. --***--------------***--------          *\n");
    printf("*                             Distance : %-5d m.                            *\n*                                                                            *\n", s);
    printf("*                  Coins : %-4d              Use 50 coins to Revive          *\n*                                                                            *\n", c);

    if (c >= 50)
    {
        do
        {
            printf("                      Do you want to revive? (y/n) : ");
            scanf("%s", &re);
        } while (re != 'y' && re != 'Y' && re != 'n' && re != 'N');
        if (re == 'y' || re == 'Y')
        {
            count = count + 50;
            coin = coin - 5;
            set_track();
            goto_game();
        }
        else if (re == 'n' || re == 'N')
            conclusion(c, s);
    }

    else
    {
        do
        {
            printf("                  Do not have enough coins (Input "
                   "k"
                   ") : ");
            scanf("%s", &re);
        } while (re != 'k' && re != 'K');
        if (re == 'k' || re == 'K')
            conclusion(c, s);
    }
}
int conclusion(int c, int s)
{
    system("cls");
    char re;
    printf("*                                                                            *\n");
    printf("*                                                                            *\n");
    printf("*                              Your Distance : %-5d m.                      *\n", s); // s
    printf("*                                                                            *\n");
    printf("*                     Your Coins : %-4d   equal : +%-4d score                *\n", c, c / 5);
    printf("*                                                                            *\n");
    printf("*                             TOTAL SCORE : %-3d                              *\n", s + (c / 5));
    printf("*                                                                            *\n");
    do
    {
        printf("                    Do you want to play again? (y/n) : ");
        scanf("%s", &re);
    } while (re != 'y' && re != 'Y' && re != 'n' && re != 'N');
    if (re == 'y' || re == 'Y')
    {
        coin = 0;
        set_track();
        pick_side = 0;
        position = 2;
        count = 1000;
        S = 0;

        coin_side = 1;
        goto_game();
    }
    else if (re == 'n' || re == 'N')
    {
        printf("\nTHANK YOU FOR PLAYING\n");
    }
}
void set_track()
{
    position = 2;
    strcpy(track[0], "|               |");
    strcpy(track[1], "|               |");
    strcpy(track[2], "|               |");
    strcpy(track[3], "|               |");
    strcpy(track[4], "|               |");
    strcpy(track[5], "|               |");
    strcpy(track[6], "|               |");
    strcpy(track[7], "|               |");
    strcpy(track[8], "|               |");
    strcpy(track[9], "|               |");
    strcpy(track[10], "|               |");
    strcpy(track[11], "|               |");
    strcpy(track[12], "|               |");
    strcpy(track[13], "|               |");
    strcpy(track[14], "|               |");
    strcpy(track[15], "|      O O      |");
    strcpy(track[16], "|               |");
    strcpy(track[17], "|      O O      |");
    strcpy(track[18], "|               |");
}
