SELECT DISTINCT YEAR(meccs.datum)
FROM meccs, csapat
WHERE meccs.magyar = csapat.id
AND meccs.datum >= "1980-01-01"
AND MONTH(meccs.datum) >= 1 AND MONTH(meccs.datum) <= 5;