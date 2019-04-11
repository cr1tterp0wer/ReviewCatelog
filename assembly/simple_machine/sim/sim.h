/*
 * sim.h - header file for the registers for the sim simulator
 * 
 * copyright(c) 2017 greg boyd. this material may be freely duplicated,
 * modified and distributed so long as the original copyright notice is
 * retained. It may not be included in any product for sale without
 * the permission of the author (gboyd.ccsf@gmail.com)
 */

/* progname is set by the main program to the name of your program */
/* You can use progname when printing messages if you wish */
char * progname;
/* we keep track of the number of instructions executed for reporting
   in verbose mode */
int ninstrs; 

/* a prototype for your program */
void simulate(int /*verbose*/ );

typedef short MEMTYPE; 
/* the registers pc,ir,accum,ctr should be used in 'simulate'.  */
MEMTYPE pc,ir,accum,ctr,cc;
/* for sim2, the areg register is used as well. */
MEMTYPE areg;
/* the registers mar and mbr are used in your function as well.
   they are the interface to memory, along with the get()
   and put() functions.
   NOTE: both get and put can cause a fault if mar is out-of-bounds.
      -- the fault prints a status message and aborts.
*/
MEMTYPE mar,mbr;
/* get memory[mar] and put it in mbr 
   if get is called in verbose mode, a line of information is output 
*/
void get(void);
/* put mbr into  memory[mar] 
   if put is called in verbose mode, a line of information is output 
*/
void put(void);


/* routines for your use in implementing verbose mode: */
/* dump dumps nwords of memory starting at start_addr.
   dump (0,0) dumps all of memory. 
   A call to dump(0,0) is done before and after your 
   function is called.
   dump returns a status according to its success: 0=failure.
*/
int dump(int /*start_addr*/, int /*nwords*/ );
/* dumpregs() dumps the standard registers pc,ir,accum,ctr */
void dumpregs(void);
/* pause simply waits for user to type ENTER */
void pause(void); 


/* here are some macros to help you take apart instruction 
   words. Simply use the ir as the argument; e.g:
   op = OP(ir);
   addr = ADDR(ir);
*/ 

/* get the operand part of the instruction word */
#define OP(x) ((x >> 12) & 0x0f)

/* get the address part of the instruction word */
#define ADDR(x) ((x & 0x03ff))



