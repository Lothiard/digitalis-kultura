SELECT csapat.nev, AVG(meccs.lott + meccs.kapott) AS atlag
FROM csapat, meccs
WHERE csapat.id = meccs.magyar
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;