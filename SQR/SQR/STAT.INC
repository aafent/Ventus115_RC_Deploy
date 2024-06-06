let $SQL2='and '

input $instat 'EXIST OR NOT EXIST STATUS '

unstring $instat by '"' into $fill1 $stat $fill2

if $stat!=''

 if $stat='NOT'
  let $SQL2=$SQL2||'NOT EXISTS'
 else
  let $SQL2=$SQL2||$stat
 end-if

  let $SQL2=$SQL2||' (select z.aitaa from da_statistor z where z.aitaa=a.aitaa and z.flag in (select zz.flag  from da_repstatus zz)) '

end-if

if $stat=''
 let $SQL2='and 1=1'
end-if
