docol:
	sub rstack, 8      
	mov [rstack], pc   
	add w, 8 		; предполагая размер ячейки 8 байт        
	mov pc, w
	jmp next           
	
exit:
	mov pc, [rstack] 
	add rstack, 8    
	jmp next         