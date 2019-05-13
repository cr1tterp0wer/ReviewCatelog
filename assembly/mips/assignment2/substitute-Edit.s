#
# substitute.s - substitute one character for another in a string
#

    .data
#VARIABLES - STORAGE RAM[memory]
userInput:  .space 80 #allocate 80 bytes, 1char = 1byte, 1byte = 8 bits
target:     .space 2  #allocate 1 byte for one char to target, 1byte for the '\0' (newline) 
replace:    .space 2  #allocate 1 byte for one char to replace
length:     .word  80

#MESSAGES
sprompt:   .asciiz    "Enter string:"
oprompt:   .asciiz    "Enter character you want to replace:"
nprompt:   .asciiz    "Enter replacement character:"
newPrompt: .asciiz    "Replaced String:"

    .text   #where our program starts
    .globl  main  # MAIN FUNCTION  - 
main:
    # Prompt user with message box
    li      $v0, 54
    la      $a0, sprompt
    la      $a1, userInput
    li      $a2, 80
    syscall
    
    # get original character
    # since there is no 'inputdialogchar' syscall, use an inputdialogstring
    # syscall. This will read a string but we will just use the first character
    li      $v0, 54
    la      $a0, oprompt
    la      $a1, target
    li      $a2, 2
    syscall
    
    li      $v0, 54
    la      $a0, nprompt
    la      $a1, replace
    li      $a2, 2
    syscall

##################
# YOUR CODE BELOW 
##################
	
##how to make a for loop?

## use jumps?
## check if something is not 0
##

add $t0, $t0, $zero # i = 0
la $t1, userInput # $a1 = &inputString

la $s0, target
lb $s1, 0($s0)

startLoop:
  add $s0, $s0, $t0
  lb $t2, 0($s0)  # t2 = inputString[ i ]
  beq $t2, $zero, endLoop # if ( t2 == /0 ) GOTO endLoop
  
  #if( inputString[ i ] == target) GOTO
  # else skip
  beq $t2, $s1, substitute
  j endSubstitute
  
  substitute:
    sb $t2, 0($s0)
  endSubstitute:

  # i++
  addi $t0, $t0, 1
  j startLoop
endLoop:

#Print Changed String
  li      $v0, 59
  la      $a0, newPrompt
  la      $a1, userInput
  syscall

























