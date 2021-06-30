/*
 * EXIT_Configure.h
 *
 *  Created on: Sep 14, 2020
 *      Author: Omar Fahmy
 */

#ifndef EXIT_CONFIGURE_H_
#define EXIT_CONFIGURE_H_

/*****************************************************************************/
/*         OPTIONS FOR EXTERNAL INTERRUPT 0 INITIAL SENSE CONTROL:		     */
/*          LOGIC_CHANGE - RISING_EDGE - FALLING_EDGE - LOW_LEVEL	         */
/*****************************************************************************/
#define EXIT0_SENSE_CONTROL 	RISING_EDGE
/*****************************************************************************/

/*****************************************************************************/
/*         OPTIONS FOR EXTERNAL INTERRUPT 1 INITIAL SENSE CONTROL:		     */
/*          LOGIC_CHANGE - RISING_EDGE - FALLING_EDGE - LOW_LEVEL	         */
/*****************************************************************************/
#define EXIT1_SENSE_CONTROL		RISING_EDGE
/*****************************************************************************/

/*****************************************************************************/
/*         OPTIONS FOR EXTERNAL INTERRUPT 2 INITIAL SENSE CONTROL:		     */
/*          			 RISING_EDGE - FALLING_EDGE					         */
/*****************************************************************************/
#define EXIT2_SENSE_CONTROL		FALLING_EDGE
/*****************************************************************************/


#endif /* EXIT_CONFIGURE_H_ */
