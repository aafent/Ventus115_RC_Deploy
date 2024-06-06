//
//select * from sy_eggr where aa in (
//select distinct aa from sy_eggr where id=13  and hmer_e between '1 jan 2005' and '31 dec 2006' 
//  and ( (upper(aitia) like '%ай╬я%') or (upper(aitia) like '%айуя%') or (upper(aitia) like '%оях%') )
//  and synal ='585458'
//);

//select * from sy_eggr where aa = 24569;


select * from sy_eggr a where a.id=13 and exists (select 1 from sy_eggr b where a.aa=b.aa and a.id != b.id );