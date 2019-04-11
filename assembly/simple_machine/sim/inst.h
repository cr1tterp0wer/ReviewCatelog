/* inst.h - the opcodes for the simple machine 
 *
 * copyright(c) 2017 greg boyd. this material may be freely duplicated,
 * modified and distributed so long as the original copyright notice is
 * retained. It may not be included in any product for sale without
 * the permission of the author (gboyd.ccsf@gmail.com)
 */
#define HALT 	0	/* halt the machine */
#define LOAD 	1	/* load accumulator from memory */
#define STORE	2	/* store accumulator to memory */
#define ADDC	3	/* add counter to accumulator */
#define MVAC	4	/* move accumulator to counter */
#define JEQ	5	/* jump to address if counter equals 0 */
#define JLT     6	/* jump to address if counter is less than 0 */
#define JMP     7	/* jump to address */
#define ADD	8	/* accumulator = memory + accumulator */
#define SUB	9	/* accumulator = memory - accumulator */
#define DEC	10	/* decrement counter */
/* LA take the memory address from the instruction and load it
   into the accumulator (load address) */
#define LA      11	
/* LIA use the memory address in the areg to load memory into the
   accumulator (load indirect address) */
#define LIA	12
#define SIA 13
#define MVAA 14

