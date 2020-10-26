#include <glib-2.0/glib.h>
//#include <gtk.h>

int main(int agrc,char *argv)
{
	GRand *rand;
	GTimer *timer;
	gint n,i,j,x=0;
	rand = g_rand_new();
	for(n=0;n<20;n++)
	{
		g_print("%d\t",g_rand_int_range(rand,1,100));
	}
	g_print("\n");
	g_rand_free(rand);
	timer=g_timer_new();
	g_timer_start(timer);
	for(i=0;i<10000;i++)
		for(j=0;j<3000;j++)
			x++;
	g_timer_stop(timer);
	g_print("%ld\tall:%.2f seconds was used!\n",x,g_timer_elapsed(timer,NULL));
}
