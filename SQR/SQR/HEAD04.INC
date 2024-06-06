 position (1,1)
 LET #pos={PAGE-X}-14
! Date-Time   (,#pos)  'DD/MM/YY HH:MI'
 print $L_G1 (,1)
 print $L_G2 (+1,1)
 print $L_X1 ({HEAD-LINE},1,{PAGE-X}) Fill
 print $L_X1 ({HEAD-SIZE},1,{PAGE-X}) Fill

