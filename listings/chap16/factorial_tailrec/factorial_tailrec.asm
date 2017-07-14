00000000004004c6 <factorial>:
4004c6:	89 f8                	mov    eax,edi
4004c8:	85 f6                	test   esi,esi
4004ca:	74 07                	je     4004d3 <factorial+0xd>
4004cc:	0f af c6             	imul   eax,esi
4004cf:	ff ce                	dec    esi
4004d1:	eb f5                	jmp    4004c8 <factorial+0x2>
4004d3:	c3                   	ret    
