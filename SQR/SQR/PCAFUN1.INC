! ****************************************************************************    
! (C) by P.C.A. 1997 - SQR Functions collection
! ****************************************************************************    

! (v) AUTHOR : adr, 1997 modify : -
Begin-Procedure pca_printcover
 let $repname = $L_REPORTPATH || $L_REPORTNAME || '.cov'
 move 0 to #sta
 move 0 to #xx
 open $repname as 99 record=200:VARY for-reading status=#fsta

 print ''     (,1)    ! move printer-point at start of current line
 while 1
	! I DONT KNOW WHY #end-if DOSENOT WORK
	read 99 into $ln:100 status=#fsta
        if #end-file
           break
        end-if
	if $ln=' ' or $ln='' 
	   break
        end-if

        add 1 to #xx

	print $ln    (,10)      ! print readed line 
	print ''     (+1,1)  ! move printer-point at start of next line
	
        if #xx > 60 
            break
        end-if
 end-while

 close 99
 LET #pos={PAGE-X} - 20
 print $L_X2 (,8,#pos) Fill
 print ''     (+1,1)  ! move printer-point at start of next line
End-Procedure

! ****************************************************************************    

! (v) AUTHOR : adr, 20/10/1999 modify : -

begin-procedure pca_replace($is,:$os,$oldstr,$newstr)
move '' to $os
move 1 to #start_inx
let #inx=instr($is,$oldstr,#start_inx)
while #inx>0
   let #ofs=#inx - #start_inx
   let $os=$os||substr($is,#start_inx,#ofs)||$newstr
   let #start_inx = #inx + length($oldstr)
   let #inx=instr($is,$oldstr,#start_inx)
end-while
let $os=$os||substr($is,#start_inx,length($is))

end-procedure

! ****************************************************************************    
