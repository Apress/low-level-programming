next:
     mov w, pc     
     add pc, 8 	; the cell size is 8 bytes
     mov w, [w]  
     jmp [w]       
