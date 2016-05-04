/*
 * main.c
 *
 *  Created on: 2016 Feb 20 22:54:54
 *  Author: DominikH
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

typedef enum
{
	NOT_ACTIVATED, ACTIVATED
} enable_flooding_t;
enable_flooding_t enable_flooding = NOT_ACTIVATED;

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
	DAVE_STATUS_t status;
	const uint32_t Button_NotPressed = 1;
	uint32_t Button1OldValue = Button_NotPressed;

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status == DAVE_STATUS_FAILURE)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U)
		{

		}
	}

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while (1U)
	{
		if (enable_flooding == ACTIVATED)
		{
			DIGITAL_IO_SetOutputHigh(&LED2);
			CAN_NODE_MO_Transmit(&CAN_NODE_0_LMO_03_Config);
		}
		else
		{
			DIGITAL_IO_SetOutputLow(&LED2);
		}

		{
			uint32_t Button1Value = DIGITAL_IO_GetInput(&Button1);

			/* react on edge */
			if ((Button1Value != Button_NotPressed)
					&& (Button1Value != Button1OldValue))

			{
				if (enable_flooding == ACTIVATED)
				{
					enable_flooding = NOT_ACTIVATED;
				}
				else
				{
					enable_flooding = ACTIVATED;
				}
			}
			Button1OldValue = Button1Value;
		}
	}
}

void CanRxInterruptHandler0(void)
{
	/* Check for Node error */
	if (CAN_NODE_GetStatus(&CAN_NODE_0) & XMC_CAN_NODE_STATUS_LAST_ERROR_CODE)
	{
		XMC_DEBUG("Something failed\n");
	}
	else if (CAN_NODE_MO_GetStatus(&CAN_NODE_0_LMO_01_Config)
			& XMC_CAN_MO_STATUS_RX_PENDING)
	{

		/* Read the received Message object and stores in Request_Node_LMO_02_Config*/
		CAN_NODE_MO_Receive(&CAN_NODE_0_LMO_01_Config);
		if (CAN_NODE_0_LMO_01_Config.mo_ptr->can_data_byte[7] == 1)
		{
			enable_flooding = ACTIVATED;
		}
		else
		{
			enable_flooding = NOT_ACTIVATED;
		}
	}
	else if (CAN_NODE_MO_GetStatus(&CAN_NODE_0_LMO_02_Config)
			& XMC_CAN_MO_STATUS_RX_PENDING)
	{
		//enable_flooding = ACTIVATED;
		/* Read the received Message object and stores in Request_Node_LMO_02_Config*/
		CAN_NODE_MO_Receive(&CAN_NODE_0_LMO_02_Config);
	}
}

