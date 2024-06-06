Begin-Procedure PrintDates
 let #ainx1 = instr($apohm,'"',1)
 let #ainx2 = instr($apohm,'"',#ainx1+1)
 let $apo=substr($apohm,#ainx1+1,#ainx2-#ainx1-1)
 let #binx1 = instr($evshm,'"',1)
 let #binx2 = instr($evshm,'"',#binx1+1)
 let $evs=substr($evshm,#binx1+1,#binx2-#binx1-1)
 
  let $linedate='Περίοδος  Από : '||$apo||' Εώς : '||$evs
  print $linedate (+1,) center

End-Procedure
