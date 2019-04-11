#include <stdio.h>
#include "sim.h"
#include "inst.h"
/*
 * simulate.c - simulate the execution of the simple machine.
 * simulate() relies on external routines and an initialized memory
 * array to access and modify instructions and data.
 *
 * Uses global state registers ir,pc,mbr,mar,accum,ctr, and macros
 * to take an instruction apart into its two pieces (address and opcode)
 * provided in sim.h header file.
 * 
 * See the handouts entitled SimpleMachine and SimpleMachineDatapaths
 * for information on the Simple Machine
 *
 * copyright(c) 2017 greg boyd. this material may be freely duplicated,
 * modified and distributed so long as the original copyright notice is
 * retained. It may not be included in any product for sale without
 * the permission of the author (gboyd.ccsf@gmail.com)
 */

void
simulate (int verbose) {

    /* pc was set by the caller. just use it. */
	/* this allows starting at different addresses 
	   as later enhancement */

#ifdef DEBUG
    printf("in simulate (%d):\n",verbose);
#endif
    while (1) {
		ninstrs++;
	/* the fetch part of the cycle */
        mar = pc;
		if (verbose) printf("FETCH:");
        get();
        ir = mbr;
        if (verbose) printf("at PC=0x%x, EXECUTING 0x%x:\n",
            (unsigned short)pc, (unsigned short)ir);
        pc++;

#ifdef DEBUG
        printf("opcode=%d\n",OP(ir));
        printf("addr=%d\n",ADDR(ir));
#endif
	/* the decode part is indicated by use of the 
	   macros OP and ADDR */

        switch (OP(ir)) {

	    /* the execute phase. One clause for each instruction. */
            case HALT:   if (verbose != 0) {
            		     dumpregs();
        		 }
			 return;
            
            case LOAD:   mar = ADDR(ir);
                         get();
                         accum = mbr;
                         break;

            case STORE:  mar = ADDR(ir);
                         mbr = accum;
                         put();
                         break;

            case MVAC:   ctr = accum;
                         break;

            case ADDC:   accum += ctr;
                         break;

            case ADD:    mar = ADDR(ir);
                         get();
                         accum = mbr + accum;
                         break;

            case SUB:    mar = ADDR(ir);
                         get();
                         accum = mbr - accum;
                         break;

            case DEC:    ctr -= 1;
                         break;

            case JEQ:    if (ctr == 0) 
                             pc = ADDR(ir);
                         break;

            case JLT:    if (ctr < 0)
                             pc = ADDR(ir);
                         break;

            case JMP:    pc = ADDR(ir);
                         break;

            case LA:     accum = ADDR(ir);
                         break;

            case LIA:    
                         mar = areg;
                         get();
                         accum = mbr;
                         break;

	    case SIA:        mar = areg;
                         mbr = accum;
                         put();
			             break;

	    case MVAA:       areg = accum;
                         break;
            default:     printf("illegal instruction!\n");
                         dumpregs();

        }
        
        if (verbose) {
            printf("after EXECUTION:\n",(unsigned short)ir);
            dumpregs();
            pause();
        }

    }
    return ;

}

