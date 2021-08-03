#include <stdio.h>
#include "tpl_os.h"

#include <math.h>



#include "Controller0.h"
#include "rtwtypes.h"

static RT_MODEL_Controller0_T Controller0_M_;
static RT_MODEL_Controller0_T *const Controller0_MPtr = &Controller0_M_;/* Real-time model */
static B_Controller0_T Controller0_B;  /* Observable signals */
static DW_Controller0_T Controller0_DW;/* Observable states */

/* '<Root>/echo' */
static real32_T Controller0_U_echo;

/* '<Root>/trigger' */
static real32_T Controller0_Y_trigger;

/* '<Root>/pulse' */
static real32_T Controller0_Y_pulse;

void setup()
{
        /* Pack model data into RTM */
         Controller0_MPtr->blockIO = &Controller0_B;
  Controller0_MPtr->dwork = &Controller0_DW;

        /* Initialize model */
	Controller0_initialize(Controller0_MPtr, &Controller0_U_echo, Controller0_Y_trigger, &Controller0_Y_pulse);
}

int main(void)
{
    setup();

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(alarm_10msec);

real_T BSWreadEcho( void )
{       
        static int i = 0;
	static uint8_T tmp = 0;
	static int n_activation = 0;
        
	n_activation++;
        i++;
	if( (i != 0) && (i % 6) == 0 )
	{
		tmp = !tmp;
		i = 0;
	}
	printf( "BSWreadEcho(%d): %d\r\n", n_activation, tmp );

	return( tmp );
}

void    BSWwriteTrig( real32_T x )
{
	static int n_activation = 0;

	n_activation++;

        if( x != 0 )
        {
                printf( "BSWwriteTrig(%d): 1\r\n", n_activation );
        }
        else
        {
                printf( "BSWwriteTrig(%d): 0\r\n", n_activation );
        }
}


void    BSWwriteSignal( real32_T x )
{
	static int n_activation = 0;

	n_activation++;

        if( x != 0 )
        {
                printf( "BSWwriteSignal (%d): 1\r\n", n_activation );
        }
        else
        {
                printf( "BSWwriteSignal (%d): 0\r\n", n_activation );
        }
}





TASK(my_periodic_task)
{
  printf( "---\r\n" );
  Controller0_U_echo = BSWreadEcho();
        
  Controller0_step(Controller0_MPtr, Controller0_U_echo, Controller0_Y_trigger, &Controller0_Y_pulse);

  BSWwriteTrig( Controller0_Y_trig );
  BSWwriteSignal( Controller0_Y_pulse);

  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}