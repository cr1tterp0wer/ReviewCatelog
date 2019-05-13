#
# substitute.s - substitute one character for another in a string
#
    .data #variables
string:      .space 80  #number of bites of storage space for string 1char = 1byte, (1byte = 8 bits) = 80 bytes
original:    .space 2   #allocate 1 byte for 1 char
replacement: .space 2

#Message
sprompt: .asciiz    "Enter string:"
oprompt: .asciiz    "Enter character you want to replace:"
nprompt: .asciiz    "Enter replacement character:"

    .text
    .globl  main
main:

    # get string
    li      $v0,54       #loading number 'immediately' into $v0 register
    la      $a0,sprompt  #loading address of 'sprompt' into argument register 0
    la      $a1,string   #loading address of 'string' into argument register 1
    li      $a2,80       #loading number 'immediately' into argument register 2
    syscall

    # get originalinal character
    # since there is no 'inputdialogchar' syscall, use an inputdialogstring
    # syscall. This will read a string but we will just use the first character
    li      $v0,54
    la      $a0,oprompt
    la      $a1,original
    li      $a2,2
    syscall

    li      $v0,54
    la      $a0,nprompt
    la      $a1,replacement
    li      $a2,2
    syscall

#
# now we are ready to do the real work of substituting every instance of
# 'old' with 'replacement' in 'string'
# HINT: before you start, initialize the following registers:
# a0 = address of the string
# a1 = char to look for
# a2 = char to replace with
# Have fun!
#
# Translate the following C code to MIPS:
#
#    int i,count=0;
#    for (i=0;string[i]!=0;i++) 
#        if (string[i] == original) { 
#            string[i]=replacement;
#            count++;
#        }
#
# last, output string and count using syscalls
#
##################
# YOUR CODE BELOW 
##################


################## Loops through + Prints string ##################

la $a1, string

loop:
  
  lb $a0, 0($a1) # string[0]
  beqz $a0, endLoop
  
  li $v0, 11
  syscall
  
  addi $a1, $a1, 1
  j loop
endLoop:

############################################################

################## loops through string and replaces ##################

la $t1, original
la $t2, replacement
li $t3, 0 # count = 0

la $a0, string
lb $a1, 0($t1) # $a1 = original[0]
lb $a2, 0($t2) # $a2 = replacement[0]

loop2:
  
  lb $t0, 0($a0) # $t0 = string[i]
  beqz $t0, endLoop2 #  if( string[i] == \0 ) GOTO endloop2:
  
  beq  $a1, $t0, replace # if( string[i] == original) GOTO replace:
  j endReplace
  replace:
    sb $a2, 0($a0)    # string[i] = replacement
    addi $t3, $t3, 1  # count = count + 1
  endReplace:

  addi $a0, $a0, 1 # i++
  j loop2
endLoop2:

############################################################
  
  li $v0, 4
  la $a0, string
  syscall
