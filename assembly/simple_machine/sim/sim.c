#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * sim.c - utility functions for sim - the simple-machine simulator
 * 
 * copyright(c) 2017 greg boyd. this material may be freely duplicated,
 * modified and distributed so long as the original copyright notice is
 * retained. It may not be included in any product for sale without
 * the permission of the author (gboyd.ccsf@gmail.com)
 */

#include "sim.h"
#define BSIZE 256
/* this macro can be used in a test to see if an 
   address is valid
*/
#define ILLEGAL(x) (( x < 0) || ( x >= ninstrs_read))
int ninstrs_read;

int verbose=0;

#define MEMSIZ 256
static MEMTYPE __memory[MEMSIZ];

void 
check_for_fault(char * from) {
    if (ILLEGAL(mar)) {
        printf(
      "%s:*** FAULT: illegal address in %s (mar=0x%04.4x, ninstrs=0x%04.4x)\n",
      progname, from, (unsigned short)mar, ninstrs_read);
        dumpregs();
        printf("******* AFTER FAULT  ********\n");
        dump(0,0);
        printf("%s: aborted.\n",progname);
        exit(1);
    }
}
    
void 
get(void) {
    check_for_fault("get");
    mbr=__memory[mar];
    if (verbose != 0) 
        printf("get() called. mar=0x%04.4x. mbr set to 0x%04.4x\n",
               (unsigned short)mar,(unsigned short)mbr);
}

void 
put(void) {
    check_for_fault("put");
    __memory[mar]=mbr;
    if (verbose != 0) 
        printf("put() called. mar=0x%04.4x, mbr=0x%04.4x\n",
               (unsigned short)mar,(unsigned short)mbr);
}

void 
pause(void) {
    char buf[BSIZE];
    printf("Hit <ENTER> to continue:");
    fgets(buf,BSIZE,stdin);
}

usage( char *str ) {
    /* output an error message, using the passed string */
    printf("%s: %s\n",progname,str);
    printf("%s: usage: %s [-v] input-file\n",progname,progname);
    exit(1);
}

get_input(char *ipfile) {
    /* 
     * takes string path to input file.
     * fills global _memory[] with instructions
     * returns number of instructions found or -1 if error
     */
    char buf[BSIZE];
    long int instr;
    int index;
    FILE *f=fopen(ipfile,"r");
    if (f == (FILE *)0) {
        printf("%s: cant read input file '%s'\n",progname,ipfile);
        return (-1);
    }
    index=0;
    while (fgets(buf,BSIZE,f)!=(char *)0) {
        char *bptr;
        if ((buf[0] == '#')|| (strlen(buf) <= 3)) continue;
        for (bptr=buf; bptr < &buf[BSIZE];bptr++) 
            if (*bptr == '#') { *bptr=0; break; }
        if (index >= MEMSIZ) {
             printf("%s: more than %d instructions!",progname,MEMSIZ);
             return(-1);
        }
#ifdef NOTDEF
        instr=strtol(buf,(char **)0,0);
        if (((instr & 0xffff0000)==0) || (((int)((short)instr)) != instr )) {
#endif
        instr=strtol(buf,(char **)0,16);
        if ( ((int) (instr & 0xffff)) != instr ) {
             printf("%s: instruction #%d is > 0xffff\n",progname,index);
             return(-1);
        }
        __memory[index++]=instr;
    }
    fclose(f);
    return(index);
}

int
dump (int begin, int ninstrs) {
    MEMTYPE *mptr;
    int index=begin;
    if ((begin==0) && (ninstrs==0)) ninstrs=ninstrs_read;
    if ((begin < 0)||(begin > (MEMSIZ-1))||
        (ninstrs <= 0)||((begin+ninstrs)>MEMSIZ)) {
         printf("%s: illegal call to dump. begin=%d, ninstrs=%d, MEMSIZ=%d\n",
              begin,ninstrs,MEMSIZ);
         return(0);
    }
    for (mptr=&__memory[begin];mptr<&__memory[begin+ninstrs];mptr++,index++) {
         printf("   __mem[0x%x]\t= 0x%04.4x\n",index,(unsigned short)*mptr);
    }
    return(1);
}

void
dumpregs(void) {
printf("    PC = 0x%04.4x, IR = 0x%04.4x, ACCUM = 0x%04.4x, CTR = 0x%04.4x",
        (unsigned short)pc, (unsigned short)ir, 
        (unsigned short)accum, (unsigned short)ctr );
printf(", AREG = 0x%04.4x", areg);
    putchar('\n');
}
       

main ( int argc, char **argv ) 
{
    char *ipfile;
    ninstrs_read=0;
    progname=argv[0];
    /* process arguments */
    if ( argc > 3 ) {
        usage("at most two arguments allowed");
    }
    if (argc == 3 ) {
        if ( strcmp(argv[1],"-v") != 0) {
            usage("first argument must be -v");
        }
        verbose++;
        argv++;
        argc--;
    }
    if (argc != 2) {
        usage("input file missing");
    }
    ipfile=argv[1];
   
    /* read in program */
    printf("%s: INPUT FILE = %s\n",progname,ipfile);
    ninstrs_read=get_input(ipfile);
    if (ninstrs_read == -1) usage("error getting input file");
    if (ninstrs_read == 0) usage("no instructions in input file");
    printf("******* BEFORE SIMULATION ********\n");
    dump(0,0);
    pc=0;
	ninstrs=0;
	if (verbose) {
		printf("START:");
		dumpregs();
	}
    simulate(verbose);
	printf("%d instructions executed.\n",ninstrs);
    printf("******* AFTER SIMULATION ********\n");
    dump(0,0);
}


