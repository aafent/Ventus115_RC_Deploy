position (1,1)
!print $L_G1 (,1)
!LET #pos={PAGE-X}-length($L_UNAME)
!print $L_UNAME (,#pos)

!position (2,1)
!LET #pos={PAGE-X}-14
!Date-Time   (,#pos)  'DD/MM/YY HH:MI'
!print $L_G2 (,1)

position (3,1)
!print $BOLDON ()
LET #pos={PAGE-X}-13
Page-Number (,#pos,13) 'Σελίδα : '
!print $BOLDOFF ()
!print $L_X1 ({HEAD-LINE},1,{PAGE-X}) Fill 
!if #HEAD_END_LINE = 0
!   let #HEAD_END_LINE={HEAD-SIZE}
!end-if
!print $L_X1 (#HEAD_END_LINE,1,{PAGE-X}) Fill
