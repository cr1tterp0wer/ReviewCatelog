  .data
myString: .asciiz "Hello World"

  .text
  .globl main

main:

  ##CALL printCharAt( myString, 2 )
  la $a0, myString
  li $a1, 0
  jal printCharAt

j end

frodo:
  
  li $a0, 1
  li $v0, 1 
  syscall
  jr $ra

gollum:
  li $a0, 2
  li $v0, 1 
  syscall
  jr $ra

#  printCharAt( String& myString, int $a1 )
#print character at:  2 arguments: $a0 = addr of string, $a1 = index of char
printCharAt:  
  move  $t0, $a0 #load the start address
  add $t0, $t0, $a1
  
  lb $a0, 0( $t0 )
  li $v0, 11
  syscall
  jr $ra
end: