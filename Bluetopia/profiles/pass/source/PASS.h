/*****< pass.h >***************************************************************/
/*      Copyright 2011 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  PASS - Bluetooth Stack Phone Alert Status Service (GATT based) Type       */
/*         Definitions, Prototypes, and Constants.                            */
/*                                                                            */
/*  Author:  Tim Cook                                                         */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   09/22/11  T. Cook        Initial creation.                               */
/******************************************************************************/
#ifndef __PASSH__
#define __PASSH__

#include "BTTypes.h"            /* Bluetooth Type Definitions/Constants.      */

   /* The following function is responsible for making sure that the    */
   /* Bluetooth Stack PASS Module is Initialized correctly.  This       */
   /* function *MUST* be called before ANY other Bluetooth Stack PASS   */
   /* function can be called.  This function returns non-zero if the    */
   /* Module was initialized correctly, or a zero value if there was an */
   /* error.                                                            */
   /* * NOTE * Internally, this module will make sure that this function*/
   /*          has been called at least once so that the module will    */
   /*          function.  Calling this function from an external        */
   /*          location is not necessary.                               */
int InitializePASSModule(void);

   /* The following function is responsible for instructing the         */
   /* Bluetooth Stack PASS Module to clean up any resources that it has */
   /* allocated.  Once this function has completed, NO other Bluetooth  */
   /* Stack PASS Functions can be called until a successful call to the */
   /* InitializePASSModule() function is made.  The parameter to this   */
   /* function specifies the context in which this function is being    */
   /* called.  If the specified parameter is TRUE, then the module will */
   /* make sure that NO functions that would require waiting/blocking on*/
   /* Mutexes/Events are called.  This parameter would be set to TRUE if*/
   /* this function was called in a context where threads would not be  */
   /* allowed to run.  If this function is called in the context where  */
   /* threads are allowed to run then this parameter should be set to   */
   /* FALSE.                                                            */
void CleanupPASSModule(Boolean_t ForceCleanup);

#endif
