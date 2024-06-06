DEFINE from_date = 1 jan 2011
DEFINE to_date = 31 dec 2011 

SELECT 	tziros.synal AS "йыд", 
		s.epvnymia AS "пяолгхеутгс",
		tziros.eidos AS "йыд.еид.", 
		e.perigrafh AS "еидос",
		convert(VARCHAR(10),tziros.hmer_ago,103) AS "тек.гл.ацояас", 
		round( convert(FLOAT,tziros.tel_timh) , 2) AS "тек.тил.ацояас",
		round( convert(FLOAT,tziros.ttl_pos),2) AS "сум.пос",
		round( convert(FLOAT,tziros.ttl_ajia), 2) AS "сум.аниа",
		round( convert(FLOAT,tziros.ttl_tziros),2) AS "тфияос",
		round(
		CASE isnull( tziros.ttl_tziros, 0)
		WHEN 0 THEN 9
		ELSE convert(FLOAT,tziros.ttl_ajia) / convert(FLOAT,tziros.ttl_tziros) * 100.0 
		END 
		, 2 ) AS "сул.сто.тфияо"
FROM

(

SELECT agores.synal, agores.eidos, agores.hmer_ago, agores.tel_timh, 

(SELECT sum(k.posothta) 
   FROM wh_kin k
  WHERE k.hmeromhnia BETWEEN '$(from_date)' and '$(to_date)'
    AND k.parkvd = "а01"
    AND k.synal = agores.synal
    AND k.eidos = agores.eidos 
    AND k.cid="10"
 ) AS ttl_pos,
 
 (SELECT sum(k.ajia) 
   FROM wh_kin k
  WHERE k.hmeromhnia BETWEEN '$(from_date)' and '$(to_date)'
    AND k.parkvd = "а01"
    AND k.synal = agores.synal
    AND k.eidos = agores.eidos 
    AND k.cid="10"
 ) AS ttl_ajia,
 
 (SELECT sum(k.ajia) 
   FROM wh_kin k
  WHERE k.hmeromhnia BETWEEN '$(from_date)' and '$(to_date)'
    AND k.parkvd = "а01"
    AND k.synal = agores.synal
    AND k.cid="10"
 ) AS ttl_tziros


FROM
(
SELECT m.parkvd, m.synal,d.eidos, max(m.aa) AS aa, max(m.hmer_e) AS hmer_ago, max(d.timh) AS tel_timh

from sy_pardet d, sy_parmas m
where d.aa = m.aa
and m.parkvd='а01'
and m.hmer_e between '$(from_date)' and '$(to_date)'
AND m.synal != "999999"
AND m.cid="10"
GROUP BY m.parkvd,m.synal, d.eidos
) agores

) tziros, wh_eidh e, sy_synal s
WHERE tziros.synal = s.synal 
  AND tziros.eidos = e.kvdikos

ORDER BY 2 ASC , 10 DESC