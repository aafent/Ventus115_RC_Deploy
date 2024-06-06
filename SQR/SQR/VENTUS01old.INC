! ******************************************************************

begin-procedure get_synal_info1($synal,:$titlos,:$afm,:$epagg_kvdikos, :$epagg,:$polh,:$dieyuynsh,:$tk,:$thl,:$fax,:$email)

begin-select
b.epvnymia       () nop
b.afm            () nop
b.epaggelma      () nop
b.polh           () nop
b.dieyuynsh      () nop
b.thl            () nop
b.fax            () nop
b.taxkvd         () nop

 move &b.epvnymia    to $titlos
 move &b.afm         to $afm
 move &b.epaggelma   to $epagg_kvdikos
 move &b.polh        to $polh
 move &b.dieyuynsh   to $dieyuynsh
 move &b.thl         to $thl
 move &b.fax         to $fax
 move &b.taxkvd      to $tk
 move ' '            to $email

from sy_synal b
where b.synal=$synal
end-select


if $epagg_kvdikos > ''
   do getepagg($epagg_kvdikos,$epagg,$tmp,$tmp)
end-if

end-procedure

! ******************************************************************

begin-procedure get_cid_info($cid, #xrhsh, :#etos_xrhshs,:$titlos,:$afm,:$epagg_kvdikos, :$epagg,:$polh,:$dieyuynsh,:$tk,:$thl,:$fax,:$email)


begin-select 

datepart(year,xrhsh_arxh)     &etos_xrhshs    () nop
 
 move &etos_xrhshs to #etos_xrhshs

from ap_xrhsh
where xrhsh=#xrhsh
and   cid  =$cid
end-select


begin-select
a.synal         () nop

  do get_synal_info1(&a.synal,$titlos,$afm,$epagg_kvdikos, $epagg,$polh,$dieyuynsh,$tk,$thl,$fax,$email)

from ap_comp a
where a.cid  =$cid
end-select

end-procedure


! ******************************************************************

begin-procedure getepagg($epagg,:$epagg_per,:$drast,:$dras_per)
  move '' to $epagg_per
  move '' to $drast
  move '' to $drast_per
  if $epagg = ''
     move '9999' to $epagg
  end-if
begin-select
a.perigrafh     () NOP
a.drast         () NOP
b.perigrafh     () NOP
  move &a.perigrafh to $epagg_per
  move &a.drast     to $drast
  move &b.perigrafh to $dras_per
from ap_epaggelma a, ap_drast b
where a.kvdikos = $epagg and a.drast = b.kvdikos
end-select
end-procedure

! ******************************************************************
