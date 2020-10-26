#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[])
{
    /*1*/
    setlocale(LC_ALL, "");
    GRand *gamerand;
    gchar gamename[10];
    /*2*/
    g_print("您叫什么名字？\n");
    scanf("%s", &gamename);
    g_print("欢迎您，%s,这里是21点游戏\n", gamename);
    setbuf(stdin, NULL);
    /*3*/
    // g_print("%s,请按键抽取数字！\n",gamename);
    // getchar();
    // getchar();
    gint key = 0;
    gint rndnumber;
    gint man_number, comp_number;
    gint man_count = 0, comp_count = 0;
    gboolean man_end = FALSE, comp_end = FALSE;
    gboolean gameover = FALSE;
    gamerand = g_rand_new();
    /*4*/
    do
    {
        //玩家抽数字
        if (!man_end)
        {
            g_print("%s,按y/Y键抽数字,按其它键表示不再抽数字!\n", gamename);
            key = getchar();
            getchar();

            if (key == 'y' || key == 'Y')
            {
                rndnumber = g_rand_int_range(gamerand, 1, 11);
                man_number = rndnumber;
                man_count += man_number;
                g_print("%s,您抽到的是:%d\n", gamename, man_number);
            }
            else
            {
                g_print("玩家放弃抽数字!\n", comp_number);
                man_end = TRUE;
            }
        }
        //电脑抽数字
        if (comp_count <= 17)
        {
            rndnumber = g_rand_int_range(gamerand, 1, 11);
            comp_number = rndnumber;
            comp_count += comp_number;
            g_print("电脑抽到的是：%d\n", comp_number);
        }
        else
        {
            g_print("电脑放弃抽数！\n", comp_number);
            comp_end = TRUE;
        }
        /* 5 */
        if ((man_count > 21 && comp_count > 21) || (man_count <= 21 && comp_count <= 21 && man_count == comp_count && man_end && comp_end))
        {
            g_print("平手，电脑%d点，%s%d点\n", comp_count, gamename, man_count);
            gameover = TRUE;
        }
        else if ((man_count > 21 && comp_count <= 21) || (man_count < 21 && comp_count == 21))
        {
            g_print("电脑赢了,电脑%d点，%s%d\n", comp_count, gamename, man_count);
            gameover = TRUE;
        }
        else if ((man_count < 21 && comp_count >= 21) || (man_count == 21 && comp_count < 21))
        {
            g_print("玩家赢了,电脑%d点，%s%d\n", comp_count, gamename, man_count);
            gameover = TRUE;
        }
        else if (man_end && comp_end)
        {
            man_count > comp_count ? g_print("玩家赢了,电脑%d点，%s%d\n", comp_count, gamename, man_count) : g_print("电脑赢了,电脑%d点，%s%d\n", comp_count, gamename, man_count);
            gameover = TRUE;
        }
    } while (!gameover);
    rndnumber = g_rand_int_range(gamerand, 1, 11);
    g_print("%s,您抽到的是：%d\n", gamename, rndnumber);
    g_rand_free(gamerand);
    return 0;
}